cmake_minimum_required(VERSION 3.25)
project(Vulkan-Starter)

# Set C++ standard to a proper standard
set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libstdc++")

# Add the GLFW and Vulkan libraries
find_package(glfw3 REQUIRED)
find_package(Vulkan REQUIRED)
find_package(glm REQUIRED)

# Dirty way to add all source files in the ./src directory
file(GLOB_RECURSE SRC_FILES "src/*.cpp")

# Create the executable
add_executable(Vulkan-Starter ${SRC_FILES})

# Link our executable against the libraries
target_link_libraries(Vulkan-Starter glfw)
target_link_libraries(Vulkan-Starter Vulkan::Vulkan)
target_link_libraries(Vulkan-Starter glm::glm)


# Build the project statically
# set(CMAKE_EXE_LINKER_FLAGS "-static")
