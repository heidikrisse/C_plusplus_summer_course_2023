#include <iostream>
#include <expected>
#include <string>

std::optional<std::string> create(bool b)
{
    if (b)
    {
        return "Sub-Zero";
    }

    return std::unexpected{error::user_failure};
}

int main()
{
    auto string{create(false)};
    if (not string.has_value())
    {
        // String does not have a value, so we have an error
        switch (error)
        {
            // ...
        }
    }
    else
    {
        // String has a value, we can use it!
        std::cout << string.value() << '\n';
    }
}
