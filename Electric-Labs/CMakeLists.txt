cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(ElectricLabs)

set(PLATFORM "Windows")

find_package(OpenGL REQUIRED)

include_directories(Electric-Labs/ThirdParty/glad/include)
include_directories(Electric-Labs/ThirdParty/glfw/include)

add_subdirectory(Electric-Labs/ThirdParty/glad)
add_subdirectory(Electric-Labs/ThirdParty/glfw)

file(GLOB_RECURSE Runtime "Electric-Labs/Source/**.cpp" "Electric-Labs/Engine/**.hpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Build/bin")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(ElectricLabs ${Runtime})

if(PLATFORM STREQUAL "Linux")
target_link_libraries(ElectricLabs GL glfw glad)
endif()

if(PLATFORM STREQUAL "Windows")
target_link_libraries(ElectricLabs opengl32 glfw glad) # not tested yet
endif()