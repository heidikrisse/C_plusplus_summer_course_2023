// user_input.h
#ifndef USER_INPUT_H
#define USER_INPUT_H

#include "device.h"

// Function to get a slave device id from the user
int get_slave_device_id_from_user();

// Function to get a register address from the user
int get_register_address(Device &slave_device, int chosen_action);

#endif // USER_INPUT_H
