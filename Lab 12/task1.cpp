#include <bits/stdc++.h>

using namespace std;

class Book
{
    private:
        string title;
        string author;
        string ISBN;
    public:
        Book(string Title, string Author, string iSBN) : title(Title), author(Author), ISBN(iSBN)
        {}
        string get_title()
        {
            return title;
        }
        string get_author()
        {
            return author;
        }
        string get_ISBN()
        {
            return ISBN;
        }
        void display()
        {
            cout << "Title : " << title;
            cout << "\nAuthor : " << author;
            cout << "\nISBN : " << ISBN << "\n";
        }

        bool operator== (Book temp)
        {
            if(temp.get_author() == author && temp.get_title() == title && temp.get_ISBN() == ISBN)
                return true;
            return false;
        }

        bool operator!= (Book temp)
        {
            if(temp.get_author() == author && temp.get_title() == title && temp.get_ISBN() == ISBN)
                return false;
            return true;
        }
};

class Library
{
    private: 
        vector < Book > inventory;
        deque < Book > borrowedBooks;
        list < Book > archievedBooks;
    public:
        Library()
        {}
        void add_book(Book book)
        {
            inventory.push_back(book);
        }
        int borrow_book(Book book)
        {
            auto itr = find(inventory.begin(), inventory.end(), book);
            if(itr == inventory.end())
                return -1;
            inventory.erase(itr);
            borrowedBooks.push_back(book);
            return 0;
        }
        int return_book(Book book)
        {
            auto itr = find(borrowedBooks.begin(), borrowedBooks.end(), book);
            if(itr == borrowedBooks.end())
                return -1;
            borrowedBooks.erase(itr);
            inventory.push_back(book);
            return 0;
        }
        int archieve_book(Book book)
        {
            auto itr = find(inventory.begin(), inventory.end(), book);
            if(itr == inventory.end())
                return -1;
            inventory.erase(itr);
            archievedBooks.push_back(book);
            return 0;
        }
        void display()
        {
            cout << "Inventory : ";
            for(Book book : inventory)
                cout << book.get_title() << " ";
            cout <<"\n";

            cout << "Borrowed books : ";
            for(Book book : borrowedBooks)
                cout << book.get_title() << " ";
            cout <<"\n";

            cout << "Archieved books : ";
            for(Book book : archievedBooks)
                cout << book.get_title() << " ";
            cout <<"\n";
        }

        void add_Book()
        {
            string title, author, ISBN;
            cout << "Enter the title : ";
            cin >> title;
            cout << "Enter the author : ";
            cin >> author;
            cout << "Enter the ISBN : ";
            cin >> ISBN;

            Book book(title, author, ISBN);
            inventory.push_back(book);
        }

        void save_to_file()
        {
            ofstream file1("inventory.txt");
            if(!file1)
            {
                cerr << "Error opening file inventory.txt!\n";
                return;  
            }
            for(Book book : inventory)
            {
                file1 << book.get_title() << "," << book.get_author() << "," << book.get_ISBN() << "\n";
            }
            file1.close();

            ofstream file2("borrowed.txt");
            if(!file2)
            {
                cerr << "Error opening file borrowed.txt!\n";
                return;  
            }
            for(Book book : inventory)
            {
                file2 << book.get_title() << "," << book.get_author() << "," << book.get_ISBN() << "\n";
            }
            file2.close();

            ofstream file3("archieved.txt");
            if(!file3)
            {
                cerr << "Error opening file archieved.txt!\n";
                return;  
            }
            for(Book book : inventory)
            {
                file3 << book.get_title() << "," << book.get_author() << "," << book.get_ISBN() << "\n";
            }
            file3.close();
        }

        void load_to_file()
        {
            string line;
            string title, author, ISBN;

            ifstream file1("inventory.txt");
            if(!file1)
            {
                cerr << "Error opening inventory.txt!\n";
                return;
            }
            while(getline(file1, line))
            {
                stringstream ss;
                getline(ss, title, ',');
                getline(ss, author, ',');
                getline(ss, ISBN, ',');

                Book book(title, author, ISBN);
                inventory.push_back(book);
            }
            file1.close();

            ifstream file2("borrowed.txt");
            if(!file2)
            {
                cerr << "Error opening borrowed.txt!\n";
                return;
            }
            while(getline(file2, line))
            {
                stringstream ss;
                getline(ss, title, ',');
                getline(ss, author, ',');
                getline(ss, ISBN, ',');

                Book book(title, author, ISBN);
                borrowedBooks.push_back(book);
            }
            file2.close();

            ifstream file3("archieved.txt");
            if(!file3)
            {
                cerr << "Error opening archieved.txt!\n";
                return;
            }
            while(getline(file3, line))
            {
                stringstream ss;
                getline(ss, title, ',');
                getline(ss, author, ',');
                getline(ss, ISBN, ',');

                Book book(title, author, ISBN);
                archievedBooks.push_back(book);
            }
            file3.close();
        }
};

int main()
{

    
}