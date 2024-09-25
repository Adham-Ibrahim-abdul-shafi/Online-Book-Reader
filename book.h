#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

class Book {
private:
    std::string isbn;
    std::string title;
    std::string author;
    std::vector<std::string> pages;

public:
    void Read();
    const std::string& GetAuthor() const;
    void SetAuthor(const std::string& author);
    const std::string& GetIsbn() const;
    void SetIsbn(const std::string& isbn);
    const std::vector<std::string>& GetPages() const;
    void SetPages(const std::vector<std::string>& pages);
    const std::string& GetTitle() const;
    void SetTitle(const std::string& title);
    std::string ToString();
};

#endif
