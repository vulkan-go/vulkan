#include "vk_default_loader.h"
#include "vulkan/vulkan.h"

#if defined(_WIN32)
#elif defined(unix) || defined(__unix__) || defined(__unix)
    #include <dlfcn.h>
    static void* (*symLoader)(void* lib, const char* procname);
    static void* loaderWrap(VkInstance instance, const char* vkproc) {
        return (*symLoader)(instance, vkproc);
    }
#elif defined(__APPLE__) && defined(__MACH__)
    // #include <GLFW/glfw3.h>
    // static void* loaderWrap(VkInstance instance, const char* vkproc) {
    //     return glfwGetInstanceProcAddress(instance, vkproc);
    // }
#endif

void* getDefaultProcAddr() {
    #if defined(_WIN32)
        // TODO: WIN32 Vulkan loader
        return NULL;
    #elif defined(__APPLE__) && defined(__MACH__)
        // return &loaderWrap;
        return NULL;
    #elif defined(unix) || defined(__unix__) || defined(__unix)
        void* libvulkan = dlopen("libvulkan.so", RTLD_NOW | RTLD_LOCAL);
        if (libvulkan == NULL) {
            return NULL;
        }
        symLoader = dlsym(libvulkan, "vkGetInstanceProcAddr");
        if (symLoader == NULL) {
            return NULL;
        }
        return &loaderWrap;
    #else
        // Unknown operating system
        return NULL;
    #endif
}
