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


# Testing
set(TEST_PROJECT_NAME intepreter_test)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${TEST_PROJECT_NAME}
  ./src/tests/Mock_TerminalExpression_Minus.h
  ./src/tests/Mock_TerminalExpression_Number.h
  ./src/tests/Mock_TerminalExpression_Plus.h
  ./src/tests/Interpreter.cc
  ${GMOCK_TESTS_SOURCE_FILES}
)
target_link_libraries(${TEST_PROJECT_NAME} GTest::gtest_main gmock_main)

include(GoogleTest)
gtest_discover_tests(${TEST_PROJECT_NAME})
