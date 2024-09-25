#include "BookReadingSession.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <chrono>

using namespace std;

string GetCurrentTimeDate() {
    auto now = chrono::system_clock::now();
    auto in_time_t = chrono::system_clock::to_time_t(now);
    stringstream ss;
    ss << put_time(localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

BookReadingSession::BookReadingSession() : BookReadingSession(nullptr) {}

BookReadingSession::BookReadingSession(Book* book) : book(book), current_page(0), last_access_date(GetCurrentTimeDate()) {}

string BookReadingSession::ToString() {
    ostringstream oss;
    oss << book->GetTitle() << " Page: " << PageIdxStr() << " - " << GetLastAccessDate();
    return oss.str();
}

string BookReadingSession::GetCurrentPageContent() {
    return book->GetPages()[current_page];
}

const Book* BookReadingSession::GetBook() const {
    return book;
}

const string& BookReadingSession::GetLastAccessDate() const {
    return last_access_date;
}

void BookReadingSession::ResetLastAccessDate() {
    last_access_date = GetCurrentTimeDate();
}

int BookReadingSession::GetCurrentPage() const {
    return current_page;
}

string BookReadingSession::PageIdxStr() {
    ostringstream oss;
    oss << current_page + 1 << "/" << book->GetPages().size();
    return oss.str();
}

void BookReadingSession::NextPage() {
    if (current_page < (int)book->GetPages().size() - 1)
        current_page++;
}

void BookReadingSession::PreviousPage() {
    if (current_page > 0)
        current_page--;
}
