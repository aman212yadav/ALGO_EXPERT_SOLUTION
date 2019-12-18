// problem link - https://www.geeksforgeeks.org/topological-sorting/

#include<bits/stdc++.h>
using namespace std;


// time  complexity - O(E+V)
// space complexity - O(V)

void topologicalSort(int V,int E,int u,int vis[],vector<int> gr[],stack<int> &stac){
       vis[u]=1;
       for(auto v : gr[u]){
          if(!vis[v])
            topologicalSort(V,E,v,vis,gr,stac);
       }
       stac.push(u);
}

int main(){

int V,E,u,v;
cin>>V>>E;
int vis[V+1]={0};
vector<int> gr[V+1];
for(int i=1;i<=E;i++){
   cin>>u>>v;
   gr[u].push_back(v);
}
stack<int> stac;

for(int i=1;i<=V;i++){
    if(!vis[i])
      topologicalSort(V,E,i,vis,gr,stac);
}
while(!stac.empty()){
    cout<<stac.top()<<" -> ";
    stac.pop();
    }

}
