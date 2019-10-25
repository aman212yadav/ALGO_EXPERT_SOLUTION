//  https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> gr[],int u,int par,int value[]){
   cout<<value[u]<<" ";
   for(auto k : gr[u]){
      if(k!=par)
      dfs(gr,k,u,value);
   }
}
int main(){
int n,m,u,v;
cin>>n>>m;
vector<int> gr[n+1];
for(int i=0;i<m;i++){
   cin>>u>>v;
   gr[u].push_back(v);
   gr[v].push_back(u);
}
int value[n+1];
for(int i=1;i<=n;i++)
 cin>>value[i];
 dfs(gr,1,-1,value);

}
