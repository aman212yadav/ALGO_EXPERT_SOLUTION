// problem link ->   https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

#include<bits/stdc++.h>
using namespace std;


// time complexity - O(n*n!)
// space complexity - O(n*n!)
void  getPermutations(vector< vector<int> > &permutations,vector<int> &perm,int l,int r){
                      if(l==r){
                         permutations.push_back(perm);
                         return;
                      }
                      for(int i=l;i<=r;i++){
                           swap(perm[l],perm[i]);
                           getPermutations(permutations,perm,l+1,r);
                           swap(perm[l],perm[i]);
                      }

}
int main(){
int n;
cin>>n;
vector<int> perm(n);
for(int i=0;i<n;i++)
   cin>>perm[i];
vector< vector<int> > permutations;
getPermutations(permutations,perm,0,n-1);
for(auto k : permutations){
    for(auto j : k){
     cout<<j<<"  ";
    }
    cout<<"\n";

}

}
