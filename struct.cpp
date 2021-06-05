#include <iostream>
using namespace std;

struct book
{
    string name;
    string author;
    int pages;
    double price;
};

int main()
{

    book b1 = {"book1", "author1", 255, 29.99};
    // b1.name = "book1";
    // b1.author = "author1";
    // b1.pages = 255;
    // b1.price = 29.99;

    cout << "enter the book name";
    cin >> b1.name;
    cout << b1.name;

    book books[10];
    books[0].name ="atomic habits";

    cout <<  books[0].name;

    return 0;
}
