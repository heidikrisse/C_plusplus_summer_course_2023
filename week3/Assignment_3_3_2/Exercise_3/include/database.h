// database.h
#ifndef DATABASE_H
#define DATABASE_H

#include "banking_functions.h"
#include <fstream>

// Function to save account data to a file
void save_account_data(const Bank &bank);

// Function to load account data from a file and create a new file if it doesn't exist
void load_account_data(Bank &bank);

#endif // DATABASE_H
