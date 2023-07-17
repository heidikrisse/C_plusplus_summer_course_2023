# Exercise

We are going to implement a simple state machine.  A state machine is pretty simple concept with a lot of complicated explanations, but let's keep it simple here.

We create a state machine to track a status of an order (e.g. from an online store).  The order should be tracked from ordered to delivered. (Make up the intermediate states)

Create a type to track the state for the machine.  Use "enum class"
Create a type for the orders (this is our state machine).  Add a member functions to print the current status and to advance the status of the order.
Create a program that runs through the different states and prints and advances through them.

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
./OrderStatus
```
