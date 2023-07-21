#include "counted_instance.h"

#include <iostream>

int CountedInstance::instance_count{0};

CountedInstance::CountedInstance()
{
    ++instance_count;
}

CountedInstance::~CountedInstance()
{
    --instance_count;
}

void CountedInstance::print_count()
{
    std::cout << "Instance count: " << instance_count << "\n";
}
