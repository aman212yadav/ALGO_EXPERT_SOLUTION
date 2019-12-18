#include<bits/stdc++.h>
using namespace std;

int knapsack_problem(int W,int weight[],int val[],int n){

    int dp[n+1][W+1];

    for(int i=0;i<=n;i++){
      for(int j=0;j<=W;j++){
          if(i==0 || j==0){
             dp[i][j]=0;
          }else{
            dp[i][j]=dp[i-1][j];
             if(j-weight[i-1]>=0){
               dp[i][j]=max(dp[i][j],val[i-1]+dp[i-1][j-weight[i-1]]);
             }
          }
      }
    }
    return dp[n][W];

}
int main(){
int n,w;
cin>>n>>w;
int weight[n],val[n];
for(int i=0;i<n;i++){
    cin>>weight[i];
}
for(int i=0;i<n;i++){
    cin>>val[i];
}
cout<<knapsack_problem(w,weight,val,n);

}
