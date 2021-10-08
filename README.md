# sensor_fusion
sensor_fusion_with_robot_localization

# realsenceのIMUを使用する方法

```bash
roslaunch sensor_fusion realsence_imu.launch 
rosrun imu_filter_madgwick imu_filter_node _use_mag:=false _publish_tf:=false _world_frame:="enu" imu/data_raw:=/camera/imu
```
## realsenceのIMUとlaser scan mathcerの統合

```bash
roslaunch sensor_fusion odom_baselink.launch
```

1. /camera/imu(sensor_msgs/IMU)をmadgwickfilter(もしくは相補フィルタ)でフィルタリングした/imu/data(sensor_msgs/IMU)を算出
2. laser scan matherで/pose_with_covariance_stamped(geometry_msgs/PoseWithCovarianceStamped)を算出
3. robot localozationで/imu/dataと/pose_with_covariance_stampedを統合してodom->base_link間の移動距離を算出(/odometry/filtered)

# 参考文献

https://github.com/hrjp/kcctgnss/blob/main/launch/ekf.launch

https://github.com/ArghyaChatterjee/gps-waypoint-based-autonomous-navigation-in-ros/blob/master/launch/include/localization_run.launch
