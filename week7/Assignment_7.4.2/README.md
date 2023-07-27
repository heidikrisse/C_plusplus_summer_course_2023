# Assignment 7.4.2

### Exercise 1.

Here we will create an interface for an UI element (these are usually called widgets).  It should have require functionality such as reacting to user actions "on_click()", "on_focus()", etc.  In addition it should have a way to move and get position of the UI element.  In addition, UI elements usually have child elements (that also fulfill the interface), you should require functionality to add / remove / list those as well.  (These will not work properly without pointers, so you'll get a better way to handle them next week, don't try too much to make them work yet)

### Exercise 2.

Make some mock class that inherits the interface.  It does not need to be a real UI or anything, just something that implements the UI interface.

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
./UIElements
```
