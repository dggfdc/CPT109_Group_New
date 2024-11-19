cmake_minimum_required(VERSION 3.29)
project(CPT109_CW C)

set(CMAKE_C_STANDARD 99)

# 包含头文件目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 定义源文件列表
set(SRC_FILES
        src/planet_manager.c
        src/researcher_manager.c
        src/user_manager.c
        src/searchplanet_manager.c
        src/statics_manager.c
)

# 创建静态库
add_library(cpt109_lib STATIC ${SRC_FILES})

# 添加主程序可执行文件
add_executable(CPT109_CW main.c)

# 链接静态库到主程序
target_link_libraries(CPT109_CW cpt109_lib)

# 定义测试源文件列表
set(TEST_SOURCES
        tests/test_planet_manager.c
        tests/test_researcher_manager.c
        tests/test_search_manager.c
        tests/test_statics_manager.c
        tests/test_user_manager.c
)

# 添加测试可执行文件并链接静态库
foreach(test_source ${TEST_SOURCES})
    # 获取测试文件名，不包含路径和扩展名
    get_filename_component(test_name ${test_source} NAME_WE)
    # 创建测试可执行文件
    add_executable(${test_name} ${test_source})
    # 链接静态库到测试可执行文件
    target_link_libraries(${test_name} cpt109_lib)
endforeach()
