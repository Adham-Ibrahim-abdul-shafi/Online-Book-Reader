#include "Book.h"

void Book::Read() {
    string str;

    cout << "Enter ISBN: ";
    cin >> str;
    SetIsbn(str);

    cout << "Enter Title: ";
    cin >> str;
    SetTitle(str);

    cout << "Enter Author Name: ";
    cin >> str;
    SetAuthor(str);

    cout << "Enter How many pages: ";
    int pages_count;
    cin >> pages_count;

    for (int page = 0; page < pages_count; ++page) {
        cout << "Enter page # " << page + 1 << ": ";
        cin >> str;
        pages.push_back(str);
    }
}

const string& Book::GetAuthor() const {
    return author;
}

void Book::SetAuthor(const string& author) {
    this->author = author;
}

const string& Book::GetIsbn() const {
    return isbn;
}

void Book::SetIsbn(const string& isbn) {
    this->isbn = isbn;
}

const vector<string>& Book::GetPages() const {
    return pages;
}

void Book::SetPages(const vector<string>& pages) {
    this->pages = pages;
}

const string& Book::GetTitle() const {
    return title;
}

void Book::SetTitle(const string& title) {
    this->title = title;
}

string Book::ToString() {
    return title;
}
