// main.cpp
#include "include/memerror1.h"

int main()
{
    // segmentation fault
    large_object a;
    large_object b = a;
    large_object c;
}
