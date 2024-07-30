# ベースイメージとして公式のROS Noeticを使用
FROM ros:noetic-ros-core

# 環境変数の設定
ENV DEBIAN_FRONTEND=noninteractive

# 必要なツールのインストール
RUN apt-get update && apt-get install -y \
    libxkbcommon-x11-0 \
    x11-apps \
    python3-pip \
    git \
    ros-noetic-turtlesim \
    ros-noetic-teleop-twist-keyboard \
    ros-noetic-ros-base \
    python3-rosdep \
    python3-catkin-tools \
    && rm -rf /var/lib/apt/lists/*

# rosdepの初期化
RUN rosdep init && rosdep update

# リポジトリのクローン
WORKDIR /root
RUN git clone https://github.com/Ginga-Kennis/ros1_template_ws.git

# 依存関係のインストール
WORKDIR /root/ros1_template_ws
RUN rosdep update && rosdep install --from-paths src --ignore-src -r -y

# ワークスペースのビルド
RUN /bin/bash -c "source /opt/ros/noetic/setup.bash && catkin build"

# エントリーポイントを設定
COPY entrypoint.sh /root/entrypoint.sh
ENTRYPOINT ["/root/entrypoint.sh"]
