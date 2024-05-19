cmake_minimum_required(VERSION 3.16)

if (WIN32)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/${CMAKE_BUILD_ARCHITECTURE})
else ()
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/${CMAKE_BUILD_TYPE})
endif ()

set(PROJECT_NAME intepreter)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} ./src/main.cpp)
