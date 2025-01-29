#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>
using namespace std;
int bookCount = 0;
class Book
{
    public:
    string title;
    string author;
    long long ISBN;
    bool isCheckedOut = false;
    map<std::string, Book> books;
    Book(const string& bookTitle, const string& bookAuthor, long long bookISBN)
        : title(bookTitle), author(bookAuthor), ISBN(bookISBN) {}
    void checkout()
    {
        if(isCheckedOut)
        {
            cout << "The book is checked out\n";
        }
        else
        {
            this -> isCheckedOut = true;
            cout << "Thank you for checking out\n";
        }
    }
    void returnBook(Book &book)
    {
        if(isCheckedOut != true)
        {
            cout << "ERROR: Book not checked out\n";
        }
        else
        {
            cout << "Thank you for returing\n";
            isCheckedOut = false;
        }
        
    }
};
class Member
{
    public:
    string name;
    int memberID;
    vector<Book> checkedOutBooks;
    Member(const string& name, long long memberID)
        : name(name), memberID(memberID) {}
    void checkOutBook(Book book)
    {
        if(book.isCheckedOut == true)
        {
            cout << "sorry the book is already checked out";
        }
        else
        {
            checkedOutBooks.push_back(book);
            book.checkout(book);
        }
        
    }
    void returnBook(Book book)
    {
        cout << "thank you for returning: " << book.title << endl;
        for(int i = 0; i < checkedOutBooks.size(); i++)
        {
            if(checkedOutBooks[i].title == book.title)
            {
                checkedOutBooks.erase(checkedOutBooks.begin() + i);
                book.returnBook(book);
                i--;
            }
        }
    }
    void displayBooks(Member member)
    {
        for(int i = 0; i < checkedOutBooks.size(); i++)
        {
            cout << checkedOutBooks[i].title << endl;
        }
    }
};
class Library
{
    public:
    vector<Book> Books;
    vector<Member> Members;
    
    void addBook(Book book)
    {
        cout << "Adding: " << book.title << endl;
        Books.push_back(book);
    }
    void removeBook(Book book)
    {
        cout << "Removing: " << book.title << endl;
        for(int i = 0; i < Books.size(); i++)
        {
            if(Books[i].title == book.title)
            {
                Books.erase(Books.begin() + i);
                i--;
            }
        }
    }
    void registerMember(Member member)
    {
        cout << "Registering: " << member.name << endl;
        Members.push_back(member);
    }
    void unregisterMember(Member member)
    {
        cout << "Removing: " << member.name << endl;
        for(int i = 0; i < Members.size(); i++)
        {
            if(Members[i].name == member.name)
            {
                Members.erase(Members.begin() + i);
                i--;
            }
        }
    }
    void displayBooks()
    {
        for(int i = 0; i < Books.size(); i++)
        {
            cout << Books[i].title << endl;
        }
    }
    void displayMembers()
    {
        for(int i = 0; i < Members.size(); i++)
        {
            cout << Members[i].name << endl;
        }
    }
};

