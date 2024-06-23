// main.cpp
#include <iostream>
#include "MemoryLeakDetector.h"



void testMemoryLeak() {
    int* ptr = new(__FILE__, __LINE__) int[5]; // Allocate memory for an array of 5 integers
    // delete[] ptr; // Uncomment to free memory and prevent leak
}

int main() {
    std::cout << "Starting memory leak check..." << std::endl;
    testMemoryLeak();
    std::cout << "Memory leak check completed." << std::endl;
    std::cout.flush(); // Ensure all output is flushed immediately

    // Add a delay or wait for user input to keep the program running for observation
  

    return 0;
}
