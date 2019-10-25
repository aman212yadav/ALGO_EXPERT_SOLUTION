// https://www.geeksforgeeks.org/c-program-check-given-string-palindrome/
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int i=0,j=s.size()-1;
    while(i<j && s[i]==s[j]){
       i++;
       j--;
    }
    if(i>=j)
     return true;
     return false;
}
int main(){
string s;
cin>>s;
bool ans=isPalindrome(s);
cout<<ans<<endl;

}
