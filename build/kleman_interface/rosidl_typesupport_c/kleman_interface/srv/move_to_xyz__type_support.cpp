// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from kleman_interface:srv/MoveToXYZ.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "kleman_interface/srv/detail/move_to_xyz__struct.h"
#include "kleman_interface/srv/detail/move_to_xyz__type_support.h"
#include "kleman_interface/srv/detail/move_to_xyz__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace kleman_interface
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _MoveToXYZ_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveToXYZ_Request_type_support_ids_t;

static const _MoveToXYZ_Request_type_support_ids_t _MoveToXYZ_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveToXYZ_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveToXYZ_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveToXYZ_Request_type_support_symbol_names_t _MoveToXYZ_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kleman_interface, srv, MoveToXYZ_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kleman_interface, srv, MoveToXYZ_Request)),
  }
};

typedef struct _MoveToXYZ_Request_type_support_data_t
{
  void * data[2];
} _MoveToXYZ_Request_type_support_data_t;

static _MoveToXYZ_Request_type_support_data_t _MoveToXYZ_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveToXYZ_Request_message_typesupport_map = {
  2,
  "kleman_interface",
  &_MoveToXYZ_Request_message_typesupport_ids.typesupport_identifier[0],
  &_MoveToXYZ_Request_message_typesupport_symbol_names.symbol_name[0],
  &_MoveToXYZ_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveToXYZ_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveToXYZ_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &kleman_interface__srv__MoveToXYZ_Request__get_type_hash,
  &kleman_interface__srv__MoveToXYZ_Request__get_type_description,
  &kleman_interface__srv__MoveToXYZ_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace kleman_interface

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, kleman_interface, srv, MoveToXYZ_Request)() {
  return &::kleman_interface::srv::rosidl_typesupport_c::MoveToXYZ_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "kleman_interface/srv/detail/move_to_xyz__struct.h"
// already included above
// #include "kleman_interface/srv/detail/move_to_xyz__type_support.h"
// already included above
// #include "kleman_interface/srv/detail/move_to_xyz__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace kleman_interface
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _MoveToXYZ_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveToXYZ_Response_type_support_ids_t;

static const _MoveToXYZ_Response_type_support_ids_t _MoveToXYZ_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveToXYZ_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveToXYZ_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveToXYZ_Response_type_support_symbol_names_t _MoveToXYZ_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kleman_interface, srv, MoveToXYZ_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kleman_interface, srv, MoveToXYZ_Response)),
  }
};

typedef struct _MoveToXYZ_Response_type_support_data_t
{
  void * data[2];
} _MoveToXYZ_Response_type_support_data_t;

static _MoveToXYZ_Response_type_support_data_t _MoveToXYZ_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveToXYZ_Response_message_typesupport_map = {
  2,
  "kleman_interface",
  &_MoveToXYZ_Response_message_typesupport_ids.typesupport_identifier[0],
  &_MoveToXYZ_Response_message_typesupport_symbol_names.symbol_name[0],
  &_MoveToXYZ_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveToXYZ_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveToXYZ_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &kleman_interface__srv__MoveToXYZ_Response__get_type_hash,
  &kleman_interface__srv__MoveToXYZ_Response__get_type_description,
  &kleman_interface__srv__MoveToXYZ_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace kleman_interface

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, kleman_interface, srv, MoveToXYZ_Response)() {
  return &::kleman_interface::srv::rosidl_typesupport_c::MoveToXYZ_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "kleman_interface/srv/detail/move_to_xyz__struct.h"
// already included above
// #include "kleman_interface/srv/detail/move_to_xyz__type_support.h"
// already included above
// #include "kleman_interface/srv/detail/move_to_xyz__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace kleman_interface
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _MoveToXYZ_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveToXYZ_Event_type_support_ids_t;

static const _MoveToXYZ_Event_type_support_ids_t _MoveToXYZ_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveToXYZ_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveToXYZ_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveToXYZ_Event_type_support_symbol_names_t _MoveToXYZ_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kleman_interface, srv, MoveToXYZ_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kleman_interface, srv, MoveToXYZ_Event)),
  }
};

typedef struct _MoveToXYZ_Event_type_support_data_t
{
  void * data[2];
} _MoveToXYZ_Event_type_support_data_t;

static _MoveToXYZ_Event_type_support_data_t _MoveToXYZ_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveToXYZ_Event_message_typesupport_map = {
  2,
  "kleman_interface",
  &_MoveToXYZ_Event_message_typesupport_ids.typesupport_identifier[0],
  &_MoveToXYZ_Event_message_typesupport_symbol_names.symbol_name[0],
  &_MoveToXYZ_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveToXYZ_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveToXYZ_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &kleman_interface__srv__MoveToXYZ_Event__get_type_hash,
  &kleman_interface__srv__MoveToXYZ_Event__get_type_description,
  &kleman_interface__srv__MoveToXYZ_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace kleman_interface

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, kleman_interface, srv, MoveToXYZ_Event)() {
  return &::kleman_interface::srv::rosidl_typesupport_c::MoveToXYZ_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "kleman_interface/srv/detail/move_to_xyz__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace kleman_interface
{

namespace srv
{

namespace rosidl_typesupport_c
{
typedef struct _MoveToXYZ_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveToXYZ_type_support_ids_t;

static const _MoveToXYZ_type_support_ids_t _MoveToXYZ_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveToXYZ_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveToXYZ_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveToXYZ_type_support_symbol_names_t _MoveToXYZ_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kleman_interface, srv, MoveToXYZ)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kleman_interface, srv, MoveToXYZ)),
  }
};

typedef struct _MoveToXYZ_type_support_data_t
{
  void * data[2];
} _MoveToXYZ_type_support_data_t;

static _MoveToXYZ_type_support_data_t _MoveToXYZ_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveToXYZ_service_typesupport_map = {
  2,
  "kleman_interface",
  &_MoveToXYZ_service_typesupport_ids.typesupport_identifier[0],
  &_MoveToXYZ_service_typesupport_symbol_names.symbol_name[0],
  &_MoveToXYZ_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t MoveToXYZ_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveToXYZ_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &MoveToXYZ_Request_message_type_support_handle,
  &MoveToXYZ_Response_message_type_support_handle,
  &MoveToXYZ_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    kleman_interface,
    srv,
    MoveToXYZ
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    kleman_interface,
    srv,
    MoveToXYZ
  ),
  &kleman_interface__srv__MoveToXYZ__get_type_hash,
  &kleman_interface__srv__MoveToXYZ__get_type_description,
  &kleman_interface__srv__MoveToXYZ__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace kleman_interface

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, kleman_interface, srv, MoveToXYZ)() {
  return &::kleman_interface::srv::rosidl_typesupport_c::MoveToXYZ_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
