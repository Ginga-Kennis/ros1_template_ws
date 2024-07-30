#!/usr/bin/env python3

import rospy
from turtlesim.srv import Spawn
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist

from python_template_pkg.pid_following import compute_cmd_vel

class TurtleFollowingNode:
    def __init__(self):
        self.load_parameters()
        self.init_pubsub()
        self.spawn_second_turtle()

    def load_parameters(self):
        self.turtle2_init_pose_x = rospy.get_param("~turtle2_init_pose_x")    
        self.turtle2_init_pose_y = rospy.get_param("~turtle2_init_pose_y")    
        self.turtle2_init_pose_theta = rospy.get_param("~turtle2_init_pose_theta")    
        self.kp_linear = rospy.get_param("~kp_linear")    
        self.kp_angular = rospy.get_param("~kp_angular")    

    def init_pubsub(self):
        self.turtle1_pose_sub = rospy.Subscriber('turtle1/pose', Pose, self.turtle1_pose_callback)
        self.turtle2_pose_sub = rospy.Subscriber('turtle2/pose', Pose, self.turtle2_pose_callback)
        self.turtle2_twist_pub = rospy.Publisher('turtle2/cmd_vel', Twist, queue_size=1)

    def spawn_second_turtle(self):
        spawn_turtle = rospy.ServiceProxy('spawn', Spawn)
        spawn_turtle(self.turtle2_init_pose_x, self.turtle2_init_pose_y, self.turtle2_init_pose_theta, 'turtle2')
        rospy.loginfo("Second turtle spawned successfully.")

    def turtle1_pose_callback(self, msg):
        self.turtle1_x = msg.x
        self.turtle1_y = msg.y
        self.turtle1_theta = msg.theta

    def turtle2_pose_callback(self, msg):
        self.turtle2_x = msg.x
        self.turtle2_y = msg.y
        self.turtle2_theta = msg.theta
        
        twist_msg = compute_cmd_vel(
            self.turtle1_x, self.turtle1_y, self.turtle2_x, self.turtle2_y, self.turtle2_theta,
            self.kp_linear, self.kp_angular
        )
        self.turtle2_twist_pub.publish(twist_msg)


if __name__ == "__main__":
    rospy.init_node("turtle_following_node")
    TurtleFollowingNode()
    rospy.spin()    