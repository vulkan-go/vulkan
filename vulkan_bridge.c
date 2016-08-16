#include "vulkan_wrapper.h"
#include "vulkan_bridge.h"

VkResult callVkCreateInstance(
    const VkInstanceCreateInfo*                 pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkInstance*                                 pInstance) {
    return vkCreateInstance(pCreateInfo, pAllocator, pInstance);
}

void callVkDestroyInstance(
    VkInstance                                  instance,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroyInstance(instance, pAllocator);
}

VkResult callVkEnumeratePhysicalDevices(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceCount,
    VkPhysicalDevice*                           pPhysicalDevices) {
    return vkEnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);
}

void callVkGetPhysicalDeviceFeatures(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures*                   pFeatures) {
    vkGetPhysicalDeviceFeatures(physicalDevice, pFeatures);
}

void callVkGetPhysicalDeviceFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties*                         pFormatProperties) {
    vkGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
}

VkResult callVkGetPhysicalDeviceImageFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkImageFormatProperties*                    pImageFormatProperties) {
    return vkGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type,
            tiling, usage, flags, pImageFormatProperties);
}

void callVkGetPhysicalDeviceProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties*                 pProperties) {
    vkGetPhysicalDeviceProperties(physicalDevice, pProperties);
}

void callVkGetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties*                    pQueueFamilyProperties) {
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice,
            pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

void callVkGetPhysicalDeviceMemoryProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties*           pMemoryProperties) {
    vkGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
}

VkResult callVkCreateDevice(
    VkPhysicalDevice                            physicalDevice,
    const VkDeviceCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDevice*                                   pDevice) {
    return vkCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);
}

void callVkDestroyDevice(
    VkDevice                                    device,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroyDevice(device, pAllocator);
}

VkResult callVkEnumerateInstanceExtensionProperties(
    const char*                                 pLayerName,
    uint32_t*                                   pPropertyCount,
    VkExtensionProperties*                      pProperties) {
    return vkEnumerateInstanceExtensionProperties(pLayerName, pPropertyCount, pProperties);
}

VkResult callVkEnumerateDeviceExtensionProperties(
    VkPhysicalDevice                            physicalDevice,
    const char*                                 pLayerName,
    uint32_t*                                   pPropertyCount,
    VkExtensionProperties*                      pProperties) {
    return vkEnumerateDeviceExtensionProperties(physicalDevice, pLayerName,
            pPropertyCount, pProperties);
}

VkResult callVkEnumerateInstanceLayerProperties(
    uint32_t*                                   pPropertyCount,
    VkLayerProperties*                          pProperties) {
    return vkEnumerateInstanceLayerProperties(pPropertyCount, pProperties);
}

VkResult callVkEnumerateDeviceLayerProperties(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkLayerProperties*                          pProperties) {
    return vkEnumerateDeviceLayerProperties(physicalDevice, pPropertyCount, pProperties);
}

void callVkGetDeviceQueue(
    VkDevice                                    device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    VkQueue*                                    pQueue) {
    vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
}

VkResult callVkQueueSubmit(
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo*                         pSubmits,
    VkFence                                     fence) {
    return vkQueueSubmit(queue, submitCount, pSubmits, fence);
}

VkResult callVkQueueWaitIdle(
    VkQueue                                     queue) {
    return vkQueueWaitIdle(queue);
}

VkResult callVkDeviceWaitIdle(
    VkDevice                                    device) {
    return vkDeviceWaitIdle(device);
}

VkResult callVkAllocateMemory(
    VkDevice                                    device,
    const VkMemoryAllocateInfo*                 pAllocateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDeviceMemory*                             pMemory) {
    return vkAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
}

void callVkFreeMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    const VkAllocationCallbacks*                pAllocator) {
    vkFreeMemory(device, memory, pAllocator);
}

VkResult callVkMapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    void**                                      ppData) {
    return vkMapMemory(device, memory, offset, size, flags, ppData);
}

void callVkUnmapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory) {
    vkUnmapMemory(device, memory);
}

VkResult callVkFlushMappedMemoryRanges(
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges) {
    return vkFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
}

VkResult callVkInvalidateMappedMemoryRanges(
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges) {
    return vkInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
}

void callVkGetDeviceMemoryCommitment(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize*                               pCommittedMemoryInBytes) {
    vkGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
}

