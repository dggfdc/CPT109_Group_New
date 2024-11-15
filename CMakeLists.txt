cmake_minimum_required(VERSION 3.29)
project(CPT109_CW C)

set(CMAKE_C_STANDARD 99)

# 包含头文件目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 主程序
add_executable(CPT109_CW main.c
        src/planet_manager.c
        src/researcher_manager.c
        src/search_manager.c
        src/statics_manager.c
        src/user_manager.c
)

# 各测试程序
add_executable(test_planet_manager tests/test_planet_manager.c src/planet_manager.c)
add_executable(test_researcher_manager tests/test_researcher_manager.c src/researcher_manager.c)
add_executable(test_search_manager tests/test_search_manager.c src/search_manager.c)
add_executable(test_statics_manager tests/test_statics_manager.c src/statics_manager.c)
add_executable(test_user_manager tests/test_user_manager.c src/user_manager.c)
