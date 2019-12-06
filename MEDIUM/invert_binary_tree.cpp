#include<bits/stdc++.h>
using namespace std;
struct node {
   int value;
   node * left;
   node * right;
};
/* logic one   - inorder traversal and swapping left and right child of each node
 time complexity O(n)
 space complexity O(n)
*/
void invertBinaryTree(node *root){
    if(root==NULL)
       return ;
       queue<node * > q;
       q.push(root);
       while(!q.empty()){
          node n=q.front();
          q.pop();
          if(n->left!=NULL)
            q.push(n->left);
          if(n->right!=NULL)
            q.push(n->right);
            node *temp=n->left;
            n->left=n->right;
            n->right=temp;
       }


}
/* logic two - recursively swapping left and right child of node
   time complexity - O(n)
   space complexity - O(n)
*/
node * invertBinaryTree(node *root){
      if(root==NULL)
       return;
       node *temp=root->left;
       root->left=root->right;
       root->right=temp;
       invertBinaryTree(root->left);
       invertBinaryTree(root->right);


}
