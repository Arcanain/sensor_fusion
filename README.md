# sensor_fusion
sensor_fusion_with_robot_localization

# realsenceのIMUを使用する方法

```bash
roslaunch sensor_fusion realsence_imu.launch 
rosrun imu_filter_madgwick imu_filter_node _use_mag:=false _publish_tf:=false _world_frame:="enu" imu/data_raw:=/camera/imu
```

# 参考文献

https://github.com/hrjp/kcctgnss/blob/main/launch/ekf.launch

https://github.com/ArghyaChatterjee/gps-waypoint-based-autonomous-navigation-in-ros/blob/master/launch/include/localization_run.launch
