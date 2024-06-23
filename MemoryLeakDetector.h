// MemoryLeakDetector.h
#ifndef MEMORY_LEAK_DETECTOR_H
#define MEMORY_LEAK_DETECTOR_H

#include <iostream>
#include <unordered_map>

struct MemoryRecord {
    size_t size;
    const char* file;
    int line;
};

extern std::unordered_map<void*, MemoryRecord> memoryMap;

void* operator new(size_t size, const char* file, int line);
void* operator new[](size_t size, const char* file, int line);
void operator delete(void* ptr) noexcept;
void operator delete[](void* ptr) noexcept;

class LeakDetector {
public:
    ~LeakDetector();
};

extern LeakDetector leakDetector;

#endif // MEMORY_LEAK_DETECTOR_H
