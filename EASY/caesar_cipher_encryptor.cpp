// https://www.geeksforgeeks.org/caesar-cipher-in-cryptography/
#include<bits/stdc++.h>
using namespace std;
void decrypt(string &s,int key){
   key=key%26;
   for(int i=0;i<s.size();i++)
    {
      s[i]='A'+(s[i]-'A'+key)%26;
    }

}
int main(){
string s;
int key;
cin>>s>>key;
decrypt(s,key);
cout<<s<<endl;

}
