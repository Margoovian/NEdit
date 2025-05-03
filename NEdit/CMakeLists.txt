cmake_minimum_required(VERSION 3.14)

# Setup ###########################################################

project(NEditLib)
project(NEditLibTests)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

###################################################################

# NEditLib ########################################################

file(GLOB NEDITLIB_SRC CONFIGURE_DEPENDS 
	"NEditLib/src/*.cpp"
	"NEditLib/src/Core/*.cpp"
)
file(GLOB NEDITLIB_HDR CONFIGURE_DEPENDS 
	"NEditLib/include/*.h"
	"NEditLib/src/Core/*.h"
)

add_library(NEditLib STATIC ${NEDITLIB_SRC})

target_include_directories(NEditLib PUBLIC "${CMAKE_CURRENT_LIST_DIR}/NEditLib/include")

target_compile_definitions(NEditLib PUBLIC SDL_MAIN_HANDLED)

target_link_libraries(NEditLib PUBLIC ImGui)
target_link_libraries(NEditLib PUBLIC SDL2::SDL2)

###################################################################

# NEditLibTests ###################################################

file(GLOB NEDITLIBTESTS_SRC CONFIGURE_DEPENDS "NEditLibTests/src/*.cpp")
file(GLOB NEDITLIBTESTS_HDR CONFIGURE_DEPENDS "NEditLibTests/src/*.h")

add_executable(NEditLibTests ${NEDITLIBTESTS_SRC} ${NEDITLIBTESTS_HDR})

target_include_directories(NEditLibTests PRIVATE "${CMAKE_CURRENT_LIST_DIR}/NEditLibTests/src")

target_link_libraries(NEditLibTests PRIVATE NEditLib)

###################################################################