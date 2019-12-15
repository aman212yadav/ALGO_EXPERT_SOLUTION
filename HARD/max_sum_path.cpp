// problem link - https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *left;
  node *right;
};


int result=INT_MIN;

// time complexity  - O(n)
// space complexity - O(1)
int max_sum_path(node *root){
               if(root==NULL){
                 return 0;
               }
               int left=max_sum_path(root->left);
               int right=max_sum_path(root->right);
               int max_val=max(root->data,max(left,right)+root->data);
               result=max(result,max(max_val,left+right+root->data));
               return max_val;
}
