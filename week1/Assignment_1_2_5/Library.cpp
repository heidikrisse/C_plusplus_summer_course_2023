#include <iostream>
#include "Library.h"

std::vector<Book> library;

// Function to add a book to the library
void addBook()
{
    std::cout << "Enter book title: ";
    std::string title{};
    std::getline(std::cin, title);

    std::cout << "Enter author name: ";
    std::string author{};
    std::getline(std::cin, author);

    std::cout << "Enter ISBN: ";
    std::string ISBN{};
    std::getline(std::cin, ISBN);

    std::cout << "Enter publication year: ";
    int year{};
    std::cin >> year;

    std::cout << "Enter quantity: ";
    int quantity{};
    std::cin >> quantity;

    Book newBook{title, author, ISBN, year, quantity, false};
    library.push_back(newBook);
    std::cout << "Book added successfully!\n";
}

// Function to print a book's details
void printBook(const Book &book)
{
    std::cout << "Title: " << book.title << "\n";
    std::cout << "Author: " << book.author << "\n";
    std::cout << "ISBN: " << book.ISBN << "\n";
    std::cout << "Year: " << book.year << "\n";
    std::cout << "Quantity: " << book.quantity << "\n";
    std::cout << "Loaned out: " << (book.loaned ? "Yes" : "No") << "\n\n";
}

// Helper functions to ask user for different search criteria:

int askForSearchType()
{
    std::cout << "Search by:\n1. Title\n2. Author\n3. ISBN\n4. Year\n5. Loan status\nEnter your choice: ";
    int choice{};
    std::cin >> choice;
    return choice;
}

std::string askForTitle()
{
    std::cout << "Enter the title you're looking for: ";
    std::string searchTitle{};
    std::getline(std::cin, searchTitle);
    return searchTitle;
}

std::string askForAuthor()
{
    std::cout << "Enter the author you're looking for: ";
    std::string searchAuthor{};
    std::getline(std::cin, searchAuthor);
    return searchAuthor;
}

std::string askForISBN()
{
    std::cout << "Enter the ISBN you're looking for: ";
    std::string searchISBN{};
    std::getline(std::cin, searchISBN);
    return searchISBN;
}

int askForYear()
{
    std::cout << "Enter the publication year you're looking for: ";
    int searchYear{};
    std::cin >> searchYear;
    return searchYear;
}

bool askForLoanStatus()
{
    std::cout << "Enter the loan status you're looking for (0 for not loaned, 1 for loaned): ";
    int searchLoaned{};
    std::cin >> searchLoaned;
    return bool(searchLoaned);
}

// Function to display a book based on user's choice of search criteria
void displayBook()
{
    int choice{askForSearchType()};

    switch (choice)
    {
    case 1:
    {
        std::string searchTitle{askForTitle()};
        // Iterates over each 'Book' object in the 'library' vector
        // '&' is used to get a reference to the actual book object in the library
        for (Book &book : library)
        {
            if (book.title == searchTitle)
                printBook(book);
        }
        break;
    }
    case 2:
    {
        std::string searchAuthor{askForAuthor()};
        for (Book &book : library)
        {
            if (book.author == searchAuthor)
                printBook(book);
        }
        break;
    }
    case 3:
    {
        std::string searchISBN{askForISBN()};
        for (Book &book : library)
        {
            if (book.ISBN == searchISBN)
                printBook(book);
        }
        break;
    }
    case 4:
    {
        int searchYear{askForYear()};
        for (Book &book : library)
        {
            if (book.year == searchYear)
                printBook(book);
        }
        break;
    }
    case 5:
    {
        bool searchLoaned{askForLoanStatus()};
        for (Book &book : library)
        {
            if (book.loaned == searchLoaned)
                printBook(book);
        }
        break;
    }
    default:
    {
        std::cout << "Invalid choice. Try again.\n";
        return;
    }
    }
}

// Function to remove a book from the library by the ISBN
void removeBook()
{
    std::cout << "Enter ISBN of book to remove: ";
    std::string ISBN{};
    std::cin >> ISBN;

    for (auto bookIterator{library.begin()}; bookIterator != library.end(); ++bookIterator)
    {
        if (bookIterator->ISBN == ISBN)
        {
            library.erase(bookIterator);
            std::cout << "Book removed successfully!\n";
            return;
        }
    }

    std::cout << "No book found with the provided ISBN.\n";
}

// Function to manage the library
void manageLibrary()
{
    // Continually asks the user what they want to do until they choose to exit
    while (true)
    {
        std::cout << "What do you want to do?\n1. Add a book\n2. Display a book\n3. Remove a book\n4. Exit\nEnter your choice (1, 2, 3 or 4): ";
        int choice{};
        std::cin >> choice;

        if (choice == 1)
        {
            addBook();
        }
        else if (choice == 2)
        {
            displayBook();
        }
        else if (choice == 3)
        {
            removeBook();
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            std::cout << "Invalid choice. Try again.\n";
        }
    }
}
