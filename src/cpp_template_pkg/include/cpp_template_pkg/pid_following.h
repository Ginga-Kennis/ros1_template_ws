#ifndef PID_FOLLOWING_H__
#define PID_FOLLOWING_H__

#include <geometry_msgs/Twist.h>
#include <cmath>

geometry_msgs::Twist computeCmdVel(
    double turtle1_x, double turtle1_y, double turtle2_x, double turtle2_y, double turtle2_theta,
    double kp_linear, double kp_angular
);

double normalizeAngle(double angle);

#endif
