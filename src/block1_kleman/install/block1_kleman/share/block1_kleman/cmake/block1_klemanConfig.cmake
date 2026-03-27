# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_block1_kleman_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED block1_kleman_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(block1_kleman_FOUND FALSE)
  elseif(NOT block1_kleman_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(block1_kleman_FOUND FALSE)
  endif()
  return()
endif()
set(_block1_kleman_CONFIG_INCLUDED TRUE)

# output package information
if(NOT block1_kleman_FIND_QUIETLY)
  message(STATUS "Found block1_kleman: 0.0.0 (${block1_kleman_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'block1_kleman' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT block1_kleman_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(block1_kleman_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${block1_kleman_DIR}/${_extra}")
endforeach()
