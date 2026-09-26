
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee {
protected:
    int id; string name; double basic;
public:
    Employee(int i,string n,double b){id=i;name=n;basic=b;}
    virtual double calculateSalary(){return basic;}
    virtual string type(){return "Employee";}
    virtual void display(){
        cout<<"ID: "<<id<<endl<<"Name: "<<name<<endl<<"Type: "<<type()<<endl;
        cout<<"Salary: "<<calculateSalary()<<" Rs"<<endl;
    }
    virtual ~Employee(){}
};
class Developer:public Employee{
public:
    Developer(int i,string n,double b):Employee(i,n,b){}
    double calculateSalary() override{return basic+10000;}
    string type() override{return "Developer";}
};
class Manager:public Employee{
public:
    Manager(int i,string n,double b):Employee(i,n,b){}
    double calculateSalary() override{return basic+10000+5000;}
    string type() override{return "Manager";}
};
class Intern:public Employee{
public:
    Intern(int i,string n,double b):Employee(i,n,b){}
    double calculateSalary() override{return basic;}
    string type() override{return "Intern";}
};

int main(){
    Employee* e[3];
    e[0]=new Developer(101,"Rahul",50000);
    e[1]=new Manager(102,"Ananya",70000);
    e[2]=new Intern(103,"Arjun",20000);
    cout<<fixed<<setprecision(2)<<"Employee Payroll"<<endl;
    for(int i=0;i<3;i++){e[i]->display();delete e[i];}
    return 0;
}