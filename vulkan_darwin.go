// +build darwin

package vulkan

/*
#cgo CFLAGS: -I. -DVK_NO_PROTOTYPES
#cgo darwin CFLAGS: -DVK_USE_PLATFORM_MACOS_MVK -DGLFW_COCOA -DGLFW_USE_CHDIR -DGLFW_USE_MENUBAR -DGLFW_INCLUDE_VULKAN -DGLFW_USE_RETINA -Wno-deprecated-declarations
#cgo darwin LDFLAGS: -framework Cocoa -framework IOKit -framework Metal -framework QuartzCore -framework MoltenVK -lc++
#cgo darwin pkg-config: glfw3

#include "vulkan/vulkan.h"
#include "vk_wrapper.h"
#include "vk_bridge.h"
*/
import "C"
import "unsafe"

const (
	// UsePlatformMacos mean enabled support of MoltenVK.
	UsePlatformMacos = 1
	// MvkMacosSurface means that VK_MVK_macos_surface is available.
	MvkMacosSurface = 1
	// MvkMacosSurfaceSpecVersion
	MvkMacosSurfaceSpecVersion = 1
	// MvkMacosSurfaceExtensionName
	MvkMacosSurfaceExtensionName = "VK_MVK_macos_surface"
)

// CreateWindowSurface creates a Vulkan surface (VK_MVK_macos_surface) for a GLFW window with glfwCreateWindowSurface.
// See http://www.glfw.org/docs/latest/group__vulkan.html#ga1a24536bec3f80b08ead18e28e6ae965
func CreateWindowSurface(instance Instance, glfwWindow uintptr, pAllocator *AllocationCallbacks, pSurface *Surface) Result {
	cinstance, _ := (C.VkInstance)(instance), cgoAllocsUnknown
	cpAllocator, _ := (*C.VkAllocationCallbacks)(unsafe.Pointer(pAllocator)), cgoAllocsUnknown
	cpSurface, _ := (*C.VkSurfaceKHR)(unsafe.Pointer(pSurface)), cgoAllocsUnknown
	ret := C.vkCreateGLFWSurface(cinstance, unsafe.Pointer(glfwWindow), cpAllocator, cpSurface)
	return (Result)(ret)
}

// GetRequiredInstanceExtensions should be used to query instance extensions required for surface initialization,
// calls glfwGetRequiredInstanceExtensions.
// See http://www.glfw.org/docs/3.2/group__vulkan.html#ga1abcbe61033958f22f63ef82008874b1
func GetRequiredInstanceExtensions() []string {
	var count uint32
	ccount, _ := (*C.uint32_t)(unsafe.Pointer(&count)), cgoAllocsUnknown
	__ret := C.vkGetRequiredInstanceExtensions(ccount)
	__v := make([]string, count)
	packSString(__v, __ret)
	return __v
}

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
