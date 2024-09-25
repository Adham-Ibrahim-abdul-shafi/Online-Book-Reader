#ifndef ADMIN_VIEW_H
#define ADMIN_VIEW_H

#include "UsersManager.h"
#include "BooksManager.h"

class AdminView {
private:
    UsersManager* users_manager { nullptr };
    BooksManager* books_manager { nullptr };

    void PrintBook(Book* book);

public:
    AdminView(UsersManager* users_manager, BooksManager* books_manager);
    ~AdminView();

    void DisplayAdminMenu();
    void AddBook();
    void UpdateBook();
    void DeleteBook();
    void ViewAllBooks();
};

#endif
