#pragma once
#include"pch.h"



struct MemoryUsage {
    uint32_t totalAllocated = 0;
    uint32_t totalFreed = 0;

    uint32_t getCurrentUsage() { return totalAllocated - totalFreed; }

};


namespace {
    MemoryUsage memUsage;
}


void* operator new(size_t size) {
    ::memUsage.totalAllocated += size;
    return malloc(size);
}

void operator delete(void* memory, size_t size) {
    ::memUsage.totalFreed += size;
    free(memory);
}


void printMemoryUsage() {
    std::cout << "Total Memory Usage: " << ::memUsage.getCurrentUsage() << std::endl;
}
