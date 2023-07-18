#include "positive_integer.h"
#include "counted_instance.h"

#include <iostream> // for std::cerr

int main()
{
    try
    {
        PositiveInteger a{42};
        PositiveInteger b{51};
        a.subtract(b);
        // Should print 0, because the result is negative and we saturate to 0
        a.print_value();

        // Negative value, should throw error: 'Value cannot be negative'
        PositiveInteger c{-1};
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << "\n";
    }

    PositiveInteger a{1};
    PositiveInteger b{2};

    a.add(b);
    a.print_value(); // Should print '3'

    a.subtract(b);
    a.print_value(); // Should print '1'

    CountedInstance instance1{};
    CountedInstance instance2{};
    CountedInstance::print_count(); // Should print 'Instance count: 2'

    return 0;
}
