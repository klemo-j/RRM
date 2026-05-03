#include "../include/manipulator.hpp"

#include <chrono>
#include <cmath>
#include <cstdlib>
#include <limits>

using namespace std::chrono_literals;

// ============================================================
//  Constructor
// ============================================================

Manipulator::Manipulator()
: Node("manipulator")
{
  // Publishers
  joint_pub_ = create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);
  state_pub_ = create_publisher<std_msgs::msg::Int8>("manipulator/state", 10);
  path_pub_  = create_publisher<visualization_msgs::msg::Marker>("manipulator/path", 200);

  // Two callback groups: timer keeps running while service is busy
  service_cbg_ = create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
  timer_cbg_   = create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);

  service_ = create_service<std_srvs::srv::Trigger>(
    "execute_machining",
    std::bind(&Manipulator::execute_callback, this,
              std::placeholders::_1, std::placeholders::_2),
    rclcpp::ServicesQoS(), service_cbg_);

  // State init
  joint_names_ = {"joint_1","joint_2","joint_3","joint_4","joint_5","joint_6"};
  q_     = {0,0,0,0,0,0};
  q_vel_ = {0,0,0,0,0,0};
  q_acc_ = {0,0,0,0,0,0};
  path_id_ = 0;
  logging_ = false;

  // Open log file
  const char* home = std::getenv("HOME");
  std::string log_path = home ? std::string(home) + "/joint_log.csv" : "/tmp/joint_log.csv";
  log_file_.open(log_path, std::ios::trunc);
  if (log_file_.is_open()) {
    log_file_ << "time,position,velocity,acceleration\n";
    RCLCPP_INFO(get_logger(), "Log: %s", log_path.c_str());
  }

  // Idle timer publishes joint_states at 50 Hz so RViz robot stays alive
  idle_timer_ = create_wall_timer(20ms, [this]() { publish_joints(); }, timer_cbg_);

  publish_state(IDLE);
  RCLCPP_INFO(get_logger(), "Manipulator ready. Call /execute_machining");
}

// ============================================================
//  Service callback
// ============================================================

void Manipulator::execute_callback(
  const std::shared_ptr<std_srvs::srv::Trigger::Request>,
  std::shared_ptr<std_srvs::srv::Trigger::Response> res)
{
  RCLCPP_INFO(get_logger(), "Sequence start");
  idle_timer_->cancel();

  // Reset log
  log_start_ = now();
  logging_   = true;

  run_sequence();

  logging_ = false;
  log_file_.flush();
  idle_timer_->reset();

  res->success = true;
  res->message = "done";
  RCLCPP_INFO(get_logger(), "Sequence end");
}

// ============================================================
//  Main sequence (orchestration per assignment)
// ============================================================

void Manipulator::run_sequence()
{
  // === Naucene body (z PoseTeacher) ===
  const ikfast_abb::JointValues home = {0,0,0,0,0,0};

  const ikfast_abb::JointValues t1 = {
     0.0,       0.225907, -0.077737, -7.1e-15, -0.148170, -7.1e-15};
  const ikfast_abb::JointValues t2 = {
    -0.338952,  0.321243, -0.196843, -1.232390, -0.360230,  1.211080};
  const ikfast_abb::JointValues tvia = {
    -0.182500,  0.275812,  0.618559, -0.232388, -0.907633,  0.144675};
  const ikfast_abb::JointValues t3 = {
     0.025728,  0.917645,  0.335134,  0.031729, -0.834506, -0.010856};
  const ikfast_abb::JointValues t4 = {
    -0.350548,  0.967319,  0.212717, -0.456644, -0.791832,  0.184856};

  // FK pre vsetky body
  Eigen::Affine3d p_t1 = ikfast_abb::computeFk(t1);
  Eigen::Affine3d p_t2 = ikfast_abb::computeFk(t2);
  Eigen::Affine3d p_t3 = ikfast_abb::computeFk(t3);
  Eigen::Affine3d p_t4 = ikfast_abb::computeFk(t4);

  // Approach / retract pozicie (-0.15 m v lokalnej osi X nastroja)
  Eigen::Affine3d a_t1 = make_approach_pose(p_t1, -0.15);
  Eigen::Affine3d a_t2 = make_approach_pose(p_t2, -0.15);
  Eigen::Affine3d a_t3 = make_approach_pose(p_t3, -0.15);
  Eigen::Affine3d a_t4 = make_approach_pose(p_t4, -0.15);

  // IK pre PTP ciele
  ikfast_abb::JointValues q_a_t1, q_a_t3;
  q_ = home;
  if (!calculate_ik(a_t1, q_, q_a_t1)) { RCLCPP_ERROR(get_logger(), "IK fail above_T1"); return; }

  // 1. Home -> nad T1 (PTP)
  move_ptp(q_a_t1, 4.0);

  // 2. Prisun k T1 (LIN)
  if (!move_lin(a_t1, p_t1, 2.0, APPROACHING)) return;

  // 3. Opracovanie hrany 1 (LIN)
  if (!move_lin(p_t1, p_t2, 4.0, MACHINING)) return;

  // 4. Odsun od T2 (LIN)
  if (!move_lin(p_t2, a_t2, 2.0, RETRACTING)) return;

  // 5. Prelet cez Tvia nad T3 (PTP s VIA)
  if (!calculate_ik(a_t3, q_, q_a_t3)) { RCLCPP_ERROR(get_logger(), "IK fail above_T3"); return; }
  move_ptp_via(q_, tvia, q_a_t3, 4.0, 8.0);

  // 6. Prisun k T3 (LIN)
  if (!move_lin(a_t3, p_t3, 2.0, APPROACHING)) return;

  // 7. Opracovanie hrany 2 (LIN)
  if (!move_lin(p_t3, p_t4, 4.0, MACHINING)) return;

  // 8. Odsun od T4 (LIN)
  if (!move_lin(p_t4, a_t4, 2.0, RETRACTING)) return;

  // 9. Naspat domov cez Tvia (PTP) - aby sa vyhol objektu
  move_ptp_via(q_, tvia, home, 4.0, 8.0);

  publish_state(IDLE);
}

