// +build windows

#include <GLFW/glfw3.h>
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
    vkCreateInstance = (PFN_vkCreateInstance)(glfwGetInstanceProcAddress(NULL,"vkCreateInstance"));
    vkDestroyInstance = (PFN_vkDestroyInstance)(glfwGetInstanceProcAddress(NULL,"vkDestroyInstance"));
    vkEnumeratePhysicalDevices = (PFN_vkEnumeratePhysicalDevices)(glfwGetInstanceProcAddress(NULL,"vkEnumeratePhysicalDevices"));
    vkGetPhysicalDeviceFeatures = (PFN_vkGetPhysicalDeviceFeatures)(glfwGetInstanceProcAddress(NULL,"vkGetPhysicalDeviceFeatures"));
    vkGetPhysicalDeviceFormatProperties = (PFN_vkGetPhysicalDeviceFormatProperties)(glfwGetInstanceProcAddress(NULL,"vkGetPhysicalDeviceFormatProperties"));
    vkGetPhysicalDeviceImageFormatProperties = (PFN_vkGetPhysicalDeviceImageFormatProperties)(glfwGetInstanceProcAddress(NULL,"vkGetPhysicalDeviceImageFormatProperties"));
    vkGetPhysicalDeviceProperties = (PFN_vkGetPhysicalDeviceProperties)(glfwGetInstanceProcAddress(NULL,"vkGetPhysicalDeviceProperties"));
    vkGetPhysicalDeviceQueueFamilyProperties = (PFN_vkGetPhysicalDeviceQueueFamilyProperties)(glfwGetInstanceProcAddress(NULL,"vkGetPhysicalDeviceQueueFamilyProperties"));
    vkGetPhysicalDeviceMemoryProperties = (PFN_vkGetPhysicalDeviceMemoryProperties)(glfwGetInstanceProcAddress(NULL,"vkGetPhysicalDeviceMemoryProperties"));
    vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr)(glfwGetInstanceProcAddress(NULL,"vkGetInstanceProcAddr"));
    vkGetDeviceProcAddr = (PFN_vkGetDeviceProcAddr)(glfwGetInstanceProcAddress(NULL,"vkGetDeviceProcAddr"));
    vkCreateDevice = (PFN_vkCreateDevice)(glfwGetInstanceProcAddress(NULL,"vkCreateDevice"));
    vkDestroyDevice = (PFN_vkDestroyDevice)(glfwGetInstanceProcAddress(NULL,"vkDestroyDevice"));
    vkEnumerateInstanceExtensionProperties = (PFN_vkEnumerateInstanceExtensionProperties)(glfwGetInstanceProcAddress(NULL,"vkEnumerateInstanceExtensionProperties"));
    vkEnumerateDeviceExtensionProperties = (PFN_vkEnumerateDeviceExtensionProperties)(glfwGetInstanceProcAddress(NULL,"vkEnumerateDeviceExtensionProperties"));
    vkEnumerateInstanceLayerProperties = (PFN_vkEnumerateInstanceLayerProperties)(glfwGetInstanceProcAddress(NULL,"vkEnumerateInstanceLayerProperties"));
    vkEnumerateDeviceLayerProperties = (PFN_vkEnumerateDeviceLayerProperties)(glfwGetInstanceProcAddress(NULL,"vkEnumerateDeviceLayerProperties"));
    vkGetDeviceQueue = (PFN_vkGetDeviceQueue)(glfwGetInstanceProcAddress(NULL,"vkGetDeviceQueue"));
    vkQueueSubmit = (PFN_vkQueueSubmit)(glfwGetInstanceProcAddress(NULL,"vkQueueSubmit"));
    vkQueueWaitIdle = (PFN_vkQueueWaitIdle)(glfwGetInstanceProcAddress(NULL,"vkQueueWaitIdle"));
    vkDeviceWaitIdle = (PFN_vkDeviceWaitIdle)(glfwGetInstanceProcAddress(NULL,"vkDeviceWaitIdle"));
    vkAllocateMemory = (PFN_vkAllocateMemory)(glfwGetInstanceProcAddress(NULL,"vkAllocateMemory"));
    vkFreeMemory = (PFN_vkFreeMemory)(glfwGetInstanceProcAddress(NULL,"vkFreeMemory"));
    vkMapMemory = (PFN_vkMapMemory)(glfwGetInstanceProcAddress(NULL,"vkMapMemory"));
    vkUnmapMemory = (PFN_vkUnmapMemory)(glfwGetInstanceProcAddress(NULL,"vkUnmapMemory"));
    vkFlushMappedMemoryRanges = (PFN_vkFlushMappedMemoryRanges)(glfwGetInstanceProcAddress(NULL,"vkFlushMappedMemoryRanges"));
    vkInvalidateMappedMemoryRanges = (PFN_vkInvalidateMappedMemoryRanges)(glfwGetInstanceProcAddress(NULL,"vkInvalidateMappedMemoryRanges"));
    vkGetDeviceMemoryCommitment = (PFN_vkGetDeviceMemoryCommitment)(glfwGetInstanceProcAddress(NULL,"vkGetDeviceMemoryCommitment"));
    vkBindBufferMemory = (PFN_vkBindBufferMemory)(glfwGetInstanceProcAddress(NULL,"vkBindBufferMemory"));
    vkBindImageMemory = (PFN_vkBindImageMemory)(glfwGetInstanceProcAddress(NULL,"vkBindImageMemory"));
    vkGetBufferMemoryRequirements = (PFN_vkGetBufferMemoryRequirements)(glfwGetInstanceProcAddress(NULL,"vkGetBufferMemoryRequirements"));
    vkGetImageMemoryRequirements = (PFN_vkGetImageMemoryRequirements)(glfwGetInstanceProcAddress(NULL,"vkGetImageMemoryRequirements"));
    vkGetImageSparseMemoryRequirements = (PFN_vkGetImageSparseMemoryRequirements)(glfwGetInstanceProcAddress(NULL,"vkGetImageSparseMemoryRequirements"));
    vkGetPhysicalDeviceSparseImageFormatProperties = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties)(glfwGetInstanceProcAddress(NULL,"vkGetPhysicalDeviceSparseImageFormatProperties"));
    vkQueueBindSparse = (PFN_vkQueueBindSparse)(glfwGetInstanceProcAddress(NULL,"vkQueueBindSparse"));
    vkCreateFence = (PFN_vkCreateFence)(glfwGetInstanceProcAddress(NULL,"vkCreateFence"));
    vkDestroyFence = (PFN_vkDestroyFence)(glfwGetInstanceProcAddress(NULL,"vkDestroyFence"));
    vkResetFences = (PFN_vkResetFences)(glfwGetInstanceProcAddress(NULL,"vkResetFences"));
    vkGetFenceStatus = (PFN_vkGetFenceStatus)(glfwGetInstanceProcAddress(NULL,"vkGetFenceStatus"));
    vkWaitForFences = (PFN_vkWaitForFences)(glfwGetInstanceProcAddress(NULL,"vkWaitForFences"));
    vkCreateSemaphore = (PFN_vkCreateSemaphore)(glfwGetInstanceProcAddress(NULL,"vkCreateSemaphore"));
    vkDestroySemaphore = (PFN_vkDestroySemaphore)(glfwGetInstanceProcAddress(NULL,"vkDestroySemaphore"));
    vkCreateEvent = (PFN_vkCreateEvent)(glfwGetInstanceProcAddress(NULL,"vkCreateEvent"));
    vkDestroyEvent = (PFN_vkDestroyEvent)(glfwGetInstanceProcAddress(NULL,"vkDestroyEvent"));
    vkGetEventStatus = (PFN_vkGetEventStatus)(glfwGetInstanceProcAddress(NULL,"vkGetEventStatus"));
    vkSetEvent = (PFN_vkSetEvent)(glfwGetInstanceProcAddress(NULL,"vkSetEvent"));
    vkResetEvent = (PFN_vkResetEvent)(glfwGetInstanceProcAddress(NULL,"vkResetEvent"));
    vkCreateQueryPool = (PFN_vkCreateQueryPool)(glfwGetInstanceProcAddress(NULL,"vkCreateQueryPool"));
    vkDestroyQueryPool = (PFN_vkDestroyQueryPool)(glfwGetInstanceProcAddress(NULL,"vkDestroyQueryPool"));
    vkGetQueryPoolResults = (PFN_vkGetQueryPoolResults)(glfwGetInstanceProcAddress(NULL,"vkGetQueryPoolResults"));
    vkCreateBuffer = (PFN_vkCreateBuffer)(glfwGetInstanceProcAddress(NULL,"vkCreateBuffer"));
    vkDestroyBuffer = (PFN_vkDestroyBuffer)(glfwGetInstanceProcAddress(NULL,"vkDestroyBuffer"));
    vkCreateBufferView = (PFN_vkCreateBufferView)(glfwGetInstanceProcAddress(NULL,"vkCreateBufferView"));
    vkDestroyBufferView = (PFN_vkDestroyBufferView)(glfwGetInstanceProcAddress(NULL,"vkDestroyBufferView"));
    vkCreateImage = (PFN_vkCreateImage)(glfwGetInstanceProcAddress(NULL,"vkCreateImage"));
    vkDestroyImage = (PFN_vkDestroyImage)(glfwGetInstanceProcAddress(NULL,"vkDestroyImage"));
    vkGetImageSubresourceLayout = (PFN_vkGetImageSubresourceLayout)(glfwGetInstanceProcAddress(NULL,"vkGetImageSubresourceLayout"));
    vkCreateImageView = (PFN_vkCreateImageView)(glfwGetInstanceProcAddress(NULL,"vkCreateImageView"));
    vkDestroyImageView = (PFN_vkDestroyImageView)(glfwGetInstanceProcAddress(NULL,"vkDestroyImageView"));
    vkCreateShaderModule = (PFN_vkCreateShaderModule)(glfwGetInstanceProcAddress(NULL,"vkCreateShaderModule"));
    vkDestroyShaderModule = (PFN_vkDestroyShaderModule)(glfwGetInstanceProcAddress(NULL,"vkDestroyShaderModule"));
    vkCreatePipelineCache = (PFN_vkCreatePipelineCache)(glfwGetInstanceProcAddress(NULL,"vkCreatePipelineCache"));
    vkDestroyPipelineCache = (PFN_vkDestroyPipelineCache)(glfwGetInstanceProcAddress(NULL,"vkDestroyPipelineCache"));
    vkGetPipelineCacheData = (PFN_vkGetPipelineCacheData)(glfwGetInstanceProcAddress(NULL,"vkGetPipelineCacheData"));
    vkMergePipelineCaches = (PFN_vkMergePipelineCaches)(glfwGetInstanceProcAddress(NULL,"vkMergePipelineCaches"));
    vkCreateGraphicsPipelines = (PFN_vkCreateGraphicsPipelines)(glfwGetInstanceProcAddress(NULL,"vkCreateGraphicsPipelines"));
    vkCreateComputePipelines = (PFN_vkCreateComputePipelines)(glfwGetInstanceProcAddress(NULL,"vkCreateComputePipelines"));
    vkDestroyPipeline = (PFN_vkDestroyPipeline)(glfwGetInstanceProcAddress(NULL,"vkDestroyPipeline"));
    vkCreatePipelineLayout = (PFN_vkCreatePipelineLayout)(glfwGetInstanceProcAddress(NULL,"vkCreatePipelineLayout"));
    vkDestroyPipelineLayout = (PFN_vkDestroyPipelineLayout)(glfwGetInstanceProcAddress(NULL,"vkDestroyPipelineLayout"));
    vkCreateSampler = (PFN_vkCreateSampler)(glfwGetInstanceProcAddress(NULL,"vkCreateSampler"));
    vkDestroySampler = (PFN_vkDestroySampler)(glfwGetInstanceProcAddress(NULL,"vkDestroySampler"));
    vkCreateDescriptorSetLayout = (PFN_vkCreateDescriptorSetLayout)(glfwGetInstanceProcAddress(NULL,"vkCreateDescriptorSetLayout"));
    vkDestroyDescriptorSetLayout = (PFN_vkDestroyDescriptorSetLayout)(glfwGetInstanceProcAddress(NULL,"vkDestroyDescriptorSetLayout"));
    vkCreateDescriptorPool = (PFN_vkCreateDescriptorPool)(glfwGetInstanceProcAddress(NULL,"vkCreateDescriptorPool"));
    vkDestroyDescriptorPool = (PFN_vkDestroyDescriptorPool)(glfwGetInstanceProcAddress(NULL,"vkDestroyDescriptorPool"));
    vkResetDescriptorPool = (PFN_vkResetDescriptorPool)(glfwGetInstanceProcAddress(NULL,"vkResetDescriptorPool"));
    vkAllocateDescriptorSets = (PFN_vkAllocateDescriptorSets)(glfwGetInstanceProcAddress(NULL,"vkAllocateDescriptorSets"));
    vkFreeDescriptorSets = (PFN_vkFreeDescriptorSets)(glfwGetInstanceProcAddress(NULL,"vkFreeDescriptorSets"));
    vkUpdateDescriptorSets = (PFN_vkUpdateDescriptorSets)(glfwGetInstanceProcAddress(NULL,"vkUpdateDescriptorSets"));
    vkCreateFramebuffer = (PFN_vkCreateFramebuffer)(glfwGetInstanceProcAddress(NULL,"vkCreateFramebuffer"));
    vkDestroyFramebuffer = (PFN_vkDestroyFramebuffer)(glfwGetInstanceProcAddress(NULL,"vkDestroyFramebuffer"));
    vkCreateRenderPass = (PFN_vkCreateRenderPass)(glfwGetInstanceProcAddress(NULL,"vkCreateRenderPass"));
    vkDestroyRenderPass = (PFN_vkDestroyRenderPass)(glfwGetInstanceProcAddress(NULL,"vkDestroyRenderPass"));
    vkGetRenderAreaGranularity = (PFN_vkGetRenderAreaGranularity)(glfwGetInstanceProcAddress(NULL,"vkGetRenderAreaGranularity"));
    vkCreateCommandPool = (PFN_vkCreateCommandPool)(glfwGetInstanceProcAddress(NULL,"vkCreateCommandPool"));
    vkDestroyCommandPool = (PFN_vkDestroyCommandPool)(glfwGetInstanceProcAddress(NULL,"vkDestroyCommandPool"));
    vkResetCommandPool = (PFN_vkResetCommandPool)(glfwGetInstanceProcAddress(NULL,"vkResetCommandPool"));
    vkAllocateCommandBuffers = (PFN_vkAllocateCommandBuffers)(glfwGetInstanceProcAddress(NULL,"vkAllocateCommandBuffers"));
    vkFreeCommandBuffers = (PFN_vkFreeCommandBuffers)(glfwGetInstanceProcAddress(NULL,"vkFreeCommandBuffers"));
    vkBeginCommandBuffer = (PFN_vkBeginCommandBuffer)(glfwGetInstanceProcAddress(NULL,"vkBeginCommandBuffer"));
    vkEndCommandBuffer = (PFN_vkEndCommandBuffer)(glfwGetInstanceProcAddress(NULL,"vkEndCommandBuffer"));
    vkResetCommandBuffer = (PFN_vkResetCommandBuffer)(glfwGetInstanceProcAddress(NULL,"vkResetCommandBuffer"));
    vkCmdBindPipeline = (PFN_vkCmdBindPipeline)(glfwGetInstanceProcAddress(NULL,"vkCmdBindPipeline"));
    vkCmdSetViewport = (PFN_vkCmdSetViewport)(glfwGetInstanceProcAddress(NULL,"vkCmdSetViewport"));
    vkCmdSetScissor = (PFN_vkCmdSetScissor)(glfwGetInstanceProcAddress(NULL,"vkCmdSetScissor"));
    vkCmdSetLineWidth = (PFN_vkCmdSetLineWidth)(glfwGetInstanceProcAddress(NULL,"vkCmdSetLineWidth"));
    vkCmdSetDepthBias = (PFN_vkCmdSetDepthBias)(glfwGetInstanceProcAddress(NULL,"vkCmdSetDepthBias"));
    vkCmdSetBlendConstants = (PFN_vkCmdSetBlendConstants)(glfwGetInstanceProcAddress(NULL,"vkCmdSetBlendConstants"));
    vkCmdSetDepthBounds = (PFN_vkCmdSetDepthBounds)(glfwGetInstanceProcAddress(NULL,"vkCmdSetDepthBounds"));
    vkCmdSetStencilCompareMask = (PFN_vkCmdSetStencilCompareMask)(glfwGetInstanceProcAddress(NULL,"vkCmdSetStencilCompareMask"));
    vkCmdSetStencilWriteMask = (PFN_vkCmdSetStencilWriteMask)(glfwGetInstanceProcAddress(NULL,"vkCmdSetStencilWriteMask"));
    vkCmdSetStencilReference = (PFN_vkCmdSetStencilReference)(glfwGetInstanceProcAddress(NULL,"vkCmdSetStencilReference"));
    vkCmdBindDescriptorSets = (PFN_vkCmdBindDescriptorSets)(glfwGetInstanceProcAddress(NULL,"vkCmdBindDescriptorSets"));
    vkCmdBindIndexBuffer = (PFN_vkCmdBindIndexBuffer)(glfwGetInstanceProcAddress(NULL,"vkCmdBindIndexBuffer"));
    vkCmdBindVertexBuffers = (PFN_vkCmdBindVertexBuffers)(glfwGetInstanceProcAddress(NULL,"vkCmdBindVertexBuffers"));
    vkCmdDraw = (PFN_vkCmdDraw)(glfwGetInstanceProcAddress(NULL,"vkCmdDraw"));
    vkCmdDrawIndexed = (PFN_vkCmdDrawIndexed)(glfwGetInstanceProcAddress(NULL,"vkCmdDrawIndexed"));
    vkCmdDrawIndirect = (PFN_vkCmdDrawIndirect)(glfwGetInstanceProcAddress(NULL,"vkCmdDrawIndirect"));
    vkCmdDrawIndexedIndirect = (PFN_vkCmdDrawIndexedIndirect)(glfwGetInstanceProcAddress(NULL,"vkCmdDrawIndexedIndirect"));
    vkCmdDispatch = (PFN_vkCmdDispatch)(glfwGetInstanceProcAddress(NULL,"vkCmdDispatch"));
    vkCmdDispatchIndirect = (PFN_vkCmdDispatchIndirect)(glfwGetInstanceProcAddress(NULL,"vkCmdDispatchIndirect"));
    vkCmdCopyBuffer = (PFN_vkCmdCopyBuffer)(glfwGetInstanceProcAddress(NULL,"vkCmdCopyBuffer"));
    vkCmdCopyImage = (PFN_vkCmdCopyImage)(glfwGetInstanceProcAddress(NULL,"vkCmdCopyImage"));
    vkCmdBlitImage = (PFN_vkCmdBlitImage)(glfwGetInstanceProcAddress(NULL,"vkCmdBlitImage"));
    vkCmdCopyBufferToImage = (PFN_vkCmdCopyBufferToImage)(glfwGetInstanceProcAddress(NULL,"vkCmdCopyBufferToImage"));
    vkCmdCopyImageToBuffer = (PFN_vkCmdCopyImageToBuffer)(glfwGetInstanceProcAddress(NULL,"vkCmdCopyImageToBuffer"));
    vkCmdUpdateBuffer = (PFN_vkCmdUpdateBuffer)(glfwGetInstanceProcAddress(NULL,"vkCmdUpdateBuffer"));
    vkCmdFillBuffer = (PFN_vkCmdFillBuffer)(glfwGetInstanceProcAddress(NULL,"vkCmdFillBuffer"));
    vkCmdClearColorImage = (PFN_vkCmdClearColorImage)(glfwGetInstanceProcAddress(NULL,"vkCmdClearColorImage"));
    vkCmdClearDepthStencilImage = (PFN_vkCmdClearDepthStencilImage)(glfwGetInstanceProcAddress(NULL,"vkCmdClearDepthStencilImage"));
    vkCmdClearAttachments = (PFN_vkCmdClearAttachments)(glfwGetInstanceProcAddress(NULL,"vkCmdClearAttachments"));
    vkCmdResolveImage = (PFN_vkCmdResolveImage)(glfwGetInstanceProcAddress(NULL,"vkCmdResolveImage"));
    vkCmdSetEvent = (PFN_vkCmdSetEvent)(glfwGetInstanceProcAddress(NULL,"vkCmdSetEvent"));
    vkCmdResetEvent = (PFN_vkCmdResetEvent)(glfwGetInstanceProcAddress(NULL,"vkCmdResetEvent"));
    vkCmdWaitEvents = (PFN_vkCmdWaitEvents)(glfwGetInstanceProcAddress(NULL,"vkCmdWaitEvents"));
    vkCmdPipelineBarrier = (PFN_vkCmdPipelineBarrier)(glfwGetInstanceProcAddress(NULL,"vkCmdPipelineBarrier"));
    vkCmdBeginQuery = (PFN_vkCmdBeginQuery)(glfwGetInstanceProcAddress(NULL,"vkCmdBeginQuery"));
    vkCmdEndQuery = (PFN_vkCmdEndQuery)(glfwGetInstanceProcAddress(NULL,"vkCmdEndQuery"));
    vkCmdResetQueryPool = (PFN_vkCmdResetQueryPool)(glfwGetInstanceProcAddress(NULL,"vkCmdResetQueryPool"));
    vkCmdWriteTimestamp = (PFN_vkCmdWriteTimestamp)(glfwGetInstanceProcAddress(NULL,"vkCmdWriteTimestamp"));
    vkCmdCopyQueryPoolResults = (PFN_vkCmdCopyQueryPoolResults)(glfwGetInstanceProcAddress(NULL,"vkCmdCopyQueryPoolResults"));
    vkCmdPushConstants = (PFN_vkCmdPushConstants)(glfwGetInstanceProcAddress(NULL,"vkCmdPushConstants"));
    vkCmdBeginRenderPass = (PFN_vkCmdBeginRenderPass)(glfwGetInstanceProcAddress(NULL,"vkCmdBeginRenderPass"));
    vkCmdNextSubpass = (PFN_vkCmdNextSubpass)(glfwGetInstanceProcAddress(NULL,"vkCmdNextSubpass"));
    vkCmdEndRenderPass = (PFN_vkCmdEndRenderPass)(glfwGetInstanceProcAddress(NULL,"vkCmdEndRenderPass"));
    vkCmdExecuteCommands = (PFN_vkCmdExecuteCommands)(glfwGetInstanceProcAddress(NULL,"vkCmdExecuteCommands"));
    vkDestroySurfaceKHR = (PFN_vkDestroySurfaceKHR)(glfwGetInstanceProcAddress(NULL,"vkDestroySurfaceKHR"));
    vkGetPhysicalDeviceSurfaceSupportKHR = (PFN_vkGetPhysicalDeviceSurfaceSupportKHR)(glfwGetInstanceProcAddress(NULL,"vkGetPhysicalDeviceSurfaceSupportKHR"));
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR)(glfwGetInstanceProcAddress(NULL,"vkGetPhysicalDeviceSurfaceCapabilitiesKHR"));
    vkGetPhysicalDeviceSurfaceFormatsKHR = (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR)(glfwGetInstanceProcAddress(NULL,"vkGetPhysicalDeviceSurfaceFormatsKHR"));
    vkGetPhysicalDeviceSurfacePresentModesKHR = (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR)(glfwGetInstanceProcAddress(NULL,"vkGetPhysicalDeviceSurfacePresentModesKHR"));
    vkCreateSwapchainKHR = (PFN_vkCreateSwapchainKHR)(glfwGetInstanceProcAddress(NULL,"vkCreateSwapchainKHR"));
    vkDestroySwapchainKHR = (PFN_vkDestroySwapchainKHR)(glfwGetInstanceProcAddress(NULL,"vkDestroySwapchainKHR"));
    vkGetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR)(glfwGetInstanceProcAddress(NULL,"vkGetSwapchainImagesKHR"));
    vkAcquireNextImageKHR = (PFN_vkAcquireNextImageKHR)(glfwGetInstanceProcAddress(NULL,"vkAcquireNextImageKHR"));
    vkQueuePresentKHR = (PFN_vkQueuePresentKHR)(glfwGetInstanceProcAddress(NULL,"vkQueuePresentKHR"));
    vkGetPhysicalDeviceDisplayPropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPropertiesKHR)(glfwGetInstanceProcAddress(NULL,"vkGetPhysicalDeviceDisplayPropertiesKHR"));
    vkGetPhysicalDeviceDisplayPlanePropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR)(glfwGetInstanceProcAddress(NULL,"vkGetPhysicalDeviceDisplayPlanePropertiesKHR"));
    vkGetDisplayPlaneSupportedDisplaysKHR = (PFN_vkGetDisplayPlaneSupportedDisplaysKHR)(glfwGetInstanceProcAddress(NULL,"vkGetDisplayPlaneSupportedDisplaysKHR"));
    vkGetDisplayModePropertiesKHR = (PFN_vkGetDisplayModePropertiesKHR)(glfwGetInstanceProcAddress(NULL,"vkGetDisplayModePropertiesKHR"));
    vkCreateDisplayModeKHR = (PFN_vkCreateDisplayModeKHR)(glfwGetInstanceProcAddress(NULL,"vkCreateDisplayModeKHR"));
    vkGetDisplayPlaneCapabilitiesKHR = (PFN_vkGetDisplayPlaneCapabilitiesKHR)(glfwGetInstanceProcAddress(NULL,"vkGetDisplayPlaneCapabilitiesKHR"));
    vkCreateDisplayPlaneSurfaceKHR = (PFN_vkCreateDisplayPlaneSurfaceKHR)(glfwGetInstanceProcAddress(NULL,"vkCreateDisplayPlaneSurfaceKHR"));
    vkCreateSharedSwapchainsKHR = (PFN_vkCreateSharedSwapchainsKHR)(glfwGetInstanceProcAddress(NULL,"vkCreateSharedSwapchainsKHR"));

