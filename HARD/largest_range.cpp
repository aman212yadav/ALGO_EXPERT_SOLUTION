// problem (largest range) -> given array find longest range of numbers
// example                 -> given array {2,6,5,0,4,9,10,1,3}
// answer will be [0,6] because all numbers in between is present in array.

#include<bits/stdc++.h>
using namespace std;

pair<int,int> largestRange(vector<int> arr){
             pair<int,int> ans;
             int largest=0;
             map<int,bool> m;
             for(int i=0;i<arr.size();i++)
                 m[arr[i]]=true;
             for(int i=0;i<arr.size();i++){
                if(!m[arr[i]])
                    continue;
                m[arr[i]]=false;
                int left=arr[i]-1,currentLargest=1;
                int right=arr[i]+1;
                while(m[left]){
                        m[left]=false;
                    left--;
                }
                while(m[right]){
                    m[right]=false;
                    right++;
                }
                if(currentLargest > largest){
                    largest=currentLargest;
                    ans.first=left+1;
                    ans.second=right-1;
                }

             }
             return ans;
}

int main(){
int n;
cin>>n;
vector<int> arr(n);
for(int i=0;i<n;i++)
  cin>>arr[i];

 pair<int,int> ans=largestRange(arr);
  cout<<ans.first<<" , "<<ans.second<<"\n";
}




