cmake_minimum_required(VERSION 2.8.12)

project(Test_demo)

if(NOT MSVC)
    add_definitions("-std=c++11 -Wall -Wextra -Werror")
else()
    add_definitions("-std=c++11 -WX -W2")
endif()

find_package(MAVSDK REQUIRED)

add_executable(Test_demo
    Test_demo.cpp
)

target_link_libraries(Test_demo
    MAVSDK::mavsdk_telemetry
    MAVSDK::mavsdk
    MAVSDK::mavsdk_action
)
