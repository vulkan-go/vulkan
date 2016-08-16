<img src="https://cl.ly/2H2E3c0T1X16/Vulkan_500px_Mar15.png" width="200">

# Golang Bindings for Vulkan API ![version-1.0.24](https://img.shields.io/badge/version-1.0.24-lightgrey.svg) [![GoDoc](https://godoc.org/github.com/vulkan-go/vulkan?status.svg)](https://godoc.org/github.com/vulkan-go/vulkan)

Package [vulkan](https://github.com/vulkan-go/vulkan) provides Go bindings for [Vulkan](https://www.khronos.org/vulkan/) — a low-overhead, cross-platform 3D graphics and compute API.

Vulkan API is the result of 18 months in an intense collaboration between leading hardware, game engine and platform vendors, built on significant contributions from multiple Khronos members. Vulkan is designed for portability across multiple platforms with desktop and mobile GPU architectures.

Read the brief: https://developer.nvidia.com/engaging-voyage-vulkan

I'm glad to announce that now it is possible to combine all the power and pragmatism of Golang with
all those benefits that Vulkan introduced. A real chance to have a way to create graphics without touching
any of C/C++, using your favourite language that scales extremely well as the codebase grows.

## How to use

Despite being almost the largest Golang binding ever, the usage of this package is straigforward due to the nature of Vulkan. Just import it like this:

```
import vk "github.com/vulkan-go/vulkan"
```

And you're set. However I must warn you that using this thing properly is not an easy task at all!

First of all, you'd need a device with the native Vulkan API support. Major platforms like Windows and Linux are
too clumsy so I decided to stick with Android. I bougth an Nvidia Shield K1 tablet for this, because of their early support back into the March of 2016: https://developer.nvidia.com/vulkan-android.

Current list of devices includes Android N devices, as specified at [Android NDK help pages](https://developer.android.com/ndk/guides/graphics/getting-started.html) and so far as I know Samsung Galaxy S7 has the native Vulkan drivers.

In order to be able create apps for android using the Android NDK without any fancy stuff being done with ANativeWindow,
I dedicated some time in May 2016 to create this framework: http://github.com/xlab/android-go. It works cool with EGL/GLES/GLES2 but of course that was a side-effect! ;) What I really did was the first Vulkan run.

Anyway, since May my binding generator improved a lot due to feedback and bugs I got while binding those two beasts,
so in August I found some time on a weekend to create examples. I had them ported from C of course, it was about 5KLOC, see [Golang Vulkan API Demos](https://github.com/vulkan-go/demos) but they do work, so the Vulkan API for Golang is official (at least for Android, heh).

I hope to receive pull-requests from the community so we'd be able to run this on Windows and Linux too, since AFAIK, there is no limitations at all. In fact, I cannot recall if there was any hacks being introduced. This thing just works in a very idiomatic way, meeting all the common Vulkan guidelines.

<a href="https://cl.ly/0n0n040w1022/IMG_1456.JPG"><img src="https://cl.ly/1g1V2o2C423s/IMG_1456.JPG" width="200"/></a>

## Layers

A good brief of the current state of Vulkan validation layers: [Explore the Vulkan Loader and Validation Layers](https://lunarg.com/wp-content/uploads/2016/07/lunarg-birds-feather-session-siggraph-july-26-2016.pdf) (PDF).

There is the full support of validation layers with custom callbacks in Go. For my Android experiments I got the standard pack of layers from https://github.com/LunarG/VulkanTools and built them like this:

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

# What's next?

* More platforms
* Some kind of SDK that will lift up the initialisation burden
* More working demos (after a little SDK)
* More people involved

Anyways, Vulkan has really rich possibilites for management and I think gophers can benefit there. Because in order to fully utilize Vulkan and its API, it's just not enough to call some functions and shovel some variables into some structs. It's about a complex architecture and I understand how to handle such things in Go without creating a lot of mess, but I cannot imagine doing that in other languages or toolsets.

[![](https://developer.nvidia.com/sites/default/files/akamai/gameworks/blog/Vulkan/vulkan_intro_management.png)](https://developer.nvidia.com/engaging-voyage-vulkan)

Let the VGo adventure begin.

## Good stuff

* [VGo Home](https://github.com/vulkan-go)
* [SaschaWillems Demos (C++)](https://github.com/SaschaWillems/Vulkan)
* [Official list of Vulkan resources](https://www.khronos.org/vulkan/resources)
* [Vulkan API quick reference](https://www.khronos.org/registry/vulkan/specs/1.0/refguide/Vulkan-1.0-web.pdf)

## License

MIT
