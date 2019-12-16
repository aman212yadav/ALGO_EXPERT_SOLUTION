// problem link 1 - https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
// problem link 2 - https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/


#include<bits/stdc++.h>
using namespace std;

// time complexity - O(n^2)
// space complexity - O(n)

int minNumberOfJumps_1(vector<int> jumps){

     vector<int> minJumps(jumps.size());
     for(int i=0;i<minJumps.size();i++){
        minJumps[i]=INT_MAX;
     }
     minJumps[0]=0;

     for(int i=1;i<jumps.size();i++){
          for(int j=0;j<i;j++){
              if(j+jumps[j] >= i && minJumps[i]> 1+minJumps[j]){
                 minJumps[i]=1+minJumps[j];
              }
          }
     }
     return minJumps[jumps.size()-1];

}


// time complexity  -  O(n)
// space complexity - O(1)
int minNumberOfJumps_2(vector<int> jumps){

     if(jumps.size()<=1){
        return 0;
     }
     int minJumps=0,maxReach=0,steps=0;
     steps=jumps[0];
     maxReach=jumps[0];
     for(int i=1;i<jumps.size();i++){
        maxReach=max(maxReach,i+jumps[i]);
        steps--;
        if(steps==0){
                minJumps++;
            steps=maxReach-i;
        }
     }
     return minJumps+1;
}
int main(){
int n;
cin>>n;

vector<int> v(n);
for(int i=0;i<n;i++)
  cin>>v[i];
 cout<<minNumberOfJumps_1(v)<<"\n";
 cout<<minNumberOfJumps_2(v)<<"\n";


}
