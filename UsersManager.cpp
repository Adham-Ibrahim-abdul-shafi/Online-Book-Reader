#include "UsersManager.h"
#include "User.h"
#include <iostream>
#include "Utilities.h"
using namespace std;

UsersManager::UsersManager() {}

UsersManager::~UsersManager() {
    cout << "Destructor: UsersManager\n";
    FreeLoadedData();
}

void UsersManager::FreeLoadedData() {
    for (auto pair : userame_userobject_map) {
        delete pair.second;
    }
    userame_userobject_map.clear();
    current_user = nullptr;
}

void UsersManager::LoadDatabase() {
    if (userame_userobject_map.size() > 0)
        return;

    cout << "UsersManager: LoadDatabase\n";
    FreeLoadedData();

    User* user1 = new User();
    user1->SetUserName("mostafa");
    user1->SetPassword("111");
    user1->SetEmail("most@gmail.com");
    user1->SetIsLibraryAdmin(true);
    user1->SetName("Mostafa Saad Ibrahim");
    userame_userobject_map[user1->GetUserName()] = user1;

    User* user2 = new User();
    user2->SetUserName("asmaa");
    user2->SetPassword("222");
    user2->SetEmail("asmaa@gmail.com");
    user2->SetIsLibraryAdmin(false);
    user2->SetName("Asmaa Saad Ibrahim");
    userame_userobject_map[user2->GetUserName()] = user2;
}

void UsersManager::AccessSystem() {
    int choice = ShowReadMenu({ "Login", "Sign Up" });
    if (choice == 1)
        DoLogin();
    else
        DoSignUp();
}

void UsersManager::DoLogin() {
    LoadDatabase();

    while (true) {
        string user_name, pass;
        cout << "Enter user name (no spaces): ";
        cin >> user_name;
        cout << "Enter password (no spaces): ";
        cin >> pass;

        if (!userame_userobject_map.count(user_name)) {
            cout << "\nInvalid user user_name or password. Try again\n\n";
            continue;
        }
        User* user_exist = userame_userobject_map[user_name];
        if (pass != user_exist->GetPassword()) {
            cout << "\nInvalid user user_name or password. Try again\n\n";
            continue;
        }
        current_user = user_exist;
        break;
    }
}

void UsersManager::DoSignUp() {
    string user_name;
    while (true) {
        cout << "Enter user name (No spaces): ";
        cin >> user_name;

        if (userame_userobject_map.count(user_name))
            cout << "Already used. Try again\n";
        else
            break;
    }
    current_user = new User();
    current_user->Read(user_name);
    userame_userobject_map[current_user->GetUserName()] = current_user;
}

BookReadingSession* UsersManager::AddReadingSession(Book* book) {
    return current_user->AddReadingSession(book);
}

const User* UsersManager::GetCurrentUser() const {
    return current_user;
}
