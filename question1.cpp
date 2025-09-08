#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

// TODO: Write the Book struct here
// struct Book { ... }
struct Book {
    string title;
    string author;
    int year;
    int pages;
    string isbn;
};

void print_book(int index, const char* title, const char* author, int year, int pages, const char* isbn) {
    cout << "Book[" << index << "]: "
         << "title=" << title << ", "
         << "author=" << author << ", "
         << "year=" << year << ", "
         << "pages=" << pages << ", "
         << "isbn=" << isbn << "\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    if (!input) {
        cerr << "Error opening " << argv[1] << endl;
        return 1;
    }

    int num_books;
    input >> num_books;
    input.ignore(); // skip newline 

    // TODO: Create array of Book
    // Book books[10];
    Book books[num_books];

    // TODO: Read books from input
    // for (int i = 0; i < num_books; i++) { ... }

    for (int i = 0; i < num_books; ++i) {
        
        getline(input, books[i].title);
        getline(input, books[i].author);
        input >> books[i].year;
        input >> books[i].pages;
        input.ignore(); 
        getline(input, books[i].isbn);
    }

    // TODO: Print books using print_book
    // for (int i = 0; i < num_books; i++) { ... }

    for (int i = 0; i < num_books; ++i) {
        print_book(i, books[i].title.c_str(), books[i].author.c_str(), books[i].year, books[i].pages, books[i].isbn.c_str());
    }

    return 0;
}
