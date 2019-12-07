// similar problem link -> https://leetcode.com/problems/number-of-islands/

#include<bits/stdc++.h>
using namespace std;


//  time complexity  -  O(n*m)
//  space complexity -  O(n*m)

int traverseNode(int i,int j,vector< vector<int> > &matrix,vector< vector<bool> > &vis,int n,int m){

     queue< pair<int,int> > q;
     q.push( { i,j});
     int sz=0;
     vis[i][j]=1;
     while(!q.empty()){
     pair<int,int> node=q.front();
     int x=node.first,y=node.second;
     q.pop();
     sz++;
      if(x>0 && !vis[x-1][y] ){
          vis[x-1][y]=1;
          if(matrix[x-1][y]){
           q.push({x-1,y});
          }
      }
      if(y>0 && !vis[x][y-1]){
         vis[x][y-1]=1;
         if(matrix[x][y-1]){
           q.push({x,y-1});
         }
      }
      if(x < n-1 && !vis[x+1][y]){
         vis[x+1][y]=1;
         if(matrix[x+1][y]){
           q.push({x+1,y});
         }
      }
      if(y < m-1 && !vis[x][y+1]){
          vis[x][y+1]=1;
          if(matrix[x][y+1])
            q.push({x,y+1});
      }

     }
    return sz;
}

vector<int> riverSizes(vector< vector<int> > &matrix,int n,int m){

        vector< vector<bool> > vis(n,vector<bool>(m,0) );
        vector<int> river_sizes;
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0){
                vis[i][j]=1;
                if(matrix[i][j]==1){
                       int river_size=traverseNode(i,j,matrix,vis,n,m);
                       if(river_size > 0)
                        river_sizes.push_back(river_size);
                }

            }
        }

        }
        return river_sizes;

}
int main(){
  int n,m;
  cin>>n>>m;
  vector< vector<int> > matrix(n,vector<int>(m));
  for(int i=0;i<n;i++)
  {
     for(int j=0;j<m;j++)
       cin>>matrix[i][j];
  }
  vector<int> river_sizes=riverSizes(matrix,n,m);
  for(auto  river_size : river_sizes ){
    cout<<river_size<<" ";

  }

}

