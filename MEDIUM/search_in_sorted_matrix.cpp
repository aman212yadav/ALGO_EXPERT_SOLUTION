// problem link -  https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/

#include<bits/stdc++.h>
using namespace std;

//time complexity  - O(N+M)
//space complexity - O(1)

bool searchInSortedMatrix(vector< vector<int> > matrix,int n,int m,int target){

     int row=0,col=m-1;
     while(row < n && col >=0){
      if(matrix[row][col] > target){
        col--;
      } else if(matrix[row][col] < target){
       row++;
      } else {
      return true;
      }
     }
     return false;

}
int main(){

int n,m,target;
cin>>n>>m;
vector< vector<int> > v(n,vector<int>(m));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>v[i][j];
    }
}
cin>>target;
cout<<searchInSortedMatrix(v,n,m,target);


}