#ifdef VK_USE_PLATFORM_XLIB_KHR
    vkCreateXlibSurfaceKHR = (PFN_vkCreateXlibSurfaceKHR)(glfwGetInstanceProcAddress(NULL,"vkCreateXlibSurfaceKHR"));
    vkGetPhysicalDeviceXlibPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR)(glfwGetInstanceProcAddress(NULL,"vkGetPhysicalDeviceXlibPresentationSupportKHR"));
#endif

#ifdef VK_USE_PLATFORM_XCB_KHR
    vkCreateXcbSurfaceKHR = (PFN_vkCreateXcbSurfaceKHR)(glfwGetInstanceProcAddress(NULL,"vkCreateXcbSurfaceKHR"));
    vkGetPhysicalDeviceXcbPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR)(glfwGetInstanceProcAddress(NULL,"vkGetPhysicalDeviceXcbPresentationSupportKHR"));
#endif

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
    vkCreateWaylandSurfaceKHR = (PFN_vkCreateWaylandSurfaceKHR)(glfwGetInstanceProcAddress(NULL,"vkCreateWaylandSurfaceKHR"));
    vkGetPhysicalDeviceWaylandPresentationSupportKHR = (PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR)(glfwGetInstanceProcAddress(NULL,"vkGetPhysicalDeviceWaylandPresentationSupportKHR"));
