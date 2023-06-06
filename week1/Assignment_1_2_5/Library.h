#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>

struct Book
{
    std::string title{};
    std::string author{};
    std::string ISBN{};
    int year{};
    int quantity{};
    bool loaned{};
};

void addBook();
void printBook(const Book &book);
int askForSearchType();
std::string askForTitle();
std::string askForAuthor();
std::string askForISBN();
int askForYear();
bool askForLoanStatus();
void displayBook();
void removeBook();
void manageLibrary();

#endif // LIBRARY_H