VkResult callVkBindBufferMemory(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset) {
    return vkBindBufferMemory(device, buffer, memory, memoryOffset);
}

VkResult callVkBindImageMemory(
    VkDevice                                    device,
    VkImage                                     image,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset) {
    return vkBindImageMemory(device, image, memory, memoryOffset);
}

void callVkGetBufferMemoryRequirements(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkMemoryRequirements*                       pMemoryRequirements) {
    vkGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
}

void callVkGetImageMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    VkMemoryRequirements*                       pMemoryRequirements) {
    vkGetImageMemoryRequirements(device, image, pMemoryRequirements);
}

void callVkGetImageSparseMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements*            pSparseMemoryRequirements) {
    vkGetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount,
                                       pSparseMemoryRequirements);
}

void callVkGetPhysicalDeviceSparseImageFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkSampleCountFlagBits                       samples,
    VkImageUsageFlags                           usage,
    VkImageTiling                               tiling,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties*              pProperties) {
    vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format,
            type, samples, usage, tiling, pPropertyCount, pProperties);
}

VkResult callVkQueueBindSparse(
    VkQueue                                     queue,
    uint32_t                                    bindInfoCount,
    const VkBindSparseInfo*                     pBindInfo,
    VkFence                                     fence) {
    return vkQueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
}

VkResult callVkCreateFence(
    VkDevice                                    device,
    const VkFenceCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence) {
    return vkCreateFence(device, pCreateInfo, pAllocator, pFence);
}

void callVkDestroyFence(
    VkDevice                                    device,
    VkFence                                     fence,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroyFence(device, fence, pAllocator);
}

VkResult callVkResetFences(
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences) {
    return vkResetFences(device, fenceCount, pFences);
}

VkResult callVkGetFenceStatus(
    VkDevice                                    device,
    VkFence                                     fence) {
    return vkGetFenceStatus(device, fence);
}

VkResult callVkWaitForFences(
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout) {
    return vkWaitForFences(device, fenceCount, pFences, waitAll, timeout);
}

VkResult callVkCreateSemaphore(
    VkDevice                                    device,
    const VkSemaphoreCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSemaphore*                                pSemaphore) {
    return vkCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
}

void callVkDestroySemaphore(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroySemaphore(device, semaphore, pAllocator);
}

VkResult callVkCreateEvent(
    VkDevice                                    device,
    const VkEventCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkEvent*                                    pEvent) {
    return vkCreateEvent(device, pCreateInfo, pAllocator, pEvent);
}

void callVkDestroyEvent(
    VkDevice                                    device,
    VkEvent                                     event,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroyEvent(device, event, pAllocator);
}

VkResult callVkGetEventStatus(
    VkDevice                                    device,
    VkEvent                                     event) {
    return vkGetEventStatus(device, event);
}

VkResult callVkSetEvent(
    VkDevice                                    device,
    VkEvent                                     event) {
    return vkSetEvent(device, event);
}

VkResult callVkResetEvent(
    VkDevice                                    device,
    VkEvent                                     event) {
    return vkResetEvent(device, event);
}

VkResult callVkCreateQueryPool(
    VkDevice                                    device,
    const VkQueryPoolCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkQueryPool*                                pQueryPool) {
    return vkCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
}

void callVkDestroyQueryPool(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroyQueryPool(device, queryPool, pAllocator);
}

VkResult callVkGetQueryPoolResults(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    size_t                                      dataSize,
    void*                                       pData,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags) {
    return vkGetQueryPoolResults(device, queryPool, firstQuery, queryCount,
                                 dataSize, pData, stride, flags);
}

VkResult callVkCreateBuffer(
    VkDevice                                    device,
    const VkBufferCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBuffer*                                   pBuffer) {
    return vkCreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
}

void callVkDestroyBuffer(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroyBuffer(device, buffer, pAllocator);
}

VkResult callVkCreateBufferView(
    VkDevice                                    device,
    const VkBufferViewCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBufferView*                               pView) {
    return vkCreateBufferView(device, pCreateInfo, pAllocator, pView);
}

void callVkDestroyBufferView(
    VkDevice                                    device,
    VkBufferView                                bufferView,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroyBufferView(device, bufferView, pAllocator);
}

VkResult callVkCreateImage(
    VkDevice                                    device,
    const VkImageCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImage*                                    pImage) {
    return vkCreateImage(device, pCreateInfo, pAllocator, pImage);
}

