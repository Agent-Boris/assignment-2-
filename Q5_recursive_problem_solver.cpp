
#include <iostream>
#include <string>
using namespace std;

int arraySum(int a[], int n) {
    if(n==0) return 0;
    return a[n-1]+arraySum(a,n-1);
}
int arrayMax(int a[], int n) {
    if(n==1) return a[0];
    int mx=arrayMax(a,n-1);
    return (a[n-1]>mx)?a[n-1]:mx;
}
string reverseString(string s, int index) {
    if(index==(int)s.length()) return "";
    return reverseString(s,index+1)+s[index];
}
bool palindrome(string s, int left, int right) {
    if(left>=right) return true;
    if(s[left]!=s[right]) return false;
    return palindrome(s,left+1,right-1);
}
long long power(int x,int n) {
    if(n==0) return 1;
    return x*power(x,n-1);
}

int main() {
    int n,a[100]; cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    string s; cin>>s;
    int x,p; cin>>x>>p;
    cout<<"Array Sum: "<<arraySum(a,n)<<endl;
    cout<<"Array Maximum: "<<arrayMax(a,n)<<endl;
    cout<<"Reversed String: "<<reverseString(s,0)<<endl;
    cout<<"Palindrome: "<<(palindrome(s,0,(int)s.length()-1)?"Yes":"No")<<endl;
    cout<<x<<"^"<<p<<": "<<power(x,p);
    return 0;
}