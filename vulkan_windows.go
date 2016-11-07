// +build windows

package vulkan

/*
#cgo CFLAGS: -I. -DVK_NO_PROTOTYPES
#cgo windows CFLAGS: -DVK_USE_PLATFORM_WIN32_KHR -D_GLFW_WIN32 -DGLFW_INCLUDE_VULKAN
#cgo windows LDFLAGS: -lglfw3 -lgdi32 -Wl,--allow-multiple-definition

#include <GLFW/glfw3.h>

#include "vk_wrapper.h"
#include "vk_bridge.h"
*/
import "C"
import "unsafe"

const (
	// UsePlatformWin32 as defined in https://www.khronos.org/registry/vulkan/specs/1.0-wsi_extensions/xhtml/vkspec.html
	UsePlatformWin32 = 1
	// KhrWin32Surface as defined in vulkan/vulkan.h:3697
	KhrWin32Surface = 1
	// KhrWin32SurfaceSpecVersion as defined in vulkan/vulkan.h:3700
	KhrWin32SurfaceSpecVersion = 5
	// KhrWin32SurfaceExtensionName as defined in vulkan/vulkan.h:3701
	KhrWin32SurfaceExtensionName = "VK_KHR_win32_surface"
	// NvExternalMemoryWin32 as defined in vulkan/vulkan.h:4085
	NvExternalMemoryWin32 = 1
	// NvExternalMemoryWin32SpecVersion as defined in vulkan/vulkan.h:4086
	NvExternalMemoryWin32SpecVersion = 1
	// NvExternalMemoryWin32ExtensionName as defined in vulkan/vulkan.h:4087
	NvExternalMemoryWin32ExtensionName = "VK_NV_external_memory_win32"
	// NvWin32KeyedMutex as defined in vulkan/vulkan.h:4116
	NvWin32KeyedMutex = 1
	// NvWin32KeyedMutexSpecVersion as defined in vulkan/vulkan.h:4117
	NvWin32KeyedMutexSpecVersion = 1
	// NvWin32KeyedMutexExtensionName as defined in vulkan/vulkan.h:4118
	NvWin32KeyedMutexExtensionName = "VK_NV_win32_keyed_mutex"
)

type (
	HINSTANCE           unsafe.Pointer
	HWND                unsafe.Pointer
	HANDLE              unsafe.Pointer
	SECURITY_ATTRIBUTES C.SECURITY_ATTRIBUTES
	DWORD               C.DWORD
)

