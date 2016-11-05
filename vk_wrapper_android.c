// +build android

#include "vk_wrapper.h"
#include <dlfcn.h>

int vkInit(void) {
    void* libvulkan = dlopen("libvulkan.so", RTLD_NOW | RTLD_LOCAL);
    if (!libvulkan) {
        return -1;
    }

    vkCreateInstance = (PFN_vkCreateInstance)(dlsym(libvulkan, "vkCreateInstance"));
    vkDestroyInstance = (PFN_vkDestroyInstance)(dlsym(libvulkan, "vkDestroyInstance"));
    vkEnumeratePhysicalDevices = (PFN_vkEnumeratePhysicalDevices)(dlsym(libvulkan, "vkEnumeratePhysicalDevices"));
    vkGetPhysicalDeviceFeatures = (PFN_vkGetPhysicalDeviceFeatures)(dlsym(libvulkan, "vkGetPhysicalDeviceFeatures"));
    vkGetPhysicalDeviceFormatProperties = (PFN_vkGetPhysicalDeviceFormatProperties)(dlsym(libvulkan, "vkGetPhysicalDeviceFormatProperties"));
    vkGetPhysicalDeviceImageFormatProperties = (PFN_vkGetPhysicalDeviceImageFormatProperties)(dlsym(libvulkan, "vkGetPhysicalDeviceImageFormatProperties"));
    vkGetPhysicalDeviceProperties = (PFN_vkGetPhysicalDeviceProperties)(dlsym(libvulkan, "vkGetPhysicalDeviceProperties"));
    vkGetPhysicalDeviceQueueFamilyProperties = (PFN_vkGetPhysicalDeviceQueueFamilyProperties)(dlsym(libvulkan, "vkGetPhysicalDeviceQueueFamilyProperties"));
    vkGetPhysicalDeviceMemoryProperties = (PFN_vkGetPhysicalDeviceMemoryProperties)(dlsym(libvulkan, "vkGetPhysicalDeviceMemoryProperties"));
    vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr)(dlsym(libvulkan, "vkGetInstanceProcAddr"));
    vkGetDeviceProcAddr = (PFN_vkGetDeviceProcAddr)(dlsym(libvulkan, "vkGetDeviceProcAddr"));
    vkCreateDevice = (PFN_vkCreateDevice)(dlsym(libvulkan, "vkCreateDevice"));
    vkDestroyDevice = (PFN_vkDestroyDevice)(dlsym(libvulkan, "vkDestroyDevice"));
    vkEnumerateInstanceExtensionProperties = (PFN_vkEnumerateInstanceExtensionProperties)(dlsym(libvulkan, "vkEnumerateInstanceExtensionProperties"));
    vkEnumerateDeviceExtensionProperties = (PFN_vkEnumerateDeviceExtensionProperties)(dlsym(libvulkan, "vkEnumerateDeviceExtensionProperties"));
    vkEnumerateInstanceLayerProperties = (PFN_vkEnumerateInstanceLayerProperties)(dlsym(libvulkan, "vkEnumerateInstanceLayerProperties"));
    vkEnumerateDeviceLayerProperties = (PFN_vkEnumerateDeviceLayerProperties)(dlsym(libvulkan, "vkEnumerateDeviceLayerProperties"));
    vkGetDeviceQueue = (PFN_vkGetDeviceQueue)(dlsym(libvulkan, "vkGetDeviceQueue"));
    vkQueueSubmit = (PFN_vkQueueSubmit)(dlsym(libvulkan, "vkQueueSubmit"));
    vkQueueWaitIdle = (PFN_vkQueueWaitIdle)(dlsym(libvulkan, "vkQueueWaitIdle"));
    vkDeviceWaitIdle = (PFN_vkDeviceWaitIdle)(dlsym(libvulkan, "vkDeviceWaitIdle"));
    vkAllocateMemory = (PFN_vkAllocateMemory)(dlsym(libvulkan, "vkAllocateMemory"));
    vkFreeMemory = (PFN_vkFreeMemory)(dlsym(libvulkan, "vkFreeMemory"));
    vkMapMemory = (PFN_vkMapMemory)(dlsym(libvulkan, "vkMapMemory"));
    vkUnmapMemory = (PFN_vkUnmapMemory)(dlsym(libvulkan, "vkUnmapMemory"));
    vkFlushMappedMemoryRanges = (PFN_vkFlushMappedMemoryRanges)(dlsym(libvulkan, "vkFlushMappedMemoryRanges"));
    vkInvalidateMappedMemoryRanges = (PFN_vkInvalidateMappedMemoryRanges)(dlsym(libvulkan, "vkInvalidateMappedMemoryRanges"));
    vkGetDeviceMemoryCommitment = (PFN_vkGetDeviceMemoryCommitment)(dlsym(libvulkan, "vkGetDeviceMemoryCommitment"));
    vkBindBufferMemory = (PFN_vkBindBufferMemory)(dlsym(libvulkan, "vkBindBufferMemory"));
    vkBindImageMemory = (PFN_vkBindImageMemory)(dlsym(libvulkan, "vkBindImageMemory"));
    vkGetBufferMemoryRequirements = (PFN_vkGetBufferMemoryRequirements)(dlsym(libvulkan, "vkGetBufferMemoryRequirements"));
    vkGetImageMemoryRequirements = (PFN_vkGetImageMemoryRequirements)(dlsym(libvulkan, "vkGetImageMemoryRequirements"));
    vkGetImageSparseMemoryRequirements = (PFN_vkGetImageSparseMemoryRequirements)(dlsym(libvulkan, "vkGetImageSparseMemoryRequirements"));
    vkGetPhysicalDeviceSparseImageFormatProperties = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties)(dlsym(libvulkan, "vkGetPhysicalDeviceSparseImageFormatProperties"));
    vkQueueBindSparse = (PFN_vkQueueBindSparse)(dlsym(libvulkan, "vkQueueBindSparse"));
    vkCreateFence = (PFN_vkCreateFence)(dlsym(libvulkan, "vkCreateFence"));
    vkDestroyFence = (PFN_vkDestroyFence)(dlsym(libvulkan, "vkDestroyFence"));
    vkResetFences = (PFN_vkResetFences)(dlsym(libvulkan, "vkResetFences"));
    vkGetFenceStatus = (PFN_vkGetFenceStatus)(dlsym(libvulkan, "vkGetFenceStatus"));
    vkWaitForFences = (PFN_vkWaitForFences)(dlsym(libvulkan, "vkWaitForFences"));
    vkCreateSemaphore = (PFN_vkCreateSemaphore)(dlsym(libvulkan, "vkCreateSemaphore"));
    vkDestroySemaphore = (PFN_vkDestroySemaphore)(dlsym(libvulkan, "vkDestroySemaphore"));
    vkCreateEvent = (PFN_vkCreateEvent)(dlsym(libvulkan, "vkCreateEvent"));
    vkDestroyEvent = (PFN_vkDestroyEvent)(dlsym(libvulkan, "vkDestroyEvent"));
    vkGetEventStatus = (PFN_vkGetEventStatus)(dlsym(libvulkan, "vkGetEventStatus"));
    vkSetEvent = (PFN_vkSetEvent)(dlsym(libvulkan, "vkSetEvent"));
    vkResetEvent = (PFN_vkResetEvent)(dlsym(libvulkan, "vkResetEvent"));
    vkCreateQueryPool = (PFN_vkCreateQueryPool)(dlsym(libvulkan, "vkCreateQueryPool"));
    vkDestroyQueryPool = (PFN_vkDestroyQueryPool)(dlsym(libvulkan, "vkDestroyQueryPool"));
    vkGetQueryPoolResults = (PFN_vkGetQueryPoolResults)(dlsym(libvulkan, "vkGetQueryPoolResults"));
    vkCreateBuffer = (PFN_vkCreateBuffer)(dlsym(libvulkan, "vkCreateBuffer"));
    vkDestroyBuffer = (PFN_vkDestroyBuffer)(dlsym(libvulkan, "vkDestroyBuffer"));
    vkCreateBufferView = (PFN_vkCreateBufferView)(dlsym(libvulkan, "vkCreateBufferView"));
    vkDestroyBufferView = (PFN_vkDestroyBufferView)(dlsym(libvulkan, "vkDestroyBufferView"));
    vkCreateImage = (PFN_vkCreateImage)(dlsym(libvulkan, "vkCreateImage"));
    vkDestroyImage = (PFN_vkDestroyImage)(dlsym(libvulkan, "vkDestroyImage"));
    vkGetImageSubresourceLayout = (PFN_vkGetImageSubresourceLayout)(dlsym(libvulkan, "vkGetImageSubresourceLayout"));
    vkCreateImageView = (PFN_vkCreateImageView)(dlsym(libvulkan, "vkCreateImageView"));
    vkDestroyImageView = (PFN_vkDestroyImageView)(dlsym(libvulkan, "vkDestroyImageView"));
    vkCreateShaderModule = (PFN_vkCreateShaderModule)(dlsym(libvulkan, "vkCreateShaderModule"));
    vkDestroyShaderModule = (PFN_vkDestroyShaderModule)(dlsym(libvulkan, "vkDestroyShaderModule"));
    vkCreatePipelineCache = (PFN_vkCreatePipelineCache)(dlsym(libvulkan, "vkCreatePipelineCache"));
    vkDestroyPipelineCache = (PFN_vkDestroyPipelineCache)(dlsym(libvulkan, "vkDestroyPipelineCache"));
    vkGetPipelineCacheData = (PFN_vkGetPipelineCacheData)(dlsym(libvulkan, "vkGetPipelineCacheData"));
    vkMergePipelineCaches = (PFN_vkMergePipelineCaches)(dlsym(libvulkan, "vkMergePipelineCaches"));
    vkCreateGraphicsPipelines = (PFN_vkCreateGraphicsPipelines)(dlsym(libvulkan, "vkCreateGraphicsPipelines"));
    vkCreateComputePipelines = (PFN_vkCreateComputePipelines)(dlsym(libvulkan, "vkCreateComputePipelines"));
    vkDestroyPipeline = (PFN_vkDestroyPipeline)(dlsym(libvulkan, "vkDestroyPipeline"));
    vkCreatePipelineLayout = (PFN_vkCreatePipelineLayout)(dlsym(libvulkan, "vkCreatePipelineLayout"));
    vkDestroyPipelineLayout = (PFN_vkDestroyPipelineLayout)(dlsym(libvulkan, "vkDestroyPipelineLayout"));
    vkCreateSampler = (PFN_vkCreateSampler)(dlsym(libvulkan, "vkCreateSampler"));
    vkDestroySampler = (PFN_vkDestroySampler)(dlsym(libvulkan, "vkDestroySampler"));
    vkCreateDescriptorSetLayout = (PFN_vkCreateDescriptorSetLayout)(dlsym(libvulkan, "vkCreateDescriptorSetLayout"));
    vkDestroyDescriptorSetLayout = (PFN_vkDestroyDescriptorSetLayout)(dlsym(libvulkan, "vkDestroyDescriptorSetLayout"));
    vkCreateDescriptorPool = (PFN_vkCreateDescriptorPool)(dlsym(libvulkan, "vkCreateDescriptorPool"));
    vkDestroyDescriptorPool = (PFN_vkDestroyDescriptorPool)(dlsym(libvulkan, "vkDestroyDescriptorPool"));
    vkResetDescriptorPool = (PFN_vkResetDescriptorPool)(dlsym(libvulkan, "vkResetDescriptorPool"));
    vkAllocateDescriptorSets = (PFN_vkAllocateDescriptorSets)(dlsym(libvulkan, "vkAllocateDescriptorSets"));
    vkFreeDescriptorSets = (PFN_vkFreeDescriptorSets)(dlsym(libvulkan, "vkFreeDescriptorSets"));
    vkUpdateDescriptorSets = (PFN_vkUpdateDescriptorSets)(dlsym(libvulkan, "vkUpdateDescriptorSets"));
    vkCreateFramebuffer = (PFN_vkCreateFramebuffer)(dlsym(libvulkan, "vkCreateFramebuffer"));
    vkDestroyFramebuffer = (PFN_vkDestroyFramebuffer)(dlsym(libvulkan, "vkDestroyFramebuffer"));
    vkCreateRenderPass = (PFN_vkCreateRenderPass)(dlsym(libvulkan, "vkCreateRenderPass"));
    vkDestroyRenderPass = (PFN_vkDestroyRenderPass)(dlsym(libvulkan, "vkDestroyRenderPass"));
    vkGetRenderAreaGranularity = (PFN_vkGetRenderAreaGranularity)(dlsym(libvulkan, "vkGetRenderAreaGranularity"));
    vkCreateCommandPool = (PFN_vkCreateCommandPool)(dlsym(libvulkan, "vkCreateCommandPool"));
    vkDestroyCommandPool = (PFN_vkDestroyCommandPool)(dlsym(libvulkan, "vkDestroyCommandPool"));
    vkResetCommandPool = (PFN_vkResetCommandPool)(dlsym(libvulkan, "vkResetCommandPool"));
    vkAllocateCommandBuffers = (PFN_vkAllocateCommandBuffers)(dlsym(libvulkan, "vkAllocateCommandBuffers"));
    vkFreeCommandBuffers = (PFN_vkFreeCommandBuffers)(dlsym(libvulkan, "vkFreeCommandBuffers"));
    vkBeginCommandBuffer = (PFN_vkBeginCommandBuffer)(dlsym(libvulkan, "vkBeginCommandBuffer"));
    vkEndCommandBuffer = (PFN_vkEndCommandBuffer)(dlsym(libvulkan, "vkEndCommandBuffer"));
    vkResetCommandBuffer = (PFN_vkResetCommandBuffer)(dlsym(libvulkan, "vkResetCommandBuffer"));
    vkCmdBindPipeline = (PFN_vkCmdBindPipeline)(dlsym(libvulkan, "vkCmdBindPipeline"));
    vkCmdSetViewport = (PFN_vkCmdSetViewport)(dlsym(libvulkan, "vkCmdSetViewport"));
    vkCmdSetScissor = (PFN_vkCmdSetScissor)(dlsym(libvulkan, "vkCmdSetScissor"));
    vkCmdSetLineWidth = (PFN_vkCmdSetLineWidth)(dlsym(libvulkan, "vkCmdSetLineWidth"));
    vkCmdSetDepthBias = (PFN_vkCmdSetDepthBias)(dlsym(libvulkan, "vkCmdSetDepthBias"));
    vkCmdSetBlendConstants = (PFN_vkCmdSetBlendConstants)(dlsym(libvulkan, "vkCmdSetBlendConstants"));
    vkCmdSetDepthBounds = (PFN_vkCmdSetDepthBounds)(dlsym(libvulkan, "vkCmdSetDepthBounds"));
    vkCmdSetStencilCompareMask = (PFN_vkCmdSetStencilCompareMask)(dlsym(libvulkan, "vkCmdSetStencilCompareMask"));
    vkCmdSetStencilWriteMask = (PFN_vkCmdSetStencilWriteMask)(dlsym(libvulkan, "vkCmdSetStencilWriteMask"));
    vkCmdSetStencilReference = (PFN_vkCmdSetStencilReference)(dlsym(libvulkan, "vkCmdSetStencilReference"));
    vkCmdBindDescriptorSets = (PFN_vkCmdBindDescriptorSets)(dlsym(libvulkan, "vkCmdBindDescriptorSets"));
    vkCmdBindIndexBuffer = (PFN_vkCmdBindIndexBuffer)(dlsym(libvulkan, "vkCmdBindIndexBuffer"));
    vkCmdBindVertexBuffers = (PFN_vkCmdBindVertexBuffers)(dlsym(libvulkan, "vkCmdBindVertexBuffers"));
    vkCmdDraw = (PFN_vkCmdDraw)(dlsym(libvulkan, "vkCmdDraw"));
    vkCmdDrawIndexed = (PFN_vkCmdDrawIndexed)(dlsym(libvulkan, "vkCmdDrawIndexed"));
    vkCmdDrawIndirect = (PFN_vkCmdDrawIndirect)(dlsym(libvulkan, "vkCmdDrawIndirect"));
    vkCmdDrawIndexedIndirect = (PFN_vkCmdDrawIndexedIndirect)(dlsym(libvulkan, "vkCmdDrawIndexedIndirect"));
    vkCmdDispatch = (PFN_vkCmdDispatch)(dlsym(libvulkan, "vkCmdDispatch"));
    vkCmdDispatchIndirect = (PFN_vkCmdDispatchIndirect)(dlsym(libvulkan, "vkCmdDispatchIndirect"));
    vkCmdCopyBuffer = (PFN_vkCmdCopyBuffer)(dlsym(libvulkan, "vkCmdCopyBuffer"));
    vkCmdCopyImage = (PFN_vkCmdCopyImage)(dlsym(libvulkan, "vkCmdCopyImage"));
    vkCmdBlitImage = (PFN_vkCmdBlitImage)(dlsym(libvulkan, "vkCmdBlitImage"));
    vkCmdCopyBufferToImage = (PFN_vkCmdCopyBufferToImage)(dlsym(libvulkan, "vkCmdCopyBufferToImage"));
    vkCmdCopyImageToBuffer = (PFN_vkCmdCopyImageToBuffer)(dlsym(libvulkan, "vkCmdCopyImageToBuffer"));
    vkCmdUpdateBuffer = (PFN_vkCmdUpdateBuffer)(dlsym(libvulkan, "vkCmdUpdateBuffer"));
    vkCmdFillBuffer = (PFN_vkCmdFillBuffer)(dlsym(libvulkan, "vkCmdFillBuffer"));
    vkCmdClearColorImage = (PFN_vkCmdClearColorImage)(dlsym(libvulkan, "vkCmdClearColorImage"));
    vkCmdClearDepthStencilImage = (PFN_vkCmdClearDepthStencilImage)(dlsym(libvulkan, "vkCmdClearDepthStencilImage"));
    vkCmdClearAttachments = (PFN_vkCmdClearAttachments)(dlsym(libvulkan, "vkCmdClearAttachments"));
    vkCmdResolveImage = (PFN_vkCmdResolveImage)(dlsym(libvulkan, "vkCmdResolveImage"));
    vkCmdSetEvent = (PFN_vkCmdSetEvent)(dlsym(libvulkan, "vkCmdSetEvent"));
    vkCmdResetEvent = (PFN_vkCmdResetEvent)(dlsym(libvulkan, "vkCmdResetEvent"));
    vkCmdWaitEvents = (PFN_vkCmdWaitEvents)(dlsym(libvulkan, "vkCmdWaitEvents"));
    vkCmdPipelineBarrier = (PFN_vkCmdPipelineBarrier)(dlsym(libvulkan, "vkCmdPipelineBarrier"));
    vkCmdBeginQuery = (PFN_vkCmdBeginQuery)(dlsym(libvulkan, "vkCmdBeginQuery"));
    vkCmdEndQuery = (PFN_vkCmdEndQuery)(dlsym(libvulkan, "vkCmdEndQuery"));
    vkCmdResetQueryPool = (PFN_vkCmdResetQueryPool)(dlsym(libvulkan, "vkCmdResetQueryPool"));
    vkCmdWriteTimestamp = (PFN_vkCmdWriteTimestamp)(dlsym(libvulkan, "vkCmdWriteTimestamp"));
    vkCmdCopyQueryPoolResults = (PFN_vkCmdCopyQueryPoolResults)(dlsym(libvulkan, "vkCmdCopyQueryPoolResults"));
    vkCmdPushConstants = (PFN_vkCmdPushConstants)(dlsym(libvulkan, "vkCmdPushConstants"));
    vkCmdBeginRenderPass = (PFN_vkCmdBeginRenderPass)(dlsym(libvulkan, "vkCmdBeginRenderPass"));
    vkCmdNextSubpass = (PFN_vkCmdNextSubpass)(dlsym(libvulkan, "vkCmdNextSubpass"));
    vkCmdEndRenderPass = (PFN_vkCmdEndRenderPass)(dlsym(libvulkan, "vkCmdEndRenderPass"));
    vkCmdExecuteCommands = (PFN_vkCmdExecuteCommands)(dlsym(libvulkan, "vkCmdExecuteCommands"));
    vkDestroySurfaceKHR = (PFN_vkDestroySurfaceKHR)(dlsym(libvulkan, "vkDestroySurfaceKHR"));
    vkGetPhysicalDeviceSurfaceSupportKHR = (PFN_vkGetPhysicalDeviceSurfaceSupportKHR)(dlsym(libvulkan, "vkGetPhysicalDeviceSurfaceSupportKHR"));
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR)(dlsym(libvulkan, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR"));
    vkGetPhysicalDeviceSurfaceFormatsKHR = (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR)(dlsym(libvulkan, "vkGetPhysicalDeviceSurfaceFormatsKHR"));
    vkGetPhysicalDeviceSurfacePresentModesKHR = (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR)(dlsym(libvulkan, "vkGetPhysicalDeviceSurfacePresentModesKHR"));
    vkCreateSwapchainKHR = (PFN_vkCreateSwapchainKHR)(dlsym(libvulkan, "vkCreateSwapchainKHR"));
    vkDestroySwapchainKHR = (PFN_vkDestroySwapchainKHR)(dlsym(libvulkan, "vkDestroySwapchainKHR"));
    vkGetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR)(dlsym(libvulkan, "vkGetSwapchainImagesKHR"));
    vkAcquireNextImageKHR = (PFN_vkAcquireNextImageKHR)(dlsym(libvulkan, "vkAcquireNextImageKHR"));
    vkQueuePresentKHR = (PFN_vkQueuePresentKHR)(dlsym(libvulkan, "vkQueuePresentKHR"));
    vkGetPhysicalDeviceDisplayPropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPropertiesKHR)(dlsym(libvulkan, "vkGetPhysicalDeviceDisplayPropertiesKHR"));
    vkGetPhysicalDeviceDisplayPlanePropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR)(dlsym(libvulkan, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR"));
    vkGetDisplayPlaneSupportedDisplaysKHR = (PFN_vkGetDisplayPlaneSupportedDisplaysKHR)(dlsym(libvulkan, "vkGetDisplayPlaneSupportedDisplaysKHR"));
    vkGetDisplayModePropertiesKHR = (PFN_vkGetDisplayModePropertiesKHR)(dlsym(libvulkan, "vkGetDisplayModePropertiesKHR"));
    vkCreateDisplayModeKHR = (PFN_vkCreateDisplayModeKHR)(dlsym(libvulkan, "vkCreateDisplayModeKHR"));
    vkGetDisplayPlaneCapabilitiesKHR = (PFN_vkGetDisplayPlaneCapabilitiesKHR)(dlsym(libvulkan, "vkGetDisplayPlaneCapabilitiesKHR"));
    vkCreateDisplayPlaneSurfaceKHR = (PFN_vkCreateDisplayPlaneSurfaceKHR)(dlsym(libvulkan, "vkCreateDisplayPlaneSurfaceKHR"));
    vkCreateSharedSwapchainsKHR = (PFN_vkCreateSharedSwapchainsKHR)(dlsym(libvulkan, "vkCreateSharedSwapchainsKHR"));

#ifdef VK_USE_PLATFORM_XLIB_KHR
    vkCreateXlibSurfaceKHR = (PFN_vkCreateXlibSurfaceKHR)(dlsym(libvulkan, "vkCreateXlibSurfaceKHR"));
    vkGetPhysicalDeviceXlibPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR)(dlsym(libvulkan, "vkGetPhysicalDeviceXlibPresentationSupportKHR"));
#endif

#ifdef VK_USE_PLATFORM_XCB_KHR
    vkCreateXcbSurfaceKHR = (PFN_vkCreateXcbSurfaceKHR)(dlsym(libvulkan, "vkCreateXcbSurfaceKHR"));
    vkGetPhysicalDeviceXcbPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR)(dlsym(libvulkan, "vkGetPhysicalDeviceXcbPresentationSupportKHR"));
