# Assignment 6.4.2

Let's return once more to the Object class we started on monday (Assignment_6.1.2 and Assignment_6.3.2 in Exercise_3_6.1.2)

### Exercise 1

Overload the << operator for the class so you can directly output it's contents
with std::cout

### Exercise 2

Create a function (think about where you should put this) that reads in a string,
checks its contents and creates Object type from the contents.  (So if it the string
represents an integer, the Object should contain integer, if it is a string/char, it should
be initial, etc.)

You can use following functions to check if the string is a float or an integer, they require
the header <charconv>

bool is_float(std::string_view input)
{
    double val;
    auto [p, ec] = std::from_chars(input.data(), input.data() + input.size(), val);
    return ec == std::errc() && p == input.data() + input.size();
}

bool is_int(std::string_view input)
{
    int val;
    auto [p, ec] = std::from_chars(input.data(), input.data() + input.size(), val);
    return ec == std::errc() && p == input.data() + input.size();
} 

### Exercise 3

Using the TextFile class we created previously (Assignment_6.2.2 and Assignment_6.3.2 in Exercise_1_6.2.2), create a function that reads a text file
line by line and creates an Object for each line and stores them in a container.

### Exercise 4

Combine what we have to create a program that reads in a text file, creates the Objects
and then prints out the elements found in the container.

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
./ObjectsTextFile
```
