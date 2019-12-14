
//problem - given n size array and a target sum ,find all quadraple whose sum is equal to A.

#include<bits/stdc++.h>
using namespace std;
struct node {
    int a,b,c,d;
};

// average time complexity  - O(n^2)
// space complexity - O(n^2)

vector<node> fourNumberSum(int arr[],int n,int targetSum){
              unordered_map< int ,vector< pair<int,int> >  > hashh;
              vector<node > answers;
              for(int i=0;i<n;i++){
                 for(int j=i+1;j<n;j++){
                     int sum=arr[i]+arr[j];
                     if(hashh.find(targetSum-sum)!= hashh.end()){
                            vector< pair<int,int> > v = hashh[targetSum-sum];
                            for(auto k : v){
                                 answers.push_back({k.first,k.second,arr[i],arr[j]});
                            }
                     }

                 }
                 for(int k=0;k<i;k++){
                     hashh[arr[k]+arr[i]].push_back({arr[k],arr[i]});
                 }
              }
              return answers;

}

int main(){

int n,target;
cin>>n>>target;
int arr[n];
for(int i=0;i<n;i++)
  {
   cin>>arr[i];
  }

vector< node > answers=fourNumberSum(arr,n,target);

 for(auto k : answers){
   cout<<k.a<<" , "<<k.b<<" , "<<k.c<<" , "<<k.d<<"\n";
 }


}
