#ifndef CPU
#define CPU
#include <stdint.h>
#define STACK_SIZE 128
#define REGISTER_COUNT

typedef struct Core {
    uint16_t  PC;
    uint16_t  I;
    uint16_t  stack[STACK_SIZE];
    uint8_t   V[REGISTER_COUNT];
} Core;

#endif