#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <vector>
#include <string>

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book);
    void deleteBook(int id);
    void viewBooks() const;
    void openBookPdf(int id) const; 
    void loadBooksFromFile(const std::string& filename);
    void saveBooksToFile(const std::string& filename) const;
};

#endif // LIBRARY_H