void callVkDestroyImage(
    VkDevice                                    device,
    VkImage                                     image,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroyImage(device, image, pAllocator);
}

void callVkGetImageSubresourceLayout(
    VkDevice                                    device,
    VkImage                                     image,
    const VkImageSubresource*                   pSubresource,
    VkSubresourceLayout*                        pLayout) {
    vkGetImageSubresourceLayout(device, image, pSubresource, pLayout);
}

VkResult callVkCreateImageView(
    VkDevice                                    device,
    const VkImageViewCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImageView*                                pView) {
    return vkCreateImageView(device, pCreateInfo, pAllocator, pView);
}

void callVkDestroyImageView(
    VkDevice                                    device,
    VkImageView                                 imageView,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroyImageView(device, imageView, pAllocator);
}

VkResult callVkCreateShaderModule(
    VkDevice                                    device,
    const VkShaderModuleCreateInfo*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkShaderModule*                             pShaderModule) {
    return vkCreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);
}

void callVkDestroyShaderModule(
    VkDevice                                    device,
    VkShaderModule                              shaderModule,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroyShaderModule(device, shaderModule, pAllocator);
}

VkResult callVkCreatePipelineCache(
    VkDevice                                    device,
    const VkPipelineCacheCreateInfo*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineCache*                            pPipelineCache) {
    return vkCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
}

void callVkDestroyPipelineCache(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroyPipelineCache(device, pipelineCache, pAllocator);
}

VkResult callVkGetPipelineCacheData(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    size_t*                                     pDataSize,
    void*                                       pData) {
    return vkGetPipelineCacheData(device, pipelineCache, pDataSize, pData);
}

VkResult callVkMergePipelineCaches(
    VkDevice                                    device,
    VkPipelineCache                             dstCache,
    uint32_t                                    srcCacheCount,
    const VkPipelineCache*                      pSrcCaches) {
    return vkMergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);
}

VkResult callVkCreateGraphicsPipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkGraphicsPipelineCreateInfo*         pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines) {
    return vkCreateGraphicsPipelines(device, pipelineCache, createInfoCount,
                                     pCreateInfos, pAllocator, pPipelines);
}

VkResult callVkCreateComputePipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkComputePipelineCreateInfo*          pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines) {
    return vkCreateComputePipelines(device, pipelineCache, createInfoCount,
                                    pCreateInfos, pAllocator, pPipelines);
}

void callVkDestroyPipeline(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroyPipeline(device, pipeline, pAllocator);
}

VkResult callVkCreatePipelineLayout(
    VkDevice                                    device,
    const VkPipelineLayoutCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineLayout*                           pPipelineLayout) {
    return vkCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);
}

void callVkDestroyPipelineLayout(
    VkDevice                                    device,
    VkPipelineLayout                            pipelineLayout,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroyPipelineLayout(device, pipelineLayout, pAllocator);
}

VkResult callVkCreateSampler(
    VkDevice                                    device,
    const VkSamplerCreateInfo*                  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSampler*                                  pSampler) {
    return vkCreateSampler(device, pCreateInfo, pAllocator, pSampler);
}

void callVkDestroySampler(
    VkDevice                                    device,
    VkSampler                                   sampler,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroySampler(device, sampler, pAllocator);
}

VkResult callVkCreateDescriptorSetLayout(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorSetLayout*                      pSetLayout) {
    return vkCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
}

void callVkDestroyDescriptorSetLayout(
    VkDevice                                    device,
    VkDescriptorSetLayout                       descriptorSetLayout,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
}

VkResult callVkCreateDescriptorPool(
    VkDevice                                    device,
    const VkDescriptorPoolCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorPool*                           pDescriptorPool) {
    return vkCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
}

void callVkDestroyDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroyDescriptorPool(device, descriptorPool, pAllocator);
}

VkResult callVkResetDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags) {
    return vkResetDescriptorPool(device, descriptorPool, flags);
}

VkResult callVkAllocateDescriptorSets(
    VkDevice                                    device,
    const VkDescriptorSetAllocateInfo*          pAllocateInfo,
    VkDescriptorSet*                            pDescriptorSets) {
    return vkAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
}

VkResult callVkFreeDescriptorSets(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets) {
    return vkFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
}

