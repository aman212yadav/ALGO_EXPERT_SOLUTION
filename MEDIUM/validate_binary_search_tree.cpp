#include<bits/stdc++.h>
using namespace std;

// problem link  https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/

// time complexity - O(n)
// space complexity - O(d)
bool validateBinaryTreeHelper(node *root,int l,inr r){
      if(root==NULL)
       return true;
      if(root->key>=l && root->key <= r && validateBinaryTreeHelper(root->left,l,root->key) && validateBinaryTreeHelper(root->right,root->key,r)){
        return true;
      }
      return false;

}
bool validateBinaryTree(node *root){
 return validateBinaryTreeHelper(root,INT_MIN,INT_MAX);
}
