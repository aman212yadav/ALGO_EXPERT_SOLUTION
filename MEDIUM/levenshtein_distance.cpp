// problem link   - https://www.geeksforgeeks.org/edit-distance-dp-5/

#include<bits/stdc++.h>
using namespace std;


// time complexity  - O(n*m)
// space complexity - O(n*m)
int  levenshteinDistance_1(string &a,string &b)
{
    int dp[a.size()+1][b.size()+1];
    for(int i=0; i<=b.size(); i++)
        dp[0][i]=i;
    for(int i=0; i<=a.size(); i++)
        dp[i][0]=i;
    for(int i=1; i<=a.size(); i++)
    {
        for(int j=1; j<=b.size(); j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
    }
    return dp[a.size()][b.size()];
}



// time complexity  - O(n*m)
// space complexity - O(min(n,m))
int  levenshteinDistance_2(string &a,string &b)
{
    int dp[2][b.size()+1];
    for(int i=0; i<=b.size(); i++)
        dp[0][i]=i;
    for(int i=1; i<=a.size(); i++)
    {
        dp[i%2][0]=i;
        for(int j=1; j<=b.size(); j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i%2][j]=dp[!(i%2)][j-1];
            }
            else
            {
                dp[i%2][j]=1+min(dp[i%2][j-1],min(dp[!(i%2)][j-1],dp[!(i%2)][j]));
            }

        }
    }
    return dp[a.size()%2][b.size()];

}
int main()
{

    string a,b;
    cin>>a>>b;
    cout<<levenshteinDistance_1(a,b)<<"\n";
    cout<<levenshteinDistance_2(a,b)<<"\n";



}
