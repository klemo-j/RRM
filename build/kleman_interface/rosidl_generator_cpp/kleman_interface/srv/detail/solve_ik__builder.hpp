// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kleman_interface:srv/SolveIK.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "kleman_interface/srv/solve_ik.hpp"


#ifndef KLEMAN_INTERFACE__SRV__DETAIL__SOLVE_IK__BUILDER_HPP_
#define KLEMAN_INTERFACE__SRV__DETAIL__SOLVE_IK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "kleman_interface/srv/detail/solve_ik__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace kleman_interface
{

namespace srv
{

namespace builder
{

class Init_SolveIK_Request_current_positions
{
public:
  explicit Init_SolveIK_Request_current_positions(::kleman_interface::srv::SolveIK_Request & msg)
  : msg_(msg)
  {}
  ::kleman_interface::srv::SolveIK_Request current_positions(::kleman_interface::srv::SolveIK_Request::_current_positions_type arg)
  {
    msg_.current_positions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kleman_interface::srv::SolveIK_Request msg_;
};

class Init_SolveIK_Request_z
{
public:
  explicit Init_SolveIK_Request_z(::kleman_interface::srv::SolveIK_Request & msg)
  : msg_(msg)
  {}
  Init_SolveIK_Request_current_positions z(::kleman_interface::srv::SolveIK_Request::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_SolveIK_Request_current_positions(msg_);
  }

private:
  ::kleman_interface::srv::SolveIK_Request msg_;
};

class Init_SolveIK_Request_y
{
public:
  explicit Init_SolveIK_Request_y(::kleman_interface::srv::SolveIK_Request & msg)
  : msg_(msg)
  {}
  Init_SolveIK_Request_z y(::kleman_interface::srv::SolveIK_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_SolveIK_Request_z(msg_);
  }

private:
  ::kleman_interface::srv::SolveIK_Request msg_;
};

class Init_SolveIK_Request_x
{
public:
  Init_SolveIK_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SolveIK_Request_y x(::kleman_interface::srv::SolveIK_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_SolveIK_Request_y(msg_);
  }

private:
  ::kleman_interface::srv::SolveIK_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kleman_interface::srv::SolveIK_Request>()
{
  return kleman_interface::srv::builder::Init_SolveIK_Request_x();
}

}  // namespace kleman_interface


namespace kleman_interface
{

namespace srv
{

namespace builder
{

class Init_SolveIK_Response_message
{
public:
  explicit Init_SolveIK_Response_message(::kleman_interface::srv::SolveIK_Response & msg)
  : msg_(msg)
  {}
  ::kleman_interface::srv::SolveIK_Response message(::kleman_interface::srv::SolveIK_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kleman_interface::srv::SolveIK_Response msg_;
};

class Init_SolveIK_Response_success
{
public:
  explicit Init_SolveIK_Response_success(::kleman_interface::srv::SolveIK_Response & msg)
  : msg_(msg)
  {}
  Init_SolveIK_Response_message success(::kleman_interface::srv::SolveIK_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SolveIK_Response_message(msg_);
  }

private:
  ::kleman_interface::srv::SolveIK_Response msg_;
};

class Init_SolveIK_Response_best_positions
{
public:
  Init_SolveIK_Response_best_positions()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SolveIK_Response_success best_positions(::kleman_interface::srv::SolveIK_Response::_best_positions_type arg)
  {
    msg_.best_positions = std::move(arg);
    return Init_SolveIK_Response_success(msg_);
  }

private:
  ::kleman_interface::srv::SolveIK_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kleman_interface::srv::SolveIK_Response>()
{
  return kleman_interface::srv::builder::Init_SolveIK_Response_best_positions();
}

}  // namespace kleman_interface


namespace kleman_interface
{

namespace srv
{

namespace builder
{

class Init_SolveIK_Event_response
{
public:
  explicit Init_SolveIK_Event_response(::kleman_interface::srv::SolveIK_Event & msg)
  : msg_(msg)
  {}
  ::kleman_interface::srv::SolveIK_Event response(::kleman_interface::srv::SolveIK_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kleman_interface::srv::SolveIK_Event msg_;
};

class Init_SolveIK_Event_request
{
public:
  explicit Init_SolveIK_Event_request(::kleman_interface::srv::SolveIK_Event & msg)
  : msg_(msg)
  {}
  Init_SolveIK_Event_response request(::kleman_interface::srv::SolveIK_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SolveIK_Event_response(msg_);
  }

private:
  ::kleman_interface::srv::SolveIK_Event msg_;
};

class Init_SolveIK_Event_info
{
public:
  Init_SolveIK_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SolveIK_Event_request info(::kleman_interface::srv::SolveIK_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SolveIK_Event_request(msg_);
  }

private:
  ::kleman_interface::srv::SolveIK_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kleman_interface::srv::SolveIK_Event>()
{
  return kleman_interface::srv::builder::Init_SolveIK_Event_info();
}

}  // namespace kleman_interface

#endif  // KLEMAN_INTERFACE__SRV__DETAIL__SOLVE_IK__BUILDER_HPP_
