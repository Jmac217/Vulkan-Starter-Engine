#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace jde {
    
    class JdeWindow {
        public:
        JdeWindow(int w, int h, std::string name);
        ~JdeWindow();
        JdeWindow(const JdeWindow &) = delete;
        JdeWindow &operator=(const JdeWindow &) = delete;
        bool shouldClose() { return glfwWindowShouldClose(window); }
        private:
        void initWindow();

        const int width;
        const int height;

        std::string windowName;
        GLFWwindow *window;
    };
}