#include <iostream>
#include "UsersManager.h"
#include "BooksManager.h"
#include "AdminView.h"
#include "UserView.h"
#include "Utilities.h"

using namespace std;

int main() {
    UsersManager users_manager;
    BooksManager books_manager;

    AdminView admin_view(&users_manager, &books_manager);
    UserView user_view(&users_manager, &books_manager);

    while (true) {
        cout << "\nAre you an Admin or a User?\n";
        int choice = ShowReadMenu({"Admin", "User", "Exit"});

        if (choice == 1) {  // Admin
            admin_view.DisplayAdminMenu();
        } else if (choice == 2) {  // User
            if (!users_manager.Login()) {
                cout << "Invalid login credentials.\n";
            } else {
                user_view.DisplayUserMenu();
            }
        } else {
            break;
        }
    }

    cout << "Thank you for using the library system!\n";
    return 0;
}
