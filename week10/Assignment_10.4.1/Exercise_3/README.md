# Assignment 10.4.1 Exercise 3

Try nlohmann's json library.Links to an external site.  Use it to read a json file from your hard drive and print the stored contents.  (You can use e.g. json files from https://github.com/LearnWebCode/json-exampleLinks to an external site.)  Then create a json file from your code and save that to your hard drive.

JSON is pretty common format to pass data around as a text.  You are bound to run into it so this is quite useful (and commonly used) library for the task.

# Install nlohmann-json3-dev (3.10.5-2)

```shell
sudo apt install nlohmann-json3-dev
```

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
./Json
```
