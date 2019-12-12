// problem link - https://www.geeksforgeeks.org/power-set/


#include<bits/stdc++.h>
using namespace std;

// time complexity - O(n*2^n)
//space complexity - O(2^n*n)
vector< vector<int> > powerset(vector<int> input){
             vector< vector<int> > powersets;
             powersets.push_back(vector<int>());
             for(auto k : input){
                int len=powersets.size();
                for(int i=0;i<len;i++){
                    vector<int> power=powersets[i];
                    power.push_back(k);
                    powersets.push_back(power);
                }
             }
             return powersets;
}
int main(){
int n;
cin>>n;
vector<int> input(n);
for(int i=0;i<n;i++){
    cin>>input[i];
}
vector< vector<int> > powersets=powerset(input);
for(auto k : powersets){
    for(auto l : k){
        cout<<l<<" , ";
    }
    cout<<"\n";

}

}
