// account_functions.h
#ifndef ACCOUNT_FUNCTIONS_H
#define ACCOUNT_FUNCTIONS_H

#include "banking_functions.h"

void add_money(Customer &customer, int account_number);
void withdraw_money(Customer &customer, int account_number);
void see_account_balance(const Customer &customer, int account_number);

#endif // ACCOUNT_FUNCTIONS_H
