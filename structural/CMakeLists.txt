cmake_minimum_required(VERSION 3.0)
project(structural)
set (CMAKE_CXX_STANDARD 11)
# Set a default build type for single-configuration
# CMake generators if no build type is set.
IF(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
   SET(CMAKE_BUILD_TYPE RelWithDebInfo)
ENDIF(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)

# Select flags.
SET(CMAKE_CXX_FLAGS "-Wall")
SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
SET(CMAKE_CXX_FLAGS_RELEASE "-O2")
SET(CMAKE_CXX_FLAGS_DEBUG  "-O0 -g")
SET(CMAKE_C_FLAGS "-Wall")
SET(CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")
SET(CMAKE_C_FLAGS_RELEASE "-O2")
SET(CMAKE_C_FLAGS_DEBUG  "-O0 -g")

add_executable(adapter adapter.cpp)
add_executable(bridge bridge.cpp)
add_executable(composite composite.cpp)
add_executable(decorator decorator.cpp)
add_executable(facade facade.cpp)
add_executable(flyweight flyweight.cpp)
add_executable(proxy proxy.cpp)
