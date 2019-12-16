// problem link -  https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

#include<bits/stdc++.h>
using namespace std;
// time complexity  - O(n*m)
// space complexity - O(n*m)

int longestCommonSubsequence(string str1,string str2){
   int lcs[str1.size()+1][str2.size()+1]={0};
   for(int i=0;i<=str2.size();i++){
        lcs[0][i]=0 ;
   }
   for(int i=0;i<=str1.size();i++){
      lcs[i][0]=0 ;
   }
   for(int i=1;i<=str1.size();i++){
      for(int j=1;j<=str2.size();j++){
          if(str1[i-1]==str2[j-1]){
             lcs[i][j]=1+lcs[i-1][j-1];
          }else{
            lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
          }
      }
   }
   return lcs[str1.size()][str2.size()];
}
int main(){
string str1,str2;
cin>>str1>>str2;
cout<<longestCommonSubsequence(str1,str2)<<"\n";


}
