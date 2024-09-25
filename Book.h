#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string isbn;
    string title;
    string author;
    vector<string> pages;

public:
    void Read();
    const string& GetAuthor() const;
    void SetAuthor(const string& author);
    const string& GetIsbn() const;
    void SetIsbn(const string& isbn);
    const vector<string>& GetPages() const;
    void SetPages(const vector<string>& pages);
    const string& GetTitle() const;
    void SetTitle(const string& title);
    string ToString();
};

#endif // BOOK_H
