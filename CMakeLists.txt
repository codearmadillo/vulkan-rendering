cmake_minimum_required(VERSION 3.17)
project(vulkanDemo)

find_package(Vulkan REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp source/util/log.h)

# Copy resources
##add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
##        COMMAND ${CMAKE_COMMAND} -E copy_directory
##        ${CMAKE_SOURCE_DIR}/source/shaders/ $<TARGET_FILE_DIR:${PROJECT_NAME}>/shaders/)

# Add subdirectories
add_subdirectory(glfw)
add_subdirectory(glm)

target_compile_definitions(
        ${PROJECT_NAME} PRIVATE VK_USE_PLATFORM_WIN32_KHR
)

# Include public API
target_include_directories(${PROJECT_NAME}
        PUBLIC glfw/include
        PUBLIC glm/glm
        PUBLIC Vulkan::Headers
        )

# Link directories for library lookup
target_link_directories(${PROJECT_NAME}
        PRIVATE glew
        PRIVATE glm
)

# Lookup libraries
target_link_libraries(${PROJECT_NAME} glm glfw Vulkan::Vulkan)