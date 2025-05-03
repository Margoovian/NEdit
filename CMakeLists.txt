cmake_minimum_required(VERSION 3.14)

# Setup ###########################################################

project(NEdit)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# FetchContent to grab dependencies
include(FetchContent)

###################################################################

# Setup ###########################################################

add_subdirectory("Application")
add_subdirectory("NEdit")

###################################################################

# SDL #############################################################

# Disable Shared Libs
set(BUILD_SHARED_LIBS OFF)
set(SDL_SHARED OFF)
set(SDL_STATIC ON)

# Fetch SDL2
FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.32.4 # Using SDL2 instead of 3 because of imGui v1.89 compatibility
    OVERRIDE_FIND_PACKAGE
)
FetchContent_MakeAvailable(SDL2)

###################################################################

# ImGUI ###########################################################

# Fetch ImGui
FetchContent_Declare(
    imgui_external
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG v1.89  # Using imGui v1.89 for compatibility with imgui-node-editor
)
FetchContent_MakeAvailable(imgui_external)

# Fetch ImGui
FetchContent_Declare(
    imgui_node_editor_external
    GIT_REPOSITORY https://github.com/thedmd/imgui-node-editor.git
    GIT_TAG develop  # Fetch from the "develop" branch
)
FetchContent_MakeAvailable(imgui_node_editor_external)

add_library(ImGui 
    ${imgui_external_SOURCE_DIR}/imgui.cpp
	${imgui_external_SOURCE_DIR}/imgui_draw.cpp
	${imgui_external_SOURCE_DIR}/imgui_tables.cpp
	${imgui_external_SOURCE_DIR}/imgui_widgets.cpp
	${imgui_external_SOURCE_DIR}/backends/imgui_impl_sdlrenderer.cpp
	${imgui_external_SOURCE_DIR}/backends/imgui_impl_sdl.cpp
	${imgui_node_editor_external_SOURCE_DIR}/crude_json.cpp
	${imgui_node_editor_external_SOURCE_DIR}/imgui_canvas.cpp
	${imgui_node_editor_external_SOURCE_DIR}/imgui_node_editor.cpp
	${imgui_node_editor_external_SOURCE_DIR}/imgui_node_editor_api.cpp
)

target_include_directories(ImGui PUBLIC ${imgui_external_SOURCE_DIR} ${imgui_node_editor_external_SOURCE_DIR})

target_link_libraries(ImGui PRIVATE SDL2::SDL2)

###################################################################