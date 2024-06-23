// MemoryLeakDetector.cpp
#include "MemoryLeakDetector.h"
#include <cstdlib> // for malloc and free

std::unordered_map<void*, MemoryRecord> memoryMap;

void* operator new(size_t size, const char* file, int line) {
    void* ptr = malloc(size);
    memoryMap[ptr] = {size, file, line};
    return ptr;
}

void* operator new[](size_t size, const char* file, int line) {
    void* ptr = malloc(size);
    memoryMap[ptr] = {size, file, line};
    return ptr;
}

void operator delete(void* ptr) noexcept {
    free(ptr);
    memoryMap.erase(ptr);
}

void operator delete[](void* ptr) noexcept {
    free(ptr);
    memoryMap.erase(ptr);
}

LeakDetector leakDetector;

LeakDetector::~LeakDetector() {
    std::cout<<"here\n";

    if (!memoryMap.empty()) {
        std::cerr << "Memory leaks detected:" << std::endl;
        for (const auto& pair : memoryMap) {
            std::cerr << "  - " << pair.second.size << " bytes leaked at " << pair.second.file << ":" << pair.second.line << std::endl;
        }


           // Free all dynamically allocated memory records
        for (auto it = memoryMap.begin(); it != memoryMap.end(); ++it) {
                free(it->first);
        }

            memoryMap.clear(); // Clear the map after freeing memory
            std::cout<<"Now Memories are cleared\n";

    } else {
        std::cerr << "No memory leaks detected." << std::endl;
    }
}