#endif

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
    vkCreateWaylandSurfaceKHR = (PFN_vkCreateWaylandSurfaceKHR)(dlsym(libvulkan, "vkCreateWaylandSurfaceKHR"));
    vkGetPhysicalDeviceWaylandPresentationSupportKHR = (PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR)(dlsym(libvulkan, "vkGetPhysicalDeviceWaylandPresentationSupportKHR"));
#endif

#ifdef VK_USE_PLATFORM_MIR_KHR
    vkCreateMirSurfaceKHR = (PFN_vkCreateMirSurfaceKHR)(dlsym(libvulkan, "vkCreateMirSurfaceKHR"));
    vkGetPhysicalDeviceMirPresentationSupportKHR = (PFN_vkGetPhysicalDeviceMirPresentationSupportKHR)(dlsym(libvulkan, "vkGetPhysicalDeviceMirPresentationSupportKHR"));
#endif

#ifdef VK_USE_PLATFORM_ANDROID_KHR
    vkCreateAndroidSurfaceKHR = (PFN_vkCreateAndroidSurfaceKHR)(dlsym(libvulkan, "vkCreateAndroidSurfaceKHR"));
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
    vkCreateWin32SurfaceKHR = (PFN_vkCreateWin32SurfaceKHR)(dlsym(libvulkan, "vkCreateWin32SurfaceKHR"));
    vkGetPhysicalDeviceWin32PresentationSupportKHR = (PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR)(dlsym(libvulkan, "vkGetPhysicalDeviceWin32PresentationSupportKHR"));
#endif

    vkCreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT)(dlsym(libvulkan, "vkCreateDebugReportCallbackEXT"));
    vkDestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT)(dlsym(libvulkan, "vkDestroyDebugReportCallbackEXT"));
    vkDebugReportMessageEXT = (PFN_vkDebugReportMessageEXT)(dlsym(libvulkan, "vkDebugReportMessageEXT"));
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
