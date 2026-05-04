#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int year;
    int pages;

public:
    Book() {
        title = "";
        author = "";
        year = 0;
        pages = 0;
    }

    Book(string t, string a, int y, int p) {
        title = t;
        author = a;
        year = y;
        pages = p;
    }

    void setTitle(string t) {
        title = t;
    }

    void setAuthor(string a) {
        author = a;
    }

    void setYear(int y) {
        year = y;
    }

    void setPages(int p) {
        pages = p;
    }
    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    int getYear() {
        return year;
    }

    int getPages() {
        return pages;
    }

    void input() {
        string temp;
        cout << "Title: "; cin >> ws; getline(cin, title);
        cout << "Author: "; getline(cin, author);
        cout << "Year: "; cin >> year;
        cout << "Pages: "; cin >> pages;
    }

    void display() {
        cout << title << " (" << author << ", " << year << ") - " << pages << " p." << endl;
    }
};

int main() {
    int n;
    cout << "How many books to enter? ";
    cin >> n;

    Book* books = new Book[n];

    for (int i = 0; i < n; i++) {
        cout << "\nBook " << i + 1 << ":" << endl;
        books[i].input();
    }

    Book maxBook = books[0];
    for (int i = 1; i < n; i++) {
        if (books[i].getPages() > maxBook.getPages()) {
            maxBook = books[i];
        }
    }
    cout << "\nBook with the most pages:" << endl;
    maxBook.display();

    delete[] books;
}