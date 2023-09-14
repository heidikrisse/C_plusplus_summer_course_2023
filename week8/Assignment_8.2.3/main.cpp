// main.cpp
#include "include/grid.h"
#include "include/grid_functions.h"
#include "include/user_ui.h"

#include <iostream>

int main()
{
    while (true)
    {
        std::cout << "\n*** Main Menu: ***\n\n";
        std::cout << "1. Create 2D Grid\n";
        std::cout << "2. Create 3D Grid\n";
        std::cout << "3. Quit\n\n";

        int main_choice{get_input("Enter your choice: ")};

        switch (main_choice)
        {
        case 1:
        {
            create_and_manage_2d_grid();
            break;
        }
        case 2:
        {
            create_and_manage_3d_grid();
            break;
        }
        case 3:
            return 0;
        default:
            std::cout << "Unsupported choice. Please try again.\n";
        }
    }
    return 0;
}
