// problem link - https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/

#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> arr,int target,bool isLeft){
     int left=0,right=arr.size()-1,ans=-1;
      while(left <= right){
          int mid=(left+right)/2;
          if(arr[mid]==target){
             ans=mid;
            if(isLeft){
              right=mid-1;
            }else{
              left=mid+1;
            }
          }else if( arr[mid] < target){
          left=mid+1;
          }else{
          right=mid-1;
          }
      }
return ans;
}

pair<int,int> findRange(vector<int> arr,int target){

            pair<int,int> range;
            range.first=binarySearch(arr,target,true);
            range.second=binarySearch(arr,target,false);
            return range;

}

int main(){
int n,target;
cin>>n>>target;
vector<int> arr(n);
for(int i=0;i<n;i++)
 cin>>arr[i];
pair<int,int> range=findRange(arr,target);

cout<<range.first<<" "<<range.second<<"\n";

}
