## Banking Program from previous exercises (Assignment 3_1_1 Exercise 5 
## and Assignment_1_3_2)

A program to perform banking operations such as creating a new customer, 
creating new accounts to a customer and manipulating account balances.
Customer and account data can be downloaded to and from a file. 

The program uses 'doctest.h' for unit testing. To get 'doctest.h' downloaded,
use the following command:

```shell
$ sudo curl https://raw.githubusercontent.com/doctest/doctest/master/doctest.h -o doctest.h
```

This command downloads 'doctest.h' from the official repository and places it in 
your current directory. Move the 'doctest.h' to your 'include' folder. 

# Build and run the program

1. Clone the repository

2. Change into the project directory

```shell
$ cd Exercise_3
```

3. Create and change into the build directory:

```shell
$ mkdir build && cd build
```

4. Run CMake

```shell
$ cmake ..
```

5. Run Make

```shell
$ make
```

6. Run the program

```shell
$ ./BankProgram
```

# Run the tests

1. Change to the project root directory

```shell
$ cd
```

2. Change into the tests directory

```shell
$ cd tests
```

3. Run the test executable

```shell
$ ./bank_unit_tests_results
```
