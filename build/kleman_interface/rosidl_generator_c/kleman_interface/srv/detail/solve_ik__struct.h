// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kleman_interface:srv/SolveIK.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "kleman_interface/srv/solve_ik.h"


#ifndef KLEMAN_INTERFACE__SRV__DETAIL__SOLVE_IK__STRUCT_H_
#define KLEMAN_INTERFACE__SRV__DETAIL__SOLVE_IK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'current_positions'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/SolveIK in the package kleman_interface.
typedef struct kleman_interface__srv__SolveIK_Request
{
  double x;
  double y;
  double z;
  rosidl_runtime_c__double__Sequence current_positions;
} kleman_interface__srv__SolveIK_Request;

// Struct for a sequence of kleman_interface__srv__SolveIK_Request.
typedef struct kleman_interface__srv__SolveIK_Request__Sequence
{
  kleman_interface__srv__SolveIK_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kleman_interface__srv__SolveIK_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'best_positions'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SolveIK in the package kleman_interface.
typedef struct kleman_interface__srv__SolveIK_Response
{
  rosidl_runtime_c__double__Sequence best_positions;
  bool success;
  rosidl_runtime_c__String message;
} kleman_interface__srv__SolveIK_Response;

// Struct for a sequence of kleman_interface__srv__SolveIK_Response.
typedef struct kleman_interface__srv__SolveIK_Response__Sequence
{
  kleman_interface__srv__SolveIK_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kleman_interface__srv__SolveIK_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  kleman_interface__srv__SolveIK_Event__request__MAX_SIZE = 1
};
// response
enum
{
  kleman_interface__srv__SolveIK_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SolveIK in the package kleman_interface.
typedef struct kleman_interface__srv__SolveIK_Event
{
  service_msgs__msg__ServiceEventInfo info;
  kleman_interface__srv__SolveIK_Request__Sequence request;
  kleman_interface__srv__SolveIK_Response__Sequence response;
} kleman_interface__srv__SolveIK_Event;

// Struct for a sequence of kleman_interface__srv__SolveIK_Event.
typedef struct kleman_interface__srv__SolveIK_Event__Sequence
{
  kleman_interface__srv__SolveIK_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kleman_interface__srv__SolveIK_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KLEMAN_INTERFACE__SRV__DETAIL__SOLVE_IK__STRUCT_H_