// ============================================================
//  PTP - quintic s-curve, v=0 a=0 na zaciatku/konci
// ============================================================

void Manipulator::move_ptp(const ikfast_abb::JointValues & target, double duration)
{
  publish_state(PTP);
  start_path(PTP);

  ikfast_abb::JointValues q0 = q_;
  const double dt = 0.01;

  for (double t = 0.0; t <= duration + 1e-9; t += dt) {
    double tau = std::min(t / duration, 1.0);
    double s   = s_curve(tau);
    double sv  = s_curve_vel(tau, duration);
    double sa  = s_curve_acc(tau, duration);

    for (size_t i = 0; i < 6; i++) {
      q_[i]     = q0[i] + (target[i] - q0[i]) * s;
      q_vel_[i] = (target[i] - q0[i]) * sv;
      q_acc_[i] = (target[i] - q0[i]) * sa;
    }

    publish_joints();
    log_sample();
    add_path_point(ikfast_abb::computeFk(q_));
    rclcpp::sleep_for(10ms);
  }

  q_ = target;
  q_vel_ = {0,0,0,0,0,0};
  q_acc_ = {0,0,0,0,0,0};
  publish_joints();
  publish_path();

  // Kratka pauza medzi pohybmi - robot stoji, v=0, a=0
  // Toto zabezpeci ze graficky budu pohyby jasne oddelene a hladke
  for (int k = 0; k < 30; k++) {
    publish_joints();
    log_sample();
    rclcpp::sleep_for(10ms);
  }
}

// ============================================================
//  PTP s VIA bodom - dva kubicke segmenty s C1 spojitostou
// ============================================================

// Kvinticky polynom q(s) pre 0..T s okrajovymi podmienkami:
//   q(0)=q0, q(T)=qT, v(0)=v0, v(T)=vT, a(0)=a0, a(T)=aT
// Vrati polohu, rychlost, zrychlenie v case s.
static inline void quintic(
  double q0, double qT, double v0, double vT, double a0, double aT,
  double T, double s,
  double & q, double & v, double & a)
{
  // Koeficienty kvintickeho polynomu (riesenie linearnej sustavy)
  const double T2 = T*T, T3 = T2*T, T4 = T3*T, T5 = T4*T;
  const double dq = qT - q0;
  const double c0 = q0;
  const double c1 = v0;
  const double c2 = 0.5 * a0;
  const double c3 = (20.0*dq - (8.0*vT + 12.0*v0)*T - (3.0*a0 - aT)*T2) / (2.0*T3);
  const double c4 = (-30.0*dq + (14.0*vT + 16.0*v0)*T + (3.0*a0 - 2.0*aT)*T2) / (2.0*T4);
  const double c5 = (12.0*dq - 6.0*(vT + v0)*T - (a0 - aT)*T2) / (2.0*T5);

  const double s2 = s*s, s3 = s2*s, s4 = s3*s, s5 = s4*s;
  q = c0 + c1*s + c2*s2 + c3*s3 + c4*s4 + c5*s5;
  v = c1 + 2.0*c2*s + 3.0*c3*s2 + 4.0*c4*s3 + 5.0*c5*s4;
  a = 2.0*c2 + 6.0*c3*s + 12.0*c4*s2 + 20.0*c5*s3;
}

