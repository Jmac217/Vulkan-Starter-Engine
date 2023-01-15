#include "first_app.hpp"

namespace jde {

    void FirstApp::run()
    {
        while (!jdeWindow.shouldClose())
        {
            glfwPollEvents();
        }
    }
}