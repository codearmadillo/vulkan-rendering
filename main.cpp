#include <iostream>

#define LOG_ERROR(x) std::cerr << "Error: " << x << std::endl
#define LOG_DEBUG(x) std::cout << "Debug: " << x << std::endl

#include "GLFW/glfw3.h"

int main() {

    if(glfwInit() != GLFW_TRUE)
    {
        LOG_ERROR("Failed to initialize GLFW");
        return EXIT_FAILURE;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan", nullptr, nullptr);
    if(window == nullptr)
    {
        LOG_ERROR("Failed to initialize GLFWWindow");
        return EXIT_FAILURE;
    }

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}
