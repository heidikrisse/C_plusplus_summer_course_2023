// exercise3.cpp
#include "../include/exercise3.h"

#include <iostream>

int CountedInstance::instance_count{0};

CountedInstance::CountedInstance(const std::string &name) : instance_name(name)
{
    ++instance_count;
    std::cout << instance_name << " created.\n";
}

CountedInstance::CountedInstance(CountedInstance &&other) noexcept : instance_name(std::move(other.instance_name))
{
    std::cout << "Resource from " << instance_name << " moved to a new instance that gets the name and other resources from instance2.\n";

    other.instance_name = "old_instance2";
}

CountedInstance::~CountedInstance()
{
    if (instance_name != "old_instance2")
    {
        --instance_count;
        std::cout << instance_name << " destroyed.\n";
    }
}

void CountedInstance::print_count()
{
    std::cout << "Instance count: " << instance_count << '\n';
}
