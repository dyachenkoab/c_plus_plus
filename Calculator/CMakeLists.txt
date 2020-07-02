cmake_minimum_required(VERSION 3.8.2)

set(PROJECT "calc")
project(${PROJECT})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -Wno-deprecated-declarations -Wno-unused-variable")

find_package(Qt5 REQUIRED COMPONENTS Widgets Qml Quick)

qt5_add_resources(RESOURCES qml.qrc)

add_executable(${PROJECT} main.cpp layer.cpp layer.h library.h ${RESOURCES})

target_link_libraries(${PROJECT}
    Qt5::Widgets
    Qt5::Qml
    Qt5::Quick
    ${CMAKE_CURRENT_SOURCE_DIR}/library.a
    )   
