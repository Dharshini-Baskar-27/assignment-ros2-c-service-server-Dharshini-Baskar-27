cmake_minimum_required(VERSION 3.8)
project(ros2_service_server)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

# TODO: Add the executable target named 'add_two_ints_server'
# 1. Add executable using src/add_two_ints_server.cpp
# 2. Add dependencies (ament_target_dependencies) for rclcpp and example_interfaces
# 3. Install the target to the DESTINATION lib/${PROJECT_NAME}

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

find_package(std_srvs REQUIRED)

add_executable(service_server src/service_server.cpp)

ament_target_dependencies(service_server
  rclcpp
  std_srvs
)

install(TARGETS
  service_server
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
