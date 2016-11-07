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
	// UsePlatformCompute means using VK for compute and headless rendering purposes only.
	UsePlatformCompute = 1
)
