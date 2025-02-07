cmake_minimum_required(VERSION 3.0.2)
project(cw1_team_20) # change your team name here!

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
  moveit_ros_planning
  moveit_ros_planning_interface
  tf2
  tf2_ros
  pcl_ros
  cw1_world_spawner
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)

## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

# Generate services in the 'srv' folder
add_service_files(
  FILES
  Task1Service.srv
)

## Generate messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES move_panda
  CATKIN_DEPENDS message_runtime cw1_world_spawner
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# Declare a C++ library
add_library(${PROJECT_NAME}_cw1_class_lib
  src/cw1_class.cpp
)

## Add cmake target dependencies of the library
add_dependencies(${PROJECT_NAME}_cw1_class_lib 
  ${${PROJECT_NAME}_EXPORTED_TARGETS} 
  ${catkin_EXPORTED_TARGETS}
)

# Declare a C++ executable
add_executable(cw1_solution_node src/cw1_node.cpp)

## Add cmake target dependencies of the executable
add_dependencies(cw1_solution_node 
  ${${PROJECT_NAME}_EXPORTED_TARGETS} 
  ${catkin_EXPORTED_TARGETS}
)

# Specify libraries to link a library or executable target against
target_link_libraries(cw1_solution_node
  ${catkin_LIBRARIES}
  ${PROJECT_NAME}_cw1_class_lib
)

#######################################################
## 🔹 Task 1: 添加 Task 1 (Pick and Place) 的 C++ 代码 ##
#######################################################

# 添加 Task 1 的 C++ 可执行文件
add_executable(task1_node src/task1_pick_and_place.cpp)

# 设置 Task 1 可执行文件的依赖关系
add_dependencies(task1_node 
  ${${PROJECT_NAME}_EXPORTED_TARGETS} 
  ${catkin_EXPORTED_TARGETS}
)

# 链接 Task 1 可执行文件所需的库
target_link_libraries(task1_node
  ${catkin_LIBRARIES}
)

#############
## Install ##
#############

## Mark executables for installation
install(TARGETS cw1_solution_node task1_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)




