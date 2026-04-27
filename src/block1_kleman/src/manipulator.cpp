#include "../include/manipulator.hpp"

#include <cmath>
#include <stdexcept>
#include <algorithm>

namespace block1_kleman
{

double Manipulator::blendingPosition(double tau) const
{
  // Kvinticky polynom:
  // s(0) = 0, s(1) = 1
  // s'(0) = 0, s'(1) = 0
  // s''(0) = 0, s''(1) = 0
  return 10.0 * std::pow(tau, 3)
       - 15.0 * std::pow(tau, 4)
       +  6.0 * std::pow(tau, 5);
}

double Manipulator::blendingVelocity(double tau, double duration) const
{
  // ds/dt = ds/dtau * dtau/dt = ds/dtau / T
  return (
    30.0 * std::pow(tau, 2)
    - 60.0 * std::pow(tau, 3)
    + 30.0 * std::pow(tau, 4)
  ) / duration;
}

double Manipulator::blendingAcceleration(double tau, double duration) const
{
  // d2s/dt2 = d2s/dtau2 / T^2
  return (
    60.0 * tau
    - 180.0 * std::pow(tau, 2)
    + 120.0 * std::pow(tau, 3)
  ) / (duration * duration);
}

std::vector<Manipulator::TrajectoryPoint> Manipulator::generatePTP(
  const JointArray & start,
  const JointArray & goal,
  double duration,
  double dt) const
{
  if (duration <= 0.0) {
    throw std::runtime_error("PTP duration must be positive");
  }

  if (dt <= 0.0) {
    throw std::runtime_error("PTP dt must be positive");
  }

  std::vector<TrajectoryPoint> trajectory;

  const int steps = static_cast<int>(std::ceil(duration / dt));

  trajectory.reserve(static_cast<size_t>(steps) + 1);

  for (int i = 0; i <= steps; i++) {
    double t = std::min(i * dt, duration);
    double tau = t / duration;

    double s = blendingPosition(tau);
    double ds = blendingVelocity(tau, duration);
    double dds = blendingAcceleration(tau, duration);

    TrajectoryPoint point;
    point.time = t;

    for (size_t j = 0; j < 6; j++) {
      double delta = goal[j] - start[j];

      point.position[j] = start[j] + s * delta;
      point.velocity[j] = ds * delta;
      point.acceleration[j] = dds * delta;
    }

    trajectory.push_back(point);
  }

  // Pre istotu presne nastavime posledny bod.
  trajectory.back().time = duration;
  trajectory.back().position = goal;

  for (size_t j = 0; j < 6; j++) {
    trajectory.back().velocity[j] = 0.0;
    trajectory.back().acceleration[j] = 0.0;
  }

  return trajectory;
}

}  // namespace block1_kleman