void callVkUpdateDescriptorSets(
    VkDevice                                    device,
    uint32_t                                    descriptorWriteCount,
    const VkWriteDescriptorSet*                 pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    const VkCopyDescriptorSet*                  pDescriptorCopies) {
    vkUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites,
                           descriptorCopyCount, pDescriptorCopies);
}

VkResult callVkCreateFramebuffer(
    VkDevice                                    device,
    const VkFramebufferCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFramebuffer*                              pFramebuffer) {
    return vkCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
}

void callVkDestroyFramebuffer(
    VkDevice                                    device,
    VkFramebuffer                               framebuffer,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroyFramebuffer(device, framebuffer, pAllocator);
}

VkResult callVkCreateRenderPass(
    VkDevice                                    device,
    const VkRenderPassCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass) {
    return vkCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
}

void callVkDestroyRenderPass(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroyRenderPass(device, renderPass, pAllocator);
}

void callVkGetRenderAreaGranularity(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    VkExtent2D*                                 pGranularity) {
    vkGetRenderAreaGranularity(device, renderPass, pGranularity);
}

VkResult callVkCreateCommandPool(
    VkDevice                                    device,
    const VkCommandPoolCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkCommandPool*                              pCommandPool) {
    return vkCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
}

void callVkDestroyCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroyCommandPool(device, commandPool, pAllocator);
}

VkResult callVkResetCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolResetFlags                     flags) {
    return vkResetCommandPool(device, commandPool, flags);
}

VkResult callVkAllocateCommandBuffers(
    VkDevice                                    device,
    const VkCommandBufferAllocateInfo*          pAllocateInfo,
    VkCommandBuffer*                            pCommandBuffers) {
    return vkAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
}

void callVkFreeCommandBuffers(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers) {
    vkFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
}

VkResult callVkBeginCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    const VkCommandBufferBeginInfo*             pBeginInfo) {
    return vkBeginCommandBuffer(commandBuffer, pBeginInfo);
}

VkResult callVkEndCommandBuffer(
    VkCommandBuffer                             commandBuffer) {
    return vkEndCommandBuffer(commandBuffer);
}

VkResult callVkResetCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    VkCommandBufferResetFlags                   flags) {
    return vkResetCommandBuffer(commandBuffer, flags);
}

void callVkCmdBindPipeline(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline) {
    vkCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
}

void callVkCmdSetViewport(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) {
    vkCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
}

void callVkCmdSetScissor(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) {
    vkCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
}

void callVkCmdSetLineWidth(
    VkCommandBuffer                             commandBuffer,
    float                                       lineWidth) {
    vkCmdSetLineWidth(commandBuffer, lineWidth);
}

void callVkCmdSetDepthBias(
    VkCommandBuffer                             commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor) {
    vkCmdSetDepthBias(commandBuffer, depthBiasConstantFactor,
                      depthBiasClamp, depthBiasSlopeFactor);
}

void callVkCmdSetBlendConstants(
    VkCommandBuffer                             commandBuffer,
    const float                                 blendConstants[4]) {
    vkCmdSetBlendConstants(commandBuffer, blendConstants);
}

void callVkCmdSetDepthBounds(
    VkCommandBuffer                             commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds) {
    vkCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
}

void callVkCmdSetStencilCompareMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask) {
    vkCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
}

void callVkCmdSetStencilWriteMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask) {
    vkCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
}

void callVkCmdSetStencilReference(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference) {
    vkCmdSetStencilReference(commandBuffer, faceMask, reference);
}

void callVkCmdBindDescriptorSets(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    const uint32_t*                             pDynamicOffsets) {
    vkCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout,
                            firstSet, descriptorSetCount, pDescriptorSets,
                            dynamicOffsetCount, pDynamicOffsets);
}

void callVkCmdBindIndexBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType) {
    vkCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
}

void callVkCmdBindVertexBuffers(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets) {
    vkCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}

void callVkCmdDraw(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance) {
    vkCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

void callVkCmdDrawIndexed(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance) {
    vkCmdDrawIndexed(commandBuffer, indexCount, instanceCount,
                     firstIndex, vertexOffset, firstInstance);
}

void callVkCmdDrawIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
    vkCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
}

void callVkCmdDrawIndexedIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
    vkCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
}

