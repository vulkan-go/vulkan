// +build darwin
// +build arm arm64

package vulkan

/*
#cgo CFLAGS: -x objective-c
#cgo LDFLAGS: -framework Foundation -framework UIKit -framework QuartzCore -framework MoltenVK

#include "vulkan/vulkan.h"
#include "vk_wrapper.h"
#include "vk_bridge.h"
*/
import "C"
import "unsafe"

const (
	// UsePlatformIos means enabled support of MoltenVK.
	UsePlatformIos = 1
	// MvkMoltenvkRevision as defined in moltenVK/vk_mvk_moltenvk.h:28
	MvkMoltenvkRevision = 1
	// MvkMoltenvkExtensionNumber as defined in moltenVK/vk_mvk_moltenvk.h:29
	MvkMoltenvkExtensionNumber = 54
	// MvkMoltenvkExtensionName as defined in moltenVK/vk_mvk_moltenvk.h:30
	MvkMoltenvkExtensionName = "VK_MVK_moltenvk"
	// MvkIosSurface as defined in moltenVK/vk_mvk_ios_surface.h:37
	MvkIosSurface = 1
	// MvkIosSurfaceSpecVersion as defined in moltenVK/vk_mvk_ios_surface.h:39
	MvkIosSurfaceSpecVersion = 1
	// MvkIosSurfaceExtensionName as defined in moltenVK/vk_mvk_ios_surface.h:40
	MvkIosSurfaceExtensionName = "VK_MVK_ios_surface"
	// MvkIosSurfaceExtensionNumber as defined in moltenVK/vk_mvk_ios_surface.h:41
	MvkIosSurfaceExtensionNumber = 52
	// StructureTypeIosSurfaceCreateInfoMvk as defined in moltenVK/vk_mvk_ios_surface.h:42
	StructureTypeIosSurfaceCreateInfoMvk = ((StructureType)(1000000000 + MvkIosSurfaceExtensionNumber*1000))
)

// MVKDeviceConfiguration as declared in moltenVK/vk_mvk_moltenvk.h:41
type MVKDeviceConfiguration struct {
	SupportDisplayContentsScale   Bool32
	ImageFlipY                    Bool32
	ShaderConversionFlipFragmentY Bool32
	ShaderConversionFlipVertexY   Bool32
	ShaderConversionLogging       Bool32
	PerformanceTracking           Bool32
	PerformanceLoggingFrameCount  uint32
	ref1c21f673                   *C.MVKDeviceConfiguration
	allocs1c21f673                interface{}
}

// MVKPhysicalDeviceMetalFeatures as declared in moltenVK/vk_mvk_moltenvk.h:52
type MVKPhysicalDeviceMetalFeatures struct {
	DepthClipMode             Bool32
	IndirectDrawing           Bool32
	BaseVertexInstanceDrawing Bool32
	MaxVertexBufferCount      uint32
	MaxFragmentBufferCount    uint32
	BufferAlignment           DeviceSize
	PushConstantsAlignment    DeviceSize
	refb64ae6e7               *C.MVKPhysicalDeviceMetalFeatures
	allocsb64ae6e7            interface{}
}

// MVKSwapchainPerformance as declared in moltenVK/vk_mvk_moltenvk.h:59
type MVKSwapchainPerformance struct {
	LastFrameInterval      float64
	AverageFrameInterval   float64
	AverageFramesPerSecond float64
	refd8d60565            *C.MVKSwapchainPerformance
	allocsd8d60565         interface{}
}

// IOSSurfaceCreateFlagsMVK type as declared in moltenVK/vk_mvk_ios_surface.h:46
type IOSSurfaceCreateFlagsMVK uint32

// IOSSurfaceCreateInfoMVK as declared in moltenVK/vk_mvk_ios_surface.h:62
type IOSSurfaceCreateInfoMVK struct {
	SType          StructureType
	PNext          unsafe.Pointer
	Flags          IOSSurfaceCreateFlagsMVK
	PView          unsafe.Pointer
	ref96717271    *C.VkIOSSurfaceCreateInfoMVK
	allocs96717271 interface{}
}

