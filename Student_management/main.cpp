#include<iostream>
#include<vector>

using namespace std;

class student
{
    string m_name;
    int m_id;
    float m_grade;

    public:
    student(string n,int i,float g) : m_name(n),m_id(i),m_grade(g) {};
    int getid() { return m_id;}
    string getname(){return m_name;}
    float getgrade(){return m_grade;}
    void display(){cout <<"name: "<<m_name <<" ID: "<<m_id<<" Grade: "<< m_grade<<endl;}

};

class studentManger
{
    vector<student> stu;
    public:
    void addstudent(string n,int i,float g){stu.emplace_back(n,i,g);}
    void showall(){
        for(auto& s : stu)
        {
            s.display();
        }
    }
    void searchById(int i)
    {
        for(auto& s : stu)
        {
            if(s.getid() == i)
            {
                s.display();
                return ;
            }
        }
       cout << "Not found requested id" << endl;
    }
};

int main()
{
    studentManger sm;
    sm.addstudent("surjith",1,23.5);
    sm.addstudent("ammu",2,50.5);
    sm.addstudent("papa",3,80.0);

    cout << "All Students"<<endl;
    sm.showall();

    cout << "search by id" <<endl;
    sm.searchById(2);
    sm.searchById(3);
    return 0;
}