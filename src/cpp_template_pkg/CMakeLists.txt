cmake_minimum_required(VERSION 3.0.2)
project(cpp_template_pkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  turtlesim
  geometry_msgs
  teleop_twist_keyboard
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES turtle_following
  CATKIN_DEPENDS roscpp turtlesim geometry_msgs teleop_twist_keyboard
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(pid_following src/pid_following.cpp)

add_executable(turtle_following_node src/turtle_following_node.cpp)
add_dependencies(turtle_following_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(turtle_following_node
  pid_following
  ${catkin_LIBRARIES}
)

