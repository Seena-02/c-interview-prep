// TODO: Understand conditional compilation

#include <stdio.h>

// Basic conditional compilation
#define DEBUG 1
#define PLATFORM_LINUX

#if DEBUG
    #define DEBUG_PRINT(fmt, ...) printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)
#else
    #define DEBUG_PRINT(fmt, ...) ((void)0)  // Compiles to nothing
#endif

// Platform-specific code
#ifdef PLATFORM_LINUX
    void platform_init(void) {
        printf("Linux platform\n");
    }
#elif defined(PLATFORM_WINDOWS)
    void platform_init(void) {
        printf("Windows platform\n");
    }
#else
    #error "Unknown platform!"
#endif

// Feature flags (common in embedded)
#define FEATURE_WIFI_ENABLED 1
#define FEATURE_BLUETOOTH_ENABLED 0

// Version checking
#if __STDC_VERSION__ >= 201112L
    #define STATIC_ASSERT(expr, msg) _Static_assert(expr, msg)
#else
    #define STATIC_ASSERT(expr, msg) \
        typedef char static_assertion_##msg[(expr) ? 1 : -1]
#endif

// TODO: Implement a configurable logging system
// - LOG_LEVEL_NONE, LOG_LEVEL_ERROR, LOG_LEVEL_WARN, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG
// - Only compile in log statements for enabled levels
// - LOG_ERROR(fmt, ...) LOG_WARN(fmt, ...) etc.

// TODO: Create platform abstraction
// - #ifdef for different GPIO implementations
// - gpio_init(), gpio_write(), gpio_read()

// Common pattern: Include guards using #pragma once (non-standard but universal)
// #pragma once  // Alternative to #ifndef/#define/#endif

int main(void) {
    platform_init();
    DEBUG_PRINT("Value: %d", 42);
    
    #if FEATURE_WIFI_ENABLED
        printf("WiFi is enabled\n");
    #endif
    
    return 0;
}
