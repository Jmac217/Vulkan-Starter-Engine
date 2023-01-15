#pragma once

#include "jde_window.hpp"
#include "jde_pipeline.hpp"
#include "jde_device.hpp"
#include "jde_swap_chain.hpp"

#include <memory>
#include <vector>

namespace jde {

    class FirstApp {
        public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;
        
        FirstApp();
        ~FirstApp();

        FirstApp(const FirstApp &) = delete;
        FirstApp &operator=(const FirstApp &) = delete;
        
        void run();

        private:
        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffers();
        void drawFrame();

        JdeWindow jdeWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
        JdeDevice jdeDevice{jdeWindow};
        JdeSwapChain jdeSwapChain{jdeDevice, jdeWindow.getExtent()};
        std::unique_ptr<JdePipeline> jdePipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;

    };
}