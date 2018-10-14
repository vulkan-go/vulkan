<img src="https://cl.ly/2H2E3c0T1X16/Vulkan_500px_Mar15.png" width="200">

# Golang Bindings for Vulkan API ![version-1.1.88](https://img.shields.io/badge/version-1.1.88-lightgrey.svg) [![GoDoc](https://godoc.org/github.com/vulkan-go/vulkan?status.svg)](https://godoc.org/github.com/vulkan-go/vulkan)

Package [vulkan](https://github.com/vulkan-go/vulkan) provides Go bindings for [Vulkan](https://www.khronos.org/vulkan/) — a low-overhead, cross-platform 3D graphics and compute API. Updated October 13, 2018 — Vulkan 1.1.88.

## Introduction

Vulkan API is the result of 18 months in an intense collaboration between leading hardware, game engine and platform vendors, built on significant contributions from multiple Khronos members. Vulkan is designed for portability across multiple platforms with desktop and mobile GPU architectures.

Read the brief: https://developer.nvidia.com/engaging-voyage-vulkan

The binding allows one to use Vulkan API directly within Go code, avoiding
adding lots of C/C++ in the projects, also can be used to study Vulkan without
diving too deep into C/C++ language semantics. For me it's just a matter of
taste, writing Go code is simply more pleasant experience.

## Project history timeline

* **2016-02-16** Vulkan API publicly released.

* **2016-03-06** [vulkan-go](https://github.com/vulkan-go) initial commit and first binding.

* **2016-05-14** Finally received my NVIDIA Shield Tablet K1 (DHL lost the first parcel), I decided to use tablet because it was the first device supporting Vulkan out of the box. And that was a really good implementation, much wow very reference.

* **2016-05-17** Created [android-go](https://github.com/xlab/android-go) project in order to run Vulkan on the android platform.

* **2016-05-23** First android-go + vulkan program runs on Tablet K1 ([screenshot](http://dl.kc.vc/vulkan/screens/first-android-vulkaninfo.png)).

* **2016-05-24** Improved VulkanInfo example runs on Tablet K1 ([screenshot](http://dl.kc.vc/vulkan/screens/improved-android-vulkaninfo.png)).

* **2016-05-28** [android-go](https://github.com/xlab/android-go) released into public ([Reddit post](https://www.reddit.com/r/golang/comments/4lgttr/full_golang_bindings_for_android_ndk_api_with/)) with plenty of examples including GLES/EGL.

* **2016-08-13** Finished an app that should draw triangle (ported from tri.c from LunarG demos). Draws nothing instead.

* **2016-08-13** First unsuccessful attempt to write a spinning cube example. More than 25 hours spent, 2.5k lines of C code rewritten into 900 lines of Go code. The reference code was found in some very old LunarG demo, it seems I should've used the latest one.. At least got the validation layers working and found some bugs in the triangle app code.

* **2016-08-16** First Vulkan API program in Go that draws triangle runs on Tablet K1 ([photo](http://dl.kc.vc/vulkan/screens/first-android-vulkandraw.jpg)), validaton layers work perfectly too.

* **2016-08-16** Public announce of this project ([Reddit post](https://www.reddit.com/r/golang/comments/4y2dj4/golang_bindings_for_vulkan_api_with_demos/)). Reaction was "Meh".

* **2016-11-01** [MoltenVK](https://moltengl.com/moltenvk/) driver merged into GLFW (see [GLFW issue #870](https://github.com/glfw/glfw/issues/870)) and this made possible to use Vulkan API under Apple OS X or macOS.

* **2016-11-06** VulkanInfo and VulkanDraw both ported to desktop OS X and use GLFW to initialize Vulkan ([screen #1](http://dl.kc.vc/vulkan/screens/first-moltenvk-vulkaninfo.png) and [screen #2](http://dl.kc.vc/vulkan/screens/first-moltenvk-vulkandraw.png))

* **2016-11-07** VulkanInfo and VulkanDraw run fine on NVIDIA GTX980 initialized through GLFW under Windows 10 ([screen #1](http://dl.kc.vc/vulkan/screens/first-windows-vulkaninfo.png) and [screen #2](http://dl.kc.vc/vulkan/screens/first-windows-vulkandraw.png)).

* **2016-11-08** VulkanInfo runs in headless (a.k.a computing) mode in Amazon AWS cloud on P2 Instance equipped Tesla K80 ([screenshot](http://dl.kc.vc/vulkan/screens/first-amazon-vulkaninfo.png)).

* **2016-11-09** [ios-go](https://github.com/xlab/ios-go) project started, it's very easy to run Golang apps on iOS that use custom surface, for my case it was Metal surface.

* **2016-11-11** VulkanInfo runs fine on my iPhone under iOS ([screenshot](http://dl.kc.vc/vulkan/screens/first-ios-vulkaninfo.png)), and so does VulkanDraw ([photo](http://dl.kc.vc/vulkan/screens/first-ios-vulkandraw.jpg) also [GPU report from XCode](http://dl.kc.vc/vulkan/screens/gpureport-ios-vulkandraw.png))

* **2016-11-13** Second unsuccessful attempt to write spinning cube. 25 hours spent. The approach was highly inspired by [Mali Vulkan SDK for Android 1.0](http://malideveloper.arm.com/downloads/deved/tutorial/SDK/Vulkan/1.0/index.html) and I created initial version of [vulkan-go/asche](https://github.com/vulkan-go/asche) — a higher level framework to simplify Vulkan initialization for new apps.

* **2016-11-29** Generic Linux support added in using GLFW ([Issue #2](https://github.com/vulkan-go/vulkan/issues/2)) thanks @jfreymuth.

* **2017-05-06** Third, successful attempt to write spining cube example. 16 hours spent, 4K LOC of C code rewritten from [cube.c](https://github.com/LunarG/VulkanSamples/blob/master/demos/cube.c) of LunarG demos. The whole process has been screencasted, maybe I will release it one day.

* **2017-05-06** [vulkan-go/asche](https://github.com/vulkan-go/asche) complete.

* **2018-10-13** Updated to Vulkan 1.1.88 spec.

![vulkan cube golang](http://dl.kc.vc/vulkan/screens/cube.gif)

See all demos in [vulkan-go/demos](https://github.com/vulkan-go/demos).

## How to use

Usage of this project is straightforward due to the stateless nature of Vulkan API.
Just import the package like this:

```
import vk "github.com/vulkan-go/vulkan"
```

Set the GetProcAddress pointer (used to look up Vulkan functions) using SetGetInstanceProcAddr or SetDefaultGetInstanceProcAddr. After that you can call Init to initialise the library. For example:

```
// Using SDL2:
vk.SetGetInstanceProcAddr(sdl.VulkanGetVkGetInstanceProcAddr())

// OR using GLFW:
vk.SetGetInstanceProcAddr(glfw.GetVulkanGetInstanceProcAddress())

// OR without using a windowing library (Linux only, recommended for compute-only tasks)
if err := vk.SetDefaultGetInstanceProcAddr(); err != nil {
    panic(err)
}

if err := vk.Init(); err != nil {
    panic(err)
}
```

And you're set. I must warn you that using the API properly is not an easy task at all, so beware and follow the official documentation: https://www.khronos.org/registry/vulkan/specs/1.0/html/vkspec.html

In order to simplify development, I created a high-level framework that manages Vulkan platform state and initialization. It is called [asche](https://github.com/vulkan-go/asche) because when you throw a gopher into volcano you get a pile of ash. Currently it's used in [VulkanCube](https://github.com/vulkan-go/demos/blob/master/vulkancube/vulkancube_android/main.go) demo app.

## Validation Layers

A good brief of the current state of Vulkan validation layers: [Explore the Vulkan Loader and Validation Layers](https://lunarg.com/wp-content/uploads/2016/07/lunarg-birds-feather-session-siggraph-july-26-2016.pdf) (PDF).

There is a full support of validation layers with custom callbacks in Go. For my Android experiments I got the standard pack of layers from https://github.com/LunarG/VulkanTools and built them like this:

```
$ cd build-android
$ ./update_external_sources_android.sh
$ ./android-generate.sh
$ ndk-build
```

After that you'd copy the objects to `android/jni/libs` in your project and activate the `ValidationLayers.mk` in your `Android.mk` so when building APK they will be copied alongside with your shared library. It just works then:

```
[INFO] Instance extensions: [VK_KHR_surface VK_KHR_android_surface]
[INFO] Instance layers: [VK_LAYER_LUNARG_screenshot VK_LAYER_GOOGLE_unique_objects VK_LAYER_LUNARG_api_dump VK_LAYER_LUNARG_image VK_LAYER_LUNARG_core_validation VK_LAYER_LUNARG_object_tracker VK_LAYER_GOOGLE_threading VK_LAYER_LUNARG_parameter_validation VK_LAYER_LUNARG_swapchain]

[Layer Swapchain][ERROR 4] The surface in pCreateInfo->surface, that was given to vkCreateSwapchainKHR(), must be a surface that is supported by the device as determined by vkGetPhysicalDeviceSurfaceSupportKHR().  However, vkGetPhysicalDeviceSurfaceSupportKHR() was never called with this surface.

[Layer Swapchain][ERROR 10] vkCreateSwapchainKHR() called with a non-supported pCreateInfo->compositeAlpha (i.e. VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR).  Supported values are:
     VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR

[Layer DS][ERROR 8] Attempt to set lineWidth to 0.000000 but physical device wideLines feature not supported/enabled so lineWidth must be 1.0f!

[Layer DS][ERROR 22] Unable to allocate 2 descriptors of type VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER from pool 0x1c. This pool only has 1 descriptors of this type remaining.
```

## Useful links

* [vulkanGo.com](https://vulkanGo.com)
* [SaschaWillems Demos (C++)](https://github.com/SaschaWillems/Vulkan)
* [LunarG Vulkan Samples](https://github.com/LunarG/VulkanSamples)
* [Official list of Vulkan resources](https://www.khronos.org/vulkan/resources)
* [Vulkan API quick reference](https://www.khronos.org/registry/vulkan/specs/1.0/refguide/Vulkan-1.0-web.pdf)

## License

MIT
