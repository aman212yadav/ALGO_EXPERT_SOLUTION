//  https://www.geeksforgeeks.org/binary-search/

#include<bits/stdc++.h>
using namespace std;
//time-complexity - O(log(n))
bool binarySearch(vector<int> &v,int l,int r,int num){
   if(l>r)
    return false;
    int mid=(l+r)/2;
    if(v[mid]==num)
     return true;
    else if(v[mid]>num){
    return binarySearch(v,l,mid-1,num);
    }else{
    return binarySearch(v,mid+1,r,num);
    }
}
int main(){
int n,num;
cin>>n>>num;
vector<int> v(n);
for(int i=0;i<n;i++)
  cin>>v[i];

bool res=binarySearch(v,0,n-1,num);
  cout<<res<<endl;



}