#endif

#ifdef VK_USE_PLATFORM_MIR_KHR
    vkCreateMirSurfaceKHR = (PFN_vkCreateMirSurfaceKHR)(glfwGetInstanceProcAddress(NULL,"vkCreateMirSurfaceKHR"));
    vkGetPhysicalDeviceMirPresentationSupportKHR = (PFN_vkGetPhysicalDeviceMirPresentationSupportKHR)(glfwGetInstanceProcAddress(NULL,"vkGetPhysicalDeviceMirPresentationSupportKHR"));
#endif

#ifdef VK_USE_PLATFORM_ANDROID_KHR
    vkCreateAndroidSurfaceKHR = (PFN_vkCreateAndroidSurfaceKHR)(glfwGetInstanceProcAddress(NULL,"vkCreateAndroidSurfaceKHR"));
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
    vkCreateWin32SurfaceKHR = (PFN_vkCreateWin32SurfaceKHR)(glfwGetInstanceProcAddress(NULL,"vkCreateWin32SurfaceKHR"));
    vkGetPhysicalDeviceWin32PresentationSupportKHR = (PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR)(glfwGetInstanceProcAddress(NULL,"vkGetPhysicalDeviceWin32PresentationSupportKHR"));
#endif

    vkCreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT)(glfwGetInstanceProcAddress(NULL,"vkCreateDebugReportCallbackEXT"));
    vkDestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT)(glfwGetInstanceProcAddress(NULL,"vkDestroyDebugReportCallbackEXT"));
    vkDebugReportMessageEXT = (PFN_vkDebugReportMessageEXT)(glfwGetInstanceProcAddress(NULL,"vkDebugReportMessageEXT"));
    return 0;
}

