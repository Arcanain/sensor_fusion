cmake_minimum_required(VERSION 3.0.2)
project(sensor_fusion)

find_package(catkin REQUIRED
    roscpp
    rospy
    std_msgs
    geometry_msgs
    tf
    nav_msgs
    sensor_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES sensor_fusion
   CATKIN_DEPENDS geometry_msgs rospy roscpp tf std_msgs nav_msgs sensor_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(fake_odom_publish src/fake_odom_publish.cpp)
target_link_libraries(fake_odom_publish ${catkin_LIBRARIES})