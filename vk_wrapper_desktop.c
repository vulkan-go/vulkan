// +build windows darwin

#include <GLFW/glfw3.h>
#include <stdio.h>
#include "vk_wrapper.h"

const char** vkGetRequiredInstanceExtensions(uint32_t *count) {
    return glfwGetRequiredInstanceExtensions(count);
}

VkResult vkCreateGLFWSurface(VkInstance instance, void *win, const VkAllocationCallbacks *allocator, VkSurfaceKHR *surface) {
   return glfwCreateWindowSurface(instance, (GLFWwindow *)(win), allocator, surface);
}

int vkInit(void) {
    if (!glfwVulkanSupported()) {
         return -1;
    }
    vgo_vkCreateInstance = (PFN_vkCreateInstance)(glfwGetInstanceProcAddress(NULL, "vkCreateInstance"));
    vgo_vkEnumerateInstanceExtensionProperties = (PFN_vkEnumerateInstanceExtensionProperties)(glfwGetInstanceProcAddress(NULL, "vkEnumerateInstanceExtensionProperties"));
    vgo_vkEnumerateInstanceLayerProperties = (PFN_vkEnumerateInstanceLayerProperties)(glfwGetInstanceProcAddress(NULL, "vkEnumerateInstanceLayerProperties"));
    
    #ifndef VK_USE_PLATFORM_MACOS_MVK
        // can safely init instance PFNs with no instance
        vkInitInstance(NULL);
    #endif

    return 0;
}

