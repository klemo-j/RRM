// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kleman_interface:srv/MoveToXYZ.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "kleman_interface/srv/move_to_xyz.hpp"


#ifndef KLEMAN_INTERFACE__SRV__DETAIL__MOVE_TO_XYZ__BUILDER_HPP_
#define KLEMAN_INTERFACE__SRV__DETAIL__MOVE_TO_XYZ__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "kleman_interface/srv/detail/move_to_xyz__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace kleman_interface
{

namespace srv
{

namespace builder
{

class Init_MoveToXYZ_Request_velocity
{
public:
  explicit Init_MoveToXYZ_Request_velocity(::kleman_interface::srv::MoveToXYZ_Request & msg)
  : msg_(msg)
  {}
  ::kleman_interface::srv::MoveToXYZ_Request velocity(::kleman_interface::srv::MoveToXYZ_Request::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kleman_interface::srv::MoveToXYZ_Request msg_;
};

class Init_MoveToXYZ_Request_z
{
public:
  explicit Init_MoveToXYZ_Request_z(::kleman_interface::srv::MoveToXYZ_Request & msg)
  : msg_(msg)
  {}
  Init_MoveToXYZ_Request_velocity z(::kleman_interface::srv::MoveToXYZ_Request::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_MoveToXYZ_Request_velocity(msg_);
  }

private:
  ::kleman_interface::srv::MoveToXYZ_Request msg_;
};

class Init_MoveToXYZ_Request_y
{
public:
  explicit Init_MoveToXYZ_Request_y(::kleman_interface::srv::MoveToXYZ_Request & msg)
  : msg_(msg)
  {}
  Init_MoveToXYZ_Request_z y(::kleman_interface::srv::MoveToXYZ_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_MoveToXYZ_Request_z(msg_);
  }

private:
  ::kleman_interface::srv::MoveToXYZ_Request msg_;
};

class Init_MoveToXYZ_Request_x
{
public:
  Init_MoveToXYZ_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveToXYZ_Request_y x(::kleman_interface::srv::MoveToXYZ_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_MoveToXYZ_Request_y(msg_);
  }

private:
  ::kleman_interface::srv::MoveToXYZ_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kleman_interface::srv::MoveToXYZ_Request>()
{
  return kleman_interface::srv::builder::Init_MoveToXYZ_Request_x();
}

}  // namespace kleman_interface


namespace kleman_interface
{

namespace srv
{

namespace builder
{

class Init_MoveToXYZ_Response_message
{
public:
  explicit Init_MoveToXYZ_Response_message(::kleman_interface::srv::MoveToXYZ_Response & msg)
  : msg_(msg)
  {}
  ::kleman_interface::srv::MoveToXYZ_Response message(::kleman_interface::srv::MoveToXYZ_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kleman_interface::srv::MoveToXYZ_Response msg_;
};

class Init_MoveToXYZ_Response_success
{
public:
  Init_MoveToXYZ_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveToXYZ_Response_message success(::kleman_interface::srv::MoveToXYZ_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_MoveToXYZ_Response_message(msg_);
  }

private:
  ::kleman_interface::srv::MoveToXYZ_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kleman_interface::srv::MoveToXYZ_Response>()
{
  return kleman_interface::srv::builder::Init_MoveToXYZ_Response_success();
}

}  // namespace kleman_interface


namespace kleman_interface
{

namespace srv
{

namespace builder
{

class Init_MoveToXYZ_Event_response
{
public:
  explicit Init_MoveToXYZ_Event_response(::kleman_interface::srv::MoveToXYZ_Event & msg)
  : msg_(msg)
  {}
  ::kleman_interface::srv::MoveToXYZ_Event response(::kleman_interface::srv::MoveToXYZ_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kleman_interface::srv::MoveToXYZ_Event msg_;
};

class Init_MoveToXYZ_Event_request
{
public:
  explicit Init_MoveToXYZ_Event_request(::kleman_interface::srv::MoveToXYZ_Event & msg)
  : msg_(msg)
  {}
  Init_MoveToXYZ_Event_response request(::kleman_interface::srv::MoveToXYZ_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_MoveToXYZ_Event_response(msg_);
  }

private:
  ::kleman_interface::srv::MoveToXYZ_Event msg_;
};

class Init_MoveToXYZ_Event_info
{
public:
  Init_MoveToXYZ_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveToXYZ_Event_request info(::kleman_interface::srv::MoveToXYZ_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_MoveToXYZ_Event_request(msg_);
  }

private:
  ::kleman_interface::srv::MoveToXYZ_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kleman_interface::srv::MoveToXYZ_Event>()
{
  return kleman_interface::srv::builder::Init_MoveToXYZ_Event_info();
}

}  // namespace kleman_interface

#endif  // KLEMAN_INTERFACE__SRV__DETAIL__MOVE_TO_XYZ__BUILDER_HPP_
