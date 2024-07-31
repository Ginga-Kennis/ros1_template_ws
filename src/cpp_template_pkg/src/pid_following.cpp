#include "cpp_template_pkg/pid_following.h"

double normalizeAngle(double angle) 
{
    if (angle > M_PI) {
        angle -= 2.0 * M_PI;
    } else if (angle < -M_PI) {
        angle += 2.0 * M_PI;
    }
    return angle;
}

geometry_msgs::Twist computeCmdVel(
    double turtle1_x, double turtle1_y, double turtle2_x, double turtle2_y, double turtle2_theta,
    double kp_linear, double kp_angular
) 
{
    geometry_msgs::Twist twist;

    // Calculate the distance and angle to turtle1
    double distance = std::sqrt(std::pow(turtle1_x - turtle2_x, 2) + std::pow(turtle1_y - turtle2_y, 2));
    double angle_to_turtle1 = std::atan2(turtle1_y - turtle2_y, turtle1_x - turtle2_x);
    double angle_error = normalizeAngle(angle_to_turtle1 - turtle2_theta);

    // Proportional control for linear velocity
    twist.linear.x = kp_linear * distance;

    // Proportional control for angular velocity
    twist.angular.z = kp_angular * angle_error;

    return twist;
}
