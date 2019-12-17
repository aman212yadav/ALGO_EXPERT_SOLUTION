// problem link - https://www.geeksforgeeks.org/box-stacking-problem-dp-22/

#include<bits/stdc++.h>
using namespace std;

struct box{
     int h;
     int w;
     int d;
};


bool canStack(box b1,box b2){
    return b1.w>b2.w && b1.d > b2.d;
}
bool cmp(box b1,box b2){
    return b1.w*b1.d > b2.w*b2.d;
}

// time  complexity - O(n^2)
// space complexity - O(n)

int diskStacking(vector<box> boxes ){
       int n=boxes.size();
       vector<box> bx;
       for(int i=0;i<n;i++){
       int h=boxes[i].h,w=boxes[i].w,d=boxes[i].d;
       bx.push_back(boxes[i]);
       bx.push_back({w,min(h,d),max(h,d)});
       bx.push_back({d,min(h,w),max(h,w)});
       }

       int lis[bx.size()];
       sort(bx.begin(),bx.end(),cmp);
       n=3*n;
       for(int i=0;i<n;i++)
          lis[i]=bx[i].h;

       for(int i=1;i<n;i++){
          for(int j=0;j<i;j++){
            if(canStack(bx[j],bx[i]) && lis[j]+bx[i].h > lis[i]){
               lis[i]=lis[j]+bx[i].h;
            }
          }
       }
       int ma=0;
       for(int i=0;i<n;i++){
         ma=max(ma,lis[i]);
       }
       return ma;
}

int main(){

int n;
cin>>n;
vector<box> boxes(n);
for(int i=0;i<n;i++){
  cin>>boxes[i].h>>boxes[i].w>>boxes[i].d;
}

cout<<diskStacking(boxes);

}
