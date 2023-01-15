#pragma once

#include "jde_device.hpp"

#include <string>
#include <vector>

namespace jde {

    struct PipelineConfigInfo {};

    class JdePipeline {
        public:
        JdePipeline(
            JdeDevice &device, 
            const std::string& vertFilepath, 
            const std::string& fragFilepath, 
            const PipelineConfigInfo& configInfo);
        ~JdePipeline() {}
        JdePipeline(const JdePipeline&) = delete;
        void operator=(const JdePipeline&) = delete;

        static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

        private:
        
        static std::vector<char> readFile(const std::string& filepath);
        void createGraphicsPipeline(
            const std::string& vertFilepath, 
            const std::string& fragFilepath, 
            const PipelineConfigInfo& configInfo);

        void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

        // implicitly will outlive any class that depends on it. "aggregation"
        JdeDevice& jdeDevice;
        VkPipeline grahpicsPipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;
    };
}