# Assignment 8.4.1 Exercise 1

If you haven't already, create unit tests for your heap array type (Assignment 8.3.1), enable the sanitizers with the compiler

```shell
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)
```

In your cmake file should do the trick.  It's useful to have this as an option in cmake, so you can toggle whether or not you want to enable sanitizers without editing the cmake file every time.

## Assignment 8.3.1 - Heap Array

We are going to create another standard-library-almost-compatible container, but this time we do not have any backing container from the standard library itself.  (We still don't care about the performance requirements)

To keep things simple for now, we keep to just non-resizable array that uses heap memory.  This probably won't be as useful in real life (just use std::vector), but is a good starting point for a more usable container. 

Again:  good to keep in handy https://en.cppreference.com/w/cpp/named_req/ContainerLinks to an external site.

It is a good idea to write unit tests for every feature you add to make sure everything works.

### Exercise 1

Create a template class for the heap array.  Again, think what template parameters we want.

Create the type aliases for those for your heap array class.  What would be the simplest way to handle the iterator?

Create a pointer(s) inside the class for storage.  Think about what other variables you need, try to keep the size of the class as low as possible.  Why using normal pointers instead of smart pointers is reasonable here?

### Exercise 2

Create constructors (default, copy, move) for the class.  Then create destructor and assignment operators.

### Exercise 3

Implement element access.  This time there is no need for operator() to get involved, we can always just use
operator[] (and at() if you want).

### Exercise 4

Implement swapping two arrays with each other.

### Exercise 5

Implement rest of the Container requirements.

### (optional) Exercise 6

Try out your container with range-based for loops, and by trying to use it as backing container to your 2D grid.

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
./HeapArray
```

# Run Unit Tests

```shell 
../tests/unit_tests_results
``` 

