# Matching Engine From Scratch
这个仓库主要有以下作用：
1. 学习matching engine底层实现机制
2. 学习大型c++项目编写方式，深入理解CICD，DDD，SOLID等开发方式，提升动手能力
3. 学习项目管理，充分运用git
4. 深入理解计算机系统，如何实现高并发，低延迟并且保证系统稳定性

# 阶段一：先搭建一个简单的撮合引擎
基本要求：一个cpp文件，可以输入txt文本，实时输出撮合过程，时间价格优先 
    输入：ask.txt , bid.txt
    输出：撮合时间，撮合条数（类型等后续再细分），测试平台信息
进阶要求：我看到了一个帖子https://segmentfault.com/a/1190000047559779 这个里面有更现代化的技术栈，但是目前先不考虑

# 当前CMake的方法
```cmd
cmake -S . -B build          # 生成构建文件（只需第一次，或改了 CMakeLists 后）
cmake --build build         # 编译
ctest --test-dir build --output-on-failure   # 运行测试
```
# 项目结构
```
MatchingEngine/
├── CMakeLists.txt
├── main.cpp
├── include/
│   ├── struct.h
│   ├── loader.h
│   └── matcher.h
├── src/
│   ├── loader.cpp
│   └── matcher.cpp
├── test/
│   ├── unit/
│   │   ├── test_loader.cpp
│   │   └── test_matcher.cpp
│   ├── e2e/
│   │   ├── test_engine.cpp
│   │   └── cases/
│   │       ├── 01_simple_match/
│   │       │   ├── input.csv
│   │       │   └── expected.csv
│   │       ├── 02_partial_fill/
│   │       └── 03_price_priority/
│   └── CMakeLists.txt
├── data/
├── scripts/
│   └── run_tests.ps1









