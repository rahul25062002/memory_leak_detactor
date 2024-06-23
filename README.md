# Memory Leak Detactor

This C++ program demonstrates a simple memory leak detection mechanism by overriding the `new` and `delete` operators. It tracks memory allocations and reports any leaks upon program exit. The leak detection mechanism can be applied to any external file by including the `MemoryLeakDetector.h` header.

## How It Works

- **MemoryRecord Structure**: Tracks the size, file, and line number of each memory allocation.
- **Global Memory Map**: Stores memory allocations using pointers as keys.
- **Custom New and Delete Operators**: Overrides `new` and `delete` (including `new[]` and `delete[]`) to log memory allocations and deallocations.
- **LeakDetector Class**: Checks for memory leaks when the program exits, printing details of any leaked memory.

## Files

- `MemoryLeakDetector.h`: Header file containing the declaration of the memory leak detection mechanism.
- `MemoryLeakDetector.cpp`: Source file containing the implementation of the memory leak detection mechanism.
- `main.cpp`: Example usage of the memory leak detection mechanism. (you can have your own file just rename it main.cpp)

## Usage

1. **Clone the Repository**:
    ```bash
    git https://github.com/rahul25062002/memory_leak_detactor.git
    cd /memory_leak_detactor
    ```

2. **Compile the Program**:
    ```bash
    g++ -o memory_leak_check main.cpp MemoryLeakDetector.cpp
    ```

3. **Run the Program**:
    ```bash
    ./memory_leak_check
    ```

4. **Check for Memory Leaks**:
    - By default, the program will detect a memory leak because the allocated memory for the array is not freed.
    - To prevent the memory leak, uncomment the `delete[] ptr;` line in the `testMemoryLeak` function.

## Example Output

### Memory Leak Detected
When the `delete[] ptr;` line is commented out:

![image](https://github.com/rahul25062002/memory_leak_detactor/assets/75932347/cbe02a19-e7ed-4c34-9c3c-7bc638fa77c9)
