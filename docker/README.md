# Build Docker image
```
docker build -t ros1_template_ws_img .
```

# Set up X server
```
xhost +local:
```

# Run Docker container
```
docker run -it \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -v /home/ginga/ros1_template_ws:/ros1_template_ws \
    --user ginga \
    --name ros1_template_ws_cont \
    ros1_template_ws_img /bin/bash
```

# Reconnect to the container
```
docker start ros1_template_ws_cont
docker attach ros1_template_ws_cont
```

# Enter the container from another terminal
```
docker exec -it ros1_template_ws_cont /bin/bash
```
