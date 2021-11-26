cmake_minimum_required(VERSION 3.20)
project(TP4)

# find python libraries
find_package(Python3 COMPONENTS Interpreter Development NumPy REQUIRED)
find_package(PythonLibs 3.0 REQUIRED)
include_directories(${PYTHON3_INCLUDE_DIRS} ${NumPy_INCLUDE_DIRS})

# populate matplotlib repository
include(FetchContent)
FetchContent_Declare(
        matplotlib
        GIT_REPOSITORY https://github.com/lava/matplotlib-cpp.git
        GIT_TAG        f23347fca25219d1c42cbb91608b5556814bf572
)
FetchContent_GetProperties(matplotlib)
if(NOT matplotlib_POPULATED)
    FetchContent_Populate(matplotlib)
endif()
include_directories(SYSTEM ${matplotlib_SOURCE_DIR})


set(CMAKE_CXX_STANDARD 17)

add_executable(TP4 main.cpp lib/Helper.cpp src/Neurone.cpp)
# link python and numpy
target_link_libraries(TP4
        PRIVATE
        ${PYTHON_LIBRARIES}
        Python3::NumPy
        )

