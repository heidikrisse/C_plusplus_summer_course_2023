# Assignment 7.3.1

### Exercise 1.

Create a template class and overload its equality operator.

The overridden operator should `static_cast` its arguments to a type given as a template parameter and do the comparison using e.g. template argument's < operator.

### Exercise 2.

Create a new type of your own choosing, and use CRTP to give it the equality comparison functionality from the result of exercise 1.  (e.g. have the new type have < operator, and use that to give the required functionality with the Exercise 1 class)

(Optional) Add other comparisons, (e.g. >, !=, >=, <=) as well with the exercise 1 class.

### Exercise 3

Create another template class and give it a function to print out its type (e.g. by using typeid or some simple checker with type_traits, no need to handle everything).
Then inherit both this functionality and the functionality created in ex 1. to your type.

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
./Comparer
```
