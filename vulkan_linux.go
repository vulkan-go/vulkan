// +build linux,!android

package vulkan

import "unsafe"

/*
#cgo pkg-config: vulkan
#cgo LDFLAGS: -ldl -lvulkan

#include "vk_wrapper.h"
#include "vk_bridge.h"
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_wayland.h>

VkPipeline nilPipeline =  (VkPipeline) { 0 };
VkPipelineCache nilPipelineCache =  (VkPipelineCache) { VK_NULL_HANDLE };

////////////////////// WAYLAND BEGIN
VkResult wlcallVkCreateInstance(
    void*                 PpCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkInstance*                                 pInstance) {
        const VkInstanceCreateInfo*                 pCreateInfo = (const VkInstanceCreateInfo*   ) PpCreateInfo;
    return vkCreateInstance(pCreateInfo, pAllocator, pInstance);
}
VkResult wlcallVkCreateWaylandSurfaceKHR(
    void*                                  Pinstance,
    const VkWaylandSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) {
    VkInstance instance = (VkInstance) Pinstance;
    return vkCreateWaylandSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}
VkBool32 wlcallVkGetPhysicalDeviceWaylandPresentationSupportKHR(
    void*                                       PphysicalDevice,
    uint32_t                                    queueFamilyIndex,
    struct wl_display*                          display) {
    VkPhysicalDevice                            physicalDevice = (VkPhysicalDevice) PphysicalDevice;
    return vkGetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice,
            queueFamilyIndex, display);
}
void wlcallVkGetPhysicalDeviceFeatures2(
    VkPhysicalDevice                            physicalDevice,
    void*                   PpFeatures) {
        VkPhysicalDeviceFeatures2*                   pFeatures = (VkPhysicalDeviceFeatures2*) PpFeatures;
    vkGetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
}
////////////////////// WAYLAND END


*/
import "C"

// cannot be created without unsafe and C
var NilPipeline = (*vulkan.Pipeline)(unsafe.Pointer(&C.nilPipeline))

// cannot be created without unsafe and C
var NilPipelineCache = (*vulkan.PipelineCache)(unsafe.Pointer(&C.nilPipelineCache))

// Linux Wayland type flags
type WaylandSurfaceCreateFlags uint32

// Linux Wayland type struct
type WaylandSurfaceCreateInfo struct {
	SType   vulkan.StructureType
	PNext   unsafe.Pointer
	Flags   WaylandSurfaceCreateFlags
	Display uintptr
	Surface uintptr
}

// CreateInstance function as declared in https://www.khronos.org/registry/vulkan/specs/1.0/man/html/vkCreateInstance.html
func CreateInstance(pCreateInfo *vulkan.InstanceCreateInfo, pAllocator *vulkan.AllocationCallbacks, pInstance *vulkan.Instance) vulkan.Result {
	cpCreateInfo, _ := pCreateInfo.PassRef()
	cpAllocator, _ := (*C.VkAllocationCallbacks)(unsafe.Pointer(pAllocator)), 0
	cpInstance, _ := (*C.VkInstance)(unsafe.Pointer(pInstance)), 0
	__ret := C.wlcallVkCreateInstance(unsafe.Pointer(cpCreateInfo), cpAllocator, cpInstance)
	__v := (vulkan.Result)(__ret)
	return __v
}

// GetPhysicalDeviceFeatures2 function as declared in https://www.khronos.org/registry/vulkan/specs/1.0/man/html/vkGetPhysicalDeviceFeatures2.html
func GetPhysicalDeviceFeatures2(physicalDevice vulkan.PhysicalDevice, pFeatures *vulkan.PhysicalDeviceFeatures2) {
	cphysicalDevice, _ := *(*C.VkPhysicalDevice)(unsafe.Pointer(&physicalDevice)), 0
	cpFeatures, _ := pFeatures.PassRef()
	C.wlcallVkGetPhysicalDeviceFeatures2(cphysicalDevice, unsafe.Pointer(cpFeatures))
}

// CreateWaylandSurface is a Linux Wayland-related function
func CreateWaylandSurface(instance vulkan.Instance, info *WaylandSurfaceCreateInfo, pAllocator *vulkan.AllocationCallbacks, pSurface *vulkan.Surface) {
	cpAllocator, _ := (*C.VkAllocationCallbacks)(unsafe.Pointer(pAllocator)), 0
	cpSurface, _ := (*C.VkSurfaceKHR)(unsafe.Pointer(pSurface)), 0

	C.wlcallVkCreateWaylandSurfaceKHR(unsafe.Pointer(instance), (*C.VkWaylandSurfaceCreateInfoKHR)(unsafe.Pointer(info)), cpAllocator, cpSurface)
}

// GetPhysicalDeviceWaylandPresentationSupport is a Linux Wayland-related function
func GetPhysicalDeviceWaylandPresentationSupport(physicalDevice vulkan.PhysicalDevice, queueFamilyIndex uint32, display uintptr) bool {
	return 0 != C.wlcallVkGetPhysicalDeviceWaylandPresentationSupportKHR(unsafe.Pointer(physicalDevice), C.uint(queueFamilyIndex), (*C.struct_wl_display)(unsafe.Pointer(display)))
}
