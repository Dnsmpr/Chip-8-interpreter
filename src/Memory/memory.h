#ifndef MEMORY_H
#define MEMORY_H
#define MEMORY_SIZE 4096
#include<stdint.h>

typedef struct {
    uint8_t mem [MEMORY_SIZE];
} memory;

void MemoryWrite(memory *mem,uint8_t data, uint16_t memoryLocation);
uint8_t MemoryRead(const memory *mem, uint16_t memoryLocation);

#endif