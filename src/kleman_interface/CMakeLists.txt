cmake_minimum_required(VERSION 3.8)
project(kleman_interface)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 1. HLAVNÉ ZÁVISLOSTI (Vyhľadávanie balíkov)
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# 2. GENEROVANIE TVOJICH SLUŽIEB (Musí to byť vonku z "if" podmienky!)
rosidl_generate_interfaces(${PROJECT_NAME}
        "srv/SavePoint.srv"
        "srv/SolveIK.srv"
        "srv/MoveToXYZ.srv"
)

# 3. TESTOVACIA ČASŤ (Pôvodná, ponechaná pre tvoj balík)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()