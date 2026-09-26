
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class PaymentMethod {
public:
    virtual void pay(double amount)=0;
    virtual void refund(double amount)=0;
    virtual string getName()=0;
    virtual ~PaymentMethod(){}
};
class CreditCardPayment:public PaymentMethod{
public:
    void pay(double amount) override{cout<<"Credit card payment successful: "<<amount<<endl;}
    void refund(double amount) override{cout<<"Credit card refund processed: "<<amount<<endl;}
    string getName() override{return "Credit Card";}
};
class UPIPayment:public PaymentMethod{
    string upi;
public:
    UPIPayment(string id){upi=id;}
    void pay(double amount) override{cout<<"UPI ID: "<<upi<<endl<<"UPI payment successful: "<<amount<<endl;}
    void refund(double amount) override{cout<<"UPI refund processed: "<<amount<<endl;}
    string getName() override{return "UPI";}
};
class WalletPayment:public PaymentMethod{
public:
    void pay(double amount) override{cout<<"Wallet payment successful: "<<amount<<endl;}
    void refund(double amount) override{cout<<"Wallet refund processed: "<<amount<<endl;}
    string getName() override{return "Wallet";}
};
class PaymentProcessor{
public:
    void process(PaymentMethod* method,double amount,string operation){
        cout<<"Method: "<<method->getName()<<endl;
        if(operation=="PAY")method->pay(amount);
        else if(operation=="REFUND")method->refund(amount);
        else cout<<"Invalid operation"<<endl;
    }
};

int main(){
    string method,operation,upi;double amount;
    cout<<"Payment method (UPI/CARD/WALLET): ";cin>>method;
    cout<<"Amount: ";cin>>amount;
    cout<<"Operation (PAY/REFUND): ";cin>>operation;
    PaymentMethod* p;
    if(method=="UPI"){cout<<"UPI ID: ";cin>>upi;p=new UPIPayment(upi);}
    else if(method=="CARD")p=new CreditCardPayment();
    else if(method=="WALLET")p=new WalletPayment();
    else{cout<<"Invalid method";return 0;}
    PaymentProcessor processor;processor.process(p,amount,operation);
    delete p;return 0;
}