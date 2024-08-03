#ifndef BUS_H
#define BUS_H
#include <stdint.h>
#include "memory.h"
#include <stdio.h>

typedef struct bus {
    memory *mem;
} bus;

void BusWrite(bus *Bus, uint8_t data, uint16_t memoryLocation);
uint8_t BusRead(const bus *Bus, uint16_t memoryLocation);
#endif