int vkInitInstance(VkInstance instance) {
    vgo_vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr)(glfwGetInstanceProcAddress(instance, "vkGetInstanceProcAddr"));
    vgo_vkDestroyInstance = (PFN_vkDestroyInstance)(glfwGetInstanceProcAddress(instance, "vkDestroyInstance"));
    vgo_vkEnumeratePhysicalDevices = (PFN_vkEnumeratePhysicalDevices)(glfwGetInstanceProcAddress(instance, "vkEnumeratePhysicalDevices"));
    vgo_vkGetPhysicalDeviceFeatures = (PFN_vkGetPhysicalDeviceFeatures)(glfwGetInstanceProcAddress(instance, "vkGetPhysicalDeviceFeatures"));
    vgo_vkGetPhysicalDeviceFormatProperties = (PFN_vkGetPhysicalDeviceFormatProperties)(glfwGetInstanceProcAddress(instance, "vkGetPhysicalDeviceFormatProperties"));
    vgo_vkGetPhysicalDeviceImageFormatProperties = (PFN_vkGetPhysicalDeviceImageFormatProperties)(glfwGetInstanceProcAddress(instance, "vkGetPhysicalDeviceImageFormatProperties"));
    vgo_vkGetPhysicalDeviceProperties = (PFN_vkGetPhysicalDeviceProperties)(glfwGetInstanceProcAddress(instance, "vkGetPhysicalDeviceProperties"));
    vgo_vkGetPhysicalDeviceQueueFamilyProperties = (PFN_vkGetPhysicalDeviceQueueFamilyProperties)(glfwGetInstanceProcAddress(instance, "vkGetPhysicalDeviceQueueFamilyProperties"));
    vgo_vkGetPhysicalDeviceMemoryProperties = (PFN_vkGetPhysicalDeviceMemoryProperties)(glfwGetInstanceProcAddress(instance, "vkGetPhysicalDeviceMemoryProperties"));
    vgo_vkGetDeviceProcAddr = (PFN_vkGetDeviceProcAddr)(glfwGetInstanceProcAddress(instance, "vkGetDeviceProcAddr"));
    vgo_vkCreateDevice = (PFN_vkCreateDevice)(glfwGetInstanceProcAddress(instance, "vkCreateDevice"));
    vgo_vkDestroyDevice = (PFN_vkDestroyDevice)(glfwGetInstanceProcAddress(instance, "vkDestroyDevice"));
    vgo_vkEnumerateDeviceExtensionProperties = (PFN_vkEnumerateDeviceExtensionProperties)(glfwGetInstanceProcAddress(instance, "vkEnumerateDeviceExtensionProperties"));
    vgo_vkEnumerateDeviceLayerProperties = (PFN_vkEnumerateDeviceLayerProperties)(glfwGetInstanceProcAddress(instance, "vkEnumerateDeviceLayerProperties"));
    vgo_vkGetDeviceQueue = (PFN_vkGetDeviceQueue)(glfwGetInstanceProcAddress(instance, "vkGetDeviceQueue"));
    vgo_vkQueueSubmit = (PFN_vkQueueSubmit)(glfwGetInstanceProcAddress(instance, "vkQueueSubmit"));
    vgo_vkQueueWaitIdle = (PFN_vkQueueWaitIdle)(glfwGetInstanceProcAddress(instance, "vkQueueWaitIdle"));
    vgo_vkDeviceWaitIdle = (PFN_vkDeviceWaitIdle)(glfwGetInstanceProcAddress(instance, "vkDeviceWaitIdle"));
    vgo_vkAllocateMemory = (PFN_vkAllocateMemory)(glfwGetInstanceProcAddress(instance, "vkAllocateMemory"));
    vgo_vkFreeMemory = (PFN_vkFreeMemory)(glfwGetInstanceProcAddress(instance, "vkFreeMemory"));
    vgo_vkMapMemory = (PFN_vkMapMemory)(glfwGetInstanceProcAddress(instance, "vkMapMemory"));
    vgo_vkUnmapMemory = (PFN_vkUnmapMemory)(glfwGetInstanceProcAddress(instance, "vkUnmapMemory"));
    vgo_vkFlushMappedMemoryRanges = (PFN_vkFlushMappedMemoryRanges)(glfwGetInstanceProcAddress(instance, "vkFlushMappedMemoryRanges"));
    vgo_vkInvalidateMappedMemoryRanges = (PFN_vkInvalidateMappedMemoryRanges)(glfwGetInstanceProcAddress(instance, "vkInvalidateMappedMemoryRanges"));
    vgo_vkGetDeviceMemoryCommitment = (PFN_vkGetDeviceMemoryCommitment)(glfwGetInstanceProcAddress(instance, "vkGetDeviceMemoryCommitment"));
    vgo_vkBindBufferMemory = (PFN_vkBindBufferMemory)(glfwGetInstanceProcAddress(instance, "vkBindBufferMemory"));
    vgo_vkBindImageMemory = (PFN_vkBindImageMemory)(glfwGetInstanceProcAddress(instance, "vkBindImageMemory"));
    vgo_vkGetBufferMemoryRequirements = (PFN_vkGetBufferMemoryRequirements)(glfwGetInstanceProcAddress(instance, "vkGetBufferMemoryRequirements"));
    vgo_vkGetImageMemoryRequirements = (PFN_vkGetImageMemoryRequirements)(glfwGetInstanceProcAddress(instance, "vkGetImageMemoryRequirements"));
    vgo_vkGetImageSparseMemoryRequirements = (PFN_vkGetImageSparseMemoryRequirements)(glfwGetInstanceProcAddress(instance, "vkGetImageSparseMemoryRequirements"));
    vgo_vkGetPhysicalDeviceSparseImageFormatProperties = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties)(glfwGetInstanceProcAddress(instance, "vkGetPhysicalDeviceSparseImageFormatProperties"));
    vgo_vkQueueBindSparse = (PFN_vkQueueBindSparse)(glfwGetInstanceProcAddress(instance, "vkQueueBindSparse"));
    vgo_vkCreateFence = (PFN_vkCreateFence)(glfwGetInstanceProcAddress(instance, "vkCreateFence"));
    vgo_vkDestroyFence = (PFN_vkDestroyFence)(glfwGetInstanceProcAddress(instance, "vkDestroyFence"));
    vgo_vkResetFences = (PFN_vkResetFences)(glfwGetInstanceProcAddress(instance, "vkResetFences"));
    vgo_vkGetFenceStatus = (PFN_vkGetFenceStatus)(glfwGetInstanceProcAddress(instance, "vkGetFenceStatus"));
    vgo_vkWaitForFences = (PFN_vkWaitForFences)(glfwGetInstanceProcAddress(instance, "vkWaitForFences"));
    vgo_vkCreateSemaphore = (PFN_vkCreateSemaphore)(glfwGetInstanceProcAddress(instance, "vkCreateSemaphore"));
    vgo_vkDestroySemaphore = (PFN_vkDestroySemaphore)(glfwGetInstanceProcAddress(instance, "vkDestroySemaphore"));
    vgo_vkCreateEvent = (PFN_vkCreateEvent)(glfwGetInstanceProcAddress(instance, "vkCreateEvent"));
    vgo_vkDestroyEvent = (PFN_vkDestroyEvent)(glfwGetInstanceProcAddress(instance, "vkDestroyEvent"));
    vgo_vkGetEventStatus = (PFN_vkGetEventStatus)(glfwGetInstanceProcAddress(instance, "vkGetEventStatus"));
    vgo_vkSetEvent = (PFN_vkSetEvent)(glfwGetInstanceProcAddress(instance, "vkSetEvent"));
    vgo_vkResetEvent = (PFN_vkResetEvent)(glfwGetInstanceProcAddress(instance, "vkResetEvent"));
    vgo_vkCreateQueryPool = (PFN_vkCreateQueryPool)(glfwGetInstanceProcAddress(instance, "vkCreateQueryPool"));
    vgo_vkDestroyQueryPool = (PFN_vkDestroyQueryPool)(glfwGetInstanceProcAddress(instance, "vkDestroyQueryPool"));
    vgo_vkGetQueryPoolResults = (PFN_vkGetQueryPoolResults)(glfwGetInstanceProcAddress(instance, "vkGetQueryPoolResults"));
    vgo_vkCreateBuffer = (PFN_vkCreateBuffer)(glfwGetInstanceProcAddress(instance, "vkCreateBuffer"));
    vgo_vkDestroyBuffer = (PFN_vkDestroyBuffer)(glfwGetInstanceProcAddress(instance, "vkDestroyBuffer"));
    vgo_vkCreateBufferView = (PFN_vkCreateBufferView)(glfwGetInstanceProcAddress(instance, "vkCreateBufferView"));
    vgo_vkDestroyBufferView = (PFN_vkDestroyBufferView)(glfwGetInstanceProcAddress(instance, "vkDestroyBufferView"));
    vgo_vkCreateImage = (PFN_vkCreateImage)(glfwGetInstanceProcAddress(instance, "vkCreateImage"));
    vgo_vkDestroyImage = (PFN_vkDestroyImage)(glfwGetInstanceProcAddress(instance, "vkDestroyImage"));
    vgo_vkGetImageSubresourceLayout = (PFN_vkGetImageSubresourceLayout)(glfwGetInstanceProcAddress(instance, "vkGetImageSubresourceLayout"));
    vgo_vkCreateImageView = (PFN_vkCreateImageView)(glfwGetInstanceProcAddress(instance, "vkCreateImageView"));
    vgo_vkDestroyImageView = (PFN_vkDestroyImageView)(glfwGetInstanceProcAddress(instance, "vkDestroyImageView"));
    vgo_vkCreateShaderModule = (PFN_vkCreateShaderModule)(glfwGetInstanceProcAddress(instance, "vkCreateShaderModule"));
    vgo_vkDestroyShaderModule = (PFN_vkDestroyShaderModule)(glfwGetInstanceProcAddress(instance, "vkDestroyShaderModule"));
    vgo_vkCreatePipelineCache = (PFN_vkCreatePipelineCache)(glfwGetInstanceProcAddress(instance, "vkCreatePipelineCache"));
    vgo_vkDestroyPipelineCache = (PFN_vkDestroyPipelineCache)(glfwGetInstanceProcAddress(instance, "vkDestroyPipelineCache"));
    vgo_vkGetPipelineCacheData = (PFN_vkGetPipelineCacheData)(glfwGetInstanceProcAddress(instance, "vkGetPipelineCacheData"));
    vgo_vkMergePipelineCaches = (PFN_vkMergePipelineCaches)(glfwGetInstanceProcAddress(instance, "vkMergePipelineCaches"));
    vgo_vkCreateGraphicsPipelines = (PFN_vkCreateGraphicsPipelines)(glfwGetInstanceProcAddress(instance, "vkCreateGraphicsPipelines"));
    vgo_vkCreateComputePipelines = (PFN_vkCreateComputePipelines)(glfwGetInstanceProcAddress(instance, "vkCreateComputePipelines"));
    vgo_vkDestroyPipeline = (PFN_vkDestroyPipeline)(glfwGetInstanceProcAddress(instance, "vkDestroyPipeline"));
    vgo_vkCreatePipelineLayout = (PFN_vkCreatePipelineLayout)(glfwGetInstanceProcAddress(instance, "vkCreatePipelineLayout"));
    vgo_vkDestroyPipelineLayout = (PFN_vkDestroyPipelineLayout)(glfwGetInstanceProcAddress(instance, "vkDestroyPipelineLayout"));
    vgo_vkCreateSampler = (PFN_vkCreateSampler)(glfwGetInstanceProcAddress(instance, "vkCreateSampler"));
    vgo_vkDestroySampler = (PFN_vkDestroySampler)(glfwGetInstanceProcAddress(instance, "vkDestroySampler"));
    vgo_vkCreateDescriptorSetLayout = (PFN_vkCreateDescriptorSetLayout)(glfwGetInstanceProcAddress(instance, "vkCreateDescriptorSetLayout"));
    vgo_vkDestroyDescriptorSetLayout = (PFN_vkDestroyDescriptorSetLayout)(glfwGetInstanceProcAddress(instance, "vkDestroyDescriptorSetLayout"));
    vgo_vkCreateDescriptorPool = (PFN_vkCreateDescriptorPool)(glfwGetInstanceProcAddress(instance, "vkCreateDescriptorPool"));
    vgo_vkDestroyDescriptorPool = (PFN_vkDestroyDescriptorPool)(glfwGetInstanceProcAddress(instance, "vkDestroyDescriptorPool"));
    vgo_vkResetDescriptorPool = (PFN_vkResetDescriptorPool)(glfwGetInstanceProcAddress(instance, "vkResetDescriptorPool"));
    vgo_vkAllocateDescriptorSets = (PFN_vkAllocateDescriptorSets)(glfwGetInstanceProcAddress(instance, "vkAllocateDescriptorSets"));
    vgo_vkFreeDescriptorSets = (PFN_vkFreeDescriptorSets)(glfwGetInstanceProcAddress(instance, "vkFreeDescriptorSets"));
    vgo_vkUpdateDescriptorSets = (PFN_vkUpdateDescriptorSets)(glfwGetInstanceProcAddress(instance, "vkUpdateDescriptorSets"));
    vgo_vkCreateFramebuffer = (PFN_vkCreateFramebuffer)(glfwGetInstanceProcAddress(instance, "vkCreateFramebuffer"));
    vgo_vkDestroyFramebuffer = (PFN_vkDestroyFramebuffer)(glfwGetInstanceProcAddress(instance, "vkDestroyFramebuffer"));
    vgo_vkCreateRenderPass = (PFN_vkCreateRenderPass)(glfwGetInstanceProcAddress(instance, "vkCreateRenderPass"));
    vgo_vkDestroyRenderPass = (PFN_vkDestroyRenderPass)(glfwGetInstanceProcAddress(instance, "vkDestroyRenderPass"));
    vgo_vkGetRenderAreaGranularity = (PFN_vkGetRenderAreaGranularity)(glfwGetInstanceProcAddress(instance, "vkGetRenderAreaGranularity"));
    vgo_vkCreateCommandPool = (PFN_vkCreateCommandPool)(glfwGetInstanceProcAddress(instance, "vkCreateCommandPool"));
    vgo_vkDestroyCommandPool = (PFN_vkDestroyCommandPool)(glfwGetInstanceProcAddress(instance, "vkDestroyCommandPool"));
    vgo_vkResetCommandPool = (PFN_vkResetCommandPool)(glfwGetInstanceProcAddress(instance, "vkResetCommandPool"));
    vgo_vkAllocateCommandBuffers = (PFN_vkAllocateCommandBuffers)(glfwGetInstanceProcAddress(instance, "vkAllocateCommandBuffers"));
    vgo_vkFreeCommandBuffers = (PFN_vkFreeCommandBuffers)(glfwGetInstanceProcAddress(instance, "vkFreeCommandBuffers"));
    vgo_vkBeginCommandBuffer = (PFN_vkBeginCommandBuffer)(glfwGetInstanceProcAddress(instance, "vkBeginCommandBuffer"));
    vgo_vkEndCommandBuffer = (PFN_vkEndCommandBuffer)(glfwGetInstanceProcAddress(instance, "vkEndCommandBuffer"));
    vgo_vkResetCommandBuffer = (PFN_vkResetCommandBuffer)(glfwGetInstanceProcAddress(instance, "vkResetCommandBuffer"));
    vgo_vkCmdBindPipeline = (PFN_vkCmdBindPipeline)(glfwGetInstanceProcAddress(instance, "vkCmdBindPipeline"));
    vgo_vkCmdSetViewport = (PFN_vkCmdSetViewport)(glfwGetInstanceProcAddress(instance, "vkCmdSetViewport"));
    vgo_vkCmdSetScissor = (PFN_vkCmdSetScissor)(glfwGetInstanceProcAddress(instance, "vkCmdSetScissor"));
    vgo_vkCmdSetLineWidth = (PFN_vkCmdSetLineWidth)(glfwGetInstanceProcAddress(instance, "vkCmdSetLineWidth"));
    vgo_vkCmdSetDepthBias = (PFN_vkCmdSetDepthBias)(glfwGetInstanceProcAddress(instance, "vkCmdSetDepthBias"));
    vgo_vkCmdSetBlendConstants = (PFN_vkCmdSetBlendConstants)(glfwGetInstanceProcAddress(instance, "vkCmdSetBlendConstants"));
    vgo_vkCmdSetDepthBounds = (PFN_vkCmdSetDepthBounds)(glfwGetInstanceProcAddress(instance, "vkCmdSetDepthBounds"));
    vgo_vkCmdSetStencilCompareMask = (PFN_vkCmdSetStencilCompareMask)(glfwGetInstanceProcAddress(instance, "vkCmdSetStencilCompareMask"));
    vgo_vkCmdSetStencilWriteMask = (PFN_vkCmdSetStencilWriteMask)(glfwGetInstanceProcAddress(instance, "vkCmdSetStencilWriteMask"));
    vgo_vkCmdSetStencilReference = (PFN_vkCmdSetStencilReference)(glfwGetInstanceProcAddress(instance, "vkCmdSetStencilReference"));
    vgo_vkCmdBindDescriptorSets = (PFN_vkCmdBindDescriptorSets)(glfwGetInstanceProcAddress(instance, "vkCmdBindDescriptorSets"));
    vgo_vkCmdBindIndexBuffer = (PFN_vkCmdBindIndexBuffer)(glfwGetInstanceProcAddress(instance, "vkCmdBindIndexBuffer"));
    vgo_vkCmdBindVertexBuffers = (PFN_vkCmdBindVertexBuffers)(glfwGetInstanceProcAddress(instance, "vkCmdBindVertexBuffers"));
    vgo_vkCmdDraw = (PFN_vkCmdDraw)(glfwGetInstanceProcAddress(instance, "vkCmdDraw"));
    vgo_vkCmdDrawIndexed = (PFN_vkCmdDrawIndexed)(glfwGetInstanceProcAddress(instance, "vkCmdDrawIndexed"));
    vgo_vkCmdDrawIndirect = (PFN_vkCmdDrawIndirect)(glfwGetInstanceProcAddress(instance, "vkCmdDrawIndirect"));
    vgo_vkCmdDrawIndexedIndirect = (PFN_vkCmdDrawIndexedIndirect)(glfwGetInstanceProcAddress(instance, "vkCmdDrawIndexedIndirect"));
    vgo_vkCmdDispatch = (PFN_vkCmdDispatch)(glfwGetInstanceProcAddress(instance, "vkCmdDispatch"));
    vgo_vkCmdDispatchIndirect = (PFN_vkCmdDispatchIndirect)(glfwGetInstanceProcAddress(instance, "vkCmdDispatchIndirect"));
    vgo_vkCmdCopyBuffer = (PFN_vkCmdCopyBuffer)(glfwGetInstanceProcAddress(instance, "vkCmdCopyBuffer"));
    vgo_vkCmdCopyImage = (PFN_vkCmdCopyImage)(glfwGetInstanceProcAddress(instance, "vkCmdCopyImage"));
    vgo_vkCmdBlitImage = (PFN_vkCmdBlitImage)(glfwGetInstanceProcAddress(instance, "vkCmdBlitImage"));
    vgo_vkCmdCopyBufferToImage = (PFN_vkCmdCopyBufferToImage)(glfwGetInstanceProcAddress(instance, "vkCmdCopyBufferToImage"));
    vgo_vkCmdCopyImageToBuffer = (PFN_vkCmdCopyImageToBuffer)(glfwGetInstanceProcAddress(instance, "vkCmdCopyImageToBuffer"));
    vgo_vkCmdUpdateBuffer = (PFN_vkCmdUpdateBuffer)(glfwGetInstanceProcAddress(instance, "vkCmdUpdateBuffer"));
    vgo_vkCmdFillBuffer = (PFN_vkCmdFillBuffer)(glfwGetInstanceProcAddress(instance, "vkCmdFillBuffer"));
    vgo_vkCmdClearColorImage = (PFN_vkCmdClearColorImage)(glfwGetInstanceProcAddress(instance, "vkCmdClearColorImage"));
    vgo_vkCmdClearDepthStencilImage = (PFN_vkCmdClearDepthStencilImage)(glfwGetInstanceProcAddress(instance, "vkCmdClearDepthStencilImage"));
    vgo_vkCmdClearAttachments = (PFN_vkCmdClearAttachments)(glfwGetInstanceProcAddress(instance, "vkCmdClearAttachments"));
    vgo_vkCmdResolveImage = (PFN_vkCmdResolveImage)(glfwGetInstanceProcAddress(instance, "vkCmdResolveImage"));
    vgo_vkCmdSetEvent = (PFN_vkCmdSetEvent)(glfwGetInstanceProcAddress(instance, "vkCmdSetEvent"));
    vgo_vkCmdResetEvent = (PFN_vkCmdResetEvent)(glfwGetInstanceProcAddress(instance, "vkCmdResetEvent"));
    vgo_vkCmdWaitEvents = (PFN_vkCmdWaitEvents)(glfwGetInstanceProcAddress(instance, "vkCmdWaitEvents"));
    vgo_vkCmdPipelineBarrier = (PFN_vkCmdPipelineBarrier)(glfwGetInstanceProcAddress(instance, "vkCmdPipelineBarrier"));
    vgo_vkCmdBeginQuery = (PFN_vkCmdBeginQuery)(glfwGetInstanceProcAddress(instance, "vkCmdBeginQuery"));
    vgo_vkCmdEndQuery = (PFN_vkCmdEndQuery)(glfwGetInstanceProcAddress(instance, "vkCmdEndQuery"));
    vgo_vkCmdResetQueryPool = (PFN_vkCmdResetQueryPool)(glfwGetInstanceProcAddress(instance, "vkCmdResetQueryPool"));
    vgo_vkCmdWriteTimestamp = (PFN_vkCmdWriteTimestamp)(glfwGetInstanceProcAddress(instance, "vkCmdWriteTimestamp"));
    vgo_vkCmdCopyQueryPoolResults = (PFN_vkCmdCopyQueryPoolResults)(glfwGetInstanceProcAddress(instance, "vkCmdCopyQueryPoolResults"));
    vgo_vkCmdPushConstants = (PFN_vkCmdPushConstants)(glfwGetInstanceProcAddress(instance, "vkCmdPushConstants"));
    vgo_vkCmdBeginRenderPass = (PFN_vkCmdBeginRenderPass)(glfwGetInstanceProcAddress(instance, "vkCmdBeginRenderPass"));
    vgo_vkCmdNextSubpass = (PFN_vkCmdNextSubpass)(glfwGetInstanceProcAddress(instance, "vkCmdNextSubpass"));
    vgo_vkCmdEndRenderPass = (PFN_vkCmdEndRenderPass)(glfwGetInstanceProcAddress(instance, "vkCmdEndRenderPass"));
    vgo_vkCmdExecuteCommands = (PFN_vkCmdExecuteCommands)(glfwGetInstanceProcAddress(instance, "vkCmdExecuteCommands"));
    vgo_vkDestroySurfaceKHR = (PFN_vkDestroySurfaceKHR)(glfwGetInstanceProcAddress(instance, "vkDestroySurfaceKHR"));
    vgo_vkGetPhysicalDeviceSurfaceSupportKHR = (PFN_vkGetPhysicalDeviceSurfaceSupportKHR)(glfwGetInstanceProcAddress(instance, "vkGetPhysicalDeviceSurfaceSupportKHR"));
    vgo_vkGetPhysicalDeviceSurfaceCapabilitiesKHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR)(glfwGetInstanceProcAddress(instance, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR"));
    vgo_vkGetPhysicalDeviceSurfaceFormatsKHR = (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR)(glfwGetInstanceProcAddress(instance, "vkGetPhysicalDeviceSurfaceFormatsKHR"));
    vgo_vkGetPhysicalDeviceSurfacePresentModesKHR = (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR)(glfwGetInstanceProcAddress(instance, "vkGetPhysicalDeviceSurfacePresentModesKHR"));
    vgo_vkCreateSwapchainKHR = (PFN_vkCreateSwapchainKHR)(glfwGetInstanceProcAddress(instance, "vkCreateSwapchainKHR"));
    vgo_vkDestroySwapchainKHR = (PFN_vkDestroySwapchainKHR)(glfwGetInstanceProcAddress(instance, "vkDestroySwapchainKHR"));
    vgo_vkGetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR)(glfwGetInstanceProcAddress(instance, "vkGetSwapchainImagesKHR"));
    vgo_vkAcquireNextImageKHR = (PFN_vkAcquireNextImageKHR)(glfwGetInstanceProcAddress(instance, "vkAcquireNextImageKHR"));
    vgo_vkQueuePresentKHR = (PFN_vkQueuePresentKHR)(glfwGetInstanceProcAddress(instance, "vkQueuePresentKHR"));
    vgo_vkGetPhysicalDeviceDisplayPropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPropertiesKHR)(glfwGetInstanceProcAddress(instance, "vkGetPhysicalDeviceDisplayPropertiesKHR"));
    vgo_vkGetPhysicalDeviceDisplayPlanePropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR)(glfwGetInstanceProcAddress(instance, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR"));
    vgo_vkGetDisplayPlaneSupportedDisplaysKHR = (PFN_vkGetDisplayPlaneSupportedDisplaysKHR)(glfwGetInstanceProcAddress(instance, "vkGetDisplayPlaneSupportedDisplaysKHR"));
    vgo_vkGetDisplayModePropertiesKHR = (PFN_vkGetDisplayModePropertiesKHR)(glfwGetInstanceProcAddress(instance, "vkGetDisplayModePropertiesKHR"));
    vgo_vkCreateDisplayModeKHR = (PFN_vkCreateDisplayModeKHR)(glfwGetInstanceProcAddress(instance, "vkCreateDisplayModeKHR"));
    vgo_vkGetDisplayPlaneCapabilitiesKHR = (PFN_vkGetDisplayPlaneCapabilitiesKHR)(glfwGetInstanceProcAddress(instance, "vkGetDisplayPlaneCapabilitiesKHR"));
    vgo_vkCreateDisplayPlaneSurfaceKHR = (PFN_vkCreateDisplayPlaneSurfaceKHR)(glfwGetInstanceProcAddress(instance, "vkCreateDisplayPlaneSurfaceKHR"));
    vgo_vkCreateSharedSwapchainsKHR = (PFN_vkCreateSharedSwapchainsKHR)(glfwGetInstanceProcAddress(instance, "vkCreateSharedSwapchainsKHR"));

#ifdef VK_USE_PLATFORM_XLIB_KHR
    vgo_vkCreateXlibSurfaceKHR = (PFN_vkCreateXlibSurfaceKHR)(glfwGetInstanceProcAddress(instance, "vkCreateXlibSurfaceKHR"));
    vgo_vkGetPhysicalDeviceXlibPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR)(glfwGetInstanceProcAddress(instance, "vkGetPhysicalDeviceXlibPresentationSupportKHR"));
#endif

#ifdef VK_USE_PLATFORM_XCB_KHR
    vgo_vkCreateXcbSurfaceKHR = (PFN_vkCreateXcbSurfaceKHR)(glfwGetInstanceProcAddress(instance, "vkCreateXcbSurfaceKHR"));
    vgo_vkGetPhysicalDeviceXcbPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR)(glfwGetInstanceProcAddress(instance, "vkGetPhysicalDeviceXcbPresentationSupportKHR"));
