#include "bus.h"

void BusWrite(bus *Bus, uint8_t data, uint16_t memoryLocation) {
    MemoryWrite(Bus->mem, data, memoryLocation);
}
uint8_t BusRead(const bus *Bus, uint16_t memoryLocation) {
    return MemoryRead(Bus->mem, memoryLocation);
}