cmake_minimum_required(VERSION 2.8.3)
project(stag)

IF (WIN32)
	message(STATUS "Compiling on Windows")
	add_definitions(-DOS_WIN=ON)
ENDIF()

# Build setup
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_STANDARD 11)

# Packages
find_package(Eigen3 REQUIRED)
find_package(OpenCV 3.4.7 REQUIRED)
IF (${OpenCV_FOUND})
   MESSAGE(STATUS "Found OpenCV ${OpenCV_VERSION}")
ELSE (${OpenCV_FOUND})
   MESSAGE(STATUS "Could not locate OpenCV.")
ENDIF (${OpenCV_FOUND})

# Libraries
set(INCLUDE_DIRS ${EIGEN3_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})
set(LIBS ${OpenCV_LIBS})

# Header includes
include_directories(include INCLUDE_DIRS)

# Source directories
file(GLOB STAG_SRC src/*.cpp)
file(GLOB ED_SRC src/ED/*.cpp)

# Executable
add_executable(stag_test src/main.cpp ${STAG_SRC} ${ED_SRC})
target_link_libraries(stag_test ${LIBS})
