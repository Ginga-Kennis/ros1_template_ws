# Use the official ROS Noetic as the base image
FROM ros:noetic-ros-core

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary tools
RUN apt-get update && apt-get install -y \
    libxkbcommon-x11-0 \
    x11-apps \
    python3-pip \
    && rm -rf /var/lib/apt/lists/*

# Install ROS-related tools
RUN apt-get update && apt-get install -y \
    ros-noetic-turtlesim \
    ros-noetic-teleop-twist-keyboard \
    ros-noetic-ros-base \
    python3-rosdep \
    python3-catkin-tools \
    && rm -rf /var/lib/apt/lists/*

# Initialize rosdep
RUN rosdep init && rosdep update

# Add ROS setup to .bashrc
RUN echo "source /opt/ros/noetic/setup.bash" >> /root/.bashrc

# Set working directory
WORKDIR /root/ros1_template_ws

# Set entrypoint
COPY entrypoint.sh /root/entrypoint.sh
ENTRYPOINT ["/root/entrypoint.sh"]
