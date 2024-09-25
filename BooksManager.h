#ifndef BOOKS_MANAGER_H
#define BOOKS_MANAGER_H

#include <iostream>
#include <map>
#include "Book.h"

class BooksManager {
private:
    std::map<std::string, Book*> isbn_to_book_map;

    void FreeLoadedData();

public:
    BooksManager();
    ~BooksManager();

    void LoadDatabase();
    void AddBook(Book* book);
    void UpdateBook(std::string isbn, Book* book);
    void DeleteBook(std::string isbn);
    Book* GetBook(std::string isbn);
    const std::map<std::string, Book*>& GetIsbnToBookMap() const;
    void SetIsbnToBookMap(const std::map<std::string, Book*>& isbnToBookMap);
};

#endif
