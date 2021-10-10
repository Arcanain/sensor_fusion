# sensor_fusion
sensor_fusion_with_robot_localization

# realsenceのIMUを使用する方法

```bash
roslaunch sensor_fusion realsence_imu.launch 
rosrun imu_filter_madgwick imu_filter_node _use_mag:=false _publish_tf:=false _world_frame:="enu" imu/data_raw:=/camera/imu
```
## realsenceのIMUとlaser scan mathcerの統合(odom->base_link)

```bash
roslaunch sensor_fusion odom_baselink.launch
```

1. /camera/imu(sensor_msgs/IMU)をmadgwickfilter(もしくは相補フィルタ)でフィルタリングした/imu/data(sensor_msgs/IMU)を算出
2. laser scan matherで/pose_with_covariance_stamped(geometry_msgs/PoseWithCovarianceStamped)を算出
3. robot localozationで/imu/dataと/pose_with_covariance_stampedを統合してodom->base_link間の移動距離を算出(/odometry/filtered)

- rviz

https://user-images.githubusercontent.com/52307432/136645633-3b62f71a-ed8d-4fb4-89fe-62d07d6a9085.MOV

## realsenceのIMUとlaser scan mathcerとGPSの統合(map->odom)

```bash
roslaunch sensor_fusion map_odom.launch
```

1. /camera/imu(sensor_msgs/IMU)をmadgwickfilter(もしくは相補フィルタ)でフィルタリングした/imu/data(sensor_msgs/IMU)を算出
2. laser scan matherで/pose_with_covariance_stamped(geometry_msgs/PoseWithCovarianceStamped)を算出
3. robot localozationで/imu/dataと/pose_with_covariance_stampedを統合してodom->base_link間の移動距離を算出(/odometry/filtered)
4. robot localozationで/imu/dataと/pose_with_covariance_stampedと/odometry/gpsを統合してmap->odom間の移動距離を算出(/odometry/filtered_map)
5. navsat_transform_nodeで/odometry/gpsを算出

-----------------------------------------------
**屋内でGPSを動かすと以下のエラーが生じる**

[ERROR] [1633800162.122453692]: INF: txbuf alloc

-----------------------------------------------

# ADIS16470とlaser scan mathcerの統合(odom->base_link, map->odom)

### ublox設定(CQ-F9Pを利用する場合)

```bash
sudo chmod 666 /dev/ttyACM0
cd ~/RTKLIB/app/qtapp
strsvr_qt
```

- GUIでの設定画面

![Screenshot from 2021-10-10 06-23-24](https://user-images.githubusercontent.com/52307432/136698028-e5ff950d-5d5b-446c-8806-70828a01b465.png)

- Ntrip Clientの設定

![Screenshot from 2021-10-10 06-23-15](https://user-images.githubusercontent.com/52307432/136698065-d0c428bc-f919-428a-bb5c-9c0c75434136.png)

- Serialの設定画面

![Screenshot from 2021-10-10 06-25-01](https://user-images.githubusercontent.com/52307432/136698110-d86996ec-732b-4aa4-82bf-40827493e00c.png)

- serialの設定

![Screenshot from 2021-10-10 06-24-54](https://user-images.githubusercontent.com/52307432/136698125-81cd73cc-5ca0-4269-be3d-3f22271bdf5f.png)

- RTK-GNSSの開始

上記の設定が完了したらstartでRTK-GNSSを開始する

![Screenshot from 2021-10-10 06-26-05](https://user-images.githubusercontent.com/52307432/136698152-63253ab3-ca79-4109-b6e5-2017b79865c8.png)


```bash
roslaunch ublox_gps ublox_zed-f9p.launch
```

**最初はstatus = 0だが、しばらく待っている(3分から5分程度)とstatus = 2になる**

- rviz

https://user-images.githubusercontent.com/52307432/136699756-c74391d3-19e7-4024-b71a-8479e8e17272.MOV

### ublox設定(rtk2go.comを利用する場合)

```bash
sudo chmod 666 /dev/ttyACM0
cd ~/RTKLIB/app/qtapp
strsvr_qt
```

- GUIでの設定画面

![Screenshot from 2021-10-10 06-51-45](https://user-images.githubusercontent.com/52307432/136698794-c29b1a5b-cdd3-428e-8b24-dd6caaab8951.png)

- Ntrip Serverの設定

![Screenshot from 2021-10-10 06-52-26](https://user-images.githubusercontent.com/52307432/136698837-6e56b583-5704-4175-8994-1d14cba8fa82.png)

- Serialの設定

![Screenshot from 2021-10-10 06-24-54](https://user-images.githubusercontent.com/52307432/136698125-81cd73cc-5ca0-4269-be3d-3f22271bdf5f.png)

- RTK-GNSSの開始

上記の設定が完了したらstartでRTK-GNSSを開始する

![Screenshot from 2021-10-10 06-51-13](https://user-images.githubusercontent.com/52307432/136698754-03651c6c-4498-43f5-b613-d4d5e53f32df.png)

```bash
roslaunch ublox_gps ublox_zed-f9p.launch
```

**最初はstatus = 0だが、しばらく待っている(3分から5分程度)とstatus = 2になる**

## 動作確認

```bash
roslaunch sensor_fusion sensor_fusion.launch
```

# 参考文献

https://github.com/hrjp/kcctgnss/blob/main/launch/ekf.launch

https://github.com/ArghyaChatterjee/gps-waypoint-based-autonomous-navigation-in-ros/blob/master/launch/include/localization_run.launch
