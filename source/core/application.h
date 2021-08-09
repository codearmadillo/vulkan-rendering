//
// Created by jrl on 09/08/2021.
//

#pragma once
#include "./window.h"

namespace Core
{
    class Application {
        public:
            Application();
            ~Application();
            void Run();
        private:
            const Core::Window m_window;
    };
}
