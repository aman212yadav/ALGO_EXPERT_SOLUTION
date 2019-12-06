// problem link  : https://www.geeksforgeeks.org/coin-change-dp-7/

#include<bits/stdc++.h>
using namespace std;

// time complexity - O(amount*denomination_size)
// space complexity - O(amount)
int numberOfWaysToMakeChange(int amount,int denom[],int n)
{
    int dp[amount+1]= {0};
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=amount;j++){
           if(j>=denom[i]){
            dp[j]+=dp[j-denom[i]];
           }
        }
    }
    return dp[amount];

}
int main()
{
int n,amount;
cin>>n;
int denom[n];
for(int i=0;i<n;i++)
    cin>>denom[i];

cin>>amount;
cout<<numberOfWaysToMakeChange(amount,denom,n)<<"\n";


}
