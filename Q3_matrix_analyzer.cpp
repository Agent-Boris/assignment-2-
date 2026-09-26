
#include <iostream>
using namespace std;

int totalSum(int a[][50], int n) {
    int sum=0; for(int i=0;i<n;i++) for(int j=0;j<n;j++) sum+=a[i][j]; return sum;
}
void rowSums(int a[][50], int n) {
    for(int i=0;i<n;i++){ int sum=0; for(int j=0;j<n;j++) sum+=a[i][j]; cout<<"Row "<<i+1<<": "<<sum<<endl; }
}
void columnSums(int a[][50], int n) {
    for(int j=0;j<n;j++){ int sum=0; for(int i=0;i<n;i++) sum+=a[i][j]; cout<<"Column "<<j+1<<": "<<sum<<endl; }
}
int mainDiagonal(int a[][50], int n) {
    int sum=0; for(int i=0;i<n;i++) sum+=a[i][i]; return sum;
}
int secondaryDiagonal(int a[][50], int n) {
    int sum=0; for(int i=0;i<n;i++) sum+=a[i][n-1-i]; return sum;
}
bool isSymmetric(int a[][50], int n) {
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(a[i][j]!=a[j][i]) return false;
    return true;
}

int main() {
    int n,a[50][50];
    cout<<"Enter matrix size: "; cin>>n;
    if(n<=0||n>50){cout<<"Invalid size";return 0;}
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
    int mx=a[0][0],mn=a[0][0];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){if(a[i][j]>mx)mx=a[i][j];if(a[i][j]<mn)mn=a[i][j];}
    cout<<"Total Sum: "<<totalSum(a,n)<<endl<<"Row Sums:"<<endl; rowSums(a,n);
    cout<<"Column Sums:"<<endl; columnSums(a,n);
    cout<<"Main Diagonal Sum: "<<mainDiagonal(a,n)<<endl;
    cout<<"Secondary Diagonal Sum: "<<secondaryDiagonal(a,n)<<endl;
    cout<<"Maximum: "<<mx<<endl<<"Minimum: "<<mn<<endl;
    cout<<"Symmetric Matrix: "<<(isSymmetric(a,n)?"Yes":"No");
    return 0;
}