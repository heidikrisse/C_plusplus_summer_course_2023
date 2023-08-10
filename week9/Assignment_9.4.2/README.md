# ProjectName

### Exercise 1.

Create a class, and then a factory function (static member function) to create a class instance.  The function should return std::optional.  Create a way for the function to fail, and return a std::nullopt in case of failure.  Then demonstrate both cases.

### Exercise 2.

Again, create a class with a factory function.  The function should return std::expected.  Create a way for the function to fail, and test out and demonstrate both outcomes.

(This is very useful sometimes, since constructors cannot return values and sometimes we want to report errors some way even when exceptions are disabled)

If your standard library version is too old to include <expected>, you can use https://github.com/TartanLlama/expectedLinks to an external site. instead (you'll just need the header in include/tl/expected.hpp)

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
./OptionalAndExpected
```
