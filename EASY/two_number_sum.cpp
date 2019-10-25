#include<bits/stdc++.h>
using namespace std;
// time-complexity  : O(n^2)
// space-complexity : O(1)
vector<int> two_number_sum(vector<int> arr,int num){
       for(int i=0;i<arr.size();i++){

        for(int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==num)
            return vector<int>{arr[i],arr[j]};
        }

       }
       return vector<int>();

}


//time-complexity  - O(n)
//space-complexity - O(n)
vector<int> two_number_sum(vector<int> arr,int num){
        map<int,bool> m;
       for(int i=0;i<arr.size();i++){
          if(m[num-arr[i]]==true){
            return vector<int>{num-arr[i],arr[i]};
          }
          m[arr[i]]=true;
       }
       return vector<int>();

}


//time-complexity   - O(nlogn)
//space-complexity  - O(1)
vector<int> two_number_sum(vector<int> arr,int num){
        sort(arr.begin(),arr.end());
        int l=0,r=arr.size()-1;
       while(l<r){
        if(arr[l]+arr[r]==num){
            return vector<int>{arr[l],arr[r]};
        }else if(arr[l]+arr[r]>num){
             r--;
        }else{
           l++;
        }
       }
       return vector<int>();

}


int main(){
int n,num;
cin>>n;
cin>>num;
vector<int> v(n);
for(int i=0;i<n;i++)
    cin>>v[i];
vector<int> r=two_number_sum(v,num);
for(auto k : r){
    cout<<k<<" ";
}


}