#endif

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
    vgo_vkCreateWaylandSurfaceKHR = (PFN_vkCreateWaylandSurfaceKHR)(glfwGetInstanceProcAddress(instance, "vkCreateWaylandSurfaceKHR"));
    vgo_vkGetPhysicalDeviceWaylandPresentationSupportKHR = (PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR)(glfwGetInstanceProcAddress(instance, "vkGetPhysicalDeviceWaylandPresentationSupportKHR"));
#endif

#ifdef VK_USE_PLATFORM_MIR_KHR
    vgo_vkCreateMirSurfaceKHR = (PFN_vkCreateMirSurfaceKHR)(glfwGetInstanceProcAddress(instance, "vkCreateMirSurfaceKHR"));
    vgo_vkGetPhysicalDeviceMirPresentationSupportKHR = (PFN_vkGetPhysicalDeviceMirPresentationSupportKHR)(glfwGetInstanceProcAddress(instance, "vkGetPhysicalDeviceMirPresentationSupportKHR"));
#endif

#ifdef VK_USE_PLATFORM_ANDROID_KHR
    vgo_vkCreateAndroidSurfaceKHR = (PFN_vkCreateAndroidSurfaceKHR)(glfwGetInstanceProcAddress(instance, "vkCreateAndroidSurfaceKHR"));
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
    vgo_vkCreateWin32SurfaceKHR = (PFN_vkCreateWin32SurfaceKHR)(glfwGetInstanceProcAddress(instance, "vkCreateWin32SurfaceKHR"));
    vgo_vkGetPhysicalDeviceWin32PresentationSupportKHR = (PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR)(glfwGetInstanceProcAddress(instance, "vkGetPhysicalDeviceWin32PresentationSupportKHR"));
