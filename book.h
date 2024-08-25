#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    std::string pdfFilePath;

public:
    Book(int id, const std::string& title, const std::string& author, const std::string& pdfFilePath = "");
    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getPdfFilePath() const;
    void displayBook() const;
};

#endif // BOOK_H
