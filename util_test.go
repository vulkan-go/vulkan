package vulkan

import (
	"fmt"
	"testing"
	"unsafe"
)

func TestBool32B(t *testing.T) {
	if !Bool32(True).B() {
		t.Fatal("expected True to convert to true")
	}
	if Bool32(False).B() {
		t.Fatal("expected False to convert to false")
	}
}

func TestVersionHelpers(t *testing.T) {
	version := Version(MakeVersion(1, 2, 3))

	if got := version.Major(); got != 1 {
		t.Fatalf("Major() = %d, want 1", got)
	}
	if got := version.Minor(); got != 2 {
		t.Fatalf("Minor() = %d, want 2", got)
	}
	if got := version.Patch(); got != 3 {
		t.Fatalf("Patch() = %d, want 3", got)
	}
	if got := version.String(); got != "1.2.3" {
		t.Fatalf("String() = %q, want %q", got, "1.2.3")
	}
}

func TestToString(t *testing.T) {
	tests := []struct {
		name string
		buf  []byte
		want string
	}{
		{name: "nil", buf: nil, want: ""},
		{name: "terminated", buf: []byte{'v', 'k', 0, 'x'}, want: "vk"},
		{name: "unterminated", buf: []byte("vulkan"), want: "vulkan"},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := ToString(tt.buf); got != tt.want {
				t.Fatalf("ToString(%v) = %q, want %q", tt.buf, got, tt.want)
			}
		})
	}
}

func TestMemcopy(t *testing.T) {
	dst := make([]byte, 4)
	src := []byte{1, 2, 3, 4}

	if got := Memcopy(unsafe.Pointer(&dst[0]), src); got != len(src) {
		t.Fatalf("Memcopy(...) = %d, want %d", got, len(src))
	}
	for i := range src {
		if dst[i] != src[i] {
			t.Fatalf("dst[%d] = %d, want %d", i, dst[i], src[i])
		}
	}
}

func TestMemview(t *testing.T) {
	data := []byte{1, 2, 3}

	if got := Memview(data); got != unsafe.Pointer(&data[0]) {
		t.Fatalf("Memview(...) = %p, want %p", got, unsafe.Pointer(&data[0]))
	}
}

func TestNewClearValue(t *testing.T) {
	clear := NewClearValue([]float32{0.25, 0.5, 0.75, 1})
	want := [4]float32{0.25, 0.5, 0.75, 1}

	if got := *(*[4]float32)(unsafe.Pointer(&clear)); got != want {
		t.Fatalf("NewClearValue(...) = %v, want %v", got, want)
	}
}

func TestNewClearDepthStencil(t *testing.T) {
	clear := NewClearDepthStencil(0.5, 7)
	depths := *(*[2]float32)(unsafe.Pointer(&clear))
	stencils := *(*[2]uint32)(unsafe.Pointer(&clear))

	if depths[0] != 0.5 {
		t.Fatalf("depth = %v, want 0.5", depths[0])
	}
	if stencils[1] != 7 {
		t.Fatalf("stencil = %d, want 7", stencils[1])
	}
}

func TestSurfaceFromPointer(t *testing.T) {
	marker := byte(1)
	var want Surface
	*(*uintptr)(unsafe.Pointer(&want)) = uintptr(unsafe.Pointer(&marker))
	raw := uintptr(unsafe.Pointer(&want))

	if got := SurfaceFromPointer(raw); *(*uintptr)(unsafe.Pointer(&got)) != uintptr(unsafe.Pointer(&marker)) {
		t.Fatalf("SurfaceFromPointer(%#x) = %#x, want %#x", raw, *(*uintptr)(unsafe.Pointer(&got)), uintptr(unsafe.Pointer(&marker)))
	}
}

func TestErrorMappings(t *testing.T) {
	tests := []struct {
		name   string
		result Result
		want   error
	}{
		{name: "success", result: Success, want: nil},
		{name: "not ready", result: NotReady, want: warnNotReady},
		{name: "timeout", result: Timeout, want: warnTimeout},
		{name: "event set", result: EventSet, want: warnEventSet},
		{name: "event reset", result: EventReset, want: warnEventReset},
		{name: "incomplete", result: Incomplete, want: warnIncomplete},
		{name: "out of host memory", result: ErrorOutOfHostMemory, want: errOutOfHostMemory},
		{name: "out of device memory", result: ErrorOutOfDeviceMemory, want: errOutOfDeviceMemory},
		{name: "initialization failed", result: ErrorInitializationFailed, want: errInitializationFailed},
		{name: "device lost", result: ErrorDeviceLost, want: errDeviceLost},
		{name: "memory map failed", result: ErrorMemoryMapFailed, want: errMemoryMapFailed},
		{name: "layer not present", result: ErrorLayerNotPresent, want: errLayerNotPresent},
		{name: "extension not present", result: ErrorExtensionNotPresent, want: errExtensionNotPresent},
		{name: "feature not present", result: ErrorFeatureNotPresent, want: errFeatureNotPresent},
		{name: "incompatible driver", result: ErrorIncompatibleDriver, want: errIncompatibleDriver},
		{name: "too many objects", result: ErrorTooManyObjects, want: errTooManyObjects},
		{name: "format not supported", result: ErrorFormatNotSupported, want: errFormatNotSupported},
		{name: "fragmented pool", result: ErrorFragmentedPool, want: errFragmentedPool},
		{name: "out of pool memory", result: ErrorOutOfPoolMemory, want: errOutOfPoolMemory},
		{name: "invalid external handle", result: ErrorInvalidExternalHandle, want: errInvalidExternalHandle},
		{name: "surface lost", result: ErrorSurfaceLost, want: errSurfaceLostKHR},
		{name: "native window in use", result: ErrorNativeWindowInUse, want: errNativeWindowInUseKHR},
		{name: "suboptimal", result: Suboptimal, want: warnSuboptimalKHR},
		{name: "out of date", result: ErrorOutOfDate, want: errOutOfDateKHR},
		{name: "incompatible display", result: ErrorIncompatibleDisplay, want: errIncompatibleDisplayKHR},
		{name: "validation failed", result: ErrorValidationFailed, want: errValidationFailedEXT},
		{name: "invalid shader", result: ErrorInvalidShaderNv, want: errInvalidShaderNV},
		{name: "invalid drm format modifier plane layout", result: ErrorInvalidDrmFormatModifierPlaneLayout, want: errInvalidDrmFormatModifierPlaneLayout},
		{name: "fragmentation", result: ErrorFragmentation, want: errFragmentation},
		{name: "not permitted", result: ErrorNotPermitted, want: errNotPermitted},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := Error(tt.result); got != tt.want {
				t.Fatalf("Error(%v) = %v, want %v", tt.result, got, tt.want)
			}
		})
	}
}

func TestErrorUnknownResult(t *testing.T) {
	result := Result(12345)
	want := fmt.Sprintf("vulkan error: unknown %v", result)

	if got := Error(result); got == nil || got.Error() != want {
		t.Fatalf("Error(%v) = %v, want %q", result, got, want)
	}
}