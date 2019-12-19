// problem link - https://www.geeksforgeeks.org/quickselect-algorithm/

#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> arr,int left,int right ){
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
int quickSelectHelper(vector<int> arr,int k,int left,int right){
              int idx=partition(arr,left,right);
              if(idx==k){
                return arr[idx];
              }else if(idx < k){
                return quickSelectHelper(arr,k,idx+1,right);
              }else{
                return quickSelectHelper(arr,k,left,idx-1);
              }
}

int quickSelect(vector<int> arr,int k){

     return quickSelectHelper(arr,k,0,arr.size()-1);

}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    k--;
    cout<<quickSelect(arr,k)<<"\n";

}



