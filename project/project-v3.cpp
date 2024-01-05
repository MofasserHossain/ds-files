#include <iostream>
using namespace std;
#define MAX_BOOKS 100

struct Book
{
    string title;
    string author;
    int year;
    bool availability;
};

struct Library
{
    Book books[MAX_BOOKS];
    int numBooks;
};

// Function to find book by title
int findBookByTitle(const Library &library, const string &title)
{
    for (int i = 0; i < library.numBooks; ++i)
    {
        if (library.books[i].title == title)
        {
            return i;
        }
    }
    return -1;
}

// Function to remove book by title
void removeBookByTitle(Library &library, const string &title)
{
    int index = findBookByTitle(library, title);

    if (index != -1)
    {
        for (int j = index; j < library.numBooks - 1; ++j)
        {
            library.books[j] = library.books[j + 1];
        }
        library.numBooks--;
        cout << "Book deleted successfully.\n";
    }
    else
    {
        cout << "Book not found.\n";
    }
}

// Function to update book by title
void updateBookByTitle(Library &library, const string &title)
{
    int index = findBookByTitle(library, title);

    if (index != -1)
    {
        cout << "Enter new title: ";
        cin.ignore();
        getline(cin, library.books[index].title);

        cout << "Enter new author: ";
        getline(cin, library.books[index].author);

        cout << "Enter new year: ";
        cin >> library.books[index].year;

        cout << "Enter new availability (1 for available, 0 for not available): ";

        int availability;

        cin >> availability;

        if (availability == 1)
        {
            library.books[index].availability = true;
        }
        else
        {
            library.books[index].availability = false;
        }

        cout << "Book updated successfully.\n";
    }
    else
    {
        cout << "Book not found.\n";
    }
}

// Function to search book by title
void searchBook(const Library &library, const string &title)
{
    int index = findBookByTitle(library, title);

    if (index != -1)
    {
        cout << "Book found:\n";
        cout << "Title: " << library.books[index].title << "\tAuthor: " << library.books[index].author
             << "\tYear: " << library.books[index].year << "\tAvailability: "
             << (library.books[index].availability ? "Available" : "Not Available") << "\n";
    }
    else
    {
        cout << "Book not found.\n";
    }
}

// Function to display all books
void displayBooks(const Library &library)
{
    if (library.numBooks == 0)
    {
        cout << "No books in the library.\n";
        return;
    }

    cout << "Library Books:\n";
    for (int i = 0; i < library.numBooks; ++i)
    {
        cout << "Title: " << library.books[i].title << "\tAuthor: " << library.books[i].author
             << "\tYear: " << library.books[i].year << "\tAvailability: "
             << (library.books[i].availability ? "Available" : "Not Available") << "\n";
    }
}

// Function to add book
void addBook(Library &library, const Book &book)
{
    if (library.numBooks < MAX_BOOKS)
    {
        library.books[library.numBooks++] = book;
        cout << "Book added successfully.\n";
    }
    else
    {
        cout << "Library is full. Cannot add more books.\n";
    }
}

int main()
{
    Library library;
    library.numBooks = 0;

    while (true)
    {
        cout << "***************************************\n";
        cout << "*                                     *\n";
        cout << "*                                     *\n";
        cout << "*    Library Management System        *\n";
        cout << "*                                     *\n";
        cout << "*                                     *\n";
        cout << "***************************************\n";

        cout << "\n\n";
        cout << "1. Add Book\n";
        cout << "2. Delete Book\n";
        cout << "3. Update Book\n";
        cout << "4. Search Book\n";
        cout << "5. Display Books\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Book book;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, book.title);

            cout << "Enter author: ";
            getline(cin, book.author);

            cout << "Enter year: ";
            cin >> book.year;

            book.availability = true;
            addBook(library, book);
            break;
        }
        case 2:
        {
            string title;
            cout << "Enter the title of the book to delete: ";
            cin.ignore();
            getline(cin, title);
            removeBookByTitle(library, title);
            break;
        }
        case 3:
        {
            string title;
            cout << "Enter the title of the book to update: ";
            cin.ignore();
            getline(cin, title);
            updateBookByTitle(library, title);
            break;
        }
        case 4:
        {
            string title;
            cout << "Enter the title of the book to search: ";
            cin.ignore();
            getline(cin, title);
            searchBook(library, title);
            break;
        }
        case 5:
            displayBooks(library);
            break;
        case 6:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
