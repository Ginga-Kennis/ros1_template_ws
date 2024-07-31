#include "cpp_template_pkg/turtle_following_node.h"
#include "cpp_template_pkg/pid_following.h"

TurtleFollowingNode::TurtleFollowingNode() : pnh_("~") 
{
    loadParameters();
    initPubSub();
    spawnSecondTurtle();
}

void TurtleFollowingNode::loadParameters() {
    pnh_.param("turtle2_init_pose_x", turtle2_init_pose_x_, 0.0);
    pnh_.param("turtle2_init_pose_y", turtle2_init_pose_y_, 0.0);
    pnh_.param("turtle2_init_pose_theta", turtle2_init_pose_theta_, 0.0);
    pnh_.param("kp_linear", kp_linear_, 1.5);
    pnh_.param("kp_angular", kp_angular_, 6.0);
}

void TurtleFollowingNode::initPubSub() {
    turtle1_pose_sub_ = nh_.subscribe("turtle1/pose", 1, &TurtleFollowingNode::turtle1PoseCallback, this);
    turtle2_pose_sub_ = nh_.subscribe("turtle2/pose", 1, &TurtleFollowingNode::turtle2PoseCallback, this);
    turtle2_twist_pub_ = nh_.advertise<geometry_msgs::Twist>("turtle2/cmd_vel", 1);
}

void TurtleFollowingNode::spawnSecondTurtle() {
    ros::ServiceClient spawn_turtle = nh_.serviceClient<turtlesim::Spawn>("spawn");
    turtlesim::Spawn srv;
    srv.request.x = turtle2_init_pose_x_;
    srv.request.y = turtle2_init_pose_y_;
    srv.request.theta = turtle2_init_pose_theta_;
    srv.request.name = "turtle2";
    if (spawn_turtle.call(srv)) {
        ROS_INFO("Second turtle spawned successfully.");
    } else {
        ROS_ERROR("Failed to spawn second turtle.");
    }
}

TurtleFollowingNode::~TurtleFollowingNode() {}

void TurtleFollowingNode::turtle1PoseCallback(const turtlesim::Pose::ConstPtr& msg) {
    turtle1_x_ = msg->x;
    turtle1_y_ = msg->y;
    turtle1_theta_ = msg->theta;
}

void TurtleFollowingNode::turtle2PoseCallback(const turtlesim::Pose::ConstPtr& msg) {
    turtle2_x_ = msg->x;
    turtle2_y_ = msg->y;
    turtle2_theta_ = msg->theta;

    geometry_msgs::Twist twist_msg = computeCmdVel(
        turtle1_x_, turtle1_y_, turtle2_x_, turtle2_y_, turtle2_theta_,
        kp_linear_, kp_angular_
    );
    turtle2_twist_pub_.publish(twist_msg);
}

int main(int argc, char** argv) 
{
    ros::init(argc, argv, "turtle_following_node");
    TurtleFollowingNode node;
    ros::spin();
    return 0;
}
