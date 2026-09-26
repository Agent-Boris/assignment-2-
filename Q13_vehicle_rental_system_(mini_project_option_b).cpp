
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle{
protected:int id;string model;double rate;bool available;
public:
    Vehicle(int i,string m,double r){id=i;model=m;rate=r;available=true;}
    virtual double rentCost(int days){return rate*days;}
    virtual string type(){return "Vehicle";}
    int getID(){return id;}bool isAvailable(){return available;}
    void setAvailable(bool value){available=value;}
    virtual void display(){cout<<id<<" "<<type()<<" "<<model<<" Daily rate: "<<rate<<endl;}
    virtual ~Vehicle(){}
};
class Car:public Vehicle{
public:Car(int i,string m,double r):Vehicle(i,m,r){}
    string type()override{return "Car";}
    double rentCost(int days)override{return rate*days;}
};
class Bike:public Vehicle{
public:Bike(int i,string m,double r):Vehicle(i,m,r){}
    string type()override{return "Bike";}
    double rentCost(int days)override{return rate*days;}
};
class Customer{
public:int id;string name;
    Customer(int i,string n){id=i;name=n;}
};
class Rental{
public:Customer* customer;Vehicle* vehicle;int days;double cost;
    Rental(Customer* c,Vehicle* v,int d){customer=c;vehicle=v;days=d;cost=v->rentCost(d);}
    void display(){cout<<customer->name<<" rented vehicle "<<vehicle->getID()<<" for "<<days<<" days. Cost: "<<cost<<endl;}
};
class RentalSystem{
    vector<Vehicle*> vehicles;vector<Rental> rentals;
public:
    void addVehicle(Vehicle* v){vehicles.push_back(v);}
    void showAvailable(){for(auto v:vehicles)if(v->isAvailable())v->display();}
    void rent(Customer* c,int id,int days){
        for(auto v:vehicles)if(v->getID()==id&&v->isAvailable()&&days>0){
            rentals.push_back(Rental(c,v,days));v->setAvailable(false);rentals.back().display();return;
        }
        cout<<"Vehicle unavailable or invalid days"<<endl;
    }
    void returnVehicle(int id){
        for(auto v:vehicles)if(v->getID()==id&&!v->isAvailable()){v->setAvailable(true);cout<<"Vehicle returned"<<endl;return;}
        cout<<"Rental not found"<<endl;
    }
    void search(int id){for(auto v:vehicles)if(v->getID()==id)v->display();}
};

int main(){
    RentalSystem system;
    system.addVehicle(new Car(1,"Swift",2000));
    system.addVehicle(new Bike(2,"Honda",500));
    Customer c(101,"Rahul");
    int choice,id,days;
    do{
        cout<<"\\n1 Show Available 2 Search Vehicle 3 Rent Vehicle 4 Return Vehicle 0 Exit\\n";
        cin>>choice;
        if(choice==1)system.showAvailable();
        else if(choice==2){cin>>id;system.search(id);}
        else if(choice==3){cin>>id>>days;system.rent(&c,id,days);}
        else if(choice==4){cin>>id;system.returnVehicle(id);}
    }while(choice!=0);
    return 0;
}