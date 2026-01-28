// TODO: Implement a state machine (essential for IoT/embedded devices)

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Example: Smart light bulb state machine
// States: OFF -> CONNECTING -> CONNECTED -> ERROR
// Events: POWER_ON, WIFI_CONNECTED, WIFI_DISCONNECTED, ERROR_OCCURRED, RESET

// Approach 1: Switch-based (simple, common)
typedef enum {
    STATE_OFF,
    STATE_CONNECTING,
    STATE_CONNECTED,
    STATE_ERROR,
    STATE_COUNT
} State;

typedef enum {
    EVENT_POWER_ON,
    EVENT_WIFI_CONNECTED,
    EVENT_WIFI_DISCONNECTED,
    EVENT_ERROR_OCCURRED,
    EVENT_RESET,
    EVENT_COUNT
} Event;

// TODO: Implement switch-based state machine
State handle_event_switch(State current, Event event) {
    switch (current) {
        case STATE_OFF:
            // Handle events in OFF state
            break;
        // ... other states
        default:
            break;
    }
    return current;
}

// Approach 2: Table-driven (more scalable, data-driven)
typedef State (*TransitionFunc)(void);

typedef struct {
    State next_state;
    TransitionFunc action;  // Optional action to perform
} Transition;

// Transition table: [current_state][event] -> next_state
// TODO: Fill in the transition table
static const Transition transition_table[STATE_COUNT][EVENT_COUNT] = {
    // STATE_OFF
    [STATE_OFF] = {
        [EVENT_POWER_ON] = { STATE_CONNECTING, NULL },
        // ... other events
    },
    // ... other states
};

// TODO: Implement table-driven state machine handler
State handle_event_table(State current, Event event);

// Approach 3: Function pointer per state (most flexible)
typedef struct StateMachine StateMachine;
typedef State (*StateHandler)(StateMachine* sm, Event event);

struct StateMachine {
    State current_state;
    StateHandler handlers[STATE_COUNT];
    // Add context data as needed
    void* user_data;
};

// TODO: Implement handlers for each state
State state_off_handler(StateMachine* sm, Event event);
State state_connecting_handler(StateMachine* sm, Event event);
State state_connected_handler(StateMachine* sm, Event event);
State state_error_handler(StateMachine* sm, Event event);

// Entry/exit actions pattern
typedef struct {
    void (*on_enter)(void);
    void (*on_exit)(void);
    StateHandler handler;
} StateConfig;

// Interview question: What are advantages of each approach?
// Switch: Simple, all logic visible, good for small FSMs
// Table: Data-driven, easy to modify, good for auto-generated code
// Function pointer: Most flexible, good for complex state behavior

int main(void) {
    State current = STATE_OFF;
    
    printf("Initial state: OFF\n");
    current = handle_event_switch(current, EVENT_POWER_ON);
    printf("After POWER_ON: state=%d\n", current);
    
    return 0;
}
