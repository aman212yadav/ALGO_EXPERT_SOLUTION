#include<bits/stdc++.h>
using namespace std;
// problem link    - https://www.geeksforgeeks.org/smallest-difference-pair-values-two-unsorted-arrays/
// time complexity - O(nlog(n)+mlog(m))
void smallestDifference(int A[],int n,int B[],int m){
   int smallest=INT_MAX;
   sort(A,A+n);
   sort(B,B+m);
   int a=0,b=0;
   while(a < n and b < m){
     int current=abs(A[a]-B[b]);
     if(current < smallest)
        smallest=current;
      if(A[a]<B[b])
         a++;
      else if(A[a]>B[b]){
         b++;
      }else{
         break;
      }
   }
   cout<<smallest<<"\n";

}
int main(){
int n,m;
cin>>n;
int A[n];
for(int i=0;i<n;i++)
  cin>>A[i];
cin>>m;
int B[m];
for(int i=0;i<m;i++)
   cin>>B[i];

smallestDifference(A,n,B,m);




}
