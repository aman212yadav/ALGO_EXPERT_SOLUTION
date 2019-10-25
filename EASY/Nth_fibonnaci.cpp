#include<bits/stdc++.h>
using namespace std;
/*    recursive
 int nth_fibonnaci(int n){
     if(n==0||n==1)
         return n;
     return nth_fibonnaci(n-1)+nth_fibonnaci(n-2);
 }
*/
// iterative
int nth_fibonnaci(int n){
     int a=0,b=1,c;
     for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
     }
     return b;
}
int main(){
  int n;
  cin>>n;
  cout<<nth_fibonnaci(n);


}
