#include<iostream>
#include<vector>

using namespace std;

class LibraryItem
{
    protected:
    int id;
    string title;

    public:
   LibraryItem(int i,string t) : id(i), title(t) {}
   virtual void display() const = 0;
   int get_id() const {return id;}
};

class Book : public LibraryItem
{
    string author;
    public:
    Book(int i,string t,string a) : LibraryItem(i,t), author(a) {}
    void display() const override {cout << "Title:" << title << " ID:" << get_id() << " author: " << author<<endl;  }

};

class Library
{
    vector<LibraryItem*> item;
    public:
    void addItem(LibraryItem* it) {item.push_back(it);}
    void display() const{
        for(const auto& i : item)
        {
            i->display();
        }
    }
    ~Library()
    {
        for(auto i : item)
        {
            delete i;
        }
    }

};

int main()
{
    Library l;
    l.addItem(new Book(1,"cpp","roopesh"));
    l.addItem(new Book(2,"network","arun"));
    l.addItem(new Book(3,"dsa","surjith"));
    cout << endl << "All Items: " << endl;
    l.display();
}