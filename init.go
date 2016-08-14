package vulkan

import (
	"errors"
)

// #include "vulkan_wrapper.h"
import "C"

func Init() error {
	ret := C.vkInit()
	if ret < 0 {
		return errors.New("dlopen: libvulkan.so not found")
	}
	return nil
}

func InitDebug(instance Instance) {
	C.vkInitDebug(C.VkInstance(instance))
}
