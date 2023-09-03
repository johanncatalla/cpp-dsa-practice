#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int year;
    std::string publisher;
};

Book addPublisher(const Book &inputbook) {
    Book newbook = inputbook;

    std::cout << "Enter Publisher Name: ";
    std::cin.ignore();
    std::getline(std::cin, newbook.publisher);

    return newbook;
}

int main() {
    Book book1;

    std::cout << "Enter Book Title: ";
    std::getline(std::cin, book1.title);

    std::cout << "Enter Book Author: ";
    std::getline(std::cin, book1.author);

    std::cout << "Enter Publication Year: ";
    std::cin >> book1.year;

    Book resBook = addPublisher(book1);

    std::cout << "\nBook Details: \n"
              << "Title: " << resBook.title
              << "\nAuthor: " << resBook.author
              << "\nPublication Year: " << resBook.year
              << "\nPublisher: " << resBook.publisher;

    return 0;
}
