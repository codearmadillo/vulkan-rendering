//
// Created by jrl on 09/08/2021.
//

#pragma once
#include "GLFW/glfw3.h"

namespace Core
{
    class Window {
        public:
            Window(int w, int h, const char* title);
            ~Window();
            [[nodiscard]] bool ShouldWindowClose() const { return glfwWindowShouldClose(m_window); }
            [[nodiscard]] bool IsInitialized() const { return m_initialized; }
        private:
            bool InitWindow(int width, int height, const char* title);
            void Terminate();
        private:
            GLFWwindow* m_window;
            const bool m_initialized = false;
    };
}