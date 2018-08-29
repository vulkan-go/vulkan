#include "vk_default_loader.h"
#include "vulkan/vulkan.h"

#if defined(_WIN32)
#elif defined(unix) || defined(__unix__) || defined(__unix)
#include <dlfcn.h>
static void* (*loadSym)(void* lib, const char* procname);
static void* loadSymWrap(VkInstance instance, const char* vkproc) {
	return (*loadSym)(instance, vkproc);
}
#endif

void* getDefaultProcAddr() {
    #if defined(_WIN32)
    // TODO: WIN32 Vulkan loader
    #elif defined(__APPLE__) && defined(__MACH__)
	// TODO: Darwin Vulkan loader (via MoltenVK)
    #elif defined(unix) || defined(__unix__) || defined(__unix)
	void* libvulkan = dlopen("libvulkan.so", RTLD_NOW | RTLD_LOCAL);
    if (libvulkan == NULL) {
        return NULL;
    }

	loadSym = dlsym(libvulkan, "vkGetInstanceProcAddr");
	if (loadSym == NULL) {
		return NULL;
	}

	return &loadSymWrap;
    #else
    // Unknown operating system
    #endif
}