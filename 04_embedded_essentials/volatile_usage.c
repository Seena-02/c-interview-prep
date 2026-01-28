// TODO: Understand volatile (CRITICAL for embedded)

#include <stdint.h>
#include <stdbool.h>

// volatile tells compiler: this value can change unexpectedly
// DO NOT optimize away reads/writes to this variable

// Use case 1: Memory-mapped hardware registers
// #define GPIO_PORT_A (*(volatile uint32_t*)0x40020000)
// void set_pin_high(int pin) {
//     GPIO_PORT_A |= (1 << pin);  // Must actually write to hardware!
// }

// Use case 2: Variables modified by interrupt handlers
volatile bool data_ready = false;

// ISR (Interrupt Service Routine) - called by hardware
void UART_IRQHandler(void) {
    // ... read data from UART
    data_ready = true;  // Signal main loop
}

void main_loop(void) {
    while (1) {
        // Without volatile, compiler might optimize this to:
        // if (data_ready) while(1) { process(); }
        // Because it doesn't know data_ready can change
        if (data_ready) {
            // process_data();
            data_ready = false;
        }
    }
}

// Use case 3: Busy-wait loops
// volatile uint32_t* status_reg = (volatile uint32_t*)0x40020004;
// while (!(*status_reg & READY_BIT)) { /* wait */ }

// TODO: Write examples demonstrating each use case

// Interview questions:
// 1. Why isn't volatile enough for thread safety? (No atomicity guarantee)
// 2. What's the difference between const volatile? (Read-only hardware reg)
// 3. When would you use volatile with a pointer?
//    volatile int* p;    // Pointer to volatile int
//    int* volatile p;    // Volatile pointer to int
//    volatile int* volatile p;  // Both

int main(void) {
    return 0;
}
