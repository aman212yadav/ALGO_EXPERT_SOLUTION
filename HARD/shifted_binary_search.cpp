// problem link - https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

#include<bits/stdc++.h>
using namespace std;

// time complexity  - O(log(n))
// space complexity - O(1)
int shiftedBinarySearch(int arr[],int target ,int n){

       int mid,left=0,right=n-1;
       while(left <= right){
         int mid=(left+right)/2;
         if(arr[mid]==target){
           return mid;
         }
         if(arr[mid]>=arr[left]){
               if(target <=arr[mid] && target>= arr[left]){
                  right=mid-1;
               }else{
                  left=mid+1;
               }
         }else{
                 if(arr[mid]< target && target <=arr[right]){
                    left=mid+1;
                 }else{
                   right=mid-1;
                 }
         }

       }
       return -1;
}

int main(){
int n,target;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
   cin>>arr[i];
cin>>target;
cout<< shiftedBinarySearch(arr,target,n)<<"\n";

}
