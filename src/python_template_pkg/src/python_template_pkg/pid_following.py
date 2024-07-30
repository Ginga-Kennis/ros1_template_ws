import math
from geometry_msgs.msg import Twist

def normalize_angle(angle):
    if angle > math.pi:
        angle -= 2 * math.pi
    elif angle < -math.pi:
        angle += 2 * math.pi
    return angle

def compute_cmd_vel(turtle1_x, turtle1_y, turtle2_x, turtle2_y, turtle2_theta, kp_linear, kp_angular):
    twist = Twist()

    # Calculate the distance and angle to turtle1
    distance = math.sqrt((turtle1_x - turtle2_x)**2 + (turtle1_y - turtle2_y)**2)
    angle_to_turtle1 = math.atan2(turtle1_y - turtle2_y, turtle1_x - turtle2_x)
    angle_error = normalize_angle(angle_to_turtle1 - turtle2_theta)

    # Proportional control for linear velocity
    twist.linear.x = kp_linear * distance

    # Proportional control for angular velocity
    twist.angular.z = kp_angular * angle_error

    return twist