// problem link - https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/

#include<bits/stdc++.h>
using namespace std;

//  time complexity  - O(nlog(n))
// space complexity  - O(n)

vector<int> continuousMedian(vector<int> integers){
        priority_queue<int> sm;
        priority_queue<int,vector<int> ,greater<int> > gr;
        vector<int> medians;
        medians.push_back(integers[0]);
       sm.push(integers[0]);
        float m,k;
          m=integers[0];
       for(int i=1;i<integers.size();i++){
               k=integers[i];
               if(sm.size()>gr.size()){
                    if(m > k ){
                       gr.push(sm.top());
                       sm.pop();
                       sm.push(k);

                    }else{
                       gr.push(k);
                    }
                      m=(sm.top()+gr.top())/2.0;
               }
               else if( sm.size()==gr.size()){
                         if(m>k){
                           sm.push(k);
                           m=sm.top();
                         }else{
                           gr.push(k);
                           m=gr.top();
                         }
               }
               else {
                      if(m<k){
                         sm.push(gr.top());
                         gr.pop();
                         gr.push(k);
                      }else{
                        sm.push(k);
                      }
                      m=(sm.top()+gr.top())/2.0;
               }

             medians.push_back(m);
       }
       return medians;
}

int main(){
int n;
cin>>n;
vector<int> integers(n);
for(int i=0;i<n;i++)
   cin>>integers[i];

vector<int> medians=continuousMedian(integers);
for(auto k : medians)
     cout<<k<<" ";

}
