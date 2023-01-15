#include "first_app.hpp"

#include <stdexcept>

namespace jde {

    FirstApp::FirstApp()
    {
        createPipelineLayout();
        createPipeline();
        createCommandBuffers();
    }

    FirstApp::~FirstApp()
    {
        vkDestroyPipelineLayout(jdeDevice.device(), pipelineLayout, nullptr);
    }

    void FirstApp::run()
    {
        while (!jdeWindow.shouldClose())
        {
            glfwPollEvents();
        }
    }

    void FirstApp::createPipelineLayout()
    {
        VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
        pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipelineLayoutInfo.setLayoutCount = 0;
        pipelineLayoutInfo.pSetLayouts = nullptr;
        pipelineLayoutInfo.pushConstantRangeCount = 0;
        pipelineLayoutInfo.pPushConstantRanges = nullptr;
        if (vkCreatePipelineLayout(jdeDevice.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create pipeline layout!");
        }
    }

    void FirstApp::createPipeline()
    {
        auto pipelineConfig = JdePipeline::defaultPipelineConfigInfo(jdeSwapChain.width(), jdeSwapChain.height());
        pipelineConfig.renderPass = jdeSwapChain.getRenderPass();
        pipelineConfig.pipelineLayout = pipelineLayout;
        jdePipeline = std::make_unique<JdePipeline>(
            jdeDevice, 
            "src/shaders/simple_shader.vert.spv", 
            "src/shaders/simple_shader.frag.spv", 
            pipelineConfig);
    }

    void FirstApp::createCommandBuffers()
    {

    }

    void FirstApp::drawFrame()
    {

    }

}