PFN_vkCreateInstance vkCreateInstance;
PFN_vkDestroyInstance vkDestroyInstance;
PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices;
PFN_vkGetPhysicalDeviceFeatures vkGetPhysicalDeviceFeatures;
PFN_vkGetPhysicalDeviceFormatProperties vkGetPhysicalDeviceFormatProperties;
PFN_vkGetPhysicalDeviceImageFormatProperties vkGetPhysicalDeviceImageFormatProperties;
PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties;
PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties;
PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties;
PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;
PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr;
PFN_vkCreateDevice vkCreateDevice;
PFN_vkDestroyDevice vkDestroyDevice;
PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties;
PFN_vkEnumerateDeviceExtensionProperties vkEnumerateDeviceExtensionProperties;
PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;
PFN_vkEnumerateDeviceLayerProperties vkEnumerateDeviceLayerProperties;
PFN_vkGetDeviceQueue vkGetDeviceQueue;
PFN_vkQueueSubmit vkQueueSubmit;
PFN_vkQueueWaitIdle vkQueueWaitIdle;
PFN_vkDeviceWaitIdle vkDeviceWaitIdle;
PFN_vkAllocateMemory vkAllocateMemory;
PFN_vkFreeMemory vkFreeMemory;
PFN_vkMapMemory vkMapMemory;
PFN_vkUnmapMemory vkUnmapMemory;
PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges;
PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges;
PFN_vkGetDeviceMemoryCommitment vkGetDeviceMemoryCommitment;
PFN_vkBindBufferMemory vkBindBufferMemory;
PFN_vkBindImageMemory vkBindImageMemory;
PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements;
PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements;
PFN_vkGetImageSparseMemoryRequirements vkGetImageSparseMemoryRequirements;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties vkGetPhysicalDeviceSparseImageFormatProperties;
PFN_vkQueueBindSparse vkQueueBindSparse;
PFN_vkCreateFence vkCreateFence;
PFN_vkDestroyFence vkDestroyFence;
PFN_vkResetFences vkResetFences;
PFN_vkGetFenceStatus vkGetFenceStatus;
PFN_vkWaitForFences vkWaitForFences;
PFN_vkCreateSemaphore vkCreateSemaphore;
PFN_vkDestroySemaphore vkDestroySemaphore;
PFN_vkCreateEvent vkCreateEvent;
PFN_vkDestroyEvent vkDestroyEvent;
PFN_vkGetEventStatus vkGetEventStatus;
PFN_vkSetEvent vkSetEvent;
PFN_vkResetEvent vkResetEvent;
PFN_vkCreateQueryPool vkCreateQueryPool;
PFN_vkDestroyQueryPool vkDestroyQueryPool;
PFN_vkGetQueryPoolResults vkGetQueryPoolResults;
PFN_vkCreateBuffer vkCreateBuffer;
PFN_vkDestroyBuffer vkDestroyBuffer;
PFN_vkCreateBufferView vkCreateBufferView;
PFN_vkDestroyBufferView vkDestroyBufferView;
PFN_vkCreateImage vkCreateImage;
PFN_vkDestroyImage vkDestroyImage;
PFN_vkGetImageSubresourceLayout vkGetImageSubresourceLayout;
PFN_vkCreateImageView vkCreateImageView;
PFN_vkDestroyImageView vkDestroyImageView;
PFN_vkCreateShaderModule vkCreateShaderModule;
PFN_vkDestroyShaderModule vkDestroyShaderModule;
PFN_vkCreatePipelineCache vkCreatePipelineCache;
PFN_vkDestroyPipelineCache vkDestroyPipelineCache;
PFN_vkGetPipelineCacheData vkGetPipelineCacheData;
PFN_vkMergePipelineCaches vkMergePipelineCaches;
PFN_vkCreateGraphicsPipelines vkCreateGraphicsPipelines;
PFN_vkCreateComputePipelines vkCreateComputePipelines;
PFN_vkDestroyPipeline vkDestroyPipeline;
PFN_vkCreatePipelineLayout vkCreatePipelineLayout;
PFN_vkDestroyPipelineLayout vkDestroyPipelineLayout;
PFN_vkCreateSampler vkCreateSampler;
PFN_vkDestroySampler vkDestroySampler;
PFN_vkCreateDescriptorSetLayout vkCreateDescriptorSetLayout;
PFN_vkDestroyDescriptorSetLayout vkDestroyDescriptorSetLayout;
PFN_vkCreateDescriptorPool vkCreateDescriptorPool;
PFN_vkDestroyDescriptorPool vkDestroyDescriptorPool;
PFN_vkResetDescriptorPool vkResetDescriptorPool;
PFN_vkAllocateDescriptorSets vkAllocateDescriptorSets;
PFN_vkFreeDescriptorSets vkFreeDescriptorSets;
PFN_vkUpdateDescriptorSets vkUpdateDescriptorSets;
PFN_vkCreateFramebuffer vkCreateFramebuffer;
PFN_vkDestroyFramebuffer vkDestroyFramebuffer;
PFN_vkCreateRenderPass vkCreateRenderPass;
PFN_vkDestroyRenderPass vkDestroyRenderPass;
PFN_vkGetRenderAreaGranularity vkGetRenderAreaGranularity;
PFN_vkCreateCommandPool vkCreateCommandPool;
PFN_vkDestroyCommandPool vkDestroyCommandPool;
PFN_vkResetCommandPool vkResetCommandPool;
PFN_vkAllocateCommandBuffers vkAllocateCommandBuffers;
PFN_vkFreeCommandBuffers vkFreeCommandBuffers;
PFN_vkBeginCommandBuffer vkBeginCommandBuffer;
PFN_vkEndCommandBuffer vkEndCommandBuffer;
PFN_vkResetCommandBuffer vkResetCommandBuffer;
PFN_vkCmdBindPipeline vkCmdBindPipeline;
PFN_vkCmdSetViewport vkCmdSetViewport;
PFN_vkCmdSetScissor vkCmdSetScissor;
PFN_vkCmdSetLineWidth vkCmdSetLineWidth;
PFN_vkCmdSetDepthBias vkCmdSetDepthBias;
PFN_vkCmdSetBlendConstants vkCmdSetBlendConstants;
PFN_vkCmdSetDepthBounds vkCmdSetDepthBounds;
PFN_vkCmdSetStencilCompareMask vkCmdSetStencilCompareMask;
PFN_vkCmdSetStencilWriteMask vkCmdSetStencilWriteMask;
PFN_vkCmdSetStencilReference vkCmdSetStencilReference;
PFN_vkCmdBindDescriptorSets vkCmdBindDescriptorSets;
PFN_vkCmdBindIndexBuffer vkCmdBindIndexBuffer;
PFN_vkCmdBindVertexBuffers vkCmdBindVertexBuffers;
PFN_vkCmdDraw vkCmdDraw;
PFN_vkCmdDrawIndexed vkCmdDrawIndexed;
PFN_vkCmdDrawIndirect vkCmdDrawIndirect;
PFN_vkCmdDrawIndexedIndirect vkCmdDrawIndexedIndirect;
PFN_vkCmdDispatch vkCmdDispatch;
PFN_vkCmdDispatchIndirect vkCmdDispatchIndirect;
PFN_vkCmdCopyBuffer vkCmdCopyBuffer;
PFN_vkCmdCopyImage vkCmdCopyImage;
PFN_vkCmdBlitImage vkCmdBlitImage;
PFN_vkCmdCopyBufferToImage vkCmdCopyBufferToImage;
PFN_vkCmdCopyImageToBuffer vkCmdCopyImageToBuffer;
PFN_vkCmdUpdateBuffer vkCmdUpdateBuffer;
PFN_vkCmdFillBuffer vkCmdFillBuffer;
PFN_vkCmdClearColorImage vkCmdClearColorImage;
PFN_vkCmdClearDepthStencilImage vkCmdClearDepthStencilImage;
PFN_vkCmdClearAttachments vkCmdClearAttachments;
PFN_vkCmdResolveImage vkCmdResolveImage;
PFN_vkCmdSetEvent vkCmdSetEvent;
PFN_vkCmdResetEvent vkCmdResetEvent;
PFN_vkCmdWaitEvents vkCmdWaitEvents;
PFN_vkCmdPipelineBarrier vkCmdPipelineBarrier;
PFN_vkCmdBeginQuery vkCmdBeginQuery;
PFN_vkCmdEndQuery vkCmdEndQuery;
PFN_vkCmdResetQueryPool vkCmdResetQueryPool;
PFN_vkCmdWriteTimestamp vkCmdWriteTimestamp;
PFN_vkCmdCopyQueryPoolResults vkCmdCopyQueryPoolResults;
PFN_vkCmdPushConstants vkCmdPushConstants;
PFN_vkCmdBeginRenderPass vkCmdBeginRenderPass;
PFN_vkCmdNextSubpass vkCmdNextSubpass;
PFN_vkCmdEndRenderPass vkCmdEndRenderPass;
PFN_vkCmdExecuteCommands vkCmdExecuteCommands;
PFN_vkDestroySurfaceKHR vkDestroySurfaceKHR;
PFN_vkGetPhysicalDeviceSurfaceSupportKHR vkGetPhysicalDeviceSurfaceSupportKHR;
PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
PFN_vkGetPhysicalDeviceSurfaceFormatsKHR vkGetPhysicalDeviceSurfaceFormatsKHR;
PFN_vkGetPhysicalDeviceSurfacePresentModesKHR vkGetPhysicalDeviceSurfacePresentModesKHR;
PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR;
PFN_vkDestroySwapchainKHR vkDestroySwapchainKHR;
PFN_vkGetSwapchainImagesKHR vkGetSwapchainImagesKHR;
PFN_vkAcquireNextImageKHR vkAcquireNextImageKHR;
PFN_vkQueuePresentKHR vkQueuePresentKHR;
PFN_vkGetPhysicalDeviceDisplayPropertiesKHR vkGetPhysicalDeviceDisplayPropertiesKHR;
PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR vkGetPhysicalDeviceDisplayPlanePropertiesKHR;
PFN_vkGetDisplayPlaneSupportedDisplaysKHR vkGetDisplayPlaneSupportedDisplaysKHR;
PFN_vkGetDisplayModePropertiesKHR vkGetDisplayModePropertiesKHR;
PFN_vkCreateDisplayModeKHR vkCreateDisplayModeKHR;
PFN_vkGetDisplayPlaneCapabilitiesKHR vkGetDisplayPlaneCapabilitiesKHR;
PFN_vkCreateDisplayPlaneSurfaceKHR vkCreateDisplayPlaneSurfaceKHR;
PFN_vkCreateSharedSwapchainsKHR vkCreateSharedSwapchainsKHR;

