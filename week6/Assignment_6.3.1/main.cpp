#include "exercise1.h"
#include "animal.h"

int main()
{
    // Testing Exercise 1
    auto instance = ClassWithStaticMemberFunction::create_instance();

    // Testing Exercise 2 and 3
    Animal a;
    a.message();

    Bird b;
    b.message();

    Parrot p;
    p.message();

    Dog d;
    d.message();

    return 0;
}