// CreateIOSSurfaceMVK function as declared in vulkan/vk_bridge.h:973
func CreateIOSSurfaceMVK(instance Instance, pCreateInfo *IOSSurfaceCreateInfoMVK, pAllocator *AllocationCallbacks, pSurface *Surface) Result {
	cinstance, _ := *(*C.VkInstance)(unsafe.Pointer(&instance)), cgoAllocsUnknown
	cpCreateInfo, _ := pCreateInfo.PassRef()
	cpAllocator, _ := (*C.VkAllocationCallbacks)(unsafe.Pointer(pAllocator)), cgoAllocsUnknown
	cpSurface, _ := (*C.VkSurfaceKHR)(unsafe.Pointer(pSurface)), cgoAllocsUnknown
	__ret := C.callVkCreateIOSSurfaceMVK(cinstance, cpCreateInfo, cpAllocator, cpSurface)
	__v := (Result)(__ret)
	return __v
}

// ActivateMoltenVKLicenseMVK function as declared in vulkan/vk_bridge.h:979
func ActivateMoltenVKLicenseMVK(licenseID string, licenseKey string, acceptLicenseTermsAndConditions Bool32) Result {
	clicenseID, _ := unpackPCharString(licenseID)
	clicenseKey, _ := unpackPCharString(licenseKey)
	cacceptLicenseTermsAndConditions, _ := (C.VkBool32)(acceptLicenseTermsAndConditions), cgoAllocsUnknown
	__ret := C.callVkActivateMoltenVKLicenseMVK(clicenseID, clicenseKey, cacceptLicenseTermsAndConditions)
	__v := (Result)(__ret)
	return __v
}

// ActivateMoltenVKLicensesMVK function as declared in vulkan/vk_bridge.h:984
func ActivateMoltenVKLicensesMVK() Result {
	__ret := C.callVkActivateMoltenVKLicensesMVK()
	__v := (Result)(__ret)
	return __v
}

// GetMoltenVKDeviceConfigurationMVK function as declared in vulkan/vk_bridge.h:986
func GetMoltenVKDeviceConfigurationMVK(device Device, pConfiguration *MVKDeviceConfiguration) Result {
	cdevice, _ := *(*C.VkDevice)(unsafe.Pointer(&device)), cgoAllocsUnknown
	cpConfiguration, _ := pConfiguration.PassRef()
	__ret := C.callVkGetMoltenVKDeviceConfigurationMVK(cdevice, cpConfiguration)
	__v := (Result)(__ret)
	return __v
}

// SetMoltenVKDeviceConfigurationMVK function as declared in vulkan/vk_bridge.h:990
func SetMoltenVKDeviceConfigurationMVK(device Device, pConfiguration *MVKDeviceConfiguration) Result {
	cdevice, _ := *(*C.VkDevice)(unsafe.Pointer(&device)), cgoAllocsUnknown
	cpConfiguration, _ := pConfiguration.PassRef()
	__ret := C.callVkSetMoltenVKDeviceConfigurationMVK(cdevice, cpConfiguration)
	__v := (Result)(__ret)
	return __v
}

// GetPhysicalDeviceMetalFeaturesMVK function as declared in vulkan/vk_bridge.h:994
func GetPhysicalDeviceMetalFeaturesMVK(physicalDevice PhysicalDevice, pMetalFeatures *MVKPhysicalDeviceMetalFeatures) Result {
	cphysicalDevice, _ := *(*C.VkPhysicalDevice)(unsafe.Pointer(&physicalDevice)), cgoAllocsUnknown
	cpMetalFeatures, _ := pMetalFeatures.PassRef()
	__ret := C.callVkGetPhysicalDeviceMetalFeaturesMVK(cphysicalDevice, cpMetalFeatures)
	__v := (Result)(__ret)
	return __v
}

// GetSwapchainPerformanceMVK function as declared in vulkan/vk_bridge.h:998
func GetSwapchainPerformanceMVK(device Device, swapchain Swapchain, pSwapchainPerf *MVKSwapchainPerformance) Result {
	cdevice, _ := *(*C.VkDevice)(unsafe.Pointer(&device)), cgoAllocsUnknown
	cswapchain, _ := *(*C.VkSwapchainKHR)(unsafe.Pointer(&swapchain)), cgoAllocsUnknown
	cpSwapchainPerf, _ := pSwapchainPerf.PassRef()
	__ret := C.callVkGetSwapchainPerformanceMVK(cdevice, cswapchain, cpSwapchainPerf)
	__v := (Result)(__ret)
	return __v
}

