// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from kleman_interface:srv/SavePoint.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "kleman_interface/srv/detail/save_point__functions.h"
#include "kleman_interface/srv/detail/save_point__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace kleman_interface
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SavePoint_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SavePoint_Request_type_support_ids_t;

static const _SavePoint_Request_type_support_ids_t _SavePoint_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SavePoint_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SavePoint_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SavePoint_Request_type_support_symbol_names_t _SavePoint_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, kleman_interface, srv, SavePoint_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, kleman_interface, srv, SavePoint_Request)),
  }
};

typedef struct _SavePoint_Request_type_support_data_t
{
  void * data[2];
} _SavePoint_Request_type_support_data_t;

static _SavePoint_Request_type_support_data_t _SavePoint_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SavePoint_Request_message_typesupport_map = {
  2,
  "kleman_interface",
  &_SavePoint_Request_message_typesupport_ids.typesupport_identifier[0],
  &_SavePoint_Request_message_typesupport_symbol_names.symbol_name[0],
  &_SavePoint_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SavePoint_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SavePoint_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &kleman_interface__srv__SavePoint_Request__get_type_hash,
  &kleman_interface__srv__SavePoint_Request__get_type_description,
  &kleman_interface__srv__SavePoint_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace kleman_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<kleman_interface::srv::SavePoint_Request>()
{
  return &::kleman_interface::srv::rosidl_typesupport_cpp::SavePoint_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, kleman_interface, srv, SavePoint_Request)() {
  return get_message_type_support_handle<kleman_interface::srv::SavePoint_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "kleman_interface/srv/detail/save_point__functions.h"
// already included above
// #include "kleman_interface/srv/detail/save_point__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace kleman_interface
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SavePoint_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SavePoint_Response_type_support_ids_t;

static const _SavePoint_Response_type_support_ids_t _SavePoint_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SavePoint_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SavePoint_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SavePoint_Response_type_support_symbol_names_t _SavePoint_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, kleman_interface, srv, SavePoint_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, kleman_interface, srv, SavePoint_Response)),
  }
};

typedef struct _SavePoint_Response_type_support_data_t
{
  void * data[2];
} _SavePoint_Response_type_support_data_t;

static _SavePoint_Response_type_support_data_t _SavePoint_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SavePoint_Response_message_typesupport_map = {
  2,
  "kleman_interface",
  &_SavePoint_Response_message_typesupport_ids.typesupport_identifier[0],
  &_SavePoint_Response_message_typesupport_symbol_names.symbol_name[0],
  &_SavePoint_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SavePoint_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SavePoint_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &kleman_interface__srv__SavePoint_Response__get_type_hash,
  &kleman_interface__srv__SavePoint_Response__get_type_description,
  &kleman_interface__srv__SavePoint_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace kleman_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<kleman_interface::srv::SavePoint_Response>()
{
  return &::kleman_interface::srv::rosidl_typesupport_cpp::SavePoint_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, kleman_interface, srv, SavePoint_Response)() {
  return get_message_type_support_handle<kleman_interface::srv::SavePoint_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "kleman_interface/srv/detail/save_point__functions.h"
// already included above
// #include "kleman_interface/srv/detail/save_point__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace kleman_interface
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SavePoint_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SavePoint_Event_type_support_ids_t;

static const _SavePoint_Event_type_support_ids_t _SavePoint_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SavePoint_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SavePoint_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SavePoint_Event_type_support_symbol_names_t _SavePoint_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, kleman_interface, srv, SavePoint_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, kleman_interface, srv, SavePoint_Event)),
  }
};

typedef struct _SavePoint_Event_type_support_data_t
{
  void * data[2];
} _SavePoint_Event_type_support_data_t;

static _SavePoint_Event_type_support_data_t _SavePoint_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SavePoint_Event_message_typesupport_map = {
  2,
  "kleman_interface",
  &_SavePoint_Event_message_typesupport_ids.typesupport_identifier[0],
  &_SavePoint_Event_message_typesupport_symbol_names.symbol_name[0],
  &_SavePoint_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SavePoint_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SavePoint_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &kleman_interface__srv__SavePoint_Event__get_type_hash,
  &kleman_interface__srv__SavePoint_Event__get_type_description,
  &kleman_interface__srv__SavePoint_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace kleman_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<kleman_interface::srv::SavePoint_Event>()
{
  return &::kleman_interface::srv::rosidl_typesupport_cpp::SavePoint_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, kleman_interface, srv, SavePoint_Event)() {
  return get_message_type_support_handle<kleman_interface::srv::SavePoint_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "kleman_interface/srv/detail/save_point__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace kleman_interface
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SavePoint_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SavePoint_type_support_ids_t;

static const _SavePoint_type_support_ids_t _SavePoint_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SavePoint_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SavePoint_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SavePoint_type_support_symbol_names_t _SavePoint_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, kleman_interface, srv, SavePoint)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, kleman_interface, srv, SavePoint)),
  }
};

typedef struct _SavePoint_type_support_data_t
{
  void * data[2];
} _SavePoint_type_support_data_t;

static _SavePoint_type_support_data_t _SavePoint_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SavePoint_service_typesupport_map = {
  2,
  "kleman_interface",
  &_SavePoint_service_typesupport_ids.typesupport_identifier[0],
  &_SavePoint_service_typesupport_symbol_names.symbol_name[0],
  &_SavePoint_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t SavePoint_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SavePoint_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<kleman_interface::srv::SavePoint_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<kleman_interface::srv::SavePoint_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<kleman_interface::srv::SavePoint_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<kleman_interface::srv::SavePoint>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<kleman_interface::srv::SavePoint>,
  &kleman_interface__srv__SavePoint__get_type_hash,
  &kleman_interface__srv__SavePoint__get_type_description,
  &kleman_interface__srv__SavePoint__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace kleman_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<kleman_interface::srv::SavePoint>()
{
  return &::kleman_interface::srv::rosidl_typesupport_cpp::SavePoint_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, kleman_interface, srv, SavePoint)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<kleman_interface::srv::SavePoint>();
}

#ifdef __cplusplus
}
#endif
