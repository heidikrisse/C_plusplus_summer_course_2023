# ProjectName

### Exercise 1

Sometimes it's possible to bypass some of limitations (e.g. if only dynamic memory allocation is forbidden) by instead using statically allocated memory.

Look at Allocator requirements.

Statically allocate a block of memory (e.g. by creating std::array, or uint8_t[SIZE] block).
Create an allocator that uses the placement new to construct objects to the memory from the static block, and manually call the destructor when deconstructing.
Try to use your allocator with std::vector.

If you can't finish this task, just post how far you got.  It's not as easy as it might first seem.

### Exercise 2 (Optional)

Create unit tests for your allocator

# Build Project

1. Navigate to the project root directory

2. Create a build directory and navigate to it:

```shell
mkdir build
cd build
```

3. Run CMake and build the project:

```shell
cmake ..
make
```

# Run Project

```shell 
./Allocator
```

# Run Unit Tests

```shell
cd ..
cd tests
./unit_tests_results
```
