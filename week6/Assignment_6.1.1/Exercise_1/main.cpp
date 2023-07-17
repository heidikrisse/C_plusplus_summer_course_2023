#include "include/status.h"
#include <iostream>
#include <random>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 2);

    int random_number = dist(gen);

    status result{};
    std::string status_text{};

    switch (static_cast<status>(random_number))
    {
    case status::SUCCESS:
    {
        result = status::SUCCESS;
        status_text = "Success";
        break;
    }
    case status::ERROR1:
    {
        result = status::ERROR1;
        status_text = "Error 1";
        break;
    }
    case status::ERROR2:
    {
        result = status::ERROR2;
        status_text = "Error 2";
        break;
    }
    }

    std::cout << "status: " << status_text << "\n";

    return 0;
}
