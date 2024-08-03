#include "memory.h"
#include <stdbool.h>

static bool isValidMemoryLocation(uint16_t memoryLocation) {
    return memoryLocation > 0 && memoryLocation < (MEMORY_SIZE - 1);
}

void MemoryWrite(memory *mem,uint8_t data, uint16_t memoryLocation) {
    if(!isValidMemoryLocation(memoryLocation)) {
        return;
    }
    mem->mem[memoryLocation] = data;
}
uint8_t MemoryRead(const memory *mem, uint16_t memoryLocation) {
    if(isValidMemoryLocation(memoryLocation)) {
        return mem->mem[memoryLocation];
    }
    return 0;
}

