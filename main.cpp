#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include "source/util/log.h"
#include <iostream>
#include <vector>

enum PROGRAM_STATUS {
    STATUS_GLFW_INIT_FAILED = 1,
    STATUS_GLFW_WINDOW_INIT_FAILED = 2
};

const uint32_t W_WIDTH = 800;
const uint32_t W_HEIGHT = 600;

class Application
{
public:
    void run()
    {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }
private:
    void initWindow()
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        m_window = glfwCreateWindow(W_WIDTH, W_HEIGHT, "Vulkan application", nullptr, nullptr);
    }
    void initVulkan()
    {
        /** Initialize Vulkan library by creating instance - connection between application and Vulkan library */
        createInstance();

    }
    void mainLoop()
    {
        while(!glfwWindowShouldClose(m_window))
        {
            glfwPollEvents();
        }
    }
    void cleanup()
    {
        vkDestroyInstance(m_instance, nullptr);
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }
    void createInstance()
    {
        /**
         * The information passed to application info is passed onto driver, and can have positive effect on performance
         */
        VkApplicationInfo appInfo {};
        /** Man structures require explicit definition of self and of type */
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Vulkan Application";
        appInfo.applicationVersion = VK_MAKE_VERSION(1,0,0);
        appInfo.pEngineName = "No Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1,0,0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo createInfo {};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        /**
         * Specify desired extensions - Vulkan is platform-agnostic, we need extensions to interface with the window system
         */
        uint32_t extensionCount = 0;
        std::vector<VkExtensionProperties> extensions(extensionCount);
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

        std::cout << "available extensions:" << std::endl;

        for (const auto& extension : extensions)
        {
            std::cout << "\t" << extension.extensionName << std::endl;
        }

        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
        createInfo.enabledExtensionCount = glfwExtensionCount;
        createInfo.ppEnabledExtensionNames = glfwExtensions;

        createInfo.enabledLayerCount = 0;

        if (vkCreateInstance(&createInfo, nullptr, &m_instance) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create Vulkan instance!");
        }

    }
private:
    GLFWwindow* m_window;
    VkInstance m_instance;
};

int main() {

    {

        Application application {};

        try
        {
            application.run();
        }
        catch (const std::exception& exp)
        {
            LOG_ERROR(exp.what());
            return EXIT_FAILURE;
        }

    }

    return EXIT_SUCCESS;

}
