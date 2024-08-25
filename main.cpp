#include <iostream>
#include "Library.h"

void displayMenu() {
    std::cout << "Library Management System" << std::endl;
    std::cout << "1. Add Book" << std::endl;
    std::cout << "2. Delete Book" << std::endl;
    std::cout << "3. View Books" << std::endl;
    std::cout << "4. Load Books from File" << std::endl;
    std::cout << "5. Save Books to File" << std::endl;
    std::cout << "6. Open Book PDF" << std::endl; 
    std::cout << "7. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    Library library;
    int choice;
    std::string filename;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            std::string title, author, pdfFilePath;

            std::cout << "Enter book ID: ";
            std::cin >> id;
            std::cin.ignore(); // ignore newline character
            std::cout << "Enter book title: ";
            std::getline(std::cin, title);
            std::cout << "Enter book author: ";
            std::getline(std::cin, author);
            std::cout << "Enter path to PDF file: "; 
            std::getline(std::cin, pdfFilePath); 

            Book book(id, title, author, pdfFilePath);
            library.addBook(book);
            break;
        }
        case 2: {
            int id;
            std::cout << "Enter book ID to delete: ";
            std::cin >> id;
            library.deleteBook(id);
            break;
        }
        case 3:
            library.viewBooks();
            break;
        case 4:
            std::cout << "Enter filename to load from: ";
            std::cin >> filename;
            library.loadBooksFromFile(filename);
            break;
        case 5:
            std::cout << "Enter filename to save to: ";
            std::cin >> filename;
            library.saveBooksToFile(filename);
            break;
        case 6: {
            int id;
            std::cout << "Enter book ID to open PDF: "; 
            std::cin >> id;
            library.openBookPdf(id); 
            break;
        }
        case 7:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice! Please try again." << std::endl;
        }
    } while (choice != 7);

    return 0;
}
