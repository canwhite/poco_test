cmake_minimum_required(VERSION 3.10)

set(APP_NAME "APP")

project(${APP_NAME})

set(SOURCE_FILES start.cpp)

#vscode中除了cmake的配置也就是插件、launch和CMakeLists之外
#关于c和c++版本，以及编译器相关在这里设置就可以了

#指定c和c++的版本
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#指定c和c++的编译器
set(CMAKE_C_COMPILER "/opt/homebrew/opt/llvm/bin/clang")
set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++")

# 发现
find_package(Poco REQUIRED 
    Foundation 
    Util 
    Net
)
#目录
include_directories(${Poco_INCLUDE_DIRS})
#添加编译器标志，像是优化级别什么的
add_definitions(${Poco_DEFINITIONS})


#生成可执行文件
add_executable(${APP_NAME} ${SOURCE_FILES})

#要先生成可执行文件，才可以link
target_link_libraries(${APP_NAME} Poco::Foundation Poco::Util Poco::Net)


