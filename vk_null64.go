// +build !386,!arm

package vulkan

import "unsafe"

var (
	// NullHandle defines a platform-specfic NULL handle.
	NullHandle unsafe.Pointer = nil
	// NullSemaphore defines a platform-specfic NULL Semaphore.
	NullSemaphore Semaphore = nil
	// NullFence defines a platform-specfic NULL Fence.
	NullFence Fence = nil
	// NullDeviceMemory defines a platform-specfic NULL DeviceMemory.
	NullDeviceMemory DeviceMemory = nil
	// NullBuffer defines a platform-specfic NULL Buffer.
	NullBuffer Buffer = nil
	// NullImage defines a platform-specfic NULL Image.
	NullImage Image = nil
	// NullEvent defines a platform-specfic NULL Event.
	NullEvent Event = nil
	// NullQueryPool defines a platform-specfic NULL QueryPool.
	NullQueryPool QueryPool = nil
	// NullBufferView defines a platform-specfic NULL BufferView.
	NullBufferView BufferView = nil
	// NullImageView defines a platform-specfic NULL ImageView.
	NullImageView ImageView = nil
	// NullShaderModule defines a platform-specfic NULL ShaderModule.
	NullShaderModule ShaderModule = nil
	// NullPipelineCache defines a platform-specfic NULL PipelineCache.
	NullPipelineCache PipelineCache = nil
	// NullPipelineLayout defines a platform-specfic NULL PipelineLayout.
	NullPipelineLayout PipelineLayout = nil
	// NullRenderPass defines a platform-specfic NULL RenderPass.
	NullRenderPass RenderPass = nil
	// NullPipeline defines a platform-specfic NULL Pipeline.
	NullPipeline Pipeline = nil
	// NullDescriptorSetLayout defines a platform-specfic NULL DescriptorSetLayout.
	NullDescriptorSetLayout DescriptorSetLayout = nil
	// NullSampler defines a platform-specfic NULL Sampler.
	NullSampler Sampler = nil
	// NullDescriptorPool defines a platform-specfic NULL DescriptorPool.
	NullDescriptorPool DescriptorPool = nil
	// NullDescriptorSet defines a platform-specfic NULL DescriptorSet.
	NullDescriptorSet DescriptorSet = nil
	// NullFramebuffer defines a platform-specfic NULL Framebuffer.
	NullFramebuffer Framebuffer = nil
	// NullCommandPool defines a platform-specfic NULL CommandPool.
	NullCommandPool CommandPool = nil
	// NullSurface defines a platform-specfic NULL Surface.
	NullSurface Surface = nil
	// NullSwapchain defines a platform-specfic NULL Swapchain.
	NullSwapchain Swapchain = nil
	// NullDisplay defines a platform-specfic NULL Display.
	NullDisplay Display = nil
	// NullDisplayMode defines a platform-specfic NULL DisplayMode.
	NullDisplayMode DisplayMode = nil
	// NullDebugReportCallback defines a platform-specfic NULL DebugReportCallback.
	NullDebugReportCallback DebugReportCallback = nil
)
