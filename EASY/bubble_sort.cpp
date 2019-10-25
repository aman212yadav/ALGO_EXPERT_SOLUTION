#include<bits/stdc++.h>
using namespace std;
void bubble_sort(vector<int> &v){
     bool isSorted=false;
     int co=0;
     while(!isSorted){
         isSorted=true;
         for(int i=0;i<v.size()-1-co;i++){
            if(v[i]>v[i+1])
                { swap(v[i],v[i+1]);
                  isSorted=false;
                }
         }
         co++;
     }
}
int main(){
int n;
cin>>n;
vector<int> v(n);
for(int i=0;i<n;i++)
  cin>>v[i];
bubble_sort(v);
for(auto k : v){
 cout<<k<<" ";
}


}
