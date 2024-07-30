# Docker イメージのビルド
```
sudo docker build -t ros1_template_ws .
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
    --name ros1_template_ws_container \
    ros1_template_ws /bin/bash
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