#endif

    vgo_vkCreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT)(glfwGetInstanceProcAddress(instance, "vkCreateDebugReportCallbackEXT"));
    vgo_vkDestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT)(glfwGetInstanceProcAddress(instance, "vkDestroyDebugReportCallbackEXT"));
    vgo_vkDebugReportMessageEXT = (PFN_vkDebugReportMessageEXT)(glfwGetInstanceProcAddress(instance, "vkDebugReportMessageEXT"));
    
    return 0;
}

PFN_vkCreateInstance vgo_vkCreateInstance;
PFN_vkDestroyInstance vgo_vkDestroyInstance;
PFN_vkEnumeratePhysicalDevices vgo_vkEnumeratePhysicalDevices;
PFN_vkGetPhysicalDeviceFeatures vgo_vkGetPhysicalDeviceFeatures;
PFN_vkGetPhysicalDeviceFormatProperties vgo_vkGetPhysicalDeviceFormatProperties;
PFN_vkGetPhysicalDeviceImageFormatProperties vgo_vkGetPhysicalDeviceImageFormatProperties;
PFN_vkGetPhysicalDeviceProperties vgo_vkGetPhysicalDeviceProperties;
PFN_vkGetPhysicalDeviceQueueFamilyProperties vgo_vkGetPhysicalDeviceQueueFamilyProperties;
PFN_vkGetPhysicalDeviceMemoryProperties vgo_vkGetPhysicalDeviceMemoryProperties;
PFN_vkGetInstanceProcAddr vgo_vkGetInstanceProcAddr;
PFN_vkGetDeviceProcAddr vgo_vkGetDeviceProcAddr;
PFN_vkCreateDevice vgo_vkCreateDevice;
PFN_vkDestroyDevice vgo_vkDestroyDevice;
PFN_vkEnumerateInstanceExtensionProperties vgo_vkEnumerateInstanceExtensionProperties;
PFN_vkEnumerateDeviceExtensionProperties vgo_vkEnumerateDeviceExtensionProperties;
PFN_vkEnumerateInstanceLayerProperties vgo_vkEnumerateInstanceLayerProperties;
PFN_vkEnumerateDeviceLayerProperties vgo_vkEnumerateDeviceLayerProperties;
PFN_vkGetDeviceQueue vgo_vkGetDeviceQueue;
PFN_vkQueueSubmit vgo_vkQueueSubmit;
PFN_vkQueueWaitIdle vgo_vkQueueWaitIdle;
PFN_vkDeviceWaitIdle vgo_vkDeviceWaitIdle;
PFN_vkAllocateMemory vgo_vkAllocateMemory;
PFN_vkFreeMemory vgo_vkFreeMemory;
PFN_vkMapMemory vgo_vkMapMemory;
PFN_vkUnmapMemory vgo_vkUnmapMemory;
PFN_vkFlushMappedMemoryRanges vgo_vkFlushMappedMemoryRanges;
PFN_vkInvalidateMappedMemoryRanges vgo_vkInvalidateMappedMemoryRanges;
PFN_vkGetDeviceMemoryCommitment vgo_vkGetDeviceMemoryCommitment;
PFN_vkBindBufferMemory vgo_vkBindBufferMemory;
PFN_vkBindImageMemory vgo_vkBindImageMemory;
PFN_vkGetBufferMemoryRequirements vgo_vkGetBufferMemoryRequirements;
PFN_vkGetImageMemoryRequirements vgo_vkGetImageMemoryRequirements;
PFN_vkGetImageSparseMemoryRequirements vgo_vkGetImageSparseMemoryRequirements;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties vgo_vkGetPhysicalDeviceSparseImageFormatProperties;
PFN_vkQueueBindSparse vgo_vkQueueBindSparse;
PFN_vkCreateFence vgo_vkCreateFence;
PFN_vkDestroyFence vgo_vkDestroyFence;
PFN_vkResetFences vgo_vkResetFences;
PFN_vkGetFenceStatus vgo_vkGetFenceStatus;
PFN_vkWaitForFences vgo_vkWaitForFences;
PFN_vkCreateSemaphore vgo_vkCreateSemaphore;
PFN_vkDestroySemaphore vgo_vkDestroySemaphore;
PFN_vkCreateEvent vgo_vkCreateEvent;
PFN_vkDestroyEvent vgo_vkDestroyEvent;
PFN_vkGetEventStatus vgo_vkGetEventStatus;
PFN_vkSetEvent vgo_vkSetEvent;
PFN_vkResetEvent vgo_vkResetEvent;
PFN_vkCreateQueryPool vgo_vkCreateQueryPool;
PFN_vkDestroyQueryPool vgo_vkDestroyQueryPool;
PFN_vkGetQueryPoolResults vgo_vkGetQueryPoolResults;
PFN_vkCreateBuffer vgo_vkCreateBuffer;
PFN_vkDestroyBuffer vgo_vkDestroyBuffer;
PFN_vkCreateBufferView vgo_vkCreateBufferView;
PFN_vkDestroyBufferView vgo_vkDestroyBufferView;
PFN_vkCreateImage vgo_vkCreateImage;
PFN_vkDestroyImage vgo_vkDestroyImage;
PFN_vkGetImageSubresourceLayout vgo_vkGetImageSubresourceLayout;
PFN_vkCreateImageView vgo_vkCreateImageView;
PFN_vkDestroyImageView vgo_vkDestroyImageView;
PFN_vkCreateShaderModule vgo_vkCreateShaderModule;
PFN_vkDestroyShaderModule vgo_vkDestroyShaderModule;
PFN_vkCreatePipelineCache vgo_vkCreatePipelineCache;
PFN_vkDestroyPipelineCache vgo_vkDestroyPipelineCache;
PFN_vkGetPipelineCacheData vgo_vkGetPipelineCacheData;
PFN_vkMergePipelineCaches vgo_vkMergePipelineCaches;
PFN_vkCreateGraphicsPipelines vgo_vkCreateGraphicsPipelines;
PFN_vkCreateComputePipelines vgo_vkCreateComputePipelines;
PFN_vkDestroyPipeline vgo_vkDestroyPipeline;
PFN_vkCreatePipelineLayout vgo_vkCreatePipelineLayout;
PFN_vkDestroyPipelineLayout vgo_vkDestroyPipelineLayout;
PFN_vkCreateSampler vgo_vkCreateSampler;
PFN_vkDestroySampler vgo_vkDestroySampler;
PFN_vkCreateDescriptorSetLayout vgo_vkCreateDescriptorSetLayout;
PFN_vkDestroyDescriptorSetLayout vgo_vkDestroyDescriptorSetLayout;
PFN_vkCreateDescriptorPool vgo_vkCreateDescriptorPool;
PFN_vkDestroyDescriptorPool vgo_vkDestroyDescriptorPool;
PFN_vkResetDescriptorPool vgo_vkResetDescriptorPool;
PFN_vkAllocateDescriptorSets vgo_vkAllocateDescriptorSets;
PFN_vkFreeDescriptorSets vgo_vkFreeDescriptorSets;
PFN_vkUpdateDescriptorSets vgo_vkUpdateDescriptorSets;
PFN_vkCreateFramebuffer vgo_vkCreateFramebuffer;
PFN_vkDestroyFramebuffer vgo_vkDestroyFramebuffer;
PFN_vkCreateRenderPass vgo_vkCreateRenderPass;
PFN_vkDestroyRenderPass vgo_vkDestroyRenderPass;
PFN_vkGetRenderAreaGranularity vgo_vkGetRenderAreaGranularity;
PFN_vkCreateCommandPool vgo_vkCreateCommandPool;
PFN_vkDestroyCommandPool vgo_vkDestroyCommandPool;
PFN_vkResetCommandPool vgo_vkResetCommandPool;
PFN_vkAllocateCommandBuffers vgo_vkAllocateCommandBuffers;
PFN_vkFreeCommandBuffers vgo_vkFreeCommandBuffers;
PFN_vkBeginCommandBuffer vgo_vkBeginCommandBuffer;
PFN_vkEndCommandBuffer vgo_vkEndCommandBuffer;
PFN_vkResetCommandBuffer vgo_vkResetCommandBuffer;
PFN_vkCmdBindPipeline vgo_vkCmdBindPipeline;
PFN_vkCmdSetViewport vgo_vkCmdSetViewport;
PFN_vkCmdSetScissor vgo_vkCmdSetScissor;
PFN_vkCmdSetLineWidth vgo_vkCmdSetLineWidth;
PFN_vkCmdSetDepthBias vgo_vkCmdSetDepthBias;
PFN_vkCmdSetBlendConstants vgo_vkCmdSetBlendConstants;
PFN_vkCmdSetDepthBounds vgo_vkCmdSetDepthBounds;
PFN_vkCmdSetStencilCompareMask vgo_vkCmdSetStencilCompareMask;
PFN_vkCmdSetStencilWriteMask vgo_vkCmdSetStencilWriteMask;
PFN_vkCmdSetStencilReference vgo_vkCmdSetStencilReference;
PFN_vkCmdBindDescriptorSets vgo_vkCmdBindDescriptorSets;
PFN_vkCmdBindIndexBuffer vgo_vkCmdBindIndexBuffer;
PFN_vkCmdBindVertexBuffers vgo_vkCmdBindVertexBuffers;
PFN_vkCmdDraw vgo_vkCmdDraw;
PFN_vkCmdDrawIndexed vgo_vkCmdDrawIndexed;
PFN_vkCmdDrawIndirect vgo_vkCmdDrawIndirect;
PFN_vkCmdDrawIndexedIndirect vgo_vkCmdDrawIndexedIndirect;
PFN_vkCmdDispatch vgo_vkCmdDispatch;
PFN_vkCmdDispatchIndirect vgo_vkCmdDispatchIndirect;
PFN_vkCmdCopyBuffer vgo_vkCmdCopyBuffer;
PFN_vkCmdCopyImage vgo_vkCmdCopyImage;
PFN_vkCmdBlitImage vgo_vkCmdBlitImage;
PFN_vkCmdCopyBufferToImage vgo_vkCmdCopyBufferToImage;
PFN_vkCmdCopyImageToBuffer vgo_vkCmdCopyImageToBuffer;
PFN_vkCmdUpdateBuffer vgo_vkCmdUpdateBuffer;
PFN_vkCmdFillBuffer vgo_vkCmdFillBuffer;
PFN_vkCmdClearColorImage vgo_vkCmdClearColorImage;
PFN_vkCmdClearDepthStencilImage vgo_vkCmdClearDepthStencilImage;
PFN_vkCmdClearAttachments vgo_vkCmdClearAttachments;
PFN_vkCmdResolveImage vgo_vkCmdResolveImage;
PFN_vkCmdSetEvent vgo_vkCmdSetEvent;
PFN_vkCmdResetEvent vgo_vkCmdResetEvent;
PFN_vkCmdWaitEvents vgo_vkCmdWaitEvents;
PFN_vkCmdPipelineBarrier vgo_vkCmdPipelineBarrier;
PFN_vkCmdBeginQuery vgo_vkCmdBeginQuery;
PFN_vkCmdEndQuery vgo_vkCmdEndQuery;
PFN_vkCmdResetQueryPool vgo_vkCmdResetQueryPool;
PFN_vkCmdWriteTimestamp vgo_vkCmdWriteTimestamp;
PFN_vkCmdCopyQueryPoolResults vgo_vkCmdCopyQueryPoolResults;
PFN_vkCmdPushConstants vgo_vkCmdPushConstants;
PFN_vkCmdBeginRenderPass vgo_vkCmdBeginRenderPass;
PFN_vkCmdNextSubpass vgo_vkCmdNextSubpass;
PFN_vkCmdEndRenderPass vgo_vkCmdEndRenderPass;
PFN_vkCmdExecuteCommands vgo_vkCmdExecuteCommands;
PFN_vkDestroySurfaceKHR vgo_vkDestroySurfaceKHR;
PFN_vkGetPhysicalDeviceSurfaceSupportKHR vgo_vkGetPhysicalDeviceSurfaceSupportKHR;
PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vgo_vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
PFN_vkGetPhysicalDeviceSurfaceFormatsKHR vgo_vkGetPhysicalDeviceSurfaceFormatsKHR;
PFN_vkGetPhysicalDeviceSurfacePresentModesKHR vgo_vkGetPhysicalDeviceSurfacePresentModesKHR;
PFN_vkCreateSwapchainKHR vgo_vkCreateSwapchainKHR;
PFN_vkDestroySwapchainKHR vgo_vkDestroySwapchainKHR;
PFN_vkGetSwapchainImagesKHR vgo_vkGetSwapchainImagesKHR;
PFN_vkAcquireNextImageKHR vgo_vkAcquireNextImageKHR;
PFN_vkQueuePresentKHR vgo_vkQueuePresentKHR;
PFN_vkGetPhysicalDeviceDisplayPropertiesKHR vgo_vkGetPhysicalDeviceDisplayPropertiesKHR;
PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR vgo_vkGetPhysicalDeviceDisplayPlanePropertiesKHR;
PFN_vkGetDisplayPlaneSupportedDisplaysKHR vgo_vkGetDisplayPlaneSupportedDisplaysKHR;
PFN_vkGetDisplayModePropertiesKHR vgo_vkGetDisplayModePropertiesKHR;
PFN_vkCreateDisplayModeKHR vgo_vkCreateDisplayModeKHR;
PFN_vkGetDisplayPlaneCapabilitiesKHR vgo_vkGetDisplayPlaneCapabilitiesKHR;
PFN_vkCreateDisplayPlaneSurfaceKHR vgo_vkCreateDisplayPlaneSurfaceKHR;
PFN_vkCreateSharedSwapchainsKHR vgo_vkCreateSharedSwapchainsKHR;

