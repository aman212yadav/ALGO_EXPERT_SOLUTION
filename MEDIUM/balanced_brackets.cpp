// problem link - https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/

#include<bits/stdc++.h>
using namespace std;

//time complexity - O(n)
//space complexity -O(n)
bool balancedBrackets(string brackets){
      stack< char > stk;
      for(auto k : brackets){
          if(k=='(' || k=='[' || k=='{' ){
            stk.push(k);
          }else if(stk.empty()){
           return false;
          }
          else if(k==')' && stk.top()!='(') {
            return false;
          }
          else if( k=='}' && stk.top()!='{' ) {
           return false;
          }
          else if( k==']' && stk.top()!='['){
           return false;
          }else{
            stk.pop();
          }
      }
        return stk.empty();
}
int main(){
string s;
cin>>s;
cout<<balancedBrackets(s)<<"\n";
}



