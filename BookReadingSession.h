#ifndef BOOKREADINGSESSION_H
#define BOOKREADINGSESSION_H

#include "Book.h"
#include <string>

using namespace std;

class BookReadingSession {
private:
    Book* book;
    int current_page;
    string last_access_date;

public:
    BookReadingSession();
    BookReadingSession(Book* book);
    string ToString();
    string GetCurrentPageContent();
    const Book* GetBook() const;
    const string& GetLastAccessDate() const;
    void ResetLastAccessDate();
    int GetCurrentPage() const;
    string PageIdxStr();
    void NextPage();
    void PreviousPage();
};

#endif // BOOKREADINGSESSION_H
