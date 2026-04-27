// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from kleman_interface:srv/MoveToXYZ.idl
// generated code does not contain a copyright notice
#include "kleman_interface/srv/detail/move_to_xyz__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
kleman_interface__srv__MoveToXYZ_Request__init(kleman_interface__srv__MoveToXYZ_Request * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  // velocity
  return true;
}

void
kleman_interface__srv__MoveToXYZ_Request__fini(kleman_interface__srv__MoveToXYZ_Request * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
  // velocity
}

bool
kleman_interface__srv__MoveToXYZ_Request__are_equal(const kleman_interface__srv__MoveToXYZ_Request * lhs, const kleman_interface__srv__MoveToXYZ_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // velocity
  if (lhs->velocity != rhs->velocity) {
    return false;
  }
  return true;
}

bool
kleman_interface__srv__MoveToXYZ_Request__copy(
  const kleman_interface__srv__MoveToXYZ_Request * input,
  kleman_interface__srv__MoveToXYZ_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // velocity
  output->velocity = input->velocity;
  return true;
}

kleman_interface__srv__MoveToXYZ_Request *
kleman_interface__srv__MoveToXYZ_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kleman_interface__srv__MoveToXYZ_Request * msg = (kleman_interface__srv__MoveToXYZ_Request *)allocator.allocate(sizeof(kleman_interface__srv__MoveToXYZ_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kleman_interface__srv__MoveToXYZ_Request));
  bool success = kleman_interface__srv__MoveToXYZ_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kleman_interface__srv__MoveToXYZ_Request__destroy(kleman_interface__srv__MoveToXYZ_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kleman_interface__srv__MoveToXYZ_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kleman_interface__srv__MoveToXYZ_Request__Sequence__init(kleman_interface__srv__MoveToXYZ_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kleman_interface__srv__MoveToXYZ_Request * data = NULL;

  if (size) {
    data = (kleman_interface__srv__MoveToXYZ_Request *)allocator.zero_allocate(size, sizeof(kleman_interface__srv__MoveToXYZ_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kleman_interface__srv__MoveToXYZ_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kleman_interface__srv__MoveToXYZ_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
kleman_interface__srv__MoveToXYZ_Request__Sequence__fini(kleman_interface__srv__MoveToXYZ_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      kleman_interface__srv__MoveToXYZ_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

kleman_interface__srv__MoveToXYZ_Request__Sequence *
kleman_interface__srv__MoveToXYZ_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kleman_interface__srv__MoveToXYZ_Request__Sequence * array = (kleman_interface__srv__MoveToXYZ_Request__Sequence *)allocator.allocate(sizeof(kleman_interface__srv__MoveToXYZ_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kleman_interface__srv__MoveToXYZ_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kleman_interface__srv__MoveToXYZ_Request__Sequence__destroy(kleman_interface__srv__MoveToXYZ_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kleman_interface__srv__MoveToXYZ_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kleman_interface__srv__MoveToXYZ_Request__Sequence__are_equal(const kleman_interface__srv__MoveToXYZ_Request__Sequence * lhs, const kleman_interface__srv__MoveToXYZ_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kleman_interface__srv__MoveToXYZ_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kleman_interface__srv__MoveToXYZ_Request__Sequence__copy(
  const kleman_interface__srv__MoveToXYZ_Request__Sequence * input,
  kleman_interface__srv__MoveToXYZ_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kleman_interface__srv__MoveToXYZ_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    kleman_interface__srv__MoveToXYZ_Request * data =
      (kleman_interface__srv__MoveToXYZ_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kleman_interface__srv__MoveToXYZ_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          kleman_interface__srv__MoveToXYZ_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kleman_interface__srv__MoveToXYZ_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
kleman_interface__srv__MoveToXYZ_Response__init(kleman_interface__srv__MoveToXYZ_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    kleman_interface__srv__MoveToXYZ_Response__fini(msg);
    return false;
  }
  return true;
}

void
kleman_interface__srv__MoveToXYZ_Response__fini(kleman_interface__srv__MoveToXYZ_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
kleman_interface__srv__MoveToXYZ_Response__are_equal(const kleman_interface__srv__MoveToXYZ_Response * lhs, const kleman_interface__srv__MoveToXYZ_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
kleman_interface__srv__MoveToXYZ_Response__copy(
  const kleman_interface__srv__MoveToXYZ_Response * input,
  kleman_interface__srv__MoveToXYZ_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

kleman_interface__srv__MoveToXYZ_Response *
kleman_interface__srv__MoveToXYZ_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kleman_interface__srv__MoveToXYZ_Response * msg = (kleman_interface__srv__MoveToXYZ_Response *)allocator.allocate(sizeof(kleman_interface__srv__MoveToXYZ_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kleman_interface__srv__MoveToXYZ_Response));
  bool success = kleman_interface__srv__MoveToXYZ_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kleman_interface__srv__MoveToXYZ_Response__destroy(kleman_interface__srv__MoveToXYZ_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kleman_interface__srv__MoveToXYZ_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kleman_interface__srv__MoveToXYZ_Response__Sequence__init(kleman_interface__srv__MoveToXYZ_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kleman_interface__srv__MoveToXYZ_Response * data = NULL;

  if (size) {
    data = (kleman_interface__srv__MoveToXYZ_Response *)allocator.zero_allocate(size, sizeof(kleman_interface__srv__MoveToXYZ_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kleman_interface__srv__MoveToXYZ_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kleman_interface__srv__MoveToXYZ_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
kleman_interface__srv__MoveToXYZ_Response__Sequence__fini(kleman_interface__srv__MoveToXYZ_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      kleman_interface__srv__MoveToXYZ_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

kleman_interface__srv__MoveToXYZ_Response__Sequence *
kleman_interface__srv__MoveToXYZ_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kleman_interface__srv__MoveToXYZ_Response__Sequence * array = (kleman_interface__srv__MoveToXYZ_Response__Sequence *)allocator.allocate(sizeof(kleman_interface__srv__MoveToXYZ_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kleman_interface__srv__MoveToXYZ_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kleman_interface__srv__MoveToXYZ_Response__Sequence__destroy(kleman_interface__srv__MoveToXYZ_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kleman_interface__srv__MoveToXYZ_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kleman_interface__srv__MoveToXYZ_Response__Sequence__are_equal(const kleman_interface__srv__MoveToXYZ_Response__Sequence * lhs, const kleman_interface__srv__MoveToXYZ_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kleman_interface__srv__MoveToXYZ_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kleman_interface__srv__MoveToXYZ_Response__Sequence__copy(
  const kleman_interface__srv__MoveToXYZ_Response__Sequence * input,
  kleman_interface__srv__MoveToXYZ_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kleman_interface__srv__MoveToXYZ_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    kleman_interface__srv__MoveToXYZ_Response * data =
      (kleman_interface__srv__MoveToXYZ_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kleman_interface__srv__MoveToXYZ_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          kleman_interface__srv__MoveToXYZ_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kleman_interface__srv__MoveToXYZ_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "kleman_interface/srv/detail/move_to_xyz__functions.h"

bool
kleman_interface__srv__MoveToXYZ_Event__init(kleman_interface__srv__MoveToXYZ_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    kleman_interface__srv__MoveToXYZ_Event__fini(msg);
    return false;
  }
  // request
  if (!kleman_interface__srv__MoveToXYZ_Request__Sequence__init(&msg->request, 0)) {
    kleman_interface__srv__MoveToXYZ_Event__fini(msg);
    return false;
  }
  // response
  if (!kleman_interface__srv__MoveToXYZ_Response__Sequence__init(&msg->response, 0)) {
    kleman_interface__srv__MoveToXYZ_Event__fini(msg);
    return false;
  }
  return true;
}

void
kleman_interface__srv__MoveToXYZ_Event__fini(kleman_interface__srv__MoveToXYZ_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  kleman_interface__srv__MoveToXYZ_Request__Sequence__fini(&msg->request);
  // response
  kleman_interface__srv__MoveToXYZ_Response__Sequence__fini(&msg->response);
}

bool
kleman_interface__srv__MoveToXYZ_Event__are_equal(const kleman_interface__srv__MoveToXYZ_Event * lhs, const kleman_interface__srv__MoveToXYZ_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!kleman_interface__srv__MoveToXYZ_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!kleman_interface__srv__MoveToXYZ_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
kleman_interface__srv__MoveToXYZ_Event__copy(
  const kleman_interface__srv__MoveToXYZ_Event * input,
  kleman_interface__srv__MoveToXYZ_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!kleman_interface__srv__MoveToXYZ_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!kleman_interface__srv__MoveToXYZ_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

kleman_interface__srv__MoveToXYZ_Event *
kleman_interface__srv__MoveToXYZ_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kleman_interface__srv__MoveToXYZ_Event * msg = (kleman_interface__srv__MoveToXYZ_Event *)allocator.allocate(sizeof(kleman_interface__srv__MoveToXYZ_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kleman_interface__srv__MoveToXYZ_Event));
  bool success = kleman_interface__srv__MoveToXYZ_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kleman_interface__srv__MoveToXYZ_Event__destroy(kleman_interface__srv__MoveToXYZ_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kleman_interface__srv__MoveToXYZ_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kleman_interface__srv__MoveToXYZ_Event__Sequence__init(kleman_interface__srv__MoveToXYZ_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kleman_interface__srv__MoveToXYZ_Event * data = NULL;

  if (size) {
    data = (kleman_interface__srv__MoveToXYZ_Event *)allocator.zero_allocate(size, sizeof(kleman_interface__srv__MoveToXYZ_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kleman_interface__srv__MoveToXYZ_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kleman_interface__srv__MoveToXYZ_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
kleman_interface__srv__MoveToXYZ_Event__Sequence__fini(kleman_interface__srv__MoveToXYZ_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      kleman_interface__srv__MoveToXYZ_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

kleman_interface__srv__MoveToXYZ_Event__Sequence *
kleman_interface__srv__MoveToXYZ_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kleman_interface__srv__MoveToXYZ_Event__Sequence * array = (kleman_interface__srv__MoveToXYZ_Event__Sequence *)allocator.allocate(sizeof(kleman_interface__srv__MoveToXYZ_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kleman_interface__srv__MoveToXYZ_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kleman_interface__srv__MoveToXYZ_Event__Sequence__destroy(kleman_interface__srv__MoveToXYZ_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kleman_interface__srv__MoveToXYZ_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kleman_interface__srv__MoveToXYZ_Event__Sequence__are_equal(const kleman_interface__srv__MoveToXYZ_Event__Sequence * lhs, const kleman_interface__srv__MoveToXYZ_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kleman_interface__srv__MoveToXYZ_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kleman_interface__srv__MoveToXYZ_Event__Sequence__copy(
  const kleman_interface__srv__MoveToXYZ_Event__Sequence * input,
  kleman_interface__srv__MoveToXYZ_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kleman_interface__srv__MoveToXYZ_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    kleman_interface__srv__MoveToXYZ_Event * data =
      (kleman_interface__srv__MoveToXYZ_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kleman_interface__srv__MoveToXYZ_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          kleman_interface__srv__MoveToXYZ_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kleman_interface__srv__MoveToXYZ_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
