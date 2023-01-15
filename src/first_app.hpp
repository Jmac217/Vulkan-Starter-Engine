#pragma once

#include "jde_window.hpp"

namespace jde {

    class FirstApp {
        public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;
        void run();
        private:
        JdeWindow jdeWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
    };
}