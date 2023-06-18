// main.cpp
#include "include/data_generator.h"
#include "include/modbus_simulator.h"

int main()
{
    // Generate devices and their registers data
    generate_devices_and_registers();

    // Simulate Modbus communication
    simulate_modbus_communication();

    return 0;
}
