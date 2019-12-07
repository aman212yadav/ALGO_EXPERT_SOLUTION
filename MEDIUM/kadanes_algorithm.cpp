//  problem link - https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

#include<bits/stdc++.h>
using namespace std;



// time complexity  - O(n)
// space complexity - O(1)
int kadanesAlgorithm(int arr[],int n){
   int max_sum_so_far=INT_MIN,max_ending_here=0;

   for(int i=0;i<n;i++){
       max_ending_here+=arr[i];
       if(max_ending_here > max_sum_so_far){
           max_sum_so_far=max_ending_here;
       }
       if(max_ending_here < 0){
           max_ending_here=0;
       }
   }
   return max_sum_so_far;


}

int main(){

int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
   cin>>arr[i];

cout<<kadanesAlgorithm(arr,n)<<"\n";



}