// allocMVKDeviceConfigurationMemory allocates memory for type C.MVKDeviceConfiguration in C.
// The caller is responsible for freeing the this memory via C.free.
func allocMVKDeviceConfigurationMemory(n int) unsafe.Pointer {
	mem, err := C.calloc(C.size_t(n), (C.size_t)(sizeOfMVKDeviceConfigurationValue))
	if err != nil {
		panic("memory alloc error: " + err.Error())
	}
	return mem
}

const sizeOfMVKDeviceConfigurationValue = unsafe.Sizeof([1]C.MVKDeviceConfiguration{})

// Ref returns the underlying reference to C object or nil if struct is nil.
func (x *MVKDeviceConfiguration) Ref() *C.MVKDeviceConfiguration {
	if x == nil {
		return nil
	}
	return x.ref1c21f673
}

// Free invokes alloc map's free mechanism that cleanups any allocated memory using C free.
// Does nothing if struct is nil or has no allocation map.
func (x *MVKDeviceConfiguration) Free() {
	if x != nil && x.allocs1c21f673 != nil {
		x.allocs1c21f673.(*cgoAllocMap).Free()
		x.ref1c21f673 = nil
	}
}

// NewMVKDeviceConfigurationRef creates a new wrapper struct with underlying reference set to the original C object.
// Returns nil if the provided pointer to C object is nil too.
func NewMVKDeviceConfigurationRef(ref unsafe.Pointer) *MVKDeviceConfiguration {
	if ref == nil {
		return nil
	}
	obj := new(MVKDeviceConfiguration)
	obj.ref1c21f673 = (*C.MVKDeviceConfiguration)(unsafe.Pointer(ref))
	return obj
}

// PassRef returns the underlying C object, otherwise it will allocate one and set its values
// from this wrapping struct, counting allocations into an allocation map.
func (x *MVKDeviceConfiguration) PassRef() (*C.MVKDeviceConfiguration, *cgoAllocMap) {
	if x == nil {
		return nil, nil
	} else if x.ref1c21f673 != nil {
		return x.ref1c21f673, nil
	}
	mem1c21f673 := allocMVKDeviceConfigurationMemory(1)
	ref1c21f673 := (*C.MVKDeviceConfiguration)(mem1c21f673)
	allocs1c21f673 := new(cgoAllocMap)
	var csupportDisplayContentsScale_allocs *cgoAllocMap
	ref1c21f673.supportDisplayContentsScale, csupportDisplayContentsScale_allocs = (C.VkBool32)(x.SupportDisplayContentsScale), cgoAllocsUnknown
	allocs1c21f673.Borrow(csupportDisplayContentsScale_allocs)

	var cimageFlipY_allocs *cgoAllocMap
	ref1c21f673.imageFlipY, cimageFlipY_allocs = (C.VkBool32)(x.ImageFlipY), cgoAllocsUnknown
	allocs1c21f673.Borrow(cimageFlipY_allocs)

	var cshaderConversionFlipFragmentY_allocs *cgoAllocMap
	ref1c21f673.shaderConversionFlipFragmentY, cshaderConversionFlipFragmentY_allocs = (C.VkBool32)(x.ShaderConversionFlipFragmentY), cgoAllocsUnknown
	allocs1c21f673.Borrow(cshaderConversionFlipFragmentY_allocs)

	var cshaderConversionFlipVertexY_allocs *cgoAllocMap
	ref1c21f673.shaderConversionFlipVertexY, cshaderConversionFlipVertexY_allocs = (C.VkBool32)(x.ShaderConversionFlipVertexY), cgoAllocsUnknown
	allocs1c21f673.Borrow(cshaderConversionFlipVertexY_allocs)

	var cshaderConversionLogging_allocs *cgoAllocMap
	ref1c21f673.shaderConversionLogging, cshaderConversionLogging_allocs = (C.VkBool32)(x.ShaderConversionLogging), cgoAllocsUnknown
	allocs1c21f673.Borrow(cshaderConversionLogging_allocs)

	var cperformanceTracking_allocs *cgoAllocMap
	ref1c21f673.performanceTracking, cperformanceTracking_allocs = (C.VkBool32)(x.PerformanceTracking), cgoAllocsUnknown
	allocs1c21f673.Borrow(cperformanceTracking_allocs)

	var cperformanceLoggingFrameCount_allocs *cgoAllocMap
	ref1c21f673.performanceLoggingFrameCount, cperformanceLoggingFrameCount_allocs = (C.uint32_t)(x.PerformanceLoggingFrameCount), cgoAllocsUnknown
	allocs1c21f673.Borrow(cperformanceLoggingFrameCount_allocs)

	x.ref1c21f673 = ref1c21f673
	x.allocs1c21f673 = allocs1c21f673
	return ref1c21f673, allocs1c21f673

}

