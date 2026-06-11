#include<iostream>
#include<memory>
#include<vector>

using namespace std;

class Employee
{
    string m_name;
    //string role;
    public:
    Employee(string n): m_name(n) {}
   virtual double get_salary()= 0;
   virtual string get_role() = 0;
   virtual void display()
   {
     cout << "Name: " << m_name <<" " << "Role: "<<get_role() << " "<<"Salary: "<< get_salary() << endl; 
   }
};

class Fulltime_employee : public Employee
{
    double salary;
    string role;
    public:
    Fulltime_employee(string n,double s):Employee(n),salary(s),role("Fulltime") {}
    double get_salary()override {return salary;}
    string get_role() override {return role;}
};

class Parttime_employee : public Employee
{
    int hours_worked;
    double hours_salary;
    string role;
    public:
    Parttime_employee(string n,int w,double s) : Employee(n),hours_worked(w),hours_salary(s),role("Parttime"){}
   double get_salary() override {return (hours_salary * hours_worked);}
    string get_role() override{return role;}

};

class Intern : public Employee
{
    double stipend;
    string role;

    public:
    Intern(string n,double s ) : Employee(n),stipend(s) {}
    double get_salary() override{ return stipend;}
    string get_role() override{return role;}

};

int main()
{
    vector<std::unique_ptr<Employee>> staff;
    staff.push_back(std::make_unique<Fulltime_employee>("surjith",32000.0));
    staff.push_back(std::make_unique<Parttime_employee>("reshma",24,1500.0));
    staff.push_back(std::make_unique<Intern>("devi",1500.0));
    staff.push_back(std::make_unique<Parttime_employee>("akhil",48,150.0));
    for( auto& c : staff)
    {
        c->display();
    }
}