// CreateWindowSurface creates a Vulkan surface (VK_KHR_win32_surface) for a GLFW window with glfwCreateWindowSurface.
// See http://www.glfw.org/docs/latest/group__vulkan.html#ga1a24536bec3f80b08ead18e28e6ae965
func CreateWindowSurface(instance Instance, glfwWindow uintptr, pAllocator *AllocationCallbacks, pSurface *Surface) Result {
	cinstance, _ := *(*C.VkInstance)(unsafe.Pointer(&instance)), cgoAllocsUnknown
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

// CreateWin32Surface function as declared in https://www.khronos.org/registry/vulkan/specs/1.0-wsi_extensions/xhtml/vkspec.html#vkCreateWin32SurfaceKHR
func CreateWin32Surface(instance Instance, pCreateInfo *Win32SurfaceCreateInfo, pAllocator *AllocationCallbacks, pSurface *Surface) Result {
	cinstance, _ := (C.VkInstance)(instance), cgoAllocsUnknown
	cpCreateInfo, _ := pCreateInfo.PassRef()
	cpAllocator, _ := (*C.VkAllocationCallbacks)(unsafe.Pointer(pAllocator)), cgoAllocsUnknown
	cpSurface, _ := (*C.VkSurfaceKHR)(unsafe.Pointer(pSurface)), cgoAllocsUnknown
	__ret := C.callVkCreateWin32SurfaceKHR(cinstance, cpCreateInfo, cpAllocator, cpSurface)
	__v := (Result)(__ret)
	return __v
}

// GetPhysicalDeviceWin32PresentationSupport function as declared in https://www.khronos.org/registry/vulkan/specs/1.0-wsi_extensions/xhtml/vkspec.html#vkGetPhysicalDeviceWin32PresentationSupportKHR
func GetPhysicalDeviceWin32PresentationSupport(physicalDevice PhysicalDevice, queueFamilyIndex uint32) Bool32 {
	cphysicalDevice, _ := *(*C.VkPhysicalDevice)(unsafe.Pointer(&physicalDevice)), cgoAllocsUnknown
	cqueueFamilyIndex, _ := (C.uint32_t)(queueFamilyIndex), cgoAllocsUnknown
	__ret := C.callVkGetPhysicalDeviceWin32PresentationSupportKHR(cphysicalDevice, cqueueFamilyIndex)
	__v := (Bool32)(__ret)
	return __v
}

// ImportMemoryWin32HandleInfoNV as declared in https://www.khronos.org/registry/vulkan/specs/1.0/man/html/VkImportMemoryWin32HandleInfoNV.html
type ImportMemoryWin32HandleInfoNV struct {
	SType          StructureType
	PNext          unsafe.Pointer
	HandleType     ExternalMemoryHandleTypeFlagsNV
	Handle         HANDLE
	ref6171f825    *C.VkImportMemoryWin32HandleInfoNV
	allocs6171f825 interface{}
}

// ExportMemoryWin32HandleInfoNV as declared in https://www.khronos.org/registry/vulkan/specs/1.0/man/html/VkExportMemoryWin32HandleInfoNV.html
type ExportMemoryWin32HandleInfoNV struct {
	SType          StructureType
	PNext          unsafe.Pointer
	PAttributes    *SECURITY_ATTRIBUTES
	DwAccess       DWORD
	ref84fe87ef    *C.VkExportMemoryWin32HandleInfoNV
	allocs84fe87ef interface{}
}

// Win32KeyedMutexAcquireReleaseInfoNV as declared in https://www.khronos.org/registry/vulkan/specs/1.0/man/html/VkWin32KeyedMutexAcquireReleaseInfoNV.html
type Win32KeyedMutexAcquireReleaseInfoNV struct {
	SType                       StructureType
	PNext                       unsafe.Pointer
	AcquireCount                uint32
	PAcquireSyncs               []DeviceMemory
	PAcquireKeys                []uint64
	PAcquireTimeoutMilliseconds []uint32
	ReleaseCount                uint32
	PReleaseSyncs               []DeviceMemory
	PReleaseKeys                []uint64
	refd7d87b9a                 *C.VkWin32KeyedMutexAcquireReleaseInfoNV
	allocsd7d87b9a              interface{}
}

// Win32SurfaceCreateFlags type as declared in https://www.khronos.org/registry/vulkan/specs/1.0-wsi_extensions/xhtml/vkspec.html#vkWin32SurfaceCreateFlagsKHR
type Win32SurfaceCreateFlags uint32

// Win32SurfaceCreateInfo as declared in https://www.khronos.org/registry/vulkan/specs/1.0-wsi_extensions/xhtml/vkspec.html#vkWin32SurfaceCreateInfoKHR
type Win32SurfaceCreateInfo struct {
	SType          StructureType
	PNext          unsafe.Pointer
	Flags          Win32SurfaceCreateFlags
	Hinstance      HINSTANCE
	Hwnd           HWND
	ref8747e274    *C.VkWin32SurfaceCreateInfoKHR
	allocs8747e274 interface{}
}

// allocWin32SurfaceCreateInfoMemory allocates memory for type C.VkWin32SurfaceCreateInfoKHR in C.
// The caller is responsible for freeing the this memory via C.free.
func allocWin32SurfaceCreateInfoMemory(n int) unsafe.Pointer {
	mem, err := C.calloc(C.size_t(n), (C.size_t)(sizeOfWin32SurfaceCreateInfoValue))
	if err != nil {
		panic("memory alloc error: " + err.Error())
	}
	return mem
}

const sizeOfWin32SurfaceCreateInfoValue = unsafe.Sizeof([1]C.VkWin32SurfaceCreateInfoKHR{})

// Ref returns the underlying reference to C object or nil if struct is nil.
func (x *Win32SurfaceCreateInfo) Ref() *C.VkWin32SurfaceCreateInfoKHR {
	if x == nil {
		return nil
	}
	return x.ref8747e274
}

// Free invokes alloc map's free mechanism that cleanups any allocated memory using C free.
// Does nothing if struct is nil or has no allocation map.
func (x *Win32SurfaceCreateInfo) Free() {
	if x != nil && x.allocs8747e274 != nil {
		x.allocs8747e274.(*cgoAllocMap).Free()
		x.ref8747e274 = nil
	}
}

// NewWin32SurfaceCreateInfoRef creates a new wrapper struct with underlying reference set to the original C object.
// Returns nil if the provided pointer to C object is nil too.
func NewWin32SurfaceCreateInfoRef(ref unsafe.Pointer) *Win32SurfaceCreateInfo {
	if ref == nil {
		return nil
	}
	obj := new(Win32SurfaceCreateInfo)
	obj.ref8747e274 = (*C.VkWin32SurfaceCreateInfoKHR)(unsafe.Pointer(ref))
	return obj
}

// PassRef returns the underlying C object, otherwise it will allocate one and set its values
// from this wrapping struct, counting allocations into an allocation map.
func (x *Win32SurfaceCreateInfo) PassRef() (*C.VkWin32SurfaceCreateInfoKHR, *cgoAllocMap) {
	if x == nil {
		return nil, nil
	} else if x.ref8747e274 != nil {
		return x.ref8747e274, nil
	}
	mem8747e274 := allocWin32SurfaceCreateInfoMemory(1)
	ref8747e274 := (*C.VkWin32SurfaceCreateInfoKHR)(mem8747e274)
	allocs8747e274 := new(cgoAllocMap)
	var csType_allocs *cgoAllocMap
	ref8747e274.sType, csType_allocs = (C.VkStructureType)(x.SType), cgoAllocsUnknown
	allocs8747e274.Borrow(csType_allocs)

	var cpNext_allocs *cgoAllocMap
	ref8747e274.pNext, cpNext_allocs = *(*unsafe.Pointer)(unsafe.Pointer(&x.PNext)), cgoAllocsUnknown
	allocs8747e274.Borrow(cpNext_allocs)

	var cflags_allocs *cgoAllocMap
	ref8747e274.flags, cflags_allocs = (C.VkWin32SurfaceCreateFlagsKHR)(x.Flags), cgoAllocsUnknown
	allocs8747e274.Borrow(cflags_allocs)

	var chinstance_allocs *cgoAllocMap
	ref8747e274.hinstance, chinstance_allocs = (C.HINSTANCE)(x.Hinstance), cgoAllocsUnknown
	allocs8747e274.Borrow(chinstance_allocs)

	var chwnd_allocs *cgoAllocMap
	ref8747e274.hwnd, chwnd_allocs = (C.HWND)(x.Hwnd), cgoAllocsUnknown
	allocs8747e274.Borrow(chwnd_allocs)

	x.ref8747e274 = ref8747e274
	x.allocs8747e274 = allocs8747e274
	return ref8747e274, allocs8747e274

}

// PassValue does the same as PassRef except that it will try to dereference the returned pointer.
func (x Win32SurfaceCreateInfo) PassValue() (C.VkWin32SurfaceCreateInfoKHR, *cgoAllocMap) {
	if x.ref8747e274 != nil {
		return *x.ref8747e274, nil
	}
	ref, allocs := x.PassRef()
	return *ref, allocs
}

// Deref uses the underlying reference to C object and fills the wrapping struct with values.
// Do not forget to call this method whether you get a struct for C object and want to read its values.
func (x *Win32SurfaceCreateInfo) Deref() {
	if x.ref8747e274 == nil {
		return
	}
	x.SType = (StructureType)(x.ref8747e274.sType)
	x.PNext = (unsafe.Pointer)(unsafe.Pointer(x.ref8747e274.pNext))
	x.Flags = (Win32SurfaceCreateFlags)(x.ref8747e274.flags)
	x.Hinstance = (HINSTANCE)(x.ref8747e274.hinstance)
	x.Hwnd = (HWND)(x.ref8747e274.hwnd)
}

// allocImportMemoryWin32HandleInfoNVMemory allocates memory for type C.VkImportMemoryWin32HandleInfoNV in C.
// The caller is responsible for freeing the this memory via C.free.
func allocImportMemoryWin32HandleInfoNVMemory(n int) unsafe.Pointer {
	mem, err := C.calloc(C.size_t(n), (C.size_t)(sizeOfImportMemoryWin32HandleInfoNVValue))
	if err != nil {
		panic("memory alloc error: " + err.Error())
	}
	return mem
}

const sizeOfImportMemoryWin32HandleInfoNVValue = unsafe.Sizeof([1]C.VkImportMemoryWin32HandleInfoNV{})

// Ref returns the underlying reference to C object or nil if struct is nil.
func (x *ImportMemoryWin32HandleInfoNV) Ref() *C.VkImportMemoryWin32HandleInfoNV {
	if x == nil {
		return nil
	}
	return x.ref6171f825
}

// Free invokes alloc map's free mechanism that cleanups any allocated memory using C free.
// Does nothing if struct is nil or has no allocation map.
func (x *ImportMemoryWin32HandleInfoNV) Free() {
	if x != nil && x.allocs6171f825 != nil {
		x.allocs6171f825.(*cgoAllocMap).Free()
		x.ref6171f825 = nil
	}
}

// NewImportMemoryWin32HandleInfoNVRef creates a new wrapper struct with underlying reference set to the original C object.
// Returns nil if the provided pointer to C object is nil too.
func NewImportMemoryWin32HandleInfoNVRef(ref unsafe.Pointer) *ImportMemoryWin32HandleInfoNV {
	if ref == nil {
		return nil
	}
	obj := new(ImportMemoryWin32HandleInfoNV)
	obj.ref6171f825 = (*C.VkImportMemoryWin32HandleInfoNV)(unsafe.Pointer(ref))
	return obj
}

// PassRef returns the underlying C object, otherwise it will allocate one and set its values
// from this wrapping struct, counting allocations into an allocation map.
func (x *ImportMemoryWin32HandleInfoNV) PassRef() (*C.VkImportMemoryWin32HandleInfoNV, *cgoAllocMap) {
	if x == nil {
		return nil, nil
	} else if x.ref6171f825 != nil {
		return x.ref6171f825, nil
	}
	mem6171f825 := allocImportMemoryWin32HandleInfoNVMemory(1)
	ref6171f825 := (*C.VkImportMemoryWin32HandleInfoNV)(mem6171f825)
	allocs6171f825 := new(cgoAllocMap)
	var csType_allocs *cgoAllocMap
	ref6171f825.sType, csType_allocs = (C.VkStructureType)(x.SType), cgoAllocsUnknown
	allocs6171f825.Borrow(csType_allocs)

	var cpNext_allocs *cgoAllocMap
	ref6171f825.pNext, cpNext_allocs = *(*unsafe.Pointer)(unsafe.Pointer(&x.PNext)), cgoAllocsUnknown
	allocs6171f825.Borrow(cpNext_allocs)

	var chandleType_allocs *cgoAllocMap
	ref6171f825.handleType, chandleType_allocs = (C.VkExternalMemoryHandleTypeFlagsNV)(x.HandleType), cgoAllocsUnknown
	allocs6171f825.Borrow(chandleType_allocs)

	var chandle_allocs *cgoAllocMap
	ref6171f825.handle, chandle_allocs = (C.HANDLE)(x.Handle), cgoAllocsUnknown
	allocs6171f825.Borrow(chandle_allocs)

	x.ref6171f825 = ref6171f825
	x.allocs6171f825 = allocs6171f825
	return ref6171f825, allocs6171f825

}

// PassValue does the same as PassRef except that it will try to dereference the returned pointer.
func (x ImportMemoryWin32HandleInfoNV) PassValue() (C.VkImportMemoryWin32HandleInfoNV, *cgoAllocMap) {
	if x.ref6171f825 != nil {
		return *x.ref6171f825, nil
	}
	ref, allocs := x.PassRef()
	return *ref, allocs
}

// Deref uses the underlying reference to C object and fills the wrapping struct with values.
// Do not forget to call this method whether you get a struct for C object and want to read its values.
func (x *ImportMemoryWin32HandleInfoNV) Deref() {
	if x.ref6171f825 == nil {
		return
	}
	x.SType = (StructureType)(x.ref6171f825.sType)
	x.PNext = (unsafe.Pointer)(unsafe.Pointer(x.ref6171f825.pNext))
	x.HandleType = (ExternalMemoryHandleTypeFlagsNV)(x.ref6171f825.handleType)
	x.Handle = (HANDLE)(x.ref6171f825.handle)
}

// allocExportMemoryWin32HandleInfoNVMemory allocates memory for type C.VkExportMemoryWin32HandleInfoNV in C.
// The caller is responsible for freeing the this memory via C.free.
func allocExportMemoryWin32HandleInfoNVMemory(n int) unsafe.Pointer {
	mem, err := C.calloc(C.size_t(n), (C.size_t)(sizeOfExportMemoryWin32HandleInfoNVValue))
	if err != nil {
		panic("memory alloc error: " + err.Error())
	}
	return mem
}

const sizeOfExportMemoryWin32HandleInfoNVValue = unsafe.Sizeof([1]C.VkExportMemoryWin32HandleInfoNV{})

// Ref returns the underlying reference to C object or nil if struct is nil.
func (x *ExportMemoryWin32HandleInfoNV) Ref() *C.VkExportMemoryWin32HandleInfoNV {
	if x == nil {
		return nil
	}
	return x.ref84fe87ef
}

// Free invokes alloc map's free mechanism that cleanups any allocated memory using C free.
// Does nothing if struct is nil or has no allocation map.
func (x *ExportMemoryWin32HandleInfoNV) Free() {
	if x != nil && x.allocs84fe87ef != nil {
		x.allocs84fe87ef.(*cgoAllocMap).Free()
		x.ref84fe87ef = nil
	}
}

// NewExportMemoryWin32HandleInfoNVRef creates a new wrapper struct with underlying reference set to the original C object.
// Returns nil if the provided pointer to C object is nil too.
func NewExportMemoryWin32HandleInfoNVRef(ref unsafe.Pointer) *ExportMemoryWin32HandleInfoNV {
	if ref == nil {
		return nil
	}
	obj := new(ExportMemoryWin32HandleInfoNV)
	obj.ref84fe87ef = (*C.VkExportMemoryWin32HandleInfoNV)(unsafe.Pointer(ref))
	return obj
}

// PassRef returns the underlying C object, otherwise it will allocate one and set its values
// from this wrapping struct, counting allocations into an allocation map.
func (x *ExportMemoryWin32HandleInfoNV) PassRef() (*C.VkExportMemoryWin32HandleInfoNV, *cgoAllocMap) {
	if x == nil {
		return nil, nil
	} else if x.ref84fe87ef != nil {
		return x.ref84fe87ef, nil
	}
	mem84fe87ef := allocExportMemoryWin32HandleInfoNVMemory(1)
	ref84fe87ef := (*C.VkExportMemoryWin32HandleInfoNV)(mem84fe87ef)
	allocs84fe87ef := new(cgoAllocMap)
	var csType_allocs *cgoAllocMap
	ref84fe87ef.sType, csType_allocs = (C.VkStructureType)(x.SType), cgoAllocsUnknown
	allocs84fe87ef.Borrow(csType_allocs)

	var cpNext_allocs *cgoAllocMap
	ref84fe87ef.pNext, cpNext_allocs = *(*unsafe.Pointer)(unsafe.Pointer(&x.PNext)), cgoAllocsUnknown
	allocs84fe87ef.Borrow(cpNext_allocs)

	var cpAttributes_allocs *cgoAllocMap
	ref84fe87ef.pAttributes, cpAttributes_allocs = *(**C.SECURITY_ATTRIBUTES)(unsafe.Pointer(&x.PAttributes)), cgoAllocsUnknown
	allocs84fe87ef.Borrow(cpAttributes_allocs)

	var cdwAccess_allocs *cgoAllocMap
	ref84fe87ef.dwAccess, cdwAccess_allocs = *(*C.DWORD)(unsafe.Pointer(&x.DwAccess)), cgoAllocsUnknown
	allocs84fe87ef.Borrow(cdwAccess_allocs)

	x.ref84fe87ef = ref84fe87ef
	x.allocs84fe87ef = allocs84fe87ef
	return ref84fe87ef, allocs84fe87ef

}

// PassValue does the same as PassRef except that it will try to dereference the returned pointer.
func (x ExportMemoryWin32HandleInfoNV) PassValue() (C.VkExportMemoryWin32HandleInfoNV, *cgoAllocMap) {
	if x.ref84fe87ef != nil {
		return *x.ref84fe87ef, nil
	}
	ref, allocs := x.PassRef()
	return *ref, allocs
}

// Deref uses the underlying reference to C object and fills the wrapping struct with values.
// Do not forget to call this method whether you get a struct for C object and want to read its values.
func (x *ExportMemoryWin32HandleInfoNV) Deref() {
	if x.ref84fe87ef == nil {
		return
	}
	x.SType = (StructureType)(x.ref84fe87ef.sType)
	x.PNext = (unsafe.Pointer)(unsafe.Pointer(x.ref84fe87ef.pNext))
	x.PAttributes = (*SECURITY_ATTRIBUTES)(unsafe.Pointer(x.ref84fe87ef.pAttributes))
	x.DwAccess = *(*DWORD)(unsafe.Pointer(&x.ref84fe87ef.dwAccess))
}

// allocWin32KeyedMutexAcquireReleaseInfoNVMemory allocates memory for type C.VkWin32KeyedMutexAcquireReleaseInfoNV in C.
// The caller is responsible for freeing the this memory via C.free.
func allocWin32KeyedMutexAcquireReleaseInfoNVMemory(n int) unsafe.Pointer {
	mem, err := C.calloc(C.size_t(n), (C.size_t)(sizeOfWin32KeyedMutexAcquireReleaseInfoNVValue))
	if err != nil {
		panic("memory alloc error: " + err.Error())
	}
	return mem
}

const sizeOfWin32KeyedMutexAcquireReleaseInfoNVValue = unsafe.Sizeof([1]C.VkWin32KeyedMutexAcquireReleaseInfoNV{})

// Ref returns the underlying reference to C object or nil if struct is nil.
func (x *Win32KeyedMutexAcquireReleaseInfoNV) Ref() *C.VkWin32KeyedMutexAcquireReleaseInfoNV {
	if x == nil {
		return nil
	}
	return x.refd7d87b9a
}

// Free invokes alloc map's free mechanism that cleanups any allocated memory using C free.
// Does nothing if struct is nil or has no allocation map.
func (x *Win32KeyedMutexAcquireReleaseInfoNV) Free() {
	if x != nil && x.allocsd7d87b9a != nil {
		x.allocsd7d87b9a.(*cgoAllocMap).Free()
		x.refd7d87b9a = nil
	}
}

// NewWin32KeyedMutexAcquireReleaseInfoNVRef creates a new wrapper struct with underlying reference set to the original C object.
// Returns nil if the provided pointer to C object is nil too.
func NewWin32KeyedMutexAcquireReleaseInfoNVRef(ref unsafe.Pointer) *Win32KeyedMutexAcquireReleaseInfoNV {
	if ref == nil {
		return nil
	}
	obj := new(Win32KeyedMutexAcquireReleaseInfoNV)
	obj.refd7d87b9a = (*C.VkWin32KeyedMutexAcquireReleaseInfoNV)(unsafe.Pointer(ref))
	return obj
}

// PassRef returns the underlying C object, otherwise it will allocate one and set its values
// from this wrapping struct, counting allocations into an allocation map.
func (x *Win32KeyedMutexAcquireReleaseInfoNV) PassRef() (*C.VkWin32KeyedMutexAcquireReleaseInfoNV, *cgoAllocMap) {
	if x == nil {
		return nil, nil
	} else if x.refd7d87b9a != nil {
		return x.refd7d87b9a, nil
	}
	memd7d87b9a := allocWin32KeyedMutexAcquireReleaseInfoNVMemory(1)
	refd7d87b9a := (*C.VkWin32KeyedMutexAcquireReleaseInfoNV)(memd7d87b9a)
	allocsd7d87b9a := new(cgoAllocMap)
	var csType_allocs *cgoAllocMap
	refd7d87b9a.sType, csType_allocs = (C.VkStructureType)(x.SType), cgoAllocsUnknown
	allocsd7d87b9a.Borrow(csType_allocs)

	var cpNext_allocs *cgoAllocMap
	refd7d87b9a.pNext, cpNext_allocs = *(*unsafe.Pointer)(unsafe.Pointer(&x.PNext)), cgoAllocsUnknown
	allocsd7d87b9a.Borrow(cpNext_allocs)

	var cacquireCount_allocs *cgoAllocMap
	refd7d87b9a.acquireCount, cacquireCount_allocs = (C.uint32_t)(x.AcquireCount), cgoAllocsUnknown
	allocsd7d87b9a.Borrow(cacquireCount_allocs)

	var cpAcquireSyncs_allocs *cgoAllocMap
	refd7d87b9a.pAcquireSyncs, cpAcquireSyncs_allocs = (*C.VkDeviceMemory)(unsafe.Pointer((*sliceHeader)(unsafe.Pointer(&x.PAcquireSyncs)).Data)), cgoAllocsUnknown
	allocsd7d87b9a.Borrow(cpAcquireSyncs_allocs)

	var cpAcquireKeys_allocs *cgoAllocMap
	refd7d87b9a.pAcquireKeys, cpAcquireKeys_allocs = (*C.uint64_t)(unsafe.Pointer((*sliceHeader)(unsafe.Pointer(&x.PAcquireKeys)).Data)), cgoAllocsUnknown
	allocsd7d87b9a.Borrow(cpAcquireKeys_allocs)

	var cpAcquireTimeoutMilliseconds_allocs *cgoAllocMap
	refd7d87b9a.pAcquireTimeoutMilliseconds, cpAcquireTimeoutMilliseconds_allocs = (*C.uint32_t)(unsafe.Pointer((*sliceHeader)(unsafe.Pointer(&x.PAcquireTimeoutMilliseconds)).Data)), cgoAllocsUnknown
	allocsd7d87b9a.Borrow(cpAcquireTimeoutMilliseconds_allocs)

	var creleaseCount_allocs *cgoAllocMap
	refd7d87b9a.releaseCount, creleaseCount_allocs = (C.uint32_t)(x.ReleaseCount), cgoAllocsUnknown
	allocsd7d87b9a.Borrow(creleaseCount_allocs)

	var cpReleaseSyncs_allocs *cgoAllocMap
	refd7d87b9a.pReleaseSyncs, cpReleaseSyncs_allocs = (*C.VkDeviceMemory)(unsafe.Pointer((*sliceHeader)(unsafe.Pointer(&x.PReleaseSyncs)).Data)), cgoAllocsUnknown
	allocsd7d87b9a.Borrow(cpReleaseSyncs_allocs)

	var cpReleaseKeys_allocs *cgoAllocMap
	refd7d87b9a.pReleaseKeys, cpReleaseKeys_allocs = (*C.uint64_t)(unsafe.Pointer((*sliceHeader)(unsafe.Pointer(&x.PReleaseKeys)).Data)), cgoAllocsUnknown
	allocsd7d87b9a.Borrow(cpReleaseKeys_allocs)

	x.refd7d87b9a = refd7d87b9a
	x.allocsd7d87b9a = allocsd7d87b9a
	return refd7d87b9a, allocsd7d87b9a

}

// PassValue does the same as PassRef except that it will try to dereference the returned pointer.
func (x Win32KeyedMutexAcquireReleaseInfoNV) PassValue() (C.VkWin32KeyedMutexAcquireReleaseInfoNV, *cgoAllocMap) {
	if x.refd7d87b9a != nil {
		return *x.refd7d87b9a, nil
	}
	ref, allocs := x.PassRef()
	return *ref, allocs
}

// Deref uses the underlying reference to C object and fills the wrapping struct with values.
// Do not forget to call this method whether you get a struct for C object and want to read its values.
func (x *Win32KeyedMutexAcquireReleaseInfoNV) Deref() {
	if x.refd7d87b9a == nil {
		return
	}
	x.SType = (StructureType)(x.refd7d87b9a.sType)
	x.PNext = (unsafe.Pointer)(unsafe.Pointer(x.refd7d87b9a.pNext))
	x.AcquireCount = (uint32)(x.refd7d87b9a.acquireCount)
	hxf5ebb88 := (*sliceHeader)(unsafe.Pointer(&x.PAcquireSyncs))
	hxf5ebb88.Data = uintptr(unsafe.Pointer(x.refd7d87b9a.pAcquireSyncs))
	hxf5ebb88.Cap = 0x7fffffff
	// hxf5ebb88.Len = ?

	hxff20e84 := (*sliceHeader)(unsafe.Pointer(&x.PAcquireKeys))
	hxff20e84.Data = uintptr(unsafe.Pointer(x.refd7d87b9a.pAcquireKeys))
	hxff20e84.Cap = 0x7fffffff
	// hxff20e84.Len = ?

	hxfa26a4d := (*sliceHeader)(unsafe.Pointer(&x.PAcquireTimeoutMilliseconds))
	hxfa26a4d.Data = uintptr(unsafe.Pointer(x.refd7d87b9a.pAcquireTimeoutMilliseconds))
	hxfa26a4d.Cap = 0x7fffffff
	// hxfa26a4d.Len = ?

	x.ReleaseCount = (uint32)(x.refd7d87b9a.releaseCount)
	hxfe48098 := (*sliceHeader)(unsafe.Pointer(&x.PReleaseSyncs))
	hxfe48098.Data = uintptr(unsafe.Pointer(x.refd7d87b9a.pReleaseSyncs))
	hxfe48098.Cap = 0x7fffffff
	// hxfe48098.Len = ?

	hxffe3496 := (*sliceHeader)(unsafe.Pointer(&x.PReleaseKeys))
	hxffe3496.Data = uintptr(unsafe.Pointer(x.refd7d87b9a.pReleaseKeys))
	hxffe3496.Cap = 0x7fffffff
	// hxffe3496.Len = ?

}

// Ref returns a reference to C object as it is.
func (x *SECURITY_ATTRIBUTES) Ref() *C.SECURITY_ATTRIBUTES {
	if x == nil {
		return nil
	}
	return (*C.SECURITY_ATTRIBUTES)(unsafe.Pointer(x))
}

// Free cleanups the referenced memory using C free.
func (x *SECURITY_ATTRIBUTES) Free() {
	if x != nil {
		C.free(unsafe.Pointer(x))
	}
}

// NewSECURITY_ATTRIBUTESRef converts the C object reference into a raw struct reference without wrapping.
func NewSECURITY_ATTRIBUTESRef(ref unsafe.Pointer) *SECURITY_ATTRIBUTES {
	return (*SECURITY_ATTRIBUTES)(ref)
}

// NewSECURITY_ATTRIBUTES allocates a new C object of this type and converts the reference into
// a raw struct reference without wrapping.
func NewSECURITY_ATTRIBUTES() *SECURITY_ATTRIBUTES {
	return (*SECURITY_ATTRIBUTES)(allocSECURITY_ATTRIBUTESMemory(1))
}

// allocSECURITY_ATTRIBUTESMemory allocates memory for type C.SECURITY_ATTRIBUTES in C.
// The caller is responsible for freeing the this memory via C.free.
func allocSECURITY_ATTRIBUTESMemory(n int) unsafe.Pointer {
	mem, err := C.calloc(C.size_t(n), (C.size_t)(sizeOfSECURITY_ATTRIBUTESValue))
	if err != nil {
		panic("memory alloc error: " + err.Error())
	}
	return mem
}

const sizeOfSECURITY_ATTRIBUTESValue = unsafe.Sizeof([1]C.SECURITY_ATTRIBUTES{})

// PassRef returns a reference to C object as it is or allocates a new C object of this type.
func (x *SECURITY_ATTRIBUTES) PassRef() *C.SECURITY_ATTRIBUTES {
	if x == nil {
		x = (*SECURITY_ATTRIBUTES)(allocSECURITY_ATTRIBUTESMemory(1))
	}
	return (*C.SECURITY_ATTRIBUTES)(unsafe.Pointer(x))
}

// Ref returns a reference to C object as it is.
func (x *DWORD) Ref() *C.DWORD {
	if x == nil {
		return nil
	}
	return (*C.DWORD)(unsafe.Pointer(x))
}

// Free cleanups the referenced memory using C free.
func (x *DWORD) Free() {
	if x != nil {
		C.free(unsafe.Pointer(x))
	}
}

// NewDWORDRef converts the C object reference into a raw struct reference without wrapping.
func NewDWORDRef(ref unsafe.Pointer) *DWORD {
	return (*DWORD)(ref)
}

// NewDWORD allocates a new C object of this type and converts the reference into
// a raw struct reference without wrapping.
func NewDWORD() *DWORD {
	return (*DWORD)(allocDWORDMemory(1))
}

// allocDWORDMemory allocates memory for type C.DWORD in C.
// The caller is responsible for freeing the this memory via C.free.
func allocDWORDMemory(n int) unsafe.Pointer {
	mem, err := C.calloc(C.size_t(n), (C.size_t)(sizeOfDWORDValue))
	if err != nil {
		panic("memory alloc error: " + err.Error())
	}
	return mem
}

const sizeOfDWORDValue = unsafe.Sizeof([1]C.DWORD{})

// PassRef returns a reference to C object as it is or allocates a new C object of this type.
func (x *DWORD) PassRef() *C.DWORD {
	if x == nil {
		x = (*DWORD)(allocDWORDMemory(1))
	}
	return (*C.DWORD)(unsafe.Pointer(x))
}