// PassValue does the same as PassRef except that it will try to dereference the returned pointer.
func (x MVKDeviceConfiguration) PassValue() (C.MVKDeviceConfiguration, *cgoAllocMap) {
	if x.ref1c21f673 != nil {
		return *x.ref1c21f673, nil
	}
	ref, allocs := x.PassRef()
	return *ref, allocs
}

// Deref uses the underlying reference to C object and fills the wrapping struct with values.
// Do not forget to call this method whether you get a struct for C object and want to read its values.
func (x *MVKDeviceConfiguration) Deref() {
	if x.ref1c21f673 == nil {
		return
	}
	x.SupportDisplayContentsScale = (Bool32)(x.ref1c21f673.supportDisplayContentsScale)
	x.ImageFlipY = (Bool32)(x.ref1c21f673.imageFlipY)
	x.ShaderConversionFlipFragmentY = (Bool32)(x.ref1c21f673.shaderConversionFlipFragmentY)
	x.ShaderConversionFlipVertexY = (Bool32)(x.ref1c21f673.shaderConversionFlipVertexY)
	x.ShaderConversionLogging = (Bool32)(x.ref1c21f673.shaderConversionLogging)
	x.PerformanceTracking = (Bool32)(x.ref1c21f673.performanceTracking)
	x.PerformanceLoggingFrameCount = (uint32)(x.ref1c21f673.performanceLoggingFrameCount)
}

// allocMVKPhysicalDeviceMetalFeaturesMemory allocates memory for type C.MVKPhysicalDeviceMetalFeatures in C.
// The caller is responsible for freeing the this memory via C.free.
func allocMVKPhysicalDeviceMetalFeaturesMemory(n int) unsafe.Pointer {
	mem, err := C.calloc(C.size_t(n), (C.size_t)(sizeOfMVKPhysicalDeviceMetalFeaturesValue))
	if err != nil {
		panic("memory alloc error: " + err.Error())
	}
	return mem
}

const sizeOfMVKPhysicalDeviceMetalFeaturesValue = unsafe.Sizeof([1]C.MVKPhysicalDeviceMetalFeatures{})

// Ref returns the underlying reference to C object or nil if struct is nil.
func (x *MVKPhysicalDeviceMetalFeatures) Ref() *C.MVKPhysicalDeviceMetalFeatures {
	if x == nil {
		return nil
	}
	return x.refb64ae6e7
}

// Free invokes alloc map's free mechanism that cleanups any allocated memory using C free.
// Does nothing if struct is nil or has no allocation map.
func (x *MVKPhysicalDeviceMetalFeatures) Free() {
	if x != nil && x.allocsb64ae6e7 != nil {
		x.allocsb64ae6e7.(*cgoAllocMap).Free()
		x.refb64ae6e7 = nil
	}
}

// NewMVKPhysicalDeviceMetalFeaturesRef creates a new wrapper struct with underlying reference set to the original C object.
// Returns nil if the provided pointer to C object is nil too.
func NewMVKPhysicalDeviceMetalFeaturesRef(ref unsafe.Pointer) *MVKPhysicalDeviceMetalFeatures {
	if ref == nil {
		return nil
	}
	obj := new(MVKPhysicalDeviceMetalFeatures)
	obj.refb64ae6e7 = (*C.MVKPhysicalDeviceMetalFeatures)(unsafe.Pointer(ref))
	return obj
}

