#pragma once

#include "jde_window.hpp"
#include "jde_pipeline.hpp"
#include "jde_device.hpp"

namespace jde {

    class FirstApp {
        public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;
        void run();
        private:
        JdeWindow jdeWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
        JdeDevice jdeDevice{jdeWindow};
        JdePipeline jdePipeline{
            jdeDevice, 
            "src/shaders/simple_shader.vert.spv", 
            "src/shaders/simple_shader.frag.spv", 
            JdePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)
        };
    };
}