#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <sensor_msgs/Imu.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "fake_imu_publish");

  ros::NodeHandle n;
  ros::Publisher imu_pub = n.advertise<sensor_msgs::Imu>("/imu/data", 50);
  
  ros::Rate r(100.0);

  while(n.ok()){
    ros::spinOnce();               // check for incoming messages

    sensor_msgs::Imu imu;

    imu.header.frame_id = "imu_link";
    imu.header.stamp = ros::Time::now();
    imu.angular_velocity.x = 0.01;
    imu.angular_velocity.y = 0.01;
    imu.angular_velocity.z = 0.01; // [rad/sec]
    
    imu.angular_velocity_covariance[0] = 0.02;
    imu.angular_velocity_covariance[1] = 0.0;
    imu.angular_velocity_covariance[2] = 0.0;
    imu.angular_velocity_covariance[3] = 0.0;
    imu.angular_velocity_covariance[4] = 0.02;
    imu.angular_velocity_covariance[5] = 0.0;
    imu.angular_velocity_covariance[6] = 0.0;
    imu.angular_velocity_covariance[7] = 0.0;
    imu.angular_velocity_covariance[8] = 0.02;

    imu.linear_acceleration.x = 0.01;      
    imu.linear_acceleration.y = 0.01;  
    imu.linear_acceleration.z = 9.81; 
    
    imu.linear_acceleration_covariance[0] = 0.04;
    imu.linear_acceleration_covariance[1] = 0.0;
    imu.linear_acceleration_covariance[2] = 0.0;
    imu.linear_acceleration_covariance[3] = 0.0;
    imu.linear_acceleration_covariance[4] = 0.04;
    imu.linear_acceleration_covariance[5] = 0.0;
    imu.linear_acceleration_covariance[6] = 0.0;
    imu.linear_acceleration_covariance[7] = 0.0;
    imu.linear_acceleration_covariance[8] = 0.04;
    
    imu.orientation.w = 0.0;
    imu.orientation.x = 0.0;
    imu.orientation.y = 0.0;
    imu.orientation.z = 1.0;

    imu.orientation_covariance[0] = 0.0025;
    imu.orientation_covariance[0] = 0.0;
    imu.orientation_covariance[0] = 0.0;
    imu.orientation_covariance[0] = 0.0;
    imu.orientation_covariance[0] = 0.0025;
    imu.orientation_covariance[0] = 0.0;
    imu.orientation_covariance[0] = 0.0;
    imu.orientation_covariance[0] = 0.0;
    imu.orientation_covariance[0] = 0.0025;
    
    imu_pub.publish(imu);
    /*
    geometry_msgs::TransformStamped tfs_msg;
    tf::TransformBroadcaster tfbroadcaster;

    tfs_msg.header.stamp = ros::Time::now();
    tfs_msg.header.frame_id = "imu_link";
    tfs_msg.child_frame_id  = "base_link";
    tfs_msg.transform.translation.x = 0.0;
    tfs_msg.transform.translation.y = 0.0;
    tfs_msg.transform.translation.z = 0.0;
    tfs_msg.transform.rotation.w = 0.0;
    tfs_msg.transform.rotation.x = 0.0;
    tfs_msg.transform.rotation.y = 0.0;
    tfs_msg.transform.rotation.z = 1.0;
    tfbroadcaster.sendTransform(tfs_msg);
    */
    r.sleep();
  }
}
  