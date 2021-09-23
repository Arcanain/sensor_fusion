cmake_minimum_required(VERSION 3.0.2)
project(sensor_fusion)

find_package(catkin REQUIRED
    roscpp
    rospy
    std_msgs
    geometry_msgs
    tf
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES sensor_fusion
   CATKIN_DEPENDS geometry_msgs rospy roscpp tf std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)