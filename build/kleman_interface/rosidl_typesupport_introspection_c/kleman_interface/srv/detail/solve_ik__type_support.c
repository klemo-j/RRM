// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from kleman_interface:srv/SolveIK.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "kleman_interface/srv/detail/solve_ik__rosidl_typesupport_introspection_c.h"
#include "kleman_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "kleman_interface/srv/detail/solve_ik__functions.h"
#include "kleman_interface/srv/detail/solve_ik__struct.h"


// Include directives for member types
// Member `current_positions`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__SolveIK_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kleman_interface__srv__SolveIK_Request__init(message_memory);
}

void kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__SolveIK_Request_fini_function(void * message_memory)
{
  kleman_interface__srv__SolveIK_Request__fini(message_memory);
}

size_t kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__size_function__SolveIK_Request__current_positions(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__get_const_function__SolveIK_Request__current_positions(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__get_function__SolveIK_Request__current_positions(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__fetch_function__SolveIK_Request__current_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__get_const_function__SolveIK_Request__current_positions(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__assign_function__SolveIK_Request__current_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__get_function__SolveIK_Request__current_positions(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__resize_function__SolveIK_Request__current_positions(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__SolveIK_Request_message_member_array[4] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kleman_interface__srv__SolveIK_Request, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kleman_interface__srv__SolveIK_Request, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kleman_interface__srv__SolveIK_Request, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current_positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kleman_interface__srv__SolveIK_Request, current_positions),  // bytes offset in struct
    NULL,  // default value
    kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__size_function__SolveIK_Request__current_positions,  // size() function pointer
    kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__get_const_function__SolveIK_Request__current_positions,  // get_const(index) function pointer
    kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__get_function__SolveIK_Request__current_positions,  // get(index) function pointer
    kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__fetch_function__SolveIK_Request__current_positions,  // fetch(index, &value) function pointer
    kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__assign_function__SolveIK_Request__current_positions,  // assign(index, value) function pointer
    kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__resize_function__SolveIK_Request__current_positions  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__SolveIK_Request_message_members = {
  "kleman_interface__srv",  // message namespace
  "SolveIK_Request",  // message name
  4,  // number of fields
  sizeof(kleman_interface__srv__SolveIK_Request),
  false,  // has_any_key_member_
  kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__SolveIK_Request_message_member_array,  // message members
  kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__SolveIK_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__SolveIK_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__SolveIK_Request_message_type_support_handle = {
  0,
  &kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__SolveIK_Request_message_members,
  get_message_typesupport_handle_function,
  &kleman_interface__srv__SolveIK_Request__get_type_hash,
  &kleman_interface__srv__SolveIK_Request__get_type_description,
  &kleman_interface__srv__SolveIK_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kleman_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kleman_interface, srv, SolveIK_Request)() {
  if (!kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__SolveIK_Request_message_type_support_handle.typesupport_identifier) {
    kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__SolveIK_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__SolveIK_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "kleman_interface/srv/detail/solve_ik__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kleman_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kleman_interface/srv/detail/solve_ik__functions.h"
// already included above
// #include "kleman_interface/srv/detail/solve_ik__struct.h"


// Include directives for member types
// Member `best_positions`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__SolveIK_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kleman_interface__srv__SolveIK_Response__init(message_memory);
}

void kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__SolveIK_Response_fini_function(void * message_memory)
{
  kleman_interface__srv__SolveIK_Response__fini(message_memory);
}

size_t kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__size_function__SolveIK_Response__best_positions(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__get_const_function__SolveIK_Response__best_positions(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__get_function__SolveIK_Response__best_positions(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__fetch_function__SolveIK_Response__best_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__get_const_function__SolveIK_Response__best_positions(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__assign_function__SolveIK_Response__best_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__get_function__SolveIK_Response__best_positions(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__resize_function__SolveIK_Response__best_positions(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__SolveIK_Response_message_member_array[3] = {
  {
    "best_positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kleman_interface__srv__SolveIK_Response, best_positions),  // bytes offset in struct
    NULL,  // default value
    kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__size_function__SolveIK_Response__best_positions,  // size() function pointer
    kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__get_const_function__SolveIK_Response__best_positions,  // get_const(index) function pointer
    kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__get_function__SolveIK_Response__best_positions,  // get(index) function pointer
    kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__fetch_function__SolveIK_Response__best_positions,  // fetch(index, &value) function pointer
    kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__assign_function__SolveIK_Response__best_positions,  // assign(index, value) function pointer
    kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__resize_function__SolveIK_Response__best_positions  // resize(index) function pointer
  },
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kleman_interface__srv__SolveIK_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kleman_interface__srv__SolveIK_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__SolveIK_Response_message_members = {
  "kleman_interface__srv",  // message namespace
  "SolveIK_Response",  // message name
  3,  // number of fields
  sizeof(kleman_interface__srv__SolveIK_Response),
  false,  // has_any_key_member_
  kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__SolveIK_Response_message_member_array,  // message members
  kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__SolveIK_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__SolveIK_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__SolveIK_Response_message_type_support_handle = {
  0,
  &kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__SolveIK_Response_message_members,
  get_message_typesupport_handle_function,
  &kleman_interface__srv__SolveIK_Response__get_type_hash,
  &kleman_interface__srv__SolveIK_Response__get_type_description,
  &kleman_interface__srv__SolveIK_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kleman_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kleman_interface, srv, SolveIK_Response)() {
  if (!kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__SolveIK_Response_message_type_support_handle.typesupport_identifier) {
    kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__SolveIK_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__SolveIK_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "kleman_interface/srv/detail/solve_ik__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kleman_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kleman_interface/srv/detail/solve_ik__functions.h"
// already included above
// #include "kleman_interface/srv/detail/solve_ik__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "kleman_interface/srv/solve_ik.h"
// Member `request`
// Member `response`
// already included above
// #include "kleman_interface/srv/detail/solve_ik__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__SolveIK_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kleman_interface__srv__SolveIK_Event__init(message_memory);
}

void kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__SolveIK_Event_fini_function(void * message_memory)
{
  kleman_interface__srv__SolveIK_Event__fini(message_memory);
}

size_t kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__size_function__SolveIK_Event__request(
  const void * untyped_member)
{
  const kleman_interface__srv__SolveIK_Request__Sequence * member =
    (const kleman_interface__srv__SolveIK_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__get_const_function__SolveIK_Event__request(
  const void * untyped_member, size_t index)
{
  const kleman_interface__srv__SolveIK_Request__Sequence * member =
    (const kleman_interface__srv__SolveIK_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__get_function__SolveIK_Event__request(
  void * untyped_member, size_t index)
{
  kleman_interface__srv__SolveIK_Request__Sequence * member =
    (kleman_interface__srv__SolveIK_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__fetch_function__SolveIK_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const kleman_interface__srv__SolveIK_Request * item =
    ((const kleman_interface__srv__SolveIK_Request *)
    kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__get_const_function__SolveIK_Event__request(untyped_member, index));
  kleman_interface__srv__SolveIK_Request * value =
    (kleman_interface__srv__SolveIK_Request *)(untyped_value);
  *value = *item;
}

void kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__assign_function__SolveIK_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  kleman_interface__srv__SolveIK_Request * item =
    ((kleman_interface__srv__SolveIK_Request *)
    kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__get_function__SolveIK_Event__request(untyped_member, index));
  const kleman_interface__srv__SolveIK_Request * value =
    (const kleman_interface__srv__SolveIK_Request *)(untyped_value);
  *item = *value;
}

bool kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__resize_function__SolveIK_Event__request(
  void * untyped_member, size_t size)
{
  kleman_interface__srv__SolveIK_Request__Sequence * member =
    (kleman_interface__srv__SolveIK_Request__Sequence *)(untyped_member);
  kleman_interface__srv__SolveIK_Request__Sequence__fini(member);
  return kleman_interface__srv__SolveIK_Request__Sequence__init(member, size);
}

size_t kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__size_function__SolveIK_Event__response(
  const void * untyped_member)
{
  const kleman_interface__srv__SolveIK_Response__Sequence * member =
    (const kleman_interface__srv__SolveIK_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__get_const_function__SolveIK_Event__response(
  const void * untyped_member, size_t index)
{
  const kleman_interface__srv__SolveIK_Response__Sequence * member =
    (const kleman_interface__srv__SolveIK_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__get_function__SolveIK_Event__response(
  void * untyped_member, size_t index)
{
  kleman_interface__srv__SolveIK_Response__Sequence * member =
    (kleman_interface__srv__SolveIK_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__fetch_function__SolveIK_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const kleman_interface__srv__SolveIK_Response * item =
    ((const kleman_interface__srv__SolveIK_Response *)
    kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__get_const_function__SolveIK_Event__response(untyped_member, index));
  kleman_interface__srv__SolveIK_Response * value =
    (kleman_interface__srv__SolveIK_Response *)(untyped_value);
  *value = *item;
}

void kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__assign_function__SolveIK_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  kleman_interface__srv__SolveIK_Response * item =
    ((kleman_interface__srv__SolveIK_Response *)
    kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__get_function__SolveIK_Event__response(untyped_member, index));
  const kleman_interface__srv__SolveIK_Response * value =
    (const kleman_interface__srv__SolveIK_Response *)(untyped_value);
  *item = *value;
}

bool kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__resize_function__SolveIK_Event__response(
  void * untyped_member, size_t size)
{
  kleman_interface__srv__SolveIK_Response__Sequence * member =
    (kleman_interface__srv__SolveIK_Response__Sequence *)(untyped_member);
  kleman_interface__srv__SolveIK_Response__Sequence__fini(member);
  return kleman_interface__srv__SolveIK_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__SolveIK_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kleman_interface__srv__SolveIK_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(kleman_interface__srv__SolveIK_Event, request),  // bytes offset in struct
    NULL,  // default value
    kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__size_function__SolveIK_Event__request,  // size() function pointer
    kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__get_const_function__SolveIK_Event__request,  // get_const(index) function pointer
    kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__get_function__SolveIK_Event__request,  // get(index) function pointer
    kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__fetch_function__SolveIK_Event__request,  // fetch(index, &value) function pointer
    kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__assign_function__SolveIK_Event__request,  // assign(index, value) function pointer
    kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__resize_function__SolveIK_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(kleman_interface__srv__SolveIK_Event, response),  // bytes offset in struct
    NULL,  // default value
    kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__size_function__SolveIK_Event__response,  // size() function pointer
    kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__get_const_function__SolveIK_Event__response,  // get_const(index) function pointer
    kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__get_function__SolveIK_Event__response,  // get(index) function pointer
    kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__fetch_function__SolveIK_Event__response,  // fetch(index, &value) function pointer
    kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__assign_function__SolveIK_Event__response,  // assign(index, value) function pointer
    kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__resize_function__SolveIK_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__SolveIK_Event_message_members = {
  "kleman_interface__srv",  // message namespace
  "SolveIK_Event",  // message name
  3,  // number of fields
  sizeof(kleman_interface__srv__SolveIK_Event),
  false,  // has_any_key_member_
  kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__SolveIK_Event_message_member_array,  // message members
  kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__SolveIK_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__SolveIK_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__SolveIK_Event_message_type_support_handle = {
  0,
  &kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__SolveIK_Event_message_members,
  get_message_typesupport_handle_function,
  &kleman_interface__srv__SolveIK_Event__get_type_hash,
  &kleman_interface__srv__SolveIK_Event__get_type_description,
  &kleman_interface__srv__SolveIK_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kleman_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kleman_interface, srv, SolveIK_Event)() {
  kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__SolveIK_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__SolveIK_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kleman_interface, srv, SolveIK_Request)();
  kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__SolveIK_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kleman_interface, srv, SolveIK_Response)();
  if (!kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__SolveIK_Event_message_type_support_handle.typesupport_identifier) {
    kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__SolveIK_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__SolveIK_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "kleman_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "kleman_interface/srv/detail/solve_ik__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers kleman_interface__srv__detail__solve_ik__rosidl_typesupport_introspection_c__SolveIK_service_members = {
  "kleman_interface__srv",  // service namespace
  "SolveIK",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // kleman_interface__srv__detail__solve_ik__rosidl_typesupport_introspection_c__SolveIK_Request_message_type_support_handle,
  NULL,  // response message
  // kleman_interface__srv__detail__solve_ik__rosidl_typesupport_introspection_c__SolveIK_Response_message_type_support_handle
  NULL  // event_message
  // kleman_interface__srv__detail__solve_ik__rosidl_typesupport_introspection_c__SolveIK_Response_message_type_support_handle
};


static rosidl_service_type_support_t kleman_interface__srv__detail__solve_ik__rosidl_typesupport_introspection_c__SolveIK_service_type_support_handle = {
  0,
  &kleman_interface__srv__detail__solve_ik__rosidl_typesupport_introspection_c__SolveIK_service_members,
  get_service_typesupport_handle_function,
  &kleman_interface__srv__SolveIK_Request__rosidl_typesupport_introspection_c__SolveIK_Request_message_type_support_handle,
  &kleman_interface__srv__SolveIK_Response__rosidl_typesupport_introspection_c__SolveIK_Response_message_type_support_handle,
  &kleman_interface__srv__SolveIK_Event__rosidl_typesupport_introspection_c__SolveIK_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    kleman_interface,
    srv,
    SolveIK
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    kleman_interface,
    srv,
    SolveIK
  ),
  &kleman_interface__srv__SolveIK__get_type_hash,
  &kleman_interface__srv__SolveIK__get_type_description,
  &kleman_interface__srv__SolveIK__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kleman_interface, srv, SolveIK_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kleman_interface, srv, SolveIK_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kleman_interface, srv, SolveIK_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kleman_interface
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kleman_interface, srv, SolveIK)(void) {
  if (!kleman_interface__srv__detail__solve_ik__rosidl_typesupport_introspection_c__SolveIK_service_type_support_handle.typesupport_identifier) {
    kleman_interface__srv__detail__solve_ik__rosidl_typesupport_introspection_c__SolveIK_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)kleman_interface__srv__detail__solve_ik__rosidl_typesupport_introspection_c__SolveIK_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kleman_interface, srv, SolveIK_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kleman_interface, srv, SolveIK_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kleman_interface, srv, SolveIK_Event)()->data;
  }

  return &kleman_interface__srv__detail__solve_ik__rosidl_typesupport_introspection_c__SolveIK_service_type_support_handle;
}
