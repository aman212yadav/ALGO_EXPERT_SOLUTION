// problem link - https://www.geeksforgeeks.org/trapping-rain-water/

#include<bits/stdc++.h>
using namespace std;

// time complexity  - O(n)
// space complexity - O(n)

int waterArea(vector<int> heights){
    vector<int> maxes(heights.size());
    maxes[0]=0;
    int maxLeft=0;
    for(int i=0;i<heights.size();i++){
        maxes[i]=maxLeft;
        maxLeft=max(heights[i],maxLeft);
    }
    int maxRight=0;
    for(int i=heights.size()-1;i>=0;i--){
         int mi=min(maxes[i],maxRight);
         if(mi>heights[i]){
            maxes[i]=mi-heights[i];
         }else{
            maxes[i]=0;
         }
         maxRight=max(maxRight,heights[i]);
    }
    int sum=0;
    for(int i=0;i<heights.size();i++){
      sum+=maxes[i];
    }
   return sum;
}
int main(){
int n;
cin>>n;
vector<int> heights(n);
for(int i=0;i<n;i++){
   cin>>heights[i];
}
cout<<waterArea(heights)<<"\n";
}
