
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double calculateArea()=0;
    virtual double calculatePerimeter()=0;
    virtual string getName()=0;
    virtual ~Shape(){}
};
class Circle:public Shape{
    double r;
public:
    Circle(double radius){r=radius;}
    double calculateArea() override{return 3.14159*r*r;}
    double calculatePerimeter() override{return 2*3.14159*r;}
    string getName() override{return "Circle";}
};
class Rectangle:public Shape{
    double l,w;
public:
    Rectangle(double a,double b){l=a;w=b;}
    double calculateArea() override{return l*w;}
    double calculatePerimeter() override{return 2*(l+w);}
    string getName() override{return "Rectangle";}
};
class Triangle:public Shape{
    double a,b,c;
public:
    Triangle(double x,double y,double z){a=x;b=y;c=z;}
    double calculateArea() override{double s=(a+b+c)/2;return sqrt(s*(s-a)*(s-b)*(s-c));}
    double calculatePerimeter() override{return a+b+c;}
    string getName() override{return "Triangle";}
};

int main(){
    Shape* s[3];
    s[0]=new Circle(5);s[1]=new Rectangle(10,4);s[2]=new Triangle(3,4,5);
    cout<<fixed<<setprecision(2);
    for(int i=0;i<3;i++){
        cout<<"Shape "<<i+1<<": "<<s[i]->getName()<<endl;
        cout<<"Area: "<<s[i]->calculateArea()<<endl;
        cout<<"Perimeter: "<<s[i]->calculatePerimeter()<<endl;
        delete s[i];
    }
    return 0;
}