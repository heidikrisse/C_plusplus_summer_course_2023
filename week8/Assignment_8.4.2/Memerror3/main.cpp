// main.cpp
#include "include/memerror3.h"

int main()
{
    // we could use the C library like this, but it's usually a bad idea
    // (bug-prone), so we want to do the wrapping to handle some of the
    // busywork for us. (And have RAII so we don't forget to clean up
    // after ourselves)
    some_c_library *lib = some_c_new();
    do_stuff_after_init(lib);
    some_c_free(lib);

    // with C++ we would use it like (so we trade initial wrapping work to
    // ease of use later on)
    cpp_wrapper wrapped;
    wrapped.do_stuff();

    // But our wrapper might still be a bit under construction...
    auto wrapped2 = build_wrapper();

    wrapped2.do_stuff();
}
