# Use the official ROS Noetic as the base image
FROM osrf/ros:noetic-desktop-full

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary tools
RUN apt-get update && apt-get install -y \
    python3-pip \
    && rm -rf /var/lib/apt/lists/*

# Install ROS-related tools
RUN apt-get update && apt-get install -y \
    python3-rosdep \
    python3-catkin-tools \
    ros-noetic-turtlesim \
    ros-noetic-teleop-twist-keyboard \
    && rm -rf /var/lib/apt/lists/*

# Add ROS setup to .bashrc
RUN echo "source /opt/ros/noetic/setup.bash" >> /root/.bashrc

# Set working directory
WORKDIR /root/ros1_template_ws

# Set entrypoint
COPY entrypoint.sh /root/entrypoint.sh
ENTRYPOINT ["/bin/bash", "/root/entrypoint.sh"]
CMD ["bash"]
