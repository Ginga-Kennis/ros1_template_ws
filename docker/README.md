# Build Docker image
```
sudo docker build -t ros1_template_ws_img .
```

# Set up X server
```
xhost +local:
```

# Run Docker container
```
sudo docker run -it \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -v /path/to/ros1_template_ws:/root/ros1_template_ws \
    --name ros1_template_ws_container \
    ros1_template_ws_img /bin/bash
```

# Reconnect to the container
```
sudo docker start ros1_template_ws_container
sudo docker attach ros1_template_ws_container
```

# Enter the container from another terminal
```
sudo docker exec -it ros1_template_ws_container /bin/bash
```
