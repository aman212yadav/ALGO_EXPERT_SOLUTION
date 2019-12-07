//problem link ->   https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/


#include<bits/stdc++.h>
using namespace std;


// time complexity -  O(V+E)
// space complexity - O(V)

void breadthFirstSearch(vector<int> *graph,int num_of_vertex,int  start_vertex){

     int vis[num_of_vertex+1]={0};
     queue<int> q;
     q.push(start_vertex);
     vis[start_vertex]=1;
     while(!q.empty()){
      int vertex=q.front();

      q.pop();

      cout<<vertex<<" -> ";
      for(auto k : graph[vertex] ){
          if( vis[k]==0){
              vis[k]=1;
              q.push(k);
          }
      }

     }

}



int main(){

int V,E,u,v;
cin>>V>>E;

vector<int> graph[V+1];
for(int i=1;i<=E;i++){
   cin>>u>>v;
   graph[u].push_back(v);
   graph[v].push_back(u);
}

breadthFirstSearch(graph,V,1);






}