#ifdef VK_USE_PLATFORM_XLIB_KHR
PFN_vkCreateXlibSurfaceKHR vkCreateXlibSurfaceKHR;
PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR vkGetPhysicalDeviceXlibPresentationSupportKHR;
#endif

#ifdef VK_USE_PLATFORM_XCB_KHR
PFN_vkCreateXcbSurfaceKHR vkCreateXcbSurfaceKHR;
PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR vkGetPhysicalDeviceXcbPresentationSupportKHR;
#endif

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
PFN_vkCreateWaylandSurfaceKHR vkCreateWaylandSurfaceKHR;
PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR vkGetPhysicalDeviceWaylandPresentationSupportKHR;
#endif

#ifdef VK_USE_PLATFORM_MIR_KHR
PFN_vkCreateMirSurfaceKHR vkCreateMirSurfaceKHR;
PFN_vkGetPhysicalDeviceMirPresentationSupportKHR vkGetPhysicalDeviceMirPresentationSupportKHR;
#endif

#ifdef VK_USE_PLATFORM_ANDROID_KHR
PFN_vkCreateAndroidSurfaceKHR vkCreateAndroidSurfaceKHR;
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
PFN_vkCreateWin32SurfaceKHR vkCreateWin32SurfaceKHR;
PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR vkGetPhysicalDeviceWin32PresentationSupportKHR;
#endif

PFN_vkCreateDebugReportCallbackEXT vkCreateDebugReportCallbackEXT;
PFN_vkDestroyDebugReportCallbackEXT vkDestroyDebugReportCallbackEXT;
PFN_vkDebugReportMessageEXT vkDebugReportMessageEXT;
