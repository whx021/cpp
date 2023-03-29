cmake_minimum_required(VERSION 3.24)
project(section_2_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(section_2_project
        boss.cpp
        boss.h
        employee.cpp
        employee.h
        manager.cpp
        manager.h
        worker.h
        workerManager.cpp
        workerManager.h
        职工管理系统.cpp)
