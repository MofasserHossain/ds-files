#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Book
{
public:
    string title;
    string author;
    int year;

    Book(string t, string a, int y) : title(t), author(a), year(y) {}
};

class Library
{
private:
    vector<Book> books;

public:
    void addBook(const Book &book)
    {
        books.push_back(book);
        cout << "Book added successfully.\n";
    }

    void deleteBook(const string &title)
    {
        auto it = remove_if(books.begin(), books.end(), [&title](const Book &book)
                            { return book.title == title; });

        if (it != books.end())
        {
            books.erase(it, books.end());
            cout << "Book deleted successfully.\n";
        }
        else
        {
            cout << "Book not found.\n";
        }
    }

    void searchBook(const string &title)
    {
        auto it = find_if(books.begin(), books.end(), [&title](const Book &book)
                          { return book.title == title; });

        if (it != books.end())
        {
            cout << "Book found:\n";
            cout << "Title: " << it->title << "\tAuthor: " << it->author << "\tYear: " << it->year << "\n";
        }
        else
        {
            cout << "Book not found.\n";
        }
    }

    void displayBooks()
    {
        if (books.empty())
        {
            cout << "No books in the library.\n";
            return;
        }

        cout << "Library Books:\n";
        for (const auto &book : books)
        {
            cout << "Title: " << book.title << "\tAuthor: " << book.author << "\tYear: " << book.year << "\n";
        }
    }
};

int main()
{
    Library library;

    while (true)
    {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Delete Book\n";
        cout << "3. Search Book\n";
        cout << "4. Display Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string title, author;
            int year;

            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);

            cout << "Enter author: ";
            getline(cin, author);

            cout << "Enter year: ";
            cin >> year;

            Book book(title, author, year);
            library.addBook(book);
            break;
        }
        case 2:
        {
            string title;
            cout << "Enter the title of the book to delete: ";
            cin.ignore();
            getline(cin, title);
            library.deleteBook(title);
            break;
        }
        case 3:
        {
            string title;
            cout << "Enter the title of the book to search: ";
            cin.ignore();
            getline(cin, title);
            library.searchBook(title);
            break;
        }
        case 4:
            library.displayBooks();
            break;
        case 5:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
