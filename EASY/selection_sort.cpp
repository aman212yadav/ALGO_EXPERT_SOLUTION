// https://www.geeksforgeeks.org/selection-sort/

#include<bits/stdc++.h>
using namespace std;
void selection_sort(vector<int> &v){
   int n=v.size(),idx=0;
   while(idx<n-1){
    int sma=idx;
    for(int j=sma+1;j<n;j++)
       if(v[j]<v[sma])
          sma=j;
     swap(v[idx],v[sma]);
     idx++;
   }
}
int main(){
int n;
cin>>n;
vector<int> v(n);
for(int i=0;i<n;i++)
 cin>>v[i];
 selection_sort(v);
 for(auto k : v){
  cout<<k<<" ";
 }



}