void callVkCmdDispatch(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    x,
    uint32_t                                    y,
    uint32_t                                    z) {
    vkCmdDispatch(commandBuffer, x, y, z);
}

void callVkCmdDispatchIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset) {
    vkCmdDispatchIndirect(commandBuffer, buffer, offset);
}

void callVkCmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferCopy*                         pRegions) {
    vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}

void callVkCmdCopyImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageCopy*                          pRegions) {
    vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout,
                   dstImage, dstImageLayout, regionCount, pRegions);
}

void callVkCmdBlitImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageBlit*                          pRegions,
    VkFilter                                    filter) {
    vkCmdBlitImage(commandBuffer, srcImage, srcImageLayout,
                   dstImage, dstImageLayout, regionCount, pRegions, filter);
}

void callVkCmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions) {
    vkCmdCopyBufferToImage(commandBuffer, srcBuffer,
                           dstImage, dstImageLayout, regionCount, pRegions);
}

void callVkCmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions) {
    vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout,
                           dstBuffer, regionCount, pRegions);
}

void callVkCmdUpdateBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const uint32_t*                             pData) {
    vkCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}

void callVkCmdFillBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data) {
    vkCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
}

void callVkCmdClearColorImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearColorValue*                    pColor,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges) {
    vkCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}

void callVkCmdClearDepthStencilImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearDepthStencilValue*             pDepthStencil,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges) {
    vkCmdClearDepthStencilImage(commandBuffer, image, imageLayout,
                                pDepthStencil, rangeCount, pRanges);
}

void callVkCmdClearAttachments(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkClearAttachment*                    pAttachments,
    uint32_t                                    rectCount,
    const VkClearRect*                          pRects) {
    vkCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}

void callVkCmdResolveImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageResolve*                       pRegions) {
    vkCmdResolveImage(commandBuffer, srcImage, srcImageLayout,
                      dstImage, dstImageLayout, regionCount, pRegions);
}

void callVkCmdSetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask) {
    vkCmdSetEvent(commandBuffer, event, stageMask);
}

void callVkCmdResetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask) {
    vkCmdResetEvent(commandBuffer, event, stageMask);
}

void callVkCmdWaitEvents(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers) {
    vkCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask,
                    memoryBarrierCount, pMemoryBarriers,
                    bufferMemoryBarrierCount, pBufferMemoryBarriers,
                    imageMemoryBarrierCount, pImageMemoryBarriers);
}

void callVkCmdPipelineBarrier(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers) {
    vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags,
                         memoryBarrierCount, pMemoryBarriers,
                         bufferMemoryBarrierCount, pBufferMemoryBarriers,
                         imageMemoryBarrierCount, pImageMemoryBarriers);
}

void callVkCmdBeginQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags) {
    vkCmdBeginQuery(commandBuffer, queryPool, query, flags);
}

void callVkCmdEndQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
    vkCmdEndQuery(commandBuffer, queryPool, query);
}

void callVkCmdResetQueryPool(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount) {
    vkCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
}

void callVkCmdWriteTimestamp(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
    vkCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
}

void callVkCmdCopyQueryPoolResults(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags) {
    vkCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount,
                              dstBuffer, dstOffset, stride, flags);
}

void callVkCmdPushConstants(
    VkCommandBuffer                             commandBuffer,
    VkPipelineLayout                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const void*                                 pValues) {
    vkCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
}

void callVkCmdBeginRenderPass(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    VkSubpassContents                           contents) {
    vkCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
}

void callVkCmdNextSubpass(
    VkCommandBuffer                             commandBuffer,
    VkSubpassContents                           contents) {
    vkCmdNextSubpass(commandBuffer, contents);
}

void callVkCmdEndRenderPass(
    VkCommandBuffer                             commandBuffer) {
    vkCmdEndRenderPass(commandBuffer);
}

void callVkCmdExecuteCommands(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers) {
    vkCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
}

void callVkDestroySurfaceKHR(
    VkInstance                                  instance,
    VkSurfaceKHR                                surface,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroySurfaceKHR(instance, surface, pAllocator);
}

VkResult callVkGetPhysicalDeviceSurfaceSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    VkSurfaceKHR                                surface,
    VkBool32*                                   pSupported) {
    return vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice,
            queueFamilyIndex, surface, pSupported);
}

VkResult callVkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    VkSurfaceCapabilitiesKHR*                   pSurfaceCapabilities) {
    return vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice,
            surface, pSurfaceCapabilities);
}

VkResult callVkGetPhysicalDeviceSurfaceFormatsKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pSurfaceFormatCount,
    VkSurfaceFormatKHR*                         pSurfaceFormats) {
    return vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice,
            surface, pSurfaceFormatCount, pSurfaceFormats);
}

VkResult callVkGetPhysicalDeviceSurfacePresentModesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pPresentModeCount,
    VkPresentModeKHR*                           pPresentModes) {
    return vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice,
            surface, pPresentModeCount, pPresentModes);
}

VkResult callVkCreateSwapchainKHR(
    VkDevice                                    device,
    const VkSwapchainCreateInfoKHR*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchain) {
    return vkCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
}

void callVkDestroySwapchainKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    const VkAllocationCallbacks*                pAllocator) {
    vkDestroySwapchainKHR(device, swapchain, pAllocator);
}

VkResult callVkGetSwapchainImagesKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint32_t*                                   pSwapchainImageCount,
    VkImage*                                    pSwapchainImages) {
    return vkGetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
}

VkResult callVkAcquireNextImageKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint64_t                                    timeout,
    VkSemaphore                                 semaphore,
    VkFence                                     fence,
    uint32_t*                                   pImageIndex) {
    return vkAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
}

VkResult callVkQueuePresentKHR(
    VkQueue                                     queue,
    const VkPresentInfoKHR*                     pPresentInfo) {
    return vkQueuePresentKHR(queue, pPresentInfo);
}

VkResult callVkGetPhysicalDeviceDisplayPropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPropertiesKHR*                     pProperties) {
    return vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice,
            pPropertyCount, pProperties);
}

VkResult callVkGetPhysicalDeviceDisplayPlanePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlanePropertiesKHR*                pProperties) {
    return vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice,
            pPropertyCount, pProperties);
}

VkResult callVkGetDisplayPlaneSupportedDisplaysKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    planeIndex,
    uint32_t*                                   pDisplayCount,
    VkDisplayKHR*                               pDisplays) {
    return vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex,
            pDisplayCount, pDisplays);
}

VkResult callVkGetDisplayModePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    uint32_t*                                   pPropertyCount,
    VkDisplayModePropertiesKHR*                 pProperties) {
    return vkGetDisplayModePropertiesKHR(physicalDevice, display,
                                         pPropertyCount, pProperties);
}

VkResult callVkCreateDisplayModeKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    const VkDisplayModeCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDisplayModeKHR*                           pMode) {
    return vkCreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);
}

VkResult callVkGetDisplayPlaneCapabilitiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayModeKHR                            mode,
    uint32_t                                    planeIndex,
    VkDisplayPlaneCapabilitiesKHR*              pCapabilities) {
    return vkGetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities);
}

VkResult callVkCreateDisplayPlaneSurfaceKHR(
    VkInstance                                  instance,
    const VkDisplaySurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) {
    return vkCreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}

VkResult callVkCreateSharedSwapchainsKHR(
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const VkSwapchainCreateInfoKHR*             pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchains) {
    return vkCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos,
                                       pAllocator, pSwapchains);
}

#ifdef VK_USE_PLATFORM_XLIB_KHR
VkResult callVkCreateXlibSurfaceKHR(
    VkInstance                                  instance,
    const VkXlibSurfaceCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) {
    return vkCreateXlibSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}

VkBool32 callVkGetPhysicalDeviceXlibPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    Display*                                    dpy,
    VisualID                                    visualID) {
    return vkGetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice,
            queueFamilyIndex, dpy, visualID);
}
#endif /* VK_USE_PLATFORM_XLIB_KHR */

#ifdef VK_USE_PLATFORM_XCB_KHR
VkResult callVkCreateXcbSurfaceKHR(
    VkInstance                                  instance,
    const VkXcbSurfaceCreateInfoKHR*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) {
    return vkCreateXcbSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}

VkBool32 callVkGetPhysicalDeviceXcbPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    xcb_connection_t*                           connection,
    xcb_visualid_t                              visual_id) {
    vkGetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice,
            queueFamilyIndex, connection, visual_id);
}
#endif /* VK_USE_PLATFORM_XCB_KHR */

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
VkResult callVkCreateWaylandSurfaceKHR(
    VkInstance                                  instance,
    const VkWaylandSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) {
    return vkCreateWaylandSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}

