#ifndef USER_VIEW_H
#define USER_VIEW_H

#include "UsersManager.h"
#include "BooksManager.h"

class UserView {
private:
    UsersManager* users_manager { nullptr };
    BooksManager* books_manager { nullptr };

    void PrintBook(Book* book);
    void PrintSession(BookReadingSession* session);

public:
    UserView(UsersManager* users_manager, BooksManager* books_manager);
    ~UserView();

    void DisplayUserMenu();
    void BorrowBook();
    void ReturnBook();
    void ViewReadingHistory();
    void SearchBookByPrefix();
    void DisplayReadingSessionDetails();
};

#endif