#ifdef VK_USE_PLATFORM_XLIB_KHR
PFN_vkCreateXlibSurfaceKHR vgo_vkCreateXlibSurfaceKHR;
PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR vgo_vkGetPhysicalDeviceXlibPresentationSupportKHR;
#endif

#ifdef VK_USE_PLATFORM_XCB_KHR
PFN_vkCreateXcbSurfaceKHR vgo_vkCreateXcbSurfaceKHR;
PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR vgo_vkGetPhysicalDeviceXcbPresentationSupportKHR;
#endif

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
PFN_vkCreateWaylandSurfaceKHR vgo_vkCreateWaylandSurfaceKHR;
PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR vgo_vkGetPhysicalDeviceWaylandPresentationSupportKHR;
#endif

#ifdef VK_USE_PLATFORM_MIR_KHR
PFN_vkCreateMirSurfaceKHR vgo_vkCreateMirSurfaceKHR;
PFN_vkGetPhysicalDeviceMirPresentationSupportKHR vgo_vkGetPhysicalDeviceMirPresentationSupportKHR;
#endif

#ifdef VK_USE_PLATFORM_ANDROID_KHR
PFN_vkCreateAndroidSurfaceKHR vgo_vkCreateAndroidSurfaceKHR;
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
PFN_vkCreateWin32SurfaceKHR vgo_vkCreateWin32SurfaceKHR;
PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR vgo_vkGetPhysicalDeviceWin32PresentationSupportKHR;
#endif

PFN_vkCreateDebugReportCallbackEXT vgo_vkCreateDebugReportCallbackEXT;
PFN_vkDestroyDebugReportCallbackEXT vgo_vkDestroyDebugReportCallbackEXT;
PFN_vkDebugReportMessageEXT vgo_vkDebugReportMessageEXT;
