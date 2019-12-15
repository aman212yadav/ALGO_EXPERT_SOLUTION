// problem link - https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/

#include<bits/stdc++.h>
using namespace std;

// time complexity  - O(n^2)
// space complexity - O(n)

int maximumSumIncreasingSubsequence(int arr[],int n){
   int msis[n];
   for(int i=0;i<n;i++){
      msis[i]=arr[i];
      for(int j=i-1;j>=0;j--){
         if( arr[i]>arr[j] && arr[i]+msis[j]> msis[i]){
            msis[i]=arr[i]+msis[j];
         }
      }
   }
   int idx=0;
   for(int i=0;i<n;i++)
         if(msis[i]>msis[idx])
            idx=i;

   return msis[idx];
}
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
   cin>>arr[i];
cout<<maximumSumIncreasingSubsequence(arr,n)<<"\n";


}
