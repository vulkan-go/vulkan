package vulkan

import (
	"errors"
)

// #include "vk_wrapper.h"
import "C"

func Init() error {
	ret := C.vkInit()
	if ret < 0 {
		return errors.New("vkInit failed")
	}
	return nil
}