VkBool32 callVkGetPhysicalDeviceWaylandPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    struct wl_display*                          display) {
    return vkGetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice,
            queueFamilyIndex, display);
}
#endif /* VK_USE_PLATFORM_WAYLAND_KHR */

#ifdef VK_USE_PLATFORM_MIR_KHR
VkResult callVkCreateMirSurfaceKHR(
    VkInstance                                  instance,
    const VkMirSurfaceCreateInfoKHR*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) {
    return vkCreateMirSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}

VkBool32 callVkGetPhysicalDeviceMirPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    MirConnection*                              connection) {
    return vkGetPhysicalDeviceMirPresentationSupportKHR(physicalDevice,
            queueFamilyIndex, connection);
}
#endif /* VK_USE_PLATFORM_MIR_KHR */

#ifdef VK_USE_PLATFORM_ANDROID_KHR
VkResult callVkCreateAndroidSurfaceKHR(
    VkInstance                                  instance,
    const VkAndroidSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) {
    return vkCreateAndroidSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
VkResult callVkCreateWin32SurfaceKHR(
    VkInstance                                  instance,
    const VkWin32SurfaceCreateInfoKHR*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) {
    return vkCreateWin32SurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}

VkBool32 callVkGetPhysicalDeviceWin32PresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex) {
    return vkGetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice, queueFamilyIndex);
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

VkResult callVkCreateDebugReportCallbackEXT(
    VkInstance                                  instance,
    const VkDebugReportCallbackCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugReportCallbackEXT*                   pCallback) {

    PFN_vkCreateDebugReportCallbackEXT pfn = (PFN_vkCreateDebugReportCallbackEXT)
            (vkGetInstanceProcAddr(instance, "vkCreateDebugReportCallbackEXT"));
    if (pfn != NULL) {
        return pfn(instance, pCreateInfo, pAllocator, pCallback);
    }
    return VK_NOT_READY;
}

void callVkDestroyDebugReportCallbackEXT(
    VkInstance                                  instance,
    VkDebugReportCallbackEXT                    callback,
    const VkAllocationCallbacks*                pAllocator) {

    PFN_vkDestroyDebugReportCallbackEXT pfn = (PFN_vkDestroyDebugReportCallbackEXT)
            (vkGetInstanceProcAddr(instance, "vkDestroyDebugReportCallbackEXT"));
    if (pfn != NULL) {
        pfn(instance, callback, pAllocator);
    }
}

void callVkDebugReportMessageEXT(
    VkInstance                                  instance,
    VkDebugReportFlagsEXT                       flags,
    VkDebugReportObjectTypeEXT                  objectType,
    uint64_t                                    object,
    size_t                                      location,
    int32_t                                     messageCode,
    const char*                                 pLayerPrefix,
    const char*                                 pMessage) {

    PFN_vkDebugReportMessageEXT pfn = (PFN_vkDebugReportMessageEXT)
                                      (vkGetInstanceProcAddr(instance, "vkDebugReportMessageEXT"));
    if (pfn != NULL) {
        pfn(instance, flags, objectType, object, location,
            messageCode, pLayerPrefix, pMessage);
    }
}

// VkResult callVkDebugMarkerSetObjectTagEXT(
//     VkDevice                                    device,
//     VkDebugMarkerObjectTagInfoEXT*              pTagInfo) {
//  return vkDebugMarkerSetObjectTagEXT(device, pTagInfo);
// }

// VkResult callVkDebugMarkerSetObjectNameEXT(
//     VkDevice                                    device,
//     VkDebugMarkerObjectNameInfoEXT*             pNameInfo) {
//  return vkDebugMarkerSetObjectNameEXT(device, pNameInfo);
// }

// void callVkCmdDebugMarkerBeginEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkDebugMarkerMarkerInfoEXT*                 pMarkerInfo) {
//  vkCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
// }

// void callVkCmdDebugMarkerEndEXT(
//     VkCommandBuffer                             commandBuffer) {
//  vkCmdDebugMarkerEndEXT(commandBuffer);
// }

// void callVkCmdDebugMarkerInsertEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkDebugMarkerMarkerInfoEXT*                 pMarkerInfo) {
//  vkCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
// }
