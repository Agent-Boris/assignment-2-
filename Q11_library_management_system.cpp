
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book{
public:
    int id;string title,author,isbn;bool available;
    Book(int i,string t,string a,string is){id=i;title=t;author=a;isbn=is;available=true;}
};
class Member{
public:
    int id;string name;vector<int> borrowed;
    Member(int i,string n){id=i;name=n;}
};
class Library{
    vector<Book> books;vector<Member> members;
public:
    void addBook(int id,string title,string author,string isbn){books.push_back(Book(id,title,author,isbn));cout<<"Book Added Successfully"<<endl;}
    void removeBook(int id){
        for(int i=0;i<(int)books.size();i++)if(books[i].id==id&&books[i].available){books.erase(books.begin()+i);cout<<"Book removed"<<endl;return;}
        cout<<"Book not found or borrowed"<<endl;
    }
    void searchTitle(string title){for(auto &b:books)if(b.title==title)cout<<b.id<<" "<<b.title<<" - "<<b.author<<endl;}
    void searchAuthor(string author){for(auto &b:books)if(b.author==author)cout<<b.id<<" "<<b.title<<endl;}
    void registerMember(int id,string name){members.push_back(Member(id,name));cout<<"Member Registered Successfully"<<endl;}
    void borrowBook(int memberID,int bookID){
        for(auto &m:members)if(m.id==memberID)
            for(auto &b:books)if(b.id==bookID&&b.available){b.available=false;m.borrowed.push_back(bookID);cout<<"Book borrowed successfully by "<<m.name<<endl;return;}
        cout<<"Member/book unavailable"<<endl;
    }
    void returnBook(int memberID,int bookID){
        for(auto &m:members)if(m.id==memberID)for(int i=0;i<(int)m.borrowed.size();i++)if(m.borrowed[i]==bookID){
            m.borrowed.erase(m.borrowed.begin()+i);
            for(auto &b:books)if(b.id==bookID)b.available=true;
            cout<<"Book returned"<<endl;return;
        }
        cout<<"Borrow record not found"<<endl;
    }
    void displayAvailable(){for(auto &b:books)if(b.available)cout<<b.id<<" - "<<b.title<<" by "<<b.author<<endl;}
    void displayBorrowed(int memberID){
        for(auto &m:members)if(m.id==memberID){cout<<"Books borrowed by "<<m.name<<":"<<endl;
            for(int id:m.borrowed)for(auto &b:books)if(b.id==id)cout<<b.id<<" - "<<b.title<<endl<<"Author: "<<b.author<<endl<<"ISBN: "<<b.isbn<<endl;
            return;}
        cout<<"Member not found";
    }
};

int main(){
    Library lib;int choice,id,memberID;string title,author,isbn,name;
    do{
        cout<<"\\n1 Add Book 2 Remove Book 3 Search Title 4 Search Author 5 Register Member 6 Borrow 7 Return 8 Available 9 Borrowed Books 0 Exit\\n";
        cin>>choice;
        if(choice==1){cin>>id;cin.ignore();getline(cin,title);getline(cin,author);getline(cin,isbn);lib.addBook(id,title,author,isbn);}
        else if(choice==2){cin>>id;lib.removeBook(id);}
        else if(choice==3){cin.ignore();getline(cin,title);lib.searchTitle(title);}
        else if(choice==4){cin.ignore();getline(cin,author);lib.searchAuthor(author);}
        else if(choice==5){cin>>id>>name;lib.registerMember(id,name);}
        else if(choice==6){cin>>memberID>>id;lib.borrowBook(memberID,id);}
        else if(choice==7){cin>>memberID>>id;lib.returnBook(memberID,id);}
        else if(choice==8)lib.displayAvailable();
        else if(choice==9){cin>>memberID;lib.displayBorrowed(memberID);}
    }while(choice!=0);
    return 0;
}