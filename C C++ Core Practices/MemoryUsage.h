#pragma once
#include"pch.h"
#include"Log.h"



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


void printMemoryUsageW() {
    std::cout << "Total Memory Usage: " << ::memUsage.getCurrentUsage() << std::endl;
}

void printMemoryUsageA() {
    LOG(L"Total Memory Usage: ");
    LOG_INT(::memUsage.getCurrentUsage());
}

#ifdef UNICODE
#define printMemoryUsage printMemoryUsageW
#else
#define printMemoryUsage printMemoryUsageA
#endif // UNICODE







