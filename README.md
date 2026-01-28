# C Interview Prep for Embedded Systems

Practice repository for C concepts relevant to embedded software engineering roles.

## Structure

```
c-interview-prep/
├── 01_memory_management/
│   ├── malloc_free_basics.c
│   ├── memory_leaks.c
│   ├── stack_vs_heap.c
│   └── struct_alignment.c
├── 02_pointers/
│   ├── function_pointers.c
│   ├── void_pointers.c
│   ├── pointer_arithmetic.c
│   ├── array_pointer_decay.c
│   └── double_pointers.c
├── 03_c_patterns/
│   ├── opaque_pointers/
│   │   ├── stack.h
│   │   └── stack.c
│   ├── error_handling.c
│   └── static_scope.c
├── 04_embedded_essentials/
│   ├── volatile_usage.c
│   ├── bitwise_operations.c
│   ├── packed_structs.c
│   ├── fixed_width_types.c
│   └── endianness.c
├── 05_preprocessor/
│   ├── macros.c
│   ├── conditional_compilation.c
│   └── header_guards/
│       ├── module.h
│       └── module.c
├── 06_data_structures/
│   ├── linked_list.c
│   ├── ring_buffer.c       # Very common in embedded
│   └── state_machine.c     # Common pattern for IoT devices
├── 07_networking_basics/
│   ├── socket_client.c
│   └── byte_packing.c      # Protocol serialization
└── Makefile
```

## How to Use

1. Each `.c` file contains a TODO comment describing what to implement
2. Compile with: `make <target>` or `gcc -Wall -Wextra -g <file>.c -o <output>`
3. Use Valgrind to check for memory issues: `valgrind ./output`

## Key Differences from C++

| C++ Feature | C Equivalent |
|-------------|--------------|
| `new`/`delete` | `malloc()`/`free()` |
| Classes | Structs + function pointers |
| RAII | Manual cleanup (goto cleanup pattern) |
| References | Pointers only |
| Exceptions | Return codes, errno |
| `nullptr` | `NULL` or `(void*)0` |
| Templates | Macros or void pointers |
| Namespaces | Prefixed function names |
