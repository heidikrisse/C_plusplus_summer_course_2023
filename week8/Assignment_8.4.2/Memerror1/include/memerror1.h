/* memerror.h
 *
 * ---------- Exercise 1: ----------
 *
 * =================================================================
==31735==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x606000000000 at pc 0x5640cde64b71 bp 0x7ffe5c3733a0 sp 0x7ffe5c373390
 *
 * 0x606000000000 is located 32 bytes to the left of 64-byte region [0x606000000020,0x606000000060)
 *
 * Answer => a heap-buffer-overflow
 *        => If an element in the middle of the vector is erased, the indices (or handles) of all subsequent objects will become invalid since they still point to their original position
 *        => The destructor of the copied object will erase(delete) the object at handle from object_storage and when the original large_object destructor is called, it will try to delete the same object
 *
 **/
#ifndef MEMERROR1_H
#define MEMERROR1_H

#include <vector>
#include <iostream>

//
// A common pattern is to store elements contiguous in memory, and then just store a
// handle to the stored element with the class actually used.
//
// This way objects of similar type can be stored contiguously, and we can avoid some
// cache trashing.
//

// We have a class for the actual data we store, usually not directly accessible
struct object_data
{
    std::string name;
};

// and the storage in a vector.  This usually is a bit less obvious than a static
// global variable, but it'll do here.
static std::vector<object_data> object_storage;

// And then the publicly available class we actually use to access the data
class large_object
{
public:
    large_object();
    ~large_object();

    // ---------- Exercise 3: ----------
    // Remove
    // large_object(const large_object &) = default; // default the copy constructor, since
    // the class is basically just the handle
    // anyways
    large_object(const large_object &other);

    // Assignment operator overload
    large_object &operator=(const large_object &other);

private:
    // int is often used as a handle, so negative values an be used to denote
    // errors.  std::ssize_t is another often seen choice, but we aren't going
    // to create more than INT_MAX elements in our container here.
    int handle;
};

// Implementations
large_object::large_object()
{
    int next_handle = object_storage.size();

    // create new default-initialised value in the container
    // and set our handle to match the index
    object_storage.push_back({std::string("object number ") + std::to_string(next_handle)});
    handle = next_handle;
}

// ---------- Exercise 3 ----------
large_object::~large_object()
{
    // delete the handle'th element from the storage
    // object_storage.erase(object_storage.begin() + handle);

    // first check if handle is valid
    if (handle >= 0 && static_cast<std::size_t>(handle) < object_storage.size())
    {
        object_storage.erase(object_storage.begin() + handle);
    }
}

// Custom copy constructor that creates a new object in object_storage for the copied object.
large_object::large_object(const large_object &other)
{
    int next_handle{object_storage.size()};
    object_storage.push_back(object_storage[other.handle]);
    handle = next_handle;
}

// Custom assignment operator to handle object assignment properly.
large_object &large_object::operator=(const large_object &other)
{
    if (this != &other)
    {
        int next_handle = object_storage.size();
        object_storage.push_back(object_storage[other.handle]);
        handle = next_handle;
    }
    return *this;
}

#endif
