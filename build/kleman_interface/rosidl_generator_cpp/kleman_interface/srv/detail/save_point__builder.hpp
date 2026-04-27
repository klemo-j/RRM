// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kleman_interface:srv/SavePoint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "kleman_interface/srv/save_point.hpp"


#ifndef KLEMAN_INTERFACE__SRV__DETAIL__SAVE_POINT__BUILDER_HPP_
#define KLEMAN_INTERFACE__SRV__DETAIL__SAVE_POINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "kleman_interface/srv/detail/save_point__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace kleman_interface
{

namespace srv
{

namespace builder
{

class Init_SavePoint_Request_velocity
{
public:
  Init_SavePoint_Request_velocity()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kleman_interface::srv::SavePoint_Request velocity(::kleman_interface::srv::SavePoint_Request::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kleman_interface::srv::SavePoint_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kleman_interface::srv::SavePoint_Request>()
{
  return kleman_interface::srv::builder::Init_SavePoint_Request_velocity();
}

}  // namespace kleman_interface


namespace kleman_interface
{

namespace srv
{

namespace builder
{

class Init_SavePoint_Response_message
{
public:
  explicit Init_SavePoint_Response_message(::kleman_interface::srv::SavePoint_Response & msg)
  : msg_(msg)
  {}
  ::kleman_interface::srv::SavePoint_Response message(::kleman_interface::srv::SavePoint_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kleman_interface::srv::SavePoint_Response msg_;
};

class Init_SavePoint_Response_result
{
public:
  Init_SavePoint_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SavePoint_Response_message result(::kleman_interface::srv::SavePoint_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return Init_SavePoint_Response_message(msg_);
  }

private:
  ::kleman_interface::srv::SavePoint_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kleman_interface::srv::SavePoint_Response>()
{
  return kleman_interface::srv::builder::Init_SavePoint_Response_result();
}

}  // namespace kleman_interface


namespace kleman_interface
{

namespace srv
{

namespace builder
{

class Init_SavePoint_Event_response
{
public:
  explicit Init_SavePoint_Event_response(::kleman_interface::srv::SavePoint_Event & msg)
  : msg_(msg)
  {}
  ::kleman_interface::srv::SavePoint_Event response(::kleman_interface::srv::SavePoint_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kleman_interface::srv::SavePoint_Event msg_;
};

class Init_SavePoint_Event_request
{
public:
  explicit Init_SavePoint_Event_request(::kleman_interface::srv::SavePoint_Event & msg)
  : msg_(msg)
  {}
  Init_SavePoint_Event_response request(::kleman_interface::srv::SavePoint_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SavePoint_Event_response(msg_);
  }

private:
  ::kleman_interface::srv::SavePoint_Event msg_;
};

class Init_SavePoint_Event_info
{
public:
  Init_SavePoint_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SavePoint_Event_request info(::kleman_interface::srv::SavePoint_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SavePoint_Event_request(msg_);
  }

private:
  ::kleman_interface::srv::SavePoint_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kleman_interface::srv::SavePoint_Event>()
{
  return kleman_interface::srv::builder::Init_SavePoint_Event_info();
}

}  // namespace kleman_interface

#endif  // KLEMAN_INTERFACE__SRV__DETAIL__SAVE_POINT__BUILDER_HPP_
