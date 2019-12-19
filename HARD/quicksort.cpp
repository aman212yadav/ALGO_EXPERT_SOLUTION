// problem link - https://www.geeksforgeeks.org/quick-sort/

#include<bits/stdc++.h>
using namespace std;

// time complexity - O(n^2) { worst case }

int partition(vector<int> &arr,int left,int right ){
     int pivot=arr[left],yellow=left+1,green=left+1;
     while(green <= right){

        if(arr[green] <=pivot){
            swap(arr[green],arr[yellow]);
            yellow++;
        }
        green++;
     }
     swap(arr[left],arr[yellow-1]);
     return yellow-1;
}

void quickSort(vector<int> &arr,int left,int right){
          if(left>=right){
            return;
          }
          int idx=partition(arr,left,right);
          quickSort(arr,left,idx-1);
          quickSort(arr,idx+1,right);
}
int main(){
int n;
cin>>n;

vector<int> arr(n);

for(int i=0;i<n;i++)
  cin>>arr[i];

 quickSort(arr,0,arr.size()-1);

 for(auto k : arr){
   cout<<k<<" ";
 }


}

