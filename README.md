

# NEdit - C++ Node Editor
*NEdit* is a simple library for creating node based application's, it handles the mundane things so you can create more.

## Building
To build *NEdit* download the project using:

-  `git clone https://github.com/Margoovian/NEdit` 

Then run the following commands from the projects root directory:

 1. `mkdir project`
 2. `cd project`
 3. `cmake ../`

> If you are on windows and using Visual Studio, you can also right click in the root directory and open in VS.

## Including into your project
NEdit uses CMake as the build system making it trivial to include into projects. Simply add NEdit as subdirectory in your `CMakeLists.txt` folder and link `NEditLib` to your project.

 If you are using git as versioning for project, you can add *NEdit* as a git submodule, to add the submodule use the command: 
 
- `git submodule add https://github.com/Margoovian/NEdit [Location]`


After adding *NEdit* to your project you can now include it into your project by adding the following line to your to your `CMakeLists.txt`  file:
 - `add_subdirectory("[NEdit Directory]")`
 
 Then after adding the subdirectory link it to your project by adding the line:
 
 - `target_link_libraries(Your_Project PRIVATE NEditLib)`

> If you don't want to go through git and setup a project, you can use CMake's **FetchContent** feature to add the project through CMake alone.

### Example CMake - Using FetchContent

	cmake_minimum_required(VERSION 3.14)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    
    include(FetchContent)
    FetchContent_Declare(
		nedit
		GIT_REPOSITORY https://github.com/Margoovian/NEdit.git
		GIT_TAG origin/main
	)
	FetchContent_MakeAvailable(nedit)
    
    project(My_Project)
    
    file(GLOB PROJ_SRC CONFIGURE_DEPENDS "src/*.cpp" "src/*.h")
    add_executable(My_Project ${PROJ_SRC})
    
    target_link_libraries(My_Project PRIVATE NEditLib)
    

 ### Example CMake - Using Subdirectories

	cmake_minimum_required(VERSION 3.14)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    
    add_subdirectory("vendor/NEdit")

    project(My_Project)
    
    file(GLOB PROJ_SRC CONFIGURE_DEPENDS "src/*.cpp" "src/*.h")
    add_executable(My_Project ${PROJ_SRC})
    
    target_link_libraries(My_Project PRIVATE NEditLib)
    
