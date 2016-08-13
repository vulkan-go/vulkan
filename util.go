package vulkan

import (
	"bytes"
	"fmt"
	"unsafe"
)

// #include "vulkan/vulkan.h"
import "C"

type Version uint32

func (v Version) String() string {
	return fmt.Sprintf("%d.%d.%d", v.Major(), v.Minor(), v.Patch())
}

func (v Version) Major() int {
	return int(uint32(v) >> 22)
}

func (v Version) Minor() int {
	return int(uint32(v) >> 12 & 0x3FF)
}

func (v Version) Patch() int {
	return int(uint32(v) & 0xFFF)
}

func MakeVersion(major, minor, patch int) uint32 {
	return uint32(major)<<22 | uint32(minor)<<12 | uint32(patch)
}

func ToString(buf []byte) string {
	var str bytes.Buffer
	for i := range buf {
		if buf[i] == '\x00' {
			return str.String()
		}
		str.WriteByte(buf[i])
	}
	return str.String()
}

func FindMemoryTypeIndex(dev PhysicalDevice,
	typeBits uint32, reqMask Flags) (uint32, bool) {

	var memProperties PhysicalDeviceMemoryProperties
	GetPhysicalDeviceMemoryProperties(dev, &memProperties)
	memProperties.Deref()

	// search memtypes to find the first index with those requirements
	for i := 0; i < 32; i++ {
		if typeBits&1 == 1 { // type is available
			memType := memProperties.MemoryTypes[i]
			memType.Deref()
			if Flags(memType.PropertyFlags)&reqMask == reqMask {
				return uint32(i), true
			}
		}
		typeBits = typeBits >> 1
	}
	return 0, false
}

// MemCopyFloat32 copies float32 values from src.Data to dst.Data on the unsafe level.
func MemCopyFloat32(dst []unsafe.Pointer, src []float32) int {
	hdr := *(*sliceHeader)(unsafe.Pointer(&dst))
	hdr.Cap = cap(src)
	hdr.Len = len(src)
	dstView := *(*[]float32)(unsafe.Pointer(&hdr))
	return copy(dstView, src)
}

func NewClearValue(color []float32) ClearValue {
	var v ClearValue
	v.SetColor(color)
	return v
}

func (cv *ClearValue) SetColor(color []float32) {
	vkClearValue := (*[4]float32)(unsafe.Pointer(cv))
	for i := 0; i < len(color); i++ {
		vkClearValue[i] = color[i]
	}
}
