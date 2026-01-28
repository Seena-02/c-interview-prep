// TODO: Understand header guards

// Method 1: Traditional include guard (100% portable)
#ifndef MODULE_H
#define MODULE_H

// This prevents the header from being processed multiple times
// even if #include "module.h" appears multiple times

// Forward declarations
struct Module;

// Type definitions
typedef struct {
    int id;
    char name[32];
} ModuleConfig;

// Function declarations (prototypes)
int module_init(const ModuleConfig* config);
void module_shutdown(void);
int module_process(int input);

// Extern variables (declaration, not definition)
extern int module_error_code;

// Inline functions (C99+) - must be in header
static inline int module_is_ready(void) {
    return module_error_code == 0;
}

// Method 2: #pragma once (non-standard but supported everywhere)
// Just put this at top of file instead of ifndef/define/endif:
// #pragma once

// Interview question: What happens without include guards?
// - Redefinition errors for types
// - Longer compile times
// - Possible subtle bugs with multiple definitions

#endif // MODULE_H
