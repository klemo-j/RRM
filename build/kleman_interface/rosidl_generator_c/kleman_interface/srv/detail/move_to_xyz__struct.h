// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kleman_interface:srv/MoveToXYZ.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "kleman_interface/srv/move_to_xyz.h"


#ifndef KLEMAN_INTERFACE__SRV__DETAIL__MOVE_TO_XYZ__STRUCT_H_
#define KLEMAN_INTERFACE__SRV__DETAIL__MOVE_TO_XYZ__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/MoveToXYZ in the package kleman_interface.
typedef struct kleman_interface__srv__MoveToXYZ_Request
{
  double x;
  double y;
  double z;
  double velocity;
} kleman_interface__srv__MoveToXYZ_Request;

// Struct for a sequence of kleman_interface__srv__MoveToXYZ_Request.
typedef struct kleman_interface__srv__MoveToXYZ_Request__Sequence
{
  kleman_interface__srv__MoveToXYZ_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kleman_interface__srv__MoveToXYZ_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/MoveToXYZ in the package kleman_interface.
typedef struct kleman_interface__srv__MoveToXYZ_Response
{
  bool success;
  rosidl_runtime_c__String message;
} kleman_interface__srv__MoveToXYZ_Response;

// Struct for a sequence of kleman_interface__srv__MoveToXYZ_Response.
typedef struct kleman_interface__srv__MoveToXYZ_Response__Sequence
{
  kleman_interface__srv__MoveToXYZ_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kleman_interface__srv__MoveToXYZ_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  kleman_interface__srv__MoveToXYZ_Event__request__MAX_SIZE = 1
};
// response
enum
{
  kleman_interface__srv__MoveToXYZ_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/MoveToXYZ in the package kleman_interface.
typedef struct kleman_interface__srv__MoveToXYZ_Event
{
  service_msgs__msg__ServiceEventInfo info;
  kleman_interface__srv__MoveToXYZ_Request__Sequence request;
  kleman_interface__srv__MoveToXYZ_Response__Sequence response;
} kleman_interface__srv__MoveToXYZ_Event;

// Struct for a sequence of kleman_interface__srv__MoveToXYZ_Event.
typedef struct kleman_interface__srv__MoveToXYZ_Event__Sequence
{
  kleman_interface__srv__MoveToXYZ_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kleman_interface__srv__MoveToXYZ_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KLEMAN_INTERFACE__SRV__DETAIL__MOVE_TO_XYZ__STRUCT_H_
