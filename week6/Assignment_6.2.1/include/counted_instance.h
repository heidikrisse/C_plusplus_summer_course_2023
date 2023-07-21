#ifndef COUNTED_INSTANCE_H
#define COUNTED_INSTANCE_H

class CountedInstance
{
private:
    static int instance_count;

public:
    CountedInstance();
    ~CountedInstance();

    static void print_count();
};

#endif
