#include <iostream>
#include <vector>
using namespace std;

//BOOK
class Book{
private:
    int bookID;
    string bookTitle;
    string bookAuthor;
    bool isIssued;

public:
    Book(int b, string t, string a){
        bookID = b;
        bookTitle = t;
        bookAuthor = a;
    }

    Book():Book(0, "Unknown", "Unknown"){};

    void displayBook(){
        cout<<"BOOK DETAILS --> \n";
        cout<<"Book ID: "<<bookID<<"\n";
        cout<<"Book Title: "<<bookTitle<<"\n";
        cout<<"Book Author: "<<bookAuthor<<"\n";
    }

    void issueBook(){
        if(!isIssued){
            isIssued = true;
            cout<<"Book Issued Successfully! \n";
        }
        else {
            cout<<"Book Not Issued! \n";
        }
    }

    void returnBook(){
        if(isIssued){
            isIssued = false;
            cout<<"Book Returned Successfully! \n";
        }
        else {
            cout<<"Book Not Returned! \n";
        }
    }
};

//MEMBER
class Member{
private:
    int memberID;
    string memberName;
    vector <int> issuedBooks;

public:
    Member(int m, string n){
        memberID = m;
        memberName = n;
    }

    Member():Member(0, "Guest"){}

    void displayMember(){
        cout<<"MEMBER DETAILS --> \n";
        cout<<"Member ID: "<<memberID<<"\n";
        cout<<"Member Name: "<<memberName<<"\n";
    }

    void issueBook(int bookID){
           issuedBooks.push_back(bookID);
           cout<<"Book Issued! \n";
    }

    void returnBook(int bookID){
        for (int i = 0; i < issuedBooks.size(); i++)
            if (issuedBooks[i] == bookID) {
            issuedBooks.erase(issuedBooks.begin() + i);
            cout<<"Book Returned (Removed from issued list)! \n";
            return;
       }

       else {
            cout<< "This Book was not issued to the member! \n";
       }
    }
};

//LIBRARY
class Library{
private:
    vector <Book> books;
    vector <Member> members;

public:
    void addBook(const Book& book){
        books.push_back(book);
        cout<<"Book Added Successfully! \n";
    }

    void addMember(const Member& member){
        members.push_back(member);
        cout<<"Member Added Successfully! \n";
    }

    void displayAllBooks(){
        for(int i=0; i<books.size(); i++){
            books[i].displayBook();
            cout<<"\n";
        }
    }

    void displayAllMembers(){
        for(int i=0; i<members.size(); i++){
            members[i].displayMember();
            cout<<"\n";
        }
    }
};

//MAIN
int main() {
    Library lib;

    // Create Books
    Book b1(101, "C++ Programming", "Bjarne Stroustrup");
    Book b2(102, "Data Structures", "Mark Allen Weiss");

    // Create Members
    Member m1(1, "Bhumik");
    Member m2(2, "Meet");

    // Add Books And Members To Library
    lib.addBook(b1);
    lib.addBook(b2);
    lib.addMember(m1);
    lib.addMember(m2);

    // Display All Books And Members
    cout << "\n--- Library Books ---\n";
    lib.displayAllBooks();

    cout << "\n--- Library Members ---\n";
    lib.displayAllMembers();

    return 0;
}



