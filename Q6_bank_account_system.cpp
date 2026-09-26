
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string name;
    double balance;
    static int count;
public:
    BankAccount(int acc,string holder,double amount) {
        accountNumber=acc; name=holder; balance=amount; count++;
    }
    void deposit(double amount) {
        if(amount>0){balance+=amount;cout<<"New Balance: "<<balance<<endl;}
        else cout<<"Invalid deposit"<<endl;
    }
    void withdraw(double amount) {
        if(amount<=0) cout<<"Invalid amount"<<endl;
        else if(amount>balance) cout<<"Insufficient balance"<<endl;
        else {balance-=amount;cout<<"New Balance: "<<balance<<endl;}
    }
    double checkBalance(){return balance;}
    void display() {
        cout<<"Account Number: "<<accountNumber<<endl<<"Account Holder: "<<name<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
    static int getCount(){return count;}
};
int BankAccount::count=0;

int main() {
    int acc; string name; double initial,dep,with;
    cout<<"Enter account number, name and initial balance: ";
    cin>>acc>>name>>initial;
    if(initial<0){cout<<"Invalid balance";return 0;}
    BankAccount b(acc,name,initial);
    cout<<fixed<<setprecision(2)<<"Account Created Successfully"<<endl;
    b.display();
    cout<<"Deposit amount: ";cin>>dep;b.deposit(dep);
    cout<<"Withdrawal amount: ";cin>>with;b.withdraw(with);
    cout<<"Total Accounts: "<<BankAccount::getCount();
    return 0;
}