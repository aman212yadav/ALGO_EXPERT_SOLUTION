// https://www.geeksforgeeks.org/insertion-sort/

#include<bits/stdc++.h>
using namespace std;


// time complexity  - O(n^2)
// space complexity - O(1)
void insertion_sort(vector<int> &v){
    for(int i=1;i<v.size();i++){
         int j=i;
         while(j>0 && v[j]<v[j-1]){
            swap(v[j],v[j-1]);
            j--;
         }
    }


}
int main(){
int n;
cin>>n;
vector<int> v(n);
for(int i=0;i<n;i++)
   cin>>v[i];
insertion_sort(v);
for(auto k : v){
 cout<<k<<" ";
}


}
