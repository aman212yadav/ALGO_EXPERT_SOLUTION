// problem link - https://www.geeksforgeeks.org/find-closest-element-binary-search-tree/


#include<bits/stdc++.h>
using namespace std;
int getClosestUtil(vector<int> gr[],int u,int closest,int num,int value[]){
    if(abs(num-closest)>abs(num-value[u])){
       closest=value[u];
    }
    if(num < value[u]){
      for(auto k : gr[u]){
         if(value[k] < value[u])
           return getClosestUtil(gr,k,closest,num,value);
      }
    }
    else if(num > value[u]){
      for(auto k : gr[u]){
         if(value[k] > value[u])
           return getClosestUtil(gr,k,closest,num,value);
      }
    }else{
    return closest;
    }
}
int getClosest(vector<int> gr[],int u,int num,int value[]){
    int closest=INT_MAX;
    return getClosestUtil(gr,1,closest,num,value);
}


int main(){
int n,m,u,v,num;
cin>>n>>m>>num;
vector<int> gr[n+1];
for(int i=0;i<m;i++){
  cin>>u>>v;
  gr[u].push_back(v);
}
int value[n+1];
for(int i=1;i<=n;i++)
   cin>>value[i];
int ans=getClosest(gr,1,num,value);
cout<<ans<<endl;

}
