# ROS1 Noetic Template Packages

This repository includes template packages for ROS1 Noetic using Python and C++, providing tips for writing code in these languages.

## Package Structure
```bash
ros1_template_ws/
    ├── docker/
    │   └── Dockerfile
    └── src/
        ├── python_template_pkg/
        └── cpp_template_pkg/
```
## Setup Instructions

1. Local Installation:
    ```bash
    git clone https://github.com/Ginga-Kennis/ros1_template_ws.git
    cd ros1_template_ws
    rosdep update
    rosdep install --ignore-src --from-paths src
    source devel/setup.bash
    ```

2. Docker Installation:  
    For setting up the development environment using Docker, please refer to the instructions provided in the [`docker/README.md`](docker/README.md) file.

