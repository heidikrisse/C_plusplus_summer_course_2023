# Personal finance management system

## Assignment for the Assesment test 1:

Build a personal finance system that can track income and expenses. 

Your program should have at least two unit tests.

Part 1.

Implement a struct called Transaction to store the necessary data for each financial transaction
Users should be able to add transactions and view them
Structure your code in multiple files
Your program needs to be built using CMake

Part 2.

Implement functionality to calculate and display the total expenses.
Implement basic file operations to store and retrieve data
Make sure you have error handling in your program

Part 3.

Add a simple user interface for your program.


## Project Structure

- The `main.cpp` file contains the main function that runs the program.
- The `include` directory contains the header files for the project.
- The `src` directory contains the source files for the project.
- The `tests` directory contains the unit tests for the project.

## Dependencies

This project uses the Doctest library for unit testing. You can get it by running the following command:

```shell
sudo curl https://raw.githubusercontent.com/doctest/doctest/master/doctest/doctest.h -o doctest.h 
```

## Build and run the project

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

4. Run the project:

```shell
./FinanceManagementSystem
```

## Run unit tests:

```shell
cd ..
cd tests
./unit/tests_results
```



