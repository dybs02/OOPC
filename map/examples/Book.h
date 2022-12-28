#ifndef _BOOK_H_
#define _BOOK_H_

#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    std::string category;
    int numOfPages;
    bool borrowed;

    Book(std::string title = "", std::string author = "", std::string category = "", int numOfPages = 0, bool borrowed = false) :
        title(title),
        author(author),
        category(category),
        numOfPages(numOfPages),
        borrowed(borrowed)
        { }

private:
    friend std::ostream& operator<<(std::ostream& s, const Book& book)
    {
        s << book.title << " - " << book.author;
        s << " (" << book.category << ")";
        s << ", " << book.numOfPages << " pages";
        s << ", (" << (book.borrowed ? "" : "not ") << "borrowed)";

        return s;
    }
};

#endif