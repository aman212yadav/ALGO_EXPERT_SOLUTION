// problem link - https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/

#include<bits/stdc++.h>
using namespace std;

// time  complexity - O(n)
// space complexity - O(1)
int longest_palindromic_substring(string s){
       int max_len=1,len=s.size();
       for(int k=1;k<len;k++){
           int i=k-1,j=k+1;

           while(i>=0 && j <len && s[i]==s[j] ){
               i--;
               j++;
           }
           len=max(len,j-i-1);
           i=k-1;j=k;
           while(i>=0 && j < len && s[i]==s[j]){
              i--;
              j++;
           }
           len=max(len,j-i-1);
       }
       return len;
}
int main(){
string s;
cin>>s;
cout<<longest_palindromic_substring(s)<<"\n";

}
