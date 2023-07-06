<img src="https://cl.ly/2H2E3c0T1X16/Vulkan_500px_Mar15.png" width="200">

# Golang Bindings for Vulkan API ![version-1.3.239](https://img.shields.io/badge/version-1.3.239-lightgrey.svg) [![GoDoc](https://pkg.go.dev/badge/github.com/goki/vulkan.svg)](https://pkg.go.dev/github.com/goki/vulkan)

Package [vulkan](https://github.com/goki/vulkan) provides Go bindings for [Vulkan](https://www.khronos.org/vulkan/) — a low-overhead, cross-platform 3D graphics and compute API. Updated February 9, 2023 — Vulkan 1.3.239.

## Introduction

The [Vulkan API](https://www.vulkan.org) is a cross-platform industry standard enabling developers to target a wide range of devices with the same graphics API.

This Go binding allows one to use Vulkan API directly within Go code, avoiding adding lots of C/C++ in the projects.  The original version is at https://github.com/vulkan-go/vulkan (still on 1.1.88 from 2018) and a fork at https://github.com/goki/vulkan is being more actively maintained at this point.

See [UPDATING](UPDATING.md) for extensive notes on how to update to newer vulkan versions as they are released.

## Examples and usage

The original author, `xlab`, has examples at: https://github.com/vulkan-go/demos and the beginnings of a toolkit at: https://github.com/vulkan-go/asche.

The updated version is being used extensively in the [goki](https://github.com/goki) framework, powering the [GoGi](https://github.com/goki/gi) 2D and 3D GUI framework, based on the [VGPU](https://github.com/goki/vgpu) toolkit that manages the considerable complexity of dealing with Vulkan.  VGPU is also used as a GPU compute engine framework in the emergent neural network modeling framework [axon](https://github.com/emer/axon).

## How to use

Usage of this project is straightforward due to the stateless nature of Vulkan API.
Just import the package like this:

```
import vk "github.com/goki/vulkan"
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

## MoltenVK os macOS

MoltenVK provides a `MoltenVK.xcframework` which contains static libraries for all Apple platforms. Unfortuantely, linking with a xcframework outside of XCode is not possible.

Instead vulkan-go expects the dylibs to be present in the library search path. 

Follow the [build instructions](https://github.com/KhronosGroup/MoltenVK#building), but instead of `make install` manually copy `./Package/Latest/MoltenVK/dylib/macOS/libMoltenVK.dylib` to `/usr/local/lib`

**IMPORTANT:** be sure to remove any existing `libMoltenVK.dylib` file *before* copying a new one, otherwise you'll have to reboot your computer due to the way the gatekeeper mechanism works!

## MoltenVK on iOS

grab MoltenVK asset from github actions, copy to suitable directory:

```
-L/Users/oreilly/dev/ios/MoltenVK/MoltenVK/dylib/iOS/`  and `-lMoltenVK ` in `vulkan_ios.go`

$ cp libMoltenVK.dylib myapp.app` 
$ lipo -create libMoltenVK.dylib -output MoltenVK`
$ mkdir MoltenVK.framework
$ mv MoltenVK MoltenVK.framework/
$ install_name_tool -change @rpath/libMoltenVK.dylib @executable_path/MoltenVK.framework/MoltenVK main
$ codesign --force --deep --verbose=2 --sign "Randall O'Reilly" widgets.app
$ codesign -vvvv ../widgets.app
```

Info.plist for `MoltenVK.framework`

```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
	<key>BuildMachineOSBuild</key>
	<string>22F82</string>
	<key>CFBundleDevelopmentRegion</key>
	<string>en</string>
	<key>CFBundleExecutable</key>
	<string>MoltenVK</string>
	<key>CFBundleIdentifier</key>
	<string>com.example.test.MoltenVK</string>
	<key>CFBundleInfoDictionaryVersion</key>
	<string>6.0</string>
	<key>CFBundleName</key>
	<string>MoltenVK</string>
	<key>CFBundlePackageType</key>
	<string>FMWK</string>
	<key>CFBundleShortVersionString</key>
	<string>1.0</string>
	<key>CFBundleSupportedPlatforms</key>
	<array>
		<string>iPhoneOS</string>
	</array>
	<key>CFBundleVersion</key>
	<string>1</string>
</dict>
</plist>
```

main Info.plist for reference:

```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
	<key>BuildMachineOSBuild</key>
	<string>22F82</string>
	<key>CFBundleDevelopmentRegion</key>
	<string>en</string>
	<key>CFBundleExecutable</key>
	<string>main</string>
	<key>CFBundleIdentifier</key>
	<string>com.example.test.widgets</string>
	<key>CFBundleInfoDictionaryVersion</key>
	<string>6.0</string>
	<key>CFBundleName</key>
	<string>Widgets</string>
	<key>CFBundlePackageType</key>
	<string>APPL</string>
	<key>CFBundleShortVersionString</key>
	<string>1.0</string>
	<key>CFBundleSignature</key>
	<string>????</string>
	<key>CFBundleSupportedPlatforms</key>
	<array>
		<string>iPhoneOS</string>
	</array>
	<key>CFBundleVersion</key>
	<string>1</string>
	<key>DTCompiler</key>
	<string>com.apple.compilers.llvm.clang.1_0</string>
	<key>DTPlatformBuild</key>
	<string>20E238</string>
	<key>DTPlatformName</key>
	<string>iphoneos</string>
	<key>DTPlatformVersion</key>
	<string>16.4</string>
	<key>DTSDKBuild</key>
	<string>20E238</string>
	<key>DTSDKName</key>
	<string>iphoneos16.4</string>
	<key>DTXcode</key>
	<string>1431</string>
	<key>DTXcodeBuild</key>
	<string>14E300c</string>
	<key>LSRequiresIPhoneOS</key>
	<true/>
	<key>MinimumOSVersion</key>
	<string>16.4</string>
	<key>UIDeviceFamily</key>
	<array>
		<integer>1</integer>
		<integer>2</integer>
	</array>
	<key>UILaunchStoryboardName</key>
	<string>LaunchScreen</string>
	<key>UIRequiredDeviceCapabilities</key>
	<array>
		<string>arm64</string>
	</array>
	<key>UISupportedInterfaceOrientations</key>
	<array>
		<string>UIInterfaceOrientationPortrait</string>
		<string>UIInterfaceOrientationLandscapeLeft</string>
		<string>UIInterfaceOrientationLandscapeRight</string>
	</array>
	<key>UISupportedInterfaceOrientations~ipad</key>
	<array>
		<string>UIInterfaceOrientationPortrait</string>
		<string>UIInterfaceOrientationPortraitUpsideDown</string>
		<string>UIInterfaceOrientationLandscapeLeft</string>
		<string>UIInterfaceOrientationLandscapeRight</string>
	</array>
</dict>
</plist>
```



## Validation Layers

A good brief of the current state of Vulkan validation layers: [Explore the Vulkan Loader and Validation Layers](https://lunarg.com/wp-content/uploads/2016/07/lunarg-birds-feather-session-siggraph-july-26-2016.pdf) (PDF).

There is a full support of validation layers with custom callbacks in Go. For my Android experiments I got the standard pack of layers from https://github.com/LunarG/VulkanTools and built them like this:

```
$ cd build-android
$ ./update_external_sources_android.sh
$ ./android-generate.sh
$ ndk-build
```

After that you'd copy the files to `android/jni/libs` in your project and activate the `ValidationLayers.mk` in your `Android.mk` so when building APK they will be copied alongside with your shared library. It just works then:

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
* [LunarG Vulkan Samples](https://github.com/LunarG/VulkanSamples) (archived)
* [Vulkan Samples from Khronos Group](https://github.com/KhronosGroup/Vulkan-Samples)
* [Official list of Vulkan resources](https://www.khronos.org/vulkan/resources)
* [API description](https://registry.khronos.org/vulkan/)
* [Vulkan API quick reference](https://www.khronos.org/registry/vulkan/specs/1.0/refguide/Vulkan-1.0-web.pdf)

## License

MIT
