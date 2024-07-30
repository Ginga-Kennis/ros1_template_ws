#!/bin/bash
set -e

# ROS環境を設定
source /opt/ros/noetic/setup.bash
source /root/ros1_template_ws/devel/setup.bash

# X11設定
export DISPLAY=$DISPLAY
export LIBGL_ALWAYS_INDIRECT=1

# 引数として渡されたコマンドを実行
exec "$@"
