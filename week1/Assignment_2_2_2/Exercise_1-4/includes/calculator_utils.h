// calculator_utils.h
#ifndef CALCULATOR_UTILS_H
#define CALCULATOR_UTILS_H

#include <string>

// Calculate functions
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

// Caesar cipher functions
std::string encrypt_caesar_cipher(const std::string &text, int shift);
std::string decrypt_caesar_cipher(const std::string &text, int shift);

#endif // CALCULATOR_UTILS_H
