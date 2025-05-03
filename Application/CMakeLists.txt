cmake_minimum_required(VERSION 3.14)

# Setup ###########################################################

project(NEdit_Demo_Application)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

###################################################################

# Application######################################################

file(GLOB N_APPLICATION_SRC CONFIGURE_DEPENDS "src/*.cpp")

add_executable(Application ${N_APPLICATION_SRC})

target_include_directories(Application PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src")

###################################################################