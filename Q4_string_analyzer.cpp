
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s; getline(cin,s);
    int vowels=0, consonants=0, digits=0, spaces=0, special=0, words=0;
    int freq[256]={0}; bool inWord=false;
    for(int i=0;i<(int)s.length();i++){
        unsigned char c=s[i]; char lower=tolower(c);
        if(isalpha(c)){
            if(lower=='a'||lower=='e'||lower=='i'||lower=='o'||lower=='u') vowels++;
            else consonants++;
        } else if(isdigit(c)) digits++;
        else if(c==' ') spaces++;
        else special++;
        if(!isspace(c)&&!inWord){words++;inWord=true;}
        if(isspace(c)) inWord=false;
        freq[lower]++;
    }
    string cleaned="";
    for(int i=0;i<(int)s.length();i++) if(isalnum((unsigned char)s[i])) cleaned+=tolower((unsigned char)s[i]);
    bool palindrome=true;
    int left=0,right=(int)cleaned.length()-1;
    while(left<right){if(cleaned[left]!=cleaned[right]){palindrome=false;break;}left++;right--;}
    int best=0; char most=' ';
    for(int i=0;i<256;i++) if(freq[i]>best){best=freq[i];most=(char)i;}
    cout<<"Vowels: "<<vowels<<endl<<"Consonants: "<<consonants<<endl;
    cout<<"Digits: "<<digits<<endl<<"Spaces: "<<spaces<<endl;
    cout<<"Special Characters: "<<special<<endl<<"Words: "<<words<<endl;
    cout<<"Palindrome: "<<(palindrome?"Yes":"No")<<endl;
    cout<<"Most Frequent Character: "<<most<<endl<<"Frequency: "<<best;
    return 0;
}