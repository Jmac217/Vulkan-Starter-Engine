#pragma once

#include "jde_window.hpp"
#include "jde_pipeline.hpp"

namespace jde {

    class FirstApp {
        public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;
        void run();
        private:
        JdeWindow jdeWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
        JdePipeline jdePipeline{"src/shaders/simple_shader.vert.spv", "src/shaders/simple_shader.frag.spv"};
    };
}