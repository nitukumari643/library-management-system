#include "Library.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

void Library::addBook(const Book& book) {
    books.push_back(book);
    std::cout << "Your Book added successfully!" << std::endl;
}

void Library::deleteBook(int id) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getId() == id) {
            books.erase(it);
            std::cout << "Book deleted successfully!" << std::endl;
            return;
        }
    }
    std::cout << "Book not found!" << std::endl;
}

void Library::viewBooks() const {
    if (books.empty()) {
        std::cout << "No books in the library." << std::endl;
        return;
    }
    for (const auto& book : books) {
        book.displayBook();
    }
}

void Library::openBookPdf(int id) const {
    for (const auto& book : books) {
        if (book.getId() == id) {
            std::string pdfPath = book.getPdfFilePath();
            if (!pdfPath.empty()) {
                std::cout << "Opening PDF: " << pdfPath << std::endl;

                #if defined(_WIN32) || defined(_WIN64)
                    std::string command = "start \"\" \"" + pdfPath + "\"";
                #elif defined(__APPLE__) || defined(__MACH__)
                    std::string command = "open \"" + pdfPath + "\"";
                #elif defined(__linux__)
                    std::string command = "xdg-open \"" + pdfPath + "\"";
                #else
                    std::cout << "Unsupported operating system." << std::endl;
                    return;
                #endif

                system(command.c_str());
            } else {
                std::cout << "No PDF file path provided for this book." << std::endl;
            }
            return;
        }
    }
    std::cout << "Book not found!" << std::endl;
}

void Library::loadBooksFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile) {
        std::cout << "Could not open file " << filename << std::endl;
        return;
    }
    books.clear();
    int id;
    std::string title, author, pdfFilePath;
    while (infile >> id) {
        infile.ignore(); // ignore the newline character after the id
        std::getline(infile, title);
        std::getline(infile, author);
        std::getline(infile, pdfFilePath);
        books.push_back(Book(id, title, author, pdfFilePath));
    }
    infile.close();
    std::cout << "Books loaded from file successfully!" << std::endl;
}

void Library::saveBooksToFile(const std::string& filename) const {
    std::ofstream outfile(filename);
    if (!outfile) {
        std::cout << "Could not open file " << filename << std::endl;
        return;
    }
    for (const auto& book : books) {
        outfile << book.getId() << std::endl;
        outfile << book.getTitle() << std::endl;
        outfile << book.getAuthor() << std::endl;
        outfile << book.getPdfFilePath() << std::endl;
    }
    outfile.close();
    std::cout << "Books saved to file successfully!" << std::endl;
}
