// problem link - https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/

#include<bits/stdc++.h>
using namespace std;



// time complexity O(n)
// space complexity O(n)
int maxSubsetSumNoAdjacent_1(int *arr,int n)
{
    if(n==0)
        return 0;
    int dp[n];
    dp[0]=arr[0];
    for(int i=1; i<n; i++)
    {
        dp[i]=dp[i-1];
        if(i-2>=0)
            dp[i]=max(dp[i],arr[i]+dp[i-2]);
    }
    return dp[n-1];
}





// time complexity O(n)
// space complexity O(1)
int maxSubsetSumNoAdjacent_2(int *arr,int n)
{
   if(n==0)
   return 0;
   if(n==1)
   return arr[0];
   int last=max(arr[0],arr[1]),secondLast=arr[0];
   for(int i=2;i<n;i++){
     int nextMax=max(secondLast+arr[i],last);
     secondLast=last;
     last=nextMax;
   }
   return last;
}
int main()
{
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
  cin>>arr[i];

cout<<maxSubsetSumNoAdjacent_1(arr,n)<<"\n";
cout<<maxSubsetSumNoAdjacent_2(arr,n)<<"\n";


}
