#ifndef TURTLE_FOLLOWING_NODE_H__
#define TURTLE_FOLLOWING_NODE_H__

#include <ros/ros.h>
#include <turtlesim/Spawn.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/Twist.h>

class TurtleFollowingNode 
{
public:
    TurtleFollowingNode();
    ~TurtleFollowingNode();

private:
  	ros::NodeHandle nh_;
  	ros::NodeHandle pnh_;

  	ros::Subscriber turtle1_pose_sub_, turtle2_pose_sub_;
  	ros::Publisher turtle2_twist_pub_;

    void loadParameters();
    void initPubSub();
    void spawnSecondTurtle();
    void turtle1PoseCallback(const turtlesim::Pose::ConstPtr& msg);
    void turtle2PoseCallback(const turtlesim::Pose::ConstPtr& msg);

    double turtle2_init_pose_x_;
    double turtle2_init_pose_y_;
    double turtle2_init_pose_theta_;
    double kp_linear_;
    double kp_angular_;

    double turtle1_x_;
    double turtle1_y_;
    double turtle1_theta_;
    double turtle2_x_;
    double turtle2_y_;
    double turtle2_theta_;
};

#endif 
