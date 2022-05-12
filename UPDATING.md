Notes on updating to newer versions of Vulkan, this is from version 1.3.211.0 of https://vulkan.lunarg.com/sdk/home

* Install [c-for-go](https://github.com/xlab/c-for-go) -- revert to the same version that was used to build the original `vulkan-go` from Oct 14, 2018 -- the current version as of 5/12/22 is apparently causing the crash from my first attempt.

```Go
$ git checkout d57f9ec2a5f5456377e535ad9d81bb9b9b2797d9
```

* On the Mac, I had to put the standard C includes in a convenient place for the c-for-go parser:

```bash
$ sudo su
$ cd /usr/local
$ mkdir stdinclude
$ cp -av /Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/* stdinclude/
```

and replaced the type definitions in `stddef.h` with something that c-for-go could parse (see below).

and then added `/usr/local/stdinclude` to the `vulkan.yml` include paths.

I could not see how to get it to produce `uint` from any `C` types, so `size_t` is defined as `uint64` instead of `uint` as in the original.  This means it won't work on a 32 bit system presumably -- it is a bit difficult to figure out exactly which uint64's need to be replaced, but someone could figure that out..

* Copy .h files from new version of Vulkan into `vulkan` dir:

```bash
$ cp /usr/local/include/vulkan/*.h vulkan/
```

* Also copied updated v1.19 to `moltenVK/vk_mvk_moltenvk.h`

* Apply patch shown below to `vulkan_core.h` to exclude a few things that didn't result in buildable `cgo_helpers.go` -- probably these could be fixed but easier to skip for now.

* `make all` -- runs c-for-go

* Fix the generated `const.go` file per patch below to fix a few things.

```bash
$ patch < const_go.patch
```

This builds on my mac but crashes after creating an instance, at this point:

```Go
	ret = vk.EnumeratePhysicalDevices(gp.Instance, &gpuCount, nil)
```

It is unclear if this is because moltenVK only supports version 1.1 of Vulkan?  I tried setting the API version to 1.1 and that didn't work either.

# vulkan_core.h patch

```
--- /usr/local/include/vulkan/vulkan_core.h     2022-05-05 01:00:38.000000000 -0700
+++ vulkan_core.h       2022-05-12 00:05:57.000000000 -0700
@@ -9843,7 +9843,7 @@
     uint32_t                                    vertexStride);
 #endif
 
-
+/*
 #define VK_NVX_binary_import 1
 VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkCuModuleNVX)
 VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkCuFunctionNVX)
@@ -9913,7 +9913,7 @@
     VkCommandBuffer                             commandBuffer,
     const VkCuLaunchInfoNVX*                    pLaunchInfo);
 #endif
-
+*/
 
 #define VK_NVX_image_view_handle 1
 #define VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION 2
@@ -11220,6 +11220,8 @@
     const VkCoarseSampleOrderCustomNV*          pCustomSampleOrders);
 #endif
 
+// ray tracing not working on mac..
+#ifdef GO_INCLUDE_NV_ray_tracing
 
 #define VK_NV_ray_tracing 1
 VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkAccelerationStructureNV)
@@ -11589,6 +11591,7 @@
     uint32_t                                    shader);
 #endif
 
+#endif // GO_INCLUDE_NV_ray_tracing
 
 #define VK_NV_representative_fragment_test 1
 #define VK_NV_REPRESENTATIVE_FRAGMENT_TEST_SPEC_VERSION 2
@@ -13313,6 +13316,7 @@
     const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]);
 #endif
 
+#ifdef GO_INCLUDE_NV_ray_tracing
 
 #define VK_NV_ray_tracing_motion_blur 1
 #define VK_NV_RAY_TRACING_MOTION_BLUR_SPEC_VERSION 1
@@ -13402,7 +13406,7 @@
     VkBool32           rayTracingMotionBlurPipelineTraceRaysIndirect;
 } VkPhysicalDeviceRayTracingMotionBlurFeaturesNV;
 
-
+#endif // GO_INCLUDE_NV_ray_tracing
 
 #define VK_EXT_ycbcr_2plane_444_formats 1
 #define VK_EXT_YCBCR_2PLANE_444_FORMATS_SPEC_VERSION 1
@@ -13984,6 +13988,7 @@
 #define VK_GOOGLE_SURFACELESS_QUERY_SPEC_VERSION 1
 #define VK_GOOGLE_SURFACELESS_QUERY_EXTENSION_NAME "VK_GOOGLE_surfaceless_query"
 
+#ifdef GO_INCLUDE_NV_ray_tracing
 
 #define VK_KHR_acceleration_structure 1
 VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkAccelerationStructureKHR)
@@ -14429,3 +14434,6 @@
 #endif
 
 #endif
+
+#endif // GO_INCLUDE_NV_ray_tracing
+
```

# const.go patch

```
--- const.go	2022-05-12 01:22:31.000000000 -0700
+++ const_fixed.go	2022-05-12 01:22:24.000000000 -0700
@@ -29,7 +29,7 @@
 	// AttachmentUnused as defined in vulkan/vulkan_core.h:124
 	AttachmentUnused = (^uint32(0))
 	// False as defined in vulkan/vulkan_core.h:125
-	False = uint32(0)
+	False = 0
 	// LodClampNone as defined in vulkan/vulkan_core.h:126
 	LodClampNone = 1000.0
 	// QueueFamilyIgnored as defined in vulkan/vulkan_core.h:127
@@ -41,7 +41,7 @@
 	// SubpassExternal as defined in vulkan/vulkan_core.h:130
 	SubpassExternal = (^uint32(0))
 	// True as defined in vulkan/vulkan_core.h:131
-	True = uint32(1)
+	True = 1
 	// WholeSize as defined in vulkan/vulkan_core.h:132
 	WholeSize = (^uint64(0))
 	// MaxMemoryTypes as defined in vulkan/vulkan_core.h:133
@@ -2221,7 +2221,7 @@
 
 // PipelineCacheHeaderVersion enumeration from https://www.khronos.org/registry/vulkan/specs/1.0/man/html/VkPipelineCacheHeaderVersion.html
 const (
-	PipelineCacheHeaderVersionOne     PipelineCacheHeaderVersion = 1
+	PipelineCacheHeaderVersion1       PipelineCacheHeaderVersion = 1
 	PipelineCacheHeaderVersionMaxEnum PipelineCacheHeaderVersion = 2147483647
 )

```

# stddef.h for mac

```C
/*===---- /Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/stddef.h/Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/stddef.h/Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/stddef.h/Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/stddef.h/Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/stddef.h/Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/stddef.h/Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/stddef.h/Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/stddef.h/Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/stddef.h/Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/stddef.hstddef.h - Basic type definitions --------------------------------===
 *
 * Copyright (c) 2008 Eli Friedman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above /Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/stddef.h/Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/stddef.hcopy/Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/stddef.hright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *===-----------------------------------------------------------------------===
 */

#ifndef __STDDEF_H
#define __STDDEF_H

#undef NULL
#ifdef __cplusplus
#if __cplusplus >= 201103L
#define NULL nullptr
#else
#undef __null  // VC++ hack.
#define NULL __null
#endif
#elif defined(__has_feature) && __has_feature(bounds_attributes)
#define NULL __unsafe_forge_single(void *, 0)
#else
#define NULL ((void*)0)
#endif

#ifndef _PTRDIFF_T
#define _PTRDIFF_T
typedef long long ptrdiff_t;
#endif
#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned long long size_t;
#endif
#ifndef __cplusplus
#ifndef _WCHAR_T
#define _WCHAR_T
typedef unsigned short wchar_t;
#endif
#endif

#ifndef offsetof
#define offsetof(t, d) __builtin_offsetof(t, d)
#endif

#endif /* __STDDEF_H */

/* Some C libraries expect to see a wint_t here. Others (notably MinGW) will use
__WINT_TYPE__ directly; accommodate both by requiring __need_wint_t */
#if defined(__need_wint_t)
#if !defined(_WINT_T)
#define _WINT_T
typedef __WINT_TYPE__ wint_t;
#endif /* _WINT_T */
#undef __need_wint_t
#endif /* __need_wint_t */
```