// PassRef returns the underlying C object, otherwise it will allocate one and set its values
// from this wrapping struct, counting allocations into an allocation map.
func (x *MVKPhysicalDeviceMetalFeatures) PassRef() (*C.MVKPhysicalDeviceMetalFeatures, *cgoAllocMap) {
	if x == nil {
		return nil, nil
	} else if x.refb64ae6e7 != nil {
		return x.refb64ae6e7, nil
	}
	memb64ae6e7 := allocMVKPhysicalDeviceMetalFeaturesMemory(1)
	refb64ae6e7 := (*C.MVKPhysicalDeviceMetalFeatures)(memb64ae6e7)
	allocsb64ae6e7 := new(cgoAllocMap)
	var cdepthClipMode_allocs *cgoAllocMap
	refb64ae6e7.depthClipMode, cdepthClipMode_allocs = (C.VkBool32)(x.DepthClipMode), cgoAllocsUnknown
	allocsb64ae6e7.Borrow(cdepthClipMode_allocs)

	var cindirectDrawing_allocs *cgoAllocMap
	refb64ae6e7.indirectDrawing, cindirectDrawing_allocs = (C.VkBool32)(x.IndirectDrawing), cgoAllocsUnknown
	allocsb64ae6e7.Borrow(cindirectDrawing_allocs)

	var cbaseVertexInstanceDrawing_allocs *cgoAllocMap
	refb64ae6e7.baseVertexInstanceDrawing, cbaseVertexInstanceDrawing_allocs = (C.VkBool32)(x.BaseVertexInstanceDrawing), cgoAllocsUnknown
	allocsb64ae6e7.Borrow(cbaseVertexInstanceDrawing_allocs)

	var cmaxVertexBufferCount_allocs *cgoAllocMap
	refb64ae6e7.maxVertexBufferCount, cmaxVertexBufferCount_allocs = (C.uint32_t)(x.MaxVertexBufferCount), cgoAllocsUnknown
	allocsb64ae6e7.Borrow(cmaxVertexBufferCount_allocs)

	var cmaxFragmentBufferCount_allocs *cgoAllocMap
	refb64ae6e7.maxFragmentBufferCount, cmaxFragmentBufferCount_allocs = (C.uint32_t)(x.MaxFragmentBufferCount), cgoAllocsUnknown
	allocsb64ae6e7.Borrow(cmaxFragmentBufferCount_allocs)

	var cbufferAlignment_allocs *cgoAllocMap
	refb64ae6e7.bufferAlignment, cbufferAlignment_allocs = (C.VkDeviceSize)(x.BufferAlignment), cgoAllocsUnknown
	allocsb64ae6e7.Borrow(cbufferAlignment_allocs)

	var cpushConstantsAlignment_allocs *cgoAllocMap
	refb64ae6e7.pushConstantsAlignment, cpushConstantsAlignment_allocs = (C.VkDeviceSize)(x.PushConstantsAlignment), cgoAllocsUnknown
	allocsb64ae6e7.Borrow(cpushConstantsAlignment_allocs)

	x.refb64ae6e7 = refb64ae6e7
	x.allocsb64ae6e7 = allocsb64ae6e7
	return refb64ae6e7, allocsb64ae6e7

}

// PassValue does the same as PassRef except that it will try to dereference the returned pointer.
func (x MVKPhysicalDeviceMetalFeatures) PassValue() (C.MVKPhysicalDeviceMetalFeatures, *cgoAllocMap) {
	if x.refb64ae6e7 != nil {
		return *x.refb64ae6e7, nil
	}
	ref, allocs := x.PassRef()
	return *ref, allocs
}

// Deref uses the underlying reference to C object and fills the wrapping struct with values.
// Do not forget to call this method whether you get a struct for C object and want to read its values.
func (x *MVKPhysicalDeviceMetalFeatures) Deref() {
	if x.refb64ae6e7 == nil {
		return
	}
	x.DepthClipMode = (Bool32)(x.refb64ae6e7.depthClipMode)
	x.IndirectDrawing = (Bool32)(x.refb64ae6e7.indirectDrawing)
	x.BaseVertexInstanceDrawing = (Bool32)(x.refb64ae6e7.baseVertexInstanceDrawing)
	x.MaxVertexBufferCount = (uint32)(x.refb64ae6e7.maxVertexBufferCount)
	x.MaxFragmentBufferCount = (uint32)(x.refb64ae6e7.maxFragmentBufferCount)
	x.BufferAlignment = (DeviceSize)(x.refb64ae6e7.bufferAlignment)
	x.PushConstantsAlignment = (DeviceSize)(x.refb64ae6e7.pushConstantsAlignment)
}

// allocMVKSwapchainPerformanceMemory allocates memory for type C.MVKSwapchainPerformance in C.
// The caller is responsible for freeing the this memory via C.free.
func allocMVKSwapchainPerformanceMemory(n int) unsafe.Pointer {
	mem, err := C.calloc(C.size_t(n), (C.size_t)(sizeOfMVKSwapchainPerformanceValue))
	if err != nil {
		panic("memory alloc error: " + err.Error())
	}
	return mem
}

const sizeOfMVKSwapchainPerformanceValue = unsafe.Sizeof([1]C.MVKSwapchainPerformance{})

// Ref returns the underlying reference to C object or nil if struct is nil.
func (x *MVKSwapchainPerformance) Ref() *C.MVKSwapchainPerformance {
	if x == nil {
		return nil
	}
	return x.refd8d60565
}

// Free invokes alloc map's free mechanism that cleanups any allocated memory using C free.
// Does nothing if struct is nil or has no allocation map.
func (x *MVKSwapchainPerformance) Free() {
	if x != nil && x.allocsd8d60565 != nil {
		x.allocsd8d60565.(*cgoAllocMap).Free()
		x.refd8d60565 = nil
	}
}

// NewMVKSwapchainPerformanceRef creates a new wrapper struct with underlying reference set to the original C object.
// Returns nil if the provided pointer to C object is nil too.
func NewMVKSwapchainPerformanceRef(ref unsafe.Pointer) *MVKSwapchainPerformance {
	if ref == nil {
		return nil
	}
	obj := new(MVKSwapchainPerformance)
	obj.refd8d60565 = (*C.MVKSwapchainPerformance)(unsafe.Pointer(ref))
	return obj
}

// PassRef returns the underlying C object, otherwise it will allocate one and set its values
// from this wrapping struct, counting allocations into an allocation map.
func (x *MVKSwapchainPerformance) PassRef() (*C.MVKSwapchainPerformance, *cgoAllocMap) {
	if x == nil {
		return nil, nil
	} else if x.refd8d60565 != nil {
		return x.refd8d60565, nil
	}
	memd8d60565 := allocMVKSwapchainPerformanceMemory(1)
	refd8d60565 := (*C.MVKSwapchainPerformance)(memd8d60565)
	allocsd8d60565 := new(cgoAllocMap)
	var clastFrameInterval_allocs *cgoAllocMap
	refd8d60565.lastFrameInterval, clastFrameInterval_allocs = (C.double)(x.LastFrameInterval), cgoAllocsUnknown
	allocsd8d60565.Borrow(clastFrameInterval_allocs)

	var caverageFrameInterval_allocs *cgoAllocMap
	refd8d60565.averageFrameInterval, caverageFrameInterval_allocs = (C.double)(x.AverageFrameInterval), cgoAllocsUnknown
	allocsd8d60565.Borrow(caverageFrameInterval_allocs)

	var caverageFramesPerSecond_allocs *cgoAllocMap
	refd8d60565.averageFramesPerSecond, caverageFramesPerSecond_allocs = (C.double)(x.AverageFramesPerSecond), cgoAllocsUnknown
	allocsd8d60565.Borrow(caverageFramesPerSecond_allocs)

	x.refd8d60565 = refd8d60565
	x.allocsd8d60565 = allocsd8d60565
	return refd8d60565, allocsd8d60565

}

// PassValue does the same as PassRef except that it will try to dereference the returned pointer.
func (x MVKSwapchainPerformance) PassValue() (C.MVKSwapchainPerformance, *cgoAllocMap) {
	if x.refd8d60565 != nil {
		return *x.refd8d60565, nil
	}
	ref, allocs := x.PassRef()
	return *ref, allocs
}

// Deref uses the underlying reference to C object and fills the wrapping struct with values.
// Do not forget to call this method whether you get a struct for C object and want to read its values.
func (x *MVKSwapchainPerformance) Deref() {
	if x.refd8d60565 == nil {
		return
	}
	x.LastFrameInterval = (float64)(x.refd8d60565.lastFrameInterval)
	x.AverageFrameInterval = (float64)(x.refd8d60565.averageFrameInterval)
	x.AverageFramesPerSecond = (float64)(x.refd8d60565.averageFramesPerSecond)
}

// allocIOSSurfaceCreateInfoMVKMemory allocates memory for type C.VkIOSSurfaceCreateInfoMVK in C.
// The caller is responsible for freeing the this memory via C.free.
func allocIOSSurfaceCreateInfoMVKMemory(n int) unsafe.Pointer {
	mem, err := C.calloc(C.size_t(n), (C.size_t)(sizeOfIOSSurfaceCreateInfoMVKValue))
	if err != nil {
		panic("memory alloc error: " + err.Error())
	}
	return mem
}

