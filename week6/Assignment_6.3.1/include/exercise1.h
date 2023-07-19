#ifndef EXERCISE1_H
#define EXERCISE1_H

class ClassWithStaticMemberFunction
{
private:
    ClassWithStaticMemberFunction() {}

public:
    ~ClassWithStaticMemberFunction() {}

    static ClassWithStaticMemberFunction create_instance();
};

#endif
