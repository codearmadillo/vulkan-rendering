//
// Created by jrl on 09/08/2021.
//

#pragma once
#include "./window.h"

namespace Tokyo::Core
{
    class Application {
        public:
            Application();
            ~Application();
            void Run();
        private:
            const Tokyo::Core::Window m_window;
    };
}
