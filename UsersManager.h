#ifndef USERS_MANAGER_H
#define USERS_MANAGER_H

#include <map>
#include "User.h"

class UsersManager {
private:
    User* current_user { nullptr };
    std::map<std::string, User*> userame_userobject_map;

    void FreeLoadedData();

public:
    UsersManager();
    ~UsersManager();

    void LoadDatabase();
    void AccessSystem();
    void DoLogin();
    void DoSignUp();

    BookReadingSession* AddReadingSession(Book* book);
    const User* GetCurrentUser() const;
};

#endif
