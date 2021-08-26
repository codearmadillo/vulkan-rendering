#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include "source/util/log.h"
#include <iostream>

enum PROGRAM_STATUS {
    STATUS_GLFW_INIT_FAILED = 1,
    STATUS_GLFW_WINDOW_INIT_FAILED = 2
};

int main() {

    {

        if(glfwInit() != GLFW_TRUE)
        {
            LOG_ERROR("Failed to initialize GLFW");
            return STATUS_GLFW_INIT_FAILED;
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        GLFWwindow* window = glfwCreateWindow(640, 480, "Vulkan test", nullptr, nullptr);

        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

        LOG_DEBUG(extensionCount << " extensions supported\n");

        glm::mat4 matrix;
        glm::vec4 vec;
        auto test = matrix * vec;

        if(window == nullptr)
        {
            LOG_ERROR("Failed to initialize GLFW window");
            return STATUS_GLFW_WINDOW_INIT_FAILED;
        }

        while(!glfwWindowShouldClose(window))
        {
            glfwPollEvents();
        }

        glfwDestroyWindow(window);
        glfwTerminate();

    }

    return EXIT_SUCCESS;

}
