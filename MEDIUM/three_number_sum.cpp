// problem link  : https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/
#include<bits/stdc++.h>
using namespace std;


// time complexity O(n*(n+log(n)))
void threeNumberSum(int arr[],int n,int target){
   sort(arr,arr+n);
   for(int i=0;i<n-2;i++){
       int left=i+1,right=n-1;
       while(left<right){
        int currentSum=arr[i]+arr[left]+arr[right];
          if(currentSum==target){
             cout<<arr[i]<<" , "<<arr[left]<<" , "<<arr[right]<<"\n";
             left++;
             right--;
          }else if( currentSum < target){
            left++;
          }else{
             right--;
          }
       }
   }

}
int main(){

int n,target;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
   cin>>arr[i];
}
cin>>target;
threeNumberSum(arr,n,target);


}
