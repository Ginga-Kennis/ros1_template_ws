# Use the official ROS Noetic as the base image
FROM osrf/ros:noetic-desktop-full

# Set environment variables
# DEBIAN_FRONTEND=noninteractive is set to prevent interactive prompts during the build process,
# which is necessary since Docker builds are non-interactive.
ENV DEBIAN_FRONTEND=noninteractive

# Create a non-root user
# Note: Adjust these ARG values to match the user environment on your host system. 
ARG USERNAME=oinarisan
ARG USER_UID=1000
ARG USER_GID=1000

# Create a new group and user based on the provided arguments.
# The user is also given a home directory, and a .config directory is created within it.
RUN groupadd --gid $USER_GID $USERNAME \
  && useradd -s /bin/bash --uid $USER_UID --gid $USER_GID -m $USERNAME \
  && mkdir /home/$USERNAME/.config && chown $USER_UID:$USER_GID /home/$USERNAME/.config

# Set up sudo
RUN apt-get update \
  && apt-get install -y sudo \
  && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME\
  && chmod 0440 /etc/sudoers.d/$USERNAME \
  && rm -rf /var/lib/apt/lists/*

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

# Set entrypoint
# The base image already has an entrypoint, so it is not necessary to define another one here.
# If you need to override or add additional initialization steps, you can uncomment the lines below.
# COPY entrypoint.sh /entrypoint.sh
# ENTRYPOINT ["/bin/bash", "/entrypoint.sh"]
# CMD ["bash"]
