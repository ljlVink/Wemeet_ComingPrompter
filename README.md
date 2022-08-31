# Wemeet_ComingPrompter

腾讯会议进入成员自动播放提示音

### 前提：

您需要在会场中点击管理成员，将成员列表**独立弹出**,可以最小化但不要关闭

当有成员进入或退出时，会自动播放一段windows自带的提示音"Windows Notify System Generic"

### 编译

可能需要点魔法
```cpp
g++ .\main.cpp  -lwinmm -o .\main.exe
```

### 开源协议

请遵守 `GPL v3`协议 [LICENSE](https://github.com/ljlVink/Wemeet_ComingPrompter/blob/main/LICENSE)