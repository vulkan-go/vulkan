// +build darwin

package vulkan

/*
#cgo CFLAGS: -I. -DVK_NO_PROTOTYPES
#cgo darwin CFLAGS: -DVK_USE_PLATFORM_MACOS_MVK -DGLFW_INCLUDE_VULKAN -D_GLFW_COCOA -Wno-deprecated-declarations
#cgo darwin LDFLAGS: -framework Cocoa -framework IOKit -framework QuartzCore -framework Metal -framework MoltenVK -lc++
#cgo darwin pkg-config: glfw3

#include <GLFW/glfw3.h>

#include "vulkan/vulkan.h"
#include "vk_wrapper.h"
#include "vk_bridge.h"
*/
import "C"
import "unsafe"

const (
	// UsePlatformMacos means enabled support of MoltenVK.
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