void Manipulator::move_ptp_via(
  const ikfast_abb::JointValues & start,
  const ikfast_abb::JointValues & via,
  const ikfast_abb::JointValues & goal,
  double t_via, double total_duration)
{
  publish_state(PTP);
  start_path(PTP);

  const double dt = 0.01;
  const double T2 = total_duration - t_via;

  // Rychlost vo via bode = priemer chord rychlosti -> C1 spojitost
  // Zrychlenie vo via = 0 (pre symetricky pohyb cez bod)
  ikfast_abb::JointValues v_via;
  for (size_t i = 0; i < 6; i++) {
    v_via[i] = 0.5 * ((via[i]-start[i])/t_via + (goal[i]-via[i])/T2);
  }

  for (double t = 0.0; t <= total_duration + 1e-9; t += dt) {
    if (t <= t_via) {
      // Segment 1: start -> via
      // v(0)=0, a(0)=0, v(T)=v_via, a(T)=0
      const double s = t;
      const double T = t_via;
      for (size_t i = 0; i < 6; i++) {
        quintic(start[i], via[i], 0.0, v_via[i], 0.0, 0.0,
                T, s, q_[i], q_vel_[i], q_acc_[i]);
      }
    } else {
      // Segment 2: via -> goal
      // v(0)=v_via, a(0)=0, v(T)=0, a(T)=0
      const double s = t - t_via;
      const double T = T2;
      for (size_t i = 0; i < 6; i++) {
        quintic(via[i], goal[i], v_via[i], 0.0, 0.0, 0.0,
                T, s, q_[i], q_vel_[i], q_acc_[i]);
      }
    }

    publish_joints();
    log_sample();
    add_path_point(ikfast_abb::computeFk(q_));
    rclcpp::sleep_for(10ms);
  }

  q_ = goal;
  q_vel_ = {0,0,0,0,0,0};
  q_acc_ = {0,0,0,0,0,0};
  publish_joints();
  publish_path();

  // Pauza medzi pohybmi
  for (int k = 0; k < 30; k++) {
    publish_joints();
    log_sample();
    rclcpp::sleep_for(10ms);
  }
}

// ============================================================
//  LIN - kartezianska linearna interpolacia, IK 100 Hz
// ============================================================

bool Manipulator::move_lin(
  const Eigen::Affine3d & start_pose,
  const Eigen::Affine3d & goal_pose,
  double duration, int state)
{
  publish_state(state);
  start_path(state);

  const double dt = 0.01;
  Eigen::Vector3d p0  = start_pose.translation();
  Eigen::Vector3d p1  = goal_pose.translation();
  Eigen::Matrix3d rot = start_pose.rotation();  // orientacia konstantna

  // Pre analyticke deriv: vypocitaj celkovy joint pohyb cez IK na konci
  ikfast_abb::JointValues q_start = q_;
  ikfast_abb::JointValues q_end;
  if (!calculate_ik(goal_pose, q_start, q_end)) {
    RCLCPP_ERROR(get_logger(), "LIN IK fail at goal");
    return false;
  }
  ikfast_abb::JointValues dq;
  for (size_t i = 0; i < 6; i++) dq[i] = q_end[i] - q_start[i];

  for (double t = 0.0; t <= duration + 1e-9; t += dt) {
    double tau = std::min(t / duration, 1.0);
    double s   = s_curve(tau);
    double sv  = s_curve_vel(tau, duration);
    double sa  = s_curve_acc(tau, duration);

    // Karteziansky bod na usecke
    Eigen::Affine3d target = Eigen::Affine3d::Identity();
    target.translation() = p0 + (p1 - p0) * s;
    target.linear()      = rot;

    // IK pre tento bod, vyber najblizsie riesenie
    ikfast_abb::JointValues new_q;
    if (!calculate_ik(target, q_, new_q)) {
      RCLCPP_ERROR(get_logger(), "LIN IK fail tau=%.3f", tau);
      return false;
    }
    q_ = new_q;

    // Analyticke vel/acc zo s-curve
    for (size_t i = 0; i < 6; i++) {
      q_vel_[i] = dq[i] * sv;
      q_acc_[i] = dq[i] * sa;
    }

    publish_joints();
    log_sample();
    add_path_point(target);
    rclcpp::sleep_for(10ms);
  }

  q_vel_ = {0,0,0,0,0,0};
  q_acc_ = {0,0,0,0,0,0};
  publish_joints();
  publish_path();

  // Pauza medzi pohybmi
  for (int k = 0; k < 30; k++) {
    publish_joints();
    log_sample();
    rclcpp::sleep_for(10ms);
  }
  return true;
}

