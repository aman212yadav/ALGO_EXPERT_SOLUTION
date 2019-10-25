// https://www.geeksforgeeks.org/sum-product-pairs-array-elements/


#include<bits/stdc++.h>
using namespace std;
// time-complexity  - O(n)
// space_complexity - O(1)
long long product_pair_sum(vector<int> v){
      long long array_sum=0,square_sum=0;
      for(auto k : v){
         array_sum+=k;
         square_sum+=k*k;
      }
      return (array_sum*array_sum-square_sum)/2;
}
int main(){
int n;
cin>>n;
vector<int> v(n);
for(int i=0;i<n;i++)
   cin>>v[i];

 cout<<product_pair_sum(v);


}
