
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
private:
    int id, marks[5]; string name;
public:
    Student(){id=0;name="";for(int i=0;i<5;i++)marks[i]=0;}
    void input(){cin>>id>>name;for(int i=0;i<5;i++)cin>>marks[i];}
    int getID(){return id;}
    int total(){int sum=0;for(int i=0;i<5;i++)sum+=marks[i];return sum;}
    double average(){return total()/5.0;}
    int highest(){int mx=marks[0];for(int i=1;i<5;i++)if(marks[i]>mx)mx=marks[i];return mx;}
    int lowest(){int mn=marks[0];for(int i=1;i<5;i++)if(marks[i]<mn)mn=marks[i];return mn;}
    char grade(){double p=average();if(p>=90)return 'A';if(p>=80)return 'B';if(p>=70)return 'C';if(p>=60)return 'D';return 'F';}
    void display(){
        cout<<"ID: "<<id<<endl<<"Name: "<<name<<endl<<"Marks: ";
        for(int i=0;i<5;i++)cout<<marks[i]<<" ";
        cout<<endl<<"Total: "<<total()<<endl<<"Average: "<<average()<<endl;
        cout<<"Percentage: "<<average()<<"%"<<endl<<"Grade: "<<grade()<<endl;
    }
};

int main(){
    int n;cout<<"Number of students: ";cin>>n;
    if(n<=0||n>100){cout<<"Invalid number";return 0;}
    Student s[100];
    for(int i=0;i<n;i++)s[i].input();
    int searchID;cout<<"Search ID: ";cin>>searchID;
    bool found=false;
    for(int i=0;i<n;i++)if(s[i].getID()==searchID){cout<<"Student Found"<<endl;s[i].display();found=true;}
    if(!found)cout<<"Student not found"<<endl;
    int top=0;for(int i=1;i<n;i++)if(s[i].average()>s[top].average())top=i;
    cout<<"Student with highest average:"<<endl;s[top].display();
    double limit;cout<<"Enter percentage limit: ";cin>>limit;
    for(int i=0;i<n;i++)if(s[i].average()>limit)s[i].display();
    return 0;
}