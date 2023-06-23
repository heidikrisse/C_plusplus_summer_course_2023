#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

/* Defines Transaction struct that holds the id, type (Income or Expense) and amount of the transaction */
struct Transaction
{
    int id{};
    std::string type{};
    double amount{};
};

#endif