const sizeOfIOSSurfaceCreateInfoMVKValue = unsafe.Sizeof([1]C.VkIOSSurfaceCreateInfoMVK{})

// Ref returns the underlying reference to C object or nil if struct is nil.
func (x *IOSSurfaceCreateInfoMVK) Ref() *C.VkIOSSurfaceCreateInfoMVK {
	if x == nil {
		return nil
	}
	return x.ref96717271
}

// Free invokes alloc map's free mechanism that cleanups any allocated memory using C free.
// Does nothing if struct is nil or has no allocation map.
func (x *IOSSurfaceCreateInfoMVK) Free() {
	if x != nil && x.allocs96717271 != nil {
		x.allocs96717271.(*cgoAllocMap).Free()
		x.ref96717271 = nil
	}
}

// NewIOSSurfaceCreateInfoMVKRef creates a new wrapper struct with underlying reference set to the original C object.
// Returns nil if the provided pointer to C object is nil too.
func NewIOSSurfaceCreateInfoMVKRef(ref unsafe.Pointer) *IOSSurfaceCreateInfoMVK {
	if ref == nil {
		return nil
	}
	obj := new(IOSSurfaceCreateInfoMVK)
	obj.ref96717271 = (*C.VkIOSSurfaceCreateInfoMVK)(unsafe.Pointer(ref))
	return obj
}

// PassRef returns the underlying C object, otherwise it will allocate one and set its values
// from this wrapping struct, counting allocations into an allocation map.
func (x *IOSSurfaceCreateInfoMVK) PassRef() (*C.VkIOSSurfaceCreateInfoMVK, *cgoAllocMap) {
	if x == nil {
		return nil, nil
	} else if x.ref96717271 != nil {
		return x.ref96717271, nil
	}
	mem96717271 := allocIOSSurfaceCreateInfoMVKMemory(1)
	ref96717271 := (*C.VkIOSSurfaceCreateInfoMVK)(mem96717271)
	allocs96717271 := new(cgoAllocMap)
	var csType_allocs *cgoAllocMap
	ref96717271.sType, csType_allocs = (C.VkStructureType)(x.SType), cgoAllocsUnknown
	allocs96717271.Borrow(csType_allocs)

	var cpNext_allocs *cgoAllocMap
	ref96717271.pNext, cpNext_allocs = *(*unsafe.Pointer)(unsafe.Pointer(&x.PNext)), cgoAllocsUnknown
	allocs96717271.Borrow(cpNext_allocs)

	var cflags_allocs *cgoAllocMap
	ref96717271.flags, cflags_allocs = (C.VkIOSSurfaceCreateFlagsMVK)(x.Flags), cgoAllocsUnknown
	allocs96717271.Borrow(cflags_allocs)

	var cpView_allocs *cgoAllocMap
	ref96717271.pView, cpView_allocs = *(*unsafe.Pointer)(unsafe.Pointer(&x.PView)), cgoAllocsUnknown
	allocs96717271.Borrow(cpView_allocs)

	x.ref96717271 = ref96717271
	x.allocs96717271 = allocs96717271
	return ref96717271, allocs96717271

}

// PassValue does the same as PassRef except that it will try to dereference the returned pointer.
func (x IOSSurfaceCreateInfoMVK) PassValue() (C.VkIOSSurfaceCreateInfoMVK, *cgoAllocMap) {
	if x.ref96717271 != nil {
		return *x.ref96717271, nil
	}
	ref, allocs := x.PassRef()
	return *ref, allocs
}

// Deref uses the underlying reference to C object and fills the wrapping struct with values.
// Do not forget to call this method whether you get a struct for C object and want to read its values.
func (x *IOSSurfaceCreateInfoMVK) Deref() {
	if x.ref96717271 == nil {
		return
	}
	x.SType = (StructureType)(x.ref96717271.sType)
	x.PNext = (unsafe.Pointer)(unsafe.Pointer(x.ref96717271.pNext))
	x.Flags = (IOSSurfaceCreateFlagsMVK)(x.ref96717271.flags)
	x.PView = (unsafe.Pointer)(unsafe.Pointer(x.ref96717271.pView))
}
