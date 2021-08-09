#pragma once

#include <iostream>
#include <exception>

namespace Tokyo::Exceptions
{
    struct WindowNotInitializedException : public std::exception
    {
        const char* what() const throw ()
        {
            return "An error occured while initializing the application window.";
        }
    };
}