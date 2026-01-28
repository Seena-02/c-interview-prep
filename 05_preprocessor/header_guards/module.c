// TODO: Implement the module

#include "module.h"
#include <stdio.h>
#include <string.h>

// Definition of extern variable (must be in exactly one .c file)
int module_error_code = 0;

// Private/static variables (not visible outside this file)
static ModuleConfig current_config;
static int initialized = 0;

// Private/static helper functions
static int validate_config(const ModuleConfig* config) {
    if (!config) return -1;
    if (config->id < 0) return -2;
    return 0;
}

// Public function implementations
int module_init(const ModuleConfig* config) {
    int err = validate_config(config);
    if (err != 0) {
        module_error_code = err;
        return err;
    }
    
    memcpy(&current_config, config, sizeof(ModuleConfig));
    initialized = 1;
    module_error_code = 0;
    
    printf("Module initialized: id=%d, name=%s\n", 
           current_config.id, current_config.name);
    return 0;
}

void module_shutdown(void) {
    if (initialized) {
        printf("Module shutdown\n");
        initialized = 0;
    }
}

int module_process(int input) {
    if (!initialized) {
        module_error_code = -3;
        return -1;
    }
    return input * 2;  // Example processing
}

// TODO: Add a main() function to test the module
// - Initialize with valid config
// - Call process
// - Check error codes
// - Shutdown
