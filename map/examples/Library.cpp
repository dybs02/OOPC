#include "Book.h"
#include "./../src/Map.h"

using namespace std;

int main() {

    Book b1 = Book("Somehow I Manage", "Michael Scott", "Biography", 100);
    Book b2 = Book("Da Vinci Code", "Dan Brown", "Thriller", 571);
    Book b3 = Book("Angels and Demons", "Dan Brown", "Thriller", 498, true);
    Book b4 = Book("Hide", "Lisa Gardner", "Crime", 452, true);


    Map<string, Book> library;
    library.add(b1.title, b1);
    library.add(b2.title, b2);
    library.add(b3.title, b3);
    library.add(b4.title, b4);

    cout << "Books: " << endl;
    cout << library << endl;

    cout << "Modifying book \"Hide\"" << endl;
    Book* found = library.find("Hide");
    if (found) {
        found->category = "Thriller, Crime";
        cout << "category = \"Thriller, Crime\"" << endl;
        found->numOfPages = 542;
        cout << "numOfPages = 542" << endl;
        found->borrowed = false;
        cout << "borrowed = false" << endl << endl;
    } else {
        cout << "Could not find book with key = \"Hide\"" << endl;
    }

    cout << "Books: " << endl;
    cout << library << endl;

    return 0;
}