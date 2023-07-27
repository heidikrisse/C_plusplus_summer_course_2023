// main.cpp
// #include "include/ui_element.h"
#include "include/button.h"

int main()
{
    Button btn;
    int choice{};
    do
    {
        std::cout << "\n*** Menu Options:***\n\n";
        std::cout << "1. Click Button\n";
        std::cout << "2. Move Button\n";
        std::cout << "3. Get Button position\n";
        std::cout << "4. Quit\n\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        int x{};
        int y{};

        switch (choice)
        {
        case 1:
            btn.on_click();

            break;
        case 2:
            std::cout << "Enter x coordinate: ";
            std::cin >> x;
            std::cout << "Enter y coordinate : ";
            std::cin >> y;
            btn.move(x, y);

            break;
        case 3:
            btn.get_position();

            break;
        case 4:
            std::cout << "Exiting...\n";

            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
