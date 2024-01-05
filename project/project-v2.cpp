#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_BOOKS = 100;

struct Book
{
    string title;
    string author;
    int year;
};

struct User
{
    string username;
    string password;
    vector<Book> books;
};

struct Library
{
    vector<User> users;
};

User *findUserByUsername(Library &library, const string &username)
{
    auto it = find_if(library.users.begin(), library.users.end(), [&username](const User &user)
                      { return user.username == username; });

    return (it != library.users.end()) ? &(*it) : nullptr;
}

void registerUser(Library &library, const string &username, const string &password)
{
    if (findUserByUsername(library, username) == nullptr)
    {
        library.users.push_back({username, password});
        cout << "User registered successfully.\n";
    }
    else
    {
        cout << "Username already exists. Please choose another.\n";
    }
}

User *authenticateUser(Library &library, const string &username, const string &password)
{
    User *user = findUserByUsername(library, username);
    if (user != nullptr && user->password == password)
    {
        return user;
    }
    return nullptr;
}

void addBook(User &user, const Book &book)
{
    if (user.books.size() < MAX_BOOKS)
    {
        user.books.push_back(book);
        cout << "Book added successfully.\n";
    }
    else
    {
        cout << "User library is full. Cannot add more books.\n";
    }
}

void deleteBook(User &user, const string &title)
{
    auto it = remove_if(user.books.begin(), user.books.end(), [&title](const Book &book)
                        { return book.title == title; });

    if (it != user.books.end())
    {
        user.books.erase(it, user.books.end());
        cout << "Book deleted successfully.\n";
    }
    else
    {
        cout << "Book not found.\n";
    }
}

void searchBook(const User &user, const string &title)
{
    auto it = find_if(user.books.begin(), user.books.end(), [&title](const Book &book)
                      { return book.title == title; });

    if (it != user.books.end())
    {
        cout << "Book found:\n";
        cout << "Title: " << it->title << "\tAuthor: " << it->author << "\tYear: " << it->year << "\n";
    }
    else
    {
        cout << "Book not found.\n";
    }
}

void displayBooks(const User &user)
{
    if (user.books.empty())
    {
        cout << "No books in the user library.\n";
        return;
    }

    cout << "User Library Books:\n";
    for (const auto &book : user.books)
    {
        cout << "Title: " << book.title << "\tAuthor: " << book.author << "\tYear: " << book.year << "\n";
    }
}

int main()
{
    Library library;

    while (true)
    {
        cout << "\nLibrary Management System\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        int mainChoice;
        cin >> mainChoice;

        if (mainChoice == 1)
        {
            string username, password;
            cout << "Enter a username: ";
            cin >> username;

            cout << "Enter a password: ";
            cin >> password;

            registerUser(library, username, password);
        }
        else if (mainChoice == 2)
        {
            string username, password;
            cout << "Enter your username: ";
            cin >> username;

            cout << "Enter your password: ";
            cin >> password;

            User *currentUser = authenticateUser(library, username, password);

            if (currentUser != nullptr)
            {
                cout << "Login successful!\n";

                while (true)
                {
                    cout << "\nUser Library Management\n";
                    cout << "1. Add Book\n";
                    cout << "2. Delete Book\n";
                    cout << "3. Search Book\n";
                    cout << "4. Display Books\n";
                    cout << "5. Logout\n";
                    cout << "Enter your choice: ";

                    int userChoice;
                    cin >> userChoice;

                    switch (userChoice)
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

                        addBook(*currentUser, book);
                        break;
                    }
                    case 2:
                    {
                        string title;
                        cout << "Enter the title of the book to delete: ";
                        cin.ignore();
                        getline(cin, title);
                        deleteBook(*currentUser, title);
                        break;
                    }
                    case 3:
                    {
                        string title;
                        cout << "Enter the title of the book to search: ";
                        cin.ignore();
                        getline(cin, title);
                        searchBook(*currentUser, title);
                        break;
                    }
                    case 4:
                        displayBooks(*currentUser);
                        break;
                    case 5:
                        cout << "Logging out.\n";
                        currentUser = nullptr;
                        break;
                    default:
                        cout << "Invalid choice. Try again.\n";
                    }

                    if (currentUser == nullptr)
                    {
                        break; // Break from the inner loop when the user logs out
                    }
                }
            }
            else
            {
                cout << "Login failed. Please try again.\n";
            }
        }
        else if (mainChoice == 3)
        {
            cout << "Exiting the program.\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
