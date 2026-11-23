cmake_minimum_required(VERSION 3.20)
  project(MatchingEngine LANGUAGES CXX)

  # C++ 标准
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)

  # 1. 公共代码编成一个静态库，主程序和测试都链接它
  add_library(engine src/loader.cpp 
                     src/matcher.cpp 
                     src/utils.cpp
                     src/submit.cpp)
  # PUBLIC：链接 engine 的目标也自动获得这个头文件路径
  target_include_directories(engine PUBLIC ${PROJECT_SOURCE_DIR}/include)

  # 2. 主程序
  add_executable(matching_engine main.cpp)
  target_link_libraries(matching_engine PRIVATE engine)

  # 3. 测试
  enable_testing()
  add_executable(test_input test/unit/test_input.cpp)
  target_link_libraries(test_input PRIVATE engine)
  add_test(NAME test_input
           COMMAND test_input
           WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/test)  # 在 test/ 下运行，../data/test.csv 才能找到
  
  add_executable(test_submit test/unit/test_submit.cpp)
  target_link_libraries(test_submit PRIVATE engine)
  target_compile_definitions(test_submit PRIVATE
        CASE_DIR_UNIT="${PROJECT_SOURCE_DIR}/test/unit/cases"   
  )
  add_test(NAME test_submit
           COMMAND test_submit
           WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/test)

  add_executable(test_engine test/e2e/test_engine.cpp)
  target_compile_definitions(test_engine PRIVATE
      CASE_DIR="${PROJECT_SOURCE_DIR}/test/e2e/cases"
  ) # 这里是为了让测试文件中的相对路径比较好找，所以在CMake里面定义了一个宏 CASE_DIR
 
  target_link_libraries(test_engine PRIVATE engine)
  add_test(NAME test_engine
           COMMAND test_engine
           WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/test/e2e)  
           # 在test/e2e/ 下运行，cases/01_simple_match/test.csv 才能找到