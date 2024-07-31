# Docker イメージのビルド
```
sudo docker build -t ros1_template_ws_image .
```

# X サーバーの設定
```
xhost +local:root
```

# Docker コンテナの実行
```
sudo docker run -it \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -v /home/oinarisan/ros1_template_ws:/root/ros1_template_ws \
    --name ros1_template_ws_container \
    ros1_template_ws_image /bin/bash
```

# コンテナに再接続
```
sudo docker start ros1_template_ws_container
sudo docker attach ros1_template_ws_container
```

# 別ターミナルからコンテナに入る
```
sudo docker exec -it ros1_template_ws_container /bin/bash
```
