#include "include/exercise_1.h"
#include "include/exercise_2.h"
#include "include/exercise_3.h"

int main()
{
    // Exercise 1:
    auto functions{get_functions()};
    call_user_function(functions);

    // Exercise 2:
    auto calculator_functions{get_calculator_functions()};
    perform_operation(calculator_functions);

    // Exercise 3:
    variable_map_t variable_map;
    set_variable(variable_map);
    calculate_operation_with_variables(calculator_functions, variable_map);

    return 0;
}
