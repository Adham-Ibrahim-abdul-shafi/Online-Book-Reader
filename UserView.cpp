#include "UserView.h"
#include <iostream>
#include "Utilities.h"
using namespace std;

UserView::UserView(UsersManager* users_manager, BooksManager* books_manager)
    : users_manager(users_manager), books_manager(books_manager) {}

UserView::~UserView() {
    cout << "Destructor: UserView\n";
}

void UserView::DisplayUserMenu() {
    cout << "\n\n";
    while (true) {
        int choice = ShowReadMenu({
            "Borrow book", "Return book", "View reading history", 
            "Search book by prefix", "Display reading session details", "Logout" 
        });

        if (choice == 1)
            BorrowBook();
        else if (choice == 2)
            ReturnBook();
        else if (choice == 3)
            ViewReadingHistory();
        else if (choice == 4)
            SearchBookByPrefix();
        else if (choice == 5)
            DisplayReadingSessionDetails();
        else
            break;
    }
}

void UserView::BorrowBook() {
    cout << "\nEnter book ISBN: ";
    string isbn;
    cin >> isbn;

    Book* book = books_manager->GetBook(isbn);
    if (!book) {
        cout << "Invalid ISBN. Try again.\n";
        return;
    }
    if (book->IsBorrowed()) {
        cout << "Sorry, the book is already borrowed by another user.\n";
        return;
    }

    book->SetBorrowed(true);
    BookReadingSession* session = users_manager->AddReadingSession(book);
    PrintSession(session);
}

void UserView::ReturnBook() {
    cout << "\nEnter book ISBN: ";
    string isbn;
    cin >> isbn;

    Book* book = books_manager->GetBook(isbn);
    if (!book) {
        cout << "Invalid ISBN. Try again.\n";
        return;
    }
    if (!book->IsBorrowed()) {
        cout << "The book is not currently borrowed.\n";
        return;
    }

    book->SetBorrowed(false);
    cout << "Book returned successfully.\n";
}

void UserView::ViewReadingHistory() {
    User* current_user = const_cast<User*>(users_manager->GetCurrentUser());
    const vector<BookReadingSession*>& sessions = current_user->GetReadingSessions();
    if (sessions.empty()) {
        cout << "You have no reading history yet.\n";
        return;
    }

    for (const auto& session : sessions) {
        PrintSession(session);
    }
}

void UserView::SearchBookByPrefix() {
    cout << "Enter book title prefix: ";
    string prefix;
    cin >> prefix;

    const map<string, Book*>& books = books_manager->GetIsbnToBookMap();
    bool found = false;

    for (const auto& pair : books) {
        if (pair.second->GetTitle().find(prefix) == 0) {
            PrintBook(pair.second);
            found = true;
        }
    }
    if (!found)
        cout << "No books found with the given prefix.\n";
}

void UserView::DisplayReadingSessionDetails() {
    cout << "Enter book ISBN: ";
    string isbn;
    cin >> isbn;

    User* current_user = const_cast<User*>(users_manager->GetCurrentUser());
    BookReadingSession* session = current_user->GetReadingSession(isbn);
    if (!session) {
        cout << "No reading session found for this book.\n";
        return;
    }
    PrintSession(session);
}

void UserView::PrintBook(Book* book) {
    cout << "\nBook: " << book->GetTitle() << "\n";
    cout << "ISBN: " << book->GetIsbn() << "\n";
    cout << "Author: " << book->GetAuthor() << "\n";
    cout << "Pages: " << book->GetPagesCount() << "\n";
    cout << "Borrowed: " << (book->IsBorrowed() ? "Yes" : "No") << "\n";
}

void
