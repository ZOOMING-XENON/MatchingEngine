# 这是我第一次尝试使用cmake
首先写CMakeLists.txt比较复杂需要学习
其次运行一共分两步，第一步是用cmake配置生成makefile，
```cmd
    cmake -S . -B build
```
其中-S代表的是src，也就是放置cmakelists.txt的地方。-B代表是配置生成的东西存放在哪里，默认存放在cmd同级目录（很混乱）因此我们要加一个build目录专门存放配置文件。

```cmd
PS E:\MatchingEngine> cmake -S . -B build
-- Building for: Ninja
-- The CXX compiler identification is GNU 16.2.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/msys64/ucrt64/bin/c++.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.5s)
-- Generating done (0.0s)
-- Build files have been written to: E:/MatchingEngine/build
PS E:\MatchingEngine> cmake --build build
[2/2] Linking CXX executable hello.exe
PS E:\MatchingEngine> ./build/hello.exe
hello world!
PS E:\MatchingEngine> 
```