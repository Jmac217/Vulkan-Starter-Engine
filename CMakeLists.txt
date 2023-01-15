cmake_minimum_required(VERSION 3.25)
project(Vulkan-Starter)

# Set C++ standard to a proper standard
set(CMAKE_CXX_STANDARD 20)

# Add the GLFW and Vulkan libraries
find_package(glfw3 REQUIRED)
find_package(Vulkan REQUIRED)
find_package(glm REQUIRED)

add_custom_target(copy_assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/src/shaders
    ${CMAKE_CURRENT_BINARY_DIR}/src/shaders
)

# Dirty way to add all source files in the ./src directory
file(GLOB_RECURSE SRC_FILES "src/*.cpp")

# Create the executable
add_executable(Vulkan-Starter ${SRC_FILES})

# Link our executable against the libraries
target_link_libraries(Vulkan-Starter glfw)
target_link_libraries(Vulkan-Starter Vulkan::Vulkan)
target_link_libraries(Vulkan-Starter glm::glm)
add_dependencies(Vulkan-Starter copy_assets)

# Build the project statically
# set(CMAKE_EXE_LINKER_FLAGS "-static")