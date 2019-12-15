// problem link - https://www.geeksforgeeks.org/minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted/

#include<bits/stdc++.h>
using namespace std;

bool isOutOfOrder(int i,vector<int> arr){
              if(i==0) {
                return arr[i]>arr[i+1];
              } else if(i==arr.size()-1){
                 return arr[i]< arr[i-1];
              } else {
                return (arr[i] < arr[i-1])||(arr[i] > arr[i+1]);
              }
}



// time complexity  - O(n)
// space complexity - O(1)
int subarraySort(vector<int> arr){
      int min_unsorted_element=INT_MAX,max_unsorted_element=INT_MIN;
      for(int i=0;i<arr.size();i++){
          if(isOutOfOrder(i,arr)){
                min_unsorted_element=min(min_unsorted_element,arr[i]);
                max_unsorted_element=max(max_unsorted_element,arr[i]);
          }
      }
      if(min_unsorted_element==INT_MAX){
        return 0;
      }
      int left_idx=0,right_idx=arr.size()-1;
      while(left_idx < arr.size() && arr[left_idx]<=min_unsorted_element){
        left_idx++;
      }
      while(right_idx>=0 && arr[right_idx]>=max_unsorted_element){
        right_idx--;
      }
      return right_idx-left_idx+1;
}
int main(){
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)
     cin>>v[i];
  cout<<subarraySort(v);
}


