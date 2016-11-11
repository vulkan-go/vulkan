/*
 * vk_mvk_moltenvk.h
 *
 * Copyright (c) 2014-2016 The Brenwill Workshop Ltd. All rights reserved.
 * http://www.brenwill.com
 *
 * Use of this document is governed by the Molten License Agreement, as included
 * in the Molten distribution package. CAREFULLY READ THAT LICENSE AGREEMENT BEFORE
 * READING AND USING THIS DOCUMENT. BY READING OR OTHERWISE USING THIS DOCUMENT,
 * YOU ACCEPT AND AGREE TO BE BOUND BY THE TERMS AND CONDITIONS OF THAT LICENSE
 * AGREEMENT. IF YOU DO NOT ACCEPT THE TERMS AND CONDITIONS OF THAT LICENSE AGREEMENT,
 * DO NOT READ OR USE THIS DOCUMENT.
 */


/** Vulkan extension VK_MVK_moltenvk. */

#ifndef __vk_mvk_moltenvk_h_
#define __vk_mvk_moltenvk_h_ 1

#ifdef __cplusplus
extern "C" {
#endif	//  __cplusplus

#include <vulkan/vulkan.h>


#define VK_MVK_MOLTENVK_REVISION				1
#define VK_MVK_MOLTENVK_EXTENSION_NUMBER		54
#define VK_MVK_MOLTENVK_EXTENSION_NAME			"VK_MVK_moltenvk"

/** MoltenVK configuration settings. */
typedef struct {
    VkBool32 supportDisplayContentsScale;   /**< If enabled, display surfaces that support contents scaling (such as Retina) will automatically use it when creating a color attachment. When used, it is the responsibility of the app to ensure depth, stencil, and resolve attachments are sized to match. Default is false. */
    VkBool32 imageFlipY;                    /**< If enabled, images will be flipped on the Y-axis, as Vulkan coordinate system is inverse of OpenGL. Default is false. */
    VkBool32 shaderConversionFlipFragmentY; /**< If enabled, MSL fragment shader code created during Runtime Shader Conversion will flip the Y-axis of each texture coordinate, as Vulkan texture coordinate system is inverse of OpenGL. Default is false. */
    VkBool32 shaderConversionFlipVertexY;   /**< If enabled, MSL vertex shader code created during Runtime Shader Conversion will flip the Y-axis of each vertex, as Vulkan coordinate system is inverse of OpenGL. Default is true. */
    VkBool32 shaderConversionLogging;       /**< If enabled, both SPIR-V and MSL code will be logged during Runtime Shader Conversion. Default is false. */
    VkBool32 performanceTracking;           /**< If enabled, per-frame performance statistics are tracked, and can be retrieved via the API. Default is false. */
    uint32_t performanceLoggingFrameCount;  /**< If non-zero, performance statistics will be periodically logged to the console, on a repeating cycle of this many frames per swapchain. The performanceTracking capability must also be enabled. Default is zero, indicating no logging. */
} MVKDeviceConfiguration;

/** Features provided by the current implementation of Metal on the current device. */
typedef struct {
	VkBool32 depthClipMode;					/**< Depth clip mode. */
	VkBool32 indirectDrawing;				/**< Draw call parameters held in a GPU buffer. */
	VkBool32 baseVertexInstanceDrawing;		/**< Draw calls support specifiying the base vertex and instance. */
	uint32_t maxVertexBufferCount;			/**< The total number of vertex buffers available for vertex shader uniform content and vertex attributes. */
	uint32_t maxFragmentBufferCount;		/**< The total number of fragment buffers available for fragment shader uniform content. */
    VkDeviceSize bufferAlignment;           /**< The alignment used when allocating memory for MTLBuffers. */
    VkDeviceSize pushConstantsAlignment;    /**< The alignment used when allocating memory for push constant structures. */
} MVKPhysicalDeviceMetalFeatures;

/** MoltenVK swapchain performance statistics. */
typedef struct {
    double lastFrameInterval;           /**< The time interval between this frame and the immediately previous frame, in seconds. */
    double averageFrameInterval;        /**< The rolling average time interval between frames, in seconds. This value has less volatility than the lastFrameInterval value. The inverse of this value is the rolling average frames per second. */
    double averageFramesPerSecond;      /**< The rolling average number of frames per second. This is simply the inverse of the averageFrameInterval value. */
} MVKSwapchainPerformance;


#pragma mark -
#pragma mark Function types

typedef VkResult (VKAPI_PTR *PFN_vkActivateMoltenVKLicenseMVK)(const char* licenseID, const char* licenseKey, VkBool32 acceptLicenseTermsAndConditions);
typedef VkResult (VKAPI_PTR *PFN_vkActivateMoltenVKLicensesMVK)();
typedef VkResult (VKAPI_PTR *PFN_vkGetMoltenVKDeviceConfigurationMVK)(VkDevice device, MVKDeviceConfiguration* pConfiguration);
typedef VkResult (VKAPI_PTR *PFN_vkSetMoltenVKDeviceConfigurationMVK)(VkDevice device, MVKDeviceConfiguration* pConfiguration);
typedef VkResult (VKAPI_PTR *PFN_vkGetPhysicalDeviceMetalFeaturesMVK)(VkPhysicalDevice physicalDevice, MVKPhysicalDeviceMetalFeatures* pMetalFeatures);
typedef VkResult (VKAPI_PTR *PFN_vkGetSwapchainPerformanceMVK)(VkDevice device, VkSwapchainKHR swapchain, MVKSwapchainPerformance* pSwapchainPerf);


#pragma mark -
#pragma mark Function prototypes

#ifndef VK_NO_PROTOTYPES

/**
 * Activates the specified license to enable MoltenVK features and functionality associated
 * with that license.
 *
 * The license consists of a pair of null-terminated strings, one containing the ID under
 * which the license was purchased, and the other containing the license key assigned to
 * the purchased license.
 *
 * In addition to the license ID and key, for any license activation to take place, you
 * must set the acceptLicenseTermsAndConditions parameter to true, to indicate that you
 * accept the terms and conditions of the MoltenVK license agreement.
 *
 * MoltenVK supports several levels of license scope. Depending on the license scope purchased,
 * a single MoltenVK license may be associated with one MoltenVK feature set, or it may be
 * associated with multiple MoltenVK feature sets. This function may be called multiple times
 * to accommodate licenses purchased for multiple individual feature sets.
 *
 * You can call this function at any time, but typically you will call this function during 
 * application startup. You can call this function multiple times to accommodate licenses 
 * purchased for multiple individual feature sets. Until a valid license is applied covering 
 * each feature set used by your application, MoltenVK will operate in evaluation mode,
 * which may include displaying a MoltenVK watermark.
 *
 * Using this function is not the preferred method for activating licenses because, in a team
 * environment, it is more difficult to enter valid licenses for each developer from your 
 * application code. Instead, consider using the vkActivateMoltenVKLicensesMVK() function,
 * which allows you to specify the license information through compiler build settings.
 * Using compiler build settings allows you to more easily specify the license information
 * for each developer.
 */
VKAPI_ATTR VkResult VKAPI_CALL vkActivateMoltenVKLicenseMVK(
    const char*                                 licenseID,
    const char*                                 licenseKey,
    VkBool32                                    acceptLicenseTermsAndConditions);

/**
 * This function allows you to enter up to four MoltenVK license ID and license key pairs
 * as compiler build settings. To use this function, configure one or more licenses using
 * the following pairs of build settings:
 *
 *   - MLN_LICENSE_ID   and MLN_LICENSE_KEY
 *   - MLN_LICENSE_ID_1 and MLN_LICENSE_KEY_1
 *   - MLN_LICENSE_ID_2 and MLN_LICENSE_KEY_2
 *   - MLN_LICENSE_ID_3 and MLN_LICENSE_KEY_3
 *
 * Each element of each pair is a single string defined as a build setting, and should not
 * include quote marks. For example, you might configure the following build settings:
 *
 *   MLN_LICENSE_ID=john.doe@example.com
 *   MLN_LICENSE_KEY=NOVOT3NGPDZ6OQSCXX4VYLXGI3QLI6Z6
 *
 * and if you purchase an additional feature set on a separate license, you can add a
 * second pair of build settings:
 *
 *   MLN_LICENSE_ID_1=john.doe@example.com
 *   MLN_LICENSE_KEY_1=MZ4T1Y2LDKBJHAL73JPTEJBHELZHEQJF
 *
 * In addition to the license ID and key, for any license activation to take place, you must
 * also set the following build setting to indicate that you accept the terms and conditions
 * of the MoltenVK license agreement:
 *
 *   MLN_LICENSE_ACCEPT_TERMS_AND_CONDITIONS=1
 *
 * You can call this function at any time, but typically you will call this function during 
 * application startup.
 *
 * If you are unable to use compiler build settings to enter license information, you can use the
 * more general vkActivateMoltenVKLicenseMVK() function to enter each license ID/key pair directly.
 */
static inline void vkActivateMoltenVKLicensesMVK() {

    // General macros for using a build setting as a string
#	define MLN_QUOTE(name) #name
#	define MLN_STR(macro) MLN_QUOTE(macro)

#	ifndef MLN_LICENSE_ACCEPT_TERMS_AND_CONDITIONS
#		define MLN_LICENSE_ACCEPT_TERMS_AND_CONDITIONS		0
#	endif

#	if defined(MLN_LICENSE_ID) && defined(MLN_LICENSE_KEY)
    vkActivateMoltenVKLicenseMVK(MLN_STR(MLN_LICENSE_ID), MLN_STR(MLN_LICENSE_KEY), MLN_LICENSE_ACCEPT_TERMS_AND_CONDITIONS);
#	endif

#	if defined(MLN_LICENSE_ID_1) && defined(MLN_LICENSE_KEY_1)
    vkActivateMoltenVKLicenseMVK(MLN_STR(MLN_LICENSE_ID_1), MLN_STR(MLN_LICENSE_KEY_1), MLN_LICENSE_ACCEPT_TERMS_AND_CONDITIONS);
#	endif

#	if defined(MLN_LICENSE_ID_2) && defined(MLN_LICENSE_KEY_2)
    vkActivateMoltenVKLicenseMVK(MLN_STR(MLN_LICENSE_ID_2), MLN_STR(MLN_LICENSE_KEY_2), MLN_LICENSE_ACCEPT_TERMS_AND_CONDITIONS);
#	endif
        
#	if defined(MLN_LICENSE_ID_3) && defined(MLN_LICENSE_KEY_3)
    vkActivateMoltenVKLicenseMVK(MLN_STR(MLN_LICENSE_ID_3), MLN_STR(MLN_LICENSE_KEY_3), MLN_LICENSE_ACCEPT_TERMS_AND_CONDITIONS);
#	endif
}

/** Populates the pConfiguration structure with the current MoltenVK configuration settings of the specified device. */
VKAPI_ATTR VkResult VKAPI_CALL vkGetMoltenVKDeviceConfigurationMVK(
    VkDevice                                    device,
    MVKDeviceConfiguration*                     pConfiguration);

/** Sets the MoltenVK configuration settings of the specified device to those found in the pConfiguration structure. */
VKAPI_ATTR VkResult VKAPI_CALL vkSetMoltenVKDeviceConfigurationMVK(
    VkDevice                                    device,
    MVKDeviceConfiguration*                     pConfiguration);

/** 
 * Populates the pMetalFeatures structure with the Metal-specific features
 * supported by the specified physical device. 
 */
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceMetalFeaturesMVK(
	VkPhysicalDevice                            physicalDevice,
	MVKPhysicalDeviceMetalFeatures*             pMetalFeatures);

/**
 * Populates the specified MVKSwapchainPerformance structure with
 * the current performance statistics for the specified swapchain.
 */
VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainPerformanceMVK(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    MVKSwapchainPerformance*                    pSwapchainPerf);


#endif // VK_NO_PROTOTYPES


#ifdef __cplusplus
}
#endif	//  __cplusplus

#endif
