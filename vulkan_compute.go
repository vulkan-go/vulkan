// +build linux,compute

package vulkan

/*
#cgo CFLAGS: -I. -DVK_NO_PROTOTYPES
#cgo linux LDFLAGS: -ldl

#include "vulkan/vulkan.h"
#include "vk_wrapper.h"
#include "vk_bridge.h"
#include "cgo_helpers.h"
*/
import "C"

const (
	// UsePlatformCompute means using Vulkan API for compute and headless rendering purposes only.
	UsePlatformCompute = 1
)

// CreateWindowSurface is a no-op for Vulkan in compute mode.
func CreateWindowSurface(_ Instance, _ uintptr, _ *AllocationCallbacks, _ *Surface) Result {
	return 0
}

// GetRequiredInstanceExtensions is a no-op for Vulkan in compute mode.
func GetRequiredInstanceExtensions() []string {
	return nil
}
