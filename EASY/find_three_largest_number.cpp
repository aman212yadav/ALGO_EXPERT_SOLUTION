#include<bits/stdc++.h>
using namespace std;
void shiftandupdate(int idx,int num,vector<int> &three){
    for(int i=0;i<=idx;i++){
      if(i==idx)
          three[i]=num;
      else
         three[i]=three[i+1];
    }

}
vector<int> find_largest_three(vector<int> v){
 vector<int> three(3,INT_MIN);
    for(auto k : v){
        if(k>three[2])
           {shiftandupdate(2,k,three);
           }else if(k>three[1]){
            shiftandupdate(1,k,three);
           }else if(k>three[0]){
            shiftandupdate(0,k,three);
           }
    }
    return three;

}
int main(){
int n;
cin>>n;
vector<int> v(n);
for(int i=0;i<n;i++)
   cin>>v[i];
vector<int> ans= find_largest_three(v);
for(auto k : ans)
  cout<<k<<" ";


}
