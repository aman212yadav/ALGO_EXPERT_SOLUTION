// https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

#include<bits/stdc++.h>
using namespace std;


//time complexity  - O(amount*n)
//space complexity - O(amount)
int minNumberOfCoinsForChange(int amount,int denom[],int n)
{

    long long minCoins[amount+1];
    minCoins[0]=0;
    for(int i=1; i<=amount; i++)
        minCoins[i]=INT_MAX;
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=amount; j++)
        {
           if(j>=denom[i])
              minCoins[j]=min(minCoins[j],1+minCoins[j-denom[i]]);
        }
    }
    if(minCoins[amount]==INT_MAX){  // when change not possible
     return -1;
    }
    return minCoins[amount];
}
int main()
{

int n,amount;
cin>>n;
int denom[n];
for(int i=0;i<n;i++)
   cin>>denom[i];

cin>>amount;
cout<<minNumberOfCoinsForChange(amount,denom,n)<<"\n";

}
