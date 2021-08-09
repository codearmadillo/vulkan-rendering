#include <iostream>

#include "GLFW/glfw3.h"
#include "source/core/application.h"
#include "source/util/log.h"

int main() {

    {
        Core::Application application;

        try {
            application.Run();
        } catch (std::exception& e)
        {
            std::cerr << e.what();
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;

}
