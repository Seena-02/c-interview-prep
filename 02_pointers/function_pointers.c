// TODO: Master function pointers (C's version of callbacks/polymorphism)

#include <stdio.h>

// 1. Declare a function pointer type for: int func(int, int)
//    typedef int (*operation_t)(int, int);
typedef int (*operation_t)(int, int);


// 2. Implement add, subtract, multiply functions matching that signature
int add(int a, int b) { return a + b;}
int subtract(int a, int b) { return a - b;}
int multiply(int a, int b) { return a * b;}

// 3. Implement a calculator that takes a function pointer:
//    int calculate(int a, int b, operation_t op);
int calculate(int a, int b, operation_t op)
{
    return op(a, b);
};

// 4. Create an array of function pointers and iterate through them
operation_t ops[3] = {add, subtract, multiply};

// Without typedef
// int(*ops[3])(int, int) = {add, subtract, multiply};

// 5. EMBEDDED PATTERN: Implement a simple callback registration system
//    - typedef void (*event_callback_t)(int event_id);
//    - void register_callback(event_callback_t cb);
//    - void trigger_event(int event_id);
//    This pattern is EVERYWHERE in embedded (interrupt handlers, event loops)
typedef void(*event_callback_t)(int event_id);

#define MAX_CALLBACKS 10
event_callback_t callbacks[MAX_CALLBACKS];
int callback_count = 0;

void register_callback(event_callback_t cb)
{
    if(callback_count < MAX_CALLBACKS)
    {
        callbacks[callback_count++] = cb;
    }
}
void trigger_event(int event_id)
{
    for(int i = 0; i < callback_count; ++i)
    {
        callbacks[i](event_id);
    }

}

void on_event(int data) { printf("Got: %d\n", data); }

// 6. Interview question: How would you implement polymorphism in C?
//    Hint: struct with function pointers (vtable pattern)

typedef struct Shape Shape;

typedef struct ShapeVTable {
    void (*draw)(struct Shape *self);
    double (*area)(struct Shape *self);
} ShapeVTable;

typedef struct Shape {
    ShapeVTable *vtable;
    int x, y;
} Shape;

void draw_circle(Shape *self) {
    printf("Circle at (%d, %d)\n", self->x, self->y);
}

void draw_square(Shape *self) {
    printf("Square at (%d, %d)\n", self->x, self->y);
}

double area_circle(Shape *self) {
    // Assuming x is radius
    return 3.14159 * self->x * self->x;
}

double area_square(Shape *self) {
    // Assuming x is side length
    return self->x * self->x;
}

ShapeVTable circle_vtable = {draw_circle, area_circle};
ShapeVTable square_vtable = {draw_square, area_square};


int main(void) {
    // Your tests here
    operation_t op = add;

    size_t len_ops = sizeof(ops) / sizeof(ops[0]);
    for(int i = 0; i < len_ops; ++i)
    {
        int result = calculate(10, 5, ops[i]);
        printf("%d\n", result);   
    }

    register_callback(on_event);
    trigger_event(42);  // Prints "Got: 42"
    printf("\n\n\n");

    //Shape c1 = { .vtable = &circle_vtable, .x = 10, .y = 20 };
    //Shape c2 = { .vtable = &circle_vtable, .x = 30, .y = 40 };  // Same vtable

    Shape c = {&circle_vtable, 5, 10};
    Shape s = {&square_vtable, 5, 10};

    c.vtable->draw(&c);
    s.vtable->draw(&s);

    //c1.vtable->draw(&c1);  // Calls draw_circle

    

    return 0;
}