// ============================================================
//  Approach/Retract pose: posun o `distance` v lokalnej X osi
// ============================================================

Eigen::Affine3d Manipulator::make_approach_pose(
  const Eigen::Affine3d & pose, double distance)
{
  Eigen::Affine3d r = pose;
  r.translation() = pose.translation() + distance * pose.rotation().col(0);
  return r;
}

// ============================================================
//  IK - vyber riesenie najblizsie predoslemu (Euklidovsky)
// ============================================================

bool Manipulator::calculate_ik(
  const Eigen::Affine3d & pose,
  const ikfast_abb::JointValues & previous,
  ikfast_abb::JointValues & result)
{
  auto sols = ikfast_abb::computeIK(pose);
  if (sols.empty()) return false;

  int best = 0;
  double best_d = std::numeric_limits<double>::max();
  for (size_t i = 0; i < sols.size(); i++) {
    double d = 0.0;
    for (size_t j = 0; j < 6; j++) {
      double e = sols[i][j] - previous[j];
      d += e * e;
    }
    if (d < best_d) { best_d = d; best = static_cast<int>(i); }
  }
  result = sols[best];
  return true;
}

// ============================================================
//  Kvinticka s-curve  10t^3 - 15t^4 + 6t^5
//  v=0 a=0 pri tau=0 a tau=1
// ============================================================

double Manipulator::s_curve(double tau)
{
  return 10.0*tau*tau*tau - 15.0*tau*tau*tau*tau + 6.0*tau*tau*tau*tau*tau;
}

double Manipulator::s_curve_vel(double tau, double T)
{
  return (30.0*tau*tau - 60.0*tau*tau*tau + 30.0*tau*tau*tau*tau) / T;
}

double Manipulator::s_curve_acc(double tau, double T)
{
  return (60.0*tau - 180.0*tau*tau + 120.0*tau*tau*tau) / (T*T);
}

// ============================================================
//  Publishing
// ============================================================

void Manipulator::publish_joints()
{
  sensor_msgs::msg::JointState m;
  m.header.stamp = now();
  for (size_t i = 0; i < 6; i++) {
    m.name.push_back(joint_names_[i]);
    m.position.push_back(q_[i]);
    m.velocity.push_back(q_vel_[i]);
    m.effort.push_back(q_acc_[i]);
  }
  joint_pub_->publish(m);
}

void Manipulator::publish_state(int state)
{
  std_msgs::msg::Int8 m;
  m.data = static_cast<int8_t>(state);
  state_pub_->publish(m);
}

void Manipulator::start_path(int state)
{
  path_marker_ = visualization_msgs::msg::Marker();
  path_marker_.header.frame_id = "base_link";
  path_marker_.header.stamp    = now();
  path_marker_.ns      = "tool_path";
  path_marker_.id      = path_id_++;
  path_marker_.type    = visualization_msgs::msg::Marker::LINE_STRIP;
  path_marker_.action  = visualization_msgs::msg::Marker::ADD;
  path_marker_.scale.x = 0.012;
  path_marker_.pose.orientation.w = 1.0;
  path_marker_.lifetime = rclcpp::Duration::from_seconds(0.0);

  // Modra=PTP, Zelena=Machining, Cervena=Approach/Retract
  path_marker_.color.a = 1.0;
  if      (state == PTP)       { path_marker_.color.r=0; path_marker_.color.g=0; path_marker_.color.b=1; }
  else if (state == MACHINING) { path_marker_.color.r=0; path_marker_.color.g=1; path_marker_.color.b=0; }
  else                          { path_marker_.color.r=1; path_marker_.color.g=0; path_marker_.color.b=0; }
}

void Manipulator::add_path_point(const Eigen::Affine3d & pose)
{
  geometry_msgs::msg::Point p;
  p.x = pose.translation().x();
  p.y = pose.translation().y();
  p.z = pose.translation().z();
  path_marker_.points.push_back(p);
  if (path_marker_.points.size() % 10 == 0) publish_path();
}

void Manipulator::publish_path()
{
  path_marker_.header.stamp = now();
  path_pub_->publish(path_marker_);
}

void Manipulator::log_sample()
{
  if (!logging_ || !log_file_.is_open()) return;
  double t = (now() - log_start_).seconds();
  // log joint_3 (index 2)
  log_file_ << t << "," << q_[2] << "," << q_vel_[2] << "," << q_acc_[2] << "\n";
}

// ============================================================
//  Main - MultiThreadedExecutor
// ============================================================

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<Manipulator>();
  rclcpp::executors::MultiThreadedExecutor exec(rclcpp::ExecutorOptions(), 2);
  exec.add_node(node);
  exec.spin();
  rclcpp::shutdown();
  return 0;
}