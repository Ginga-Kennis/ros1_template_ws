#!/bin/bash

# ROS環境を設定
source /opt/ros/noetic/setup.bash

# X11設定
export DISPLAY=$DISPLAY
export LIBGL_ALWAYS_INDIRECT=1

# 引数として渡されたコマンドを実行
exec "$@"
