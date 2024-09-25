#include "AdminView.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

AdminView::AdminView(UsersManager* users_manager, BooksManager* books_manager)
    : users_manager(users_manager), books_manager(books_manager) {}

AdminView::~AdminView() {
    cout << "Destructor: AdminView\n";
}

void AdminView::DisplayAdminMenu() {
    cout << "\n\n";
    while (true) {
        int choice = ShowReadMenu({
            "View all books", "Add book", "Update book", "Delete book", "Logout"
        });

        if (choice == 1)
            ViewAllBooks();
        else if (choice == 2)
            AddBook();
        else if (choice == 3)
            UpdateBook();
        else if (choice == 4)
            DeleteBook();
        else
            break;
    }
}

void AdminView::AddBook() {
    Book* book = new Book();
    book->Read();
    books_manager->AddBook(book);
}

void AdminView::UpdateBook() {
    cout << "\nEnter book ISBN: ";
    string isbn;
    cin >> isbn;

    Book* book = books_manager->GetBook(isbn);
    if (!book) {
        cout << "Invalid ISBN. Try again.\n";
        return;
    }
    book->Read();
    books_manager->UpdateBook(isbn, book);
}

void AdminView::DeleteBook() {
    cout << "\nEnter book ISBN: ";
    string isbn;
    cin >> isbn;

    Book* book = books_manager->GetBook(isbn);
    if (!book) {
        cout << "Invalid ISBN. Try again.\n";
        return;
    }
    books_manager->DeleteBook(isbn);
    cout << "Book deleted successfully.\n";
}

void AdminView::ViewAllBooks() {
    const map<string, Book*>& books = books_manager->GetIsbnToBookMap();

    if (books.empty()) {
        cout << "No books in the library.\n";
        return;
    }

    for (const auto& pair : books) {
        PrintBook(pair.second);
    }
}

void AdminView::PrintBook(Book* book) {
    cout << "\nBook: " << book->GetTitle() << "\n";
    cout << "ISBN: " << book->GetIsbn() << "\n";
    cout << "Author: " << book->GetAuthor() << "\n";
    cout << "Pages: " << book->GetPagesCount() << "\n";
    cout << "Borrowed: " << (book->IsBorrowed() ? "Yes" : "No") << "\n";
}
