//
// Created by jrl on 09/08/2021.
//

#include "window.h"
#include "../util/log.h"

namespace Core
{
    Window::Window(const int w, const int h, const char* title)
    : m_initialized(InitWindow(w, h, title)) {
    }
    Window::~Window() {
        Terminate();
    }
    bool Window::InitWindow(const int width, const int height, const char* title) {

        if(glfwInit() != GLFW_TRUE)
        {
            LOG_ERROR("Failed to initialize GLFW");
            return false;
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);

        if(m_window == nullptr)
        {
            LOG_ERROR("Failed to initialize GLFWWindow");
            return false;
        }

        return true;

    }
    void Window::Terminate()
    {
        if(m_window != nullptr)
            glfwDestroyWindow(m_window);
        glfwTerminate();
    }

}