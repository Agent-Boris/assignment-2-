
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Product{
public:
    int id,stock;string name;double price;
    Product(int i,string n,double p,int s){id=i;name=n;price=p;stock=s;}
};
class Cart{
public:
    vector<Product*> products;vector<int> quantities;
    void add(Product* p,int q){
        if(q<=0||q>p->stock){cout<<"Invalid quantity or insufficient stock"<<endl;return;}
        for(int i=0;i<(int)products.size();i++)if(products[i]->id==p->id){quantities[i]+=q;return;}
        products.push_back(p);quantities.push_back(q);
    }
    void remove(int id){
        for(int i=0;i<(int)products.size();i++)if(products[i]->id==id){products.erase(products.begin()+i);quantities.erase(quantities.begin()+i);return;}
    }
    void update(int id,int q){for(int i=0;i<(int)products.size();i++)if(products[i]->id==id&&q>0&&q<=products[i]->stock)quantities[i]=q;}
    double subtotal(){double sum=0;for(int i=0;i<(int)products.size();i++)sum+=products[i]->price*quantities[i];return sum;}
    void view(){for(int i=0;i<(int)products.size();i++)cout<<products[i]->name<<" x"<<quantities[i]<<" "<<products[i]->price*quantities[i]<<endl;}
};
class Customer{
public:int id;string name;Cart cart;
    Customer(int i,string n){id=i;name=n;}
};
class PaymentMethod{
public:virtual bool pay(double amount)=0;virtual string name()=0;virtual ~PaymentMethod(){}
};
class CardPayment:public PaymentMethod{
public:bool pay(double amount)override{cout<<"Card payment successful"<<endl;return true;}string name()override{return "Card";}
};
class UPIPayment:public PaymentMethod{
    string upi;
public:UPIPayment(string u){upi=u;}bool pay(double amount)override{cout<<"UPI payment successful for "<<upi<<endl;return true;}string name()override{return "UPI";}
};
class Order{
    static int nextID;
public:
    int id;Customer* customer;double total;string status;
    Order(Customer* c,double amount){id=nextID++;customer=c;total=amount;status="CONFIRMED";}
    void display(PaymentMethod* p){
        cout<<"===== ORDER SUMMARY ====="<<endl<<"Order ID: "<<id<<endl<<"Customer: "<<customer->name<<endl<<"Products:"<<endl;
        customer->cart.view();cout<<"Subtotal: "<<total<<endl<<"Total: "<<total<<endl;
        cout<<"Payment Method: "<<p->name()<<endl<<"Payment Status: SUCCESS"<<endl<<"Order Status: "<<status<<endl;
    }
};
int Order::nextID=1001;

int main(){
    Product p1(101,"Laptop",60000,5),p2(102,"Mouse",1500,10);
    Customer c(501,"Rahul");
    c.cart.add(&p1,1);c.cart.add(&p2,2);
    cout<<fixed<<setprecision(2);
    string type,upi;cout<<"Payment type (UPI/CARD): ";cin>>type;
    PaymentMethod* payment;
    if(type=="UPI"){cout<<"UPI ID: ";cin>>upi;payment=new UPIPayment(upi);}
    else payment=new CardPayment();
    double total=c.cart.subtotal();
    if(payment->pay(total)){
        Order order(&c,total);order.display(payment);
        for(int i=0;i<(int)c.cart.products.size();i++)c.cart.products[i]->stock-=c.cart.quantities[i];
    }
    delete payment;return 0;
}