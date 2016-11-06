package vulkan

import (
	"errors"
)

// #include "vk_wrapper.h"
import "C"

// Init checks for Vulkan support on the platform and obtains PFNs for global Vulkan API functions.
func Init() error {
	ret := C.vkInit()
	if ret < 0 {
		return errors.New("vkInit failed")
	}
	return nil
}

// InitInstance obtains instance PFNs for Vulkan API functions, this is necessary on
// OS X using MoltenVK, but for the other platforms it's an option. Not implemented for Android.
func InitInstance(instance Instance) error {
	ret := C.vkInitInstance((C.VkInstance)(instance))
	if ret < 0 {
		return errors.New("vkInitInstance failed")
	}
	return nil
}
