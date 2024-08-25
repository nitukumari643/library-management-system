#include "Book.h"
#include <iostream>

Book::Book(int id, const std::string& title, const std::string& author, const std::string& pdfFilePath)
    : id(id), title(title), author(author), pdfFilePath(pdfFilePath) {} // Update the constructor

int Book::getId() const {
    return id;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getPdfFilePath() const {
    return pdfFilePath;
}

void Book::displayBook() const {
    std::cout << "ID: " << id << ", Title: " << title << ", Author: " << author << std::endl;
    if (!pdfFilePath.empty()) {
        std::cout << "PDF File: " << pdfFilePath << std::endl;
    }
}
