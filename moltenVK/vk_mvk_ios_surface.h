/*
 * vk_mvk_ios_surface.h
 *
 * Copyright (c) 2014-2016 The Brenwill Workshop Ltd. All rights reserved.
 * http://www.brenwill.com
 *
 * Use of this document is governed by the Molten License Agreement, as included
 * in the MoltenVK distribution package. CAREFULLY READ THAT LICENSE AGREEMENT BEFORE
 * READING AND USING THIS DOCUMENT. BY READING OR OTHERWISE USING THIS DOCUMENT,
 * YOU ACCEPT AND AGREE TO BE BOUND BY THE TERMS AND CONDITIONS OF THAT LICENSE
 * AGREEMENT. IF YOU DO NOT ACCEPT THE TERMS AND CONDITIONS OF THAT LICENSE AGREEMENT,
 * DO NOT READ OR USE THIS DOCUMENT.
 */


/**
 * Vulkan extension VK_MVK_ios_surface.
 *
 * This extension supports creating Vulkan surfaces on iOS devices
 * for the MoltenVK implementation of Vulkan.
 *
 * This extension requires the VK_KHR_surface extension.
 */

#ifndef __vk_mvk_ios_surface_h_
#define __vk_mvk_ios_surface_h_ 1

#ifdef __cplusplus
extern "C" {
#endif	//  __cplusplus
	
#include <vulkan/vulkan.h>


#ifdef VK_USE_PLATFORM_IOS_MVK

#define VK_MVK_ios_surface								1

#define VK_MVK_IOS_SURFACE_SPEC_VERSION					1
#define VK_MVK_IOS_SURFACE_EXTENSION_NAME				"VK_MVK_ios_surface"
#define VK_MVK_IOS_SURFACE_EXTENSION_NUMBER				52
#define	VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK	((VkStructureType)(1000000000 + (VK_MVK_IOS_SURFACE_EXTENSION_NUMBER * 1000)))


/** Flags used to create a WSI surface on the iOS platform. */
typedef VkFlags VkIOSSurfaceCreateFlagsMVK;

/**
 * The parameters affecting creation of a WSI surface on the iOS platform.
 *
 *   - sType is the type of this structure. This value must be VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK.
 *   - pNext is NULL or a pointer to an extension-specific structure.
 *   - flags is reserved for future use. This value must be zero.
 *   - pView is a reference to a UIView object which will display this surface.
 *           Under MoltenVK, this UIView must be backed by a CALayer instance of type CAMetalLayer.
 */
typedef struct VkIOSSurfaceCreateInfoMVK {
	VkStructureType                         sType;
	const void*                             pNext;
	VkIOSSurfaceCreateFlagsMVK              flags;
	const void*                             pView;
} VkIOSSurfaceCreateInfoMVK;

typedef VkResult (VKAPI_PTR *PFN_vkCreateIOSSurfaceMVK)(VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

#ifndef VK_NO_PROTOTYPES

/**
 * Function to create a VkSurfaceKHR for an iOS UIView.
 *
 *   - instance is the VkInstance to associate the surface with. 
 *   - pCreateInfo is a pointer to an instance of the VkIOSSurfaceCreateInfoMVK
 *     structure containing the parameters affecting the creation of the surface object.
 *   - pAllocator is the allocator used for host memory allocated for the surface object
 *     when there is no more specific allocator available (see Memory Allocation).
 *     Under MoltenVK, this parameter is ignored, and may be NULL.
 *
 * The resulting surface object handle is returned in pSurface.
 */
VKAPI_ATTR VkResult VKAPI_CALL vkCreateIOSSurfaceMVK(
	VkInstance                              instance,
	const VkIOSSurfaceCreateInfoMVK*        pCreateInfo,
	const VkAllocationCallbacks*            pAllocator,
	VkSurfaceKHR*                           pSurface);

#endif	// VK_NO_PROTOTYPES

#endif	// VK_USE_PLATFORM_IOS_MVK


#ifdef __cplusplus
}
#endif	//  __cplusplus

#endif
