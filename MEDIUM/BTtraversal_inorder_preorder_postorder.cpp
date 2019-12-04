#include<bits/stdc++.h>
using namespace std;
struct node{
  int key;
  node *left;
  node *right;
  node(){
   left=NULL;
   right=NULL;
  }
};
node * insertNode(node *root,int key){
   if(root==NULL){
     root=new node();
     root->key=key;
     return root;
   }
   if(root->key < key){
    root->right=insertNode(root->right,key);
   }else{
    root->left=insertNode(root->left,key);
   }
   return root;
}
bool searchNode(node *root,int key){
      if(root==NULL){
       return false;
      }
      if(root->key==key)
       return true;
      else if(root->key < key){
       return searchNode(root->right,key);
      }else{
       return searchNode(root->left,key);
      }
}
int inorderSuccessor(node *root){
     while(root->left!=NULL){
      root=root->left;
     }
     return root->key;
}
node * deleteNode(node *root,int key){
    if(root==NULL){
     return root;
    }
    if(root->key < key){
    root->right=deleteNode(root->right,key);
    }
    else if( root->key > key){
    root->left=deleteNode(root->left,key);
    }else{
       if(root->left==NULL && root->right==NULL){
        root=NULL;
       }else if(root->left==NULL){
         root=root->right;
       }else if(root->right==NULL){
        root=root->left;
       }else{
       int inorderSuc=inorderSuccessor(root->right);
       root->key=inorderSuc;
       root->right=deleteNode(root->right,inorderSuc);
       }
    }
    return root;
}
void preorderTraversal(node *root){
   if(root==NULL){
     return ;
   }
   cout<<root->key<<" , ";
   preorderTraversal(root->left);
   preorderTraversal(root->right);
}
void postorderTraversal(node *root){
  if(root==NULL){
    return ;
  }
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout<<root->key<<" , ";
}
void inorderTraversal(node *root){
   if(root==NULL){
    return;
   }
   inorderTraversal(root->left);
   cout<<root->key<<" , ";
   inorderTraversal(root->right);
}
int main(){
int numOfQuery,qType,key;
node* root=NULL;
cin>>numOfQuery;
while(numOfQuery--){
   cin>>qType;
   if(qType==1){ // insert
      cin>>key;
      root=insertNode(root,key);
   }else if(qType==2){ //search
     cin>>key;
     if(searchNode(root,key)){
      cout<<" Present ; \n";
     }else{
      cout<<" Not Present ; \n";
     }
   } else if(qType==3){ //delete
     cin>>key;
     root=deleteNode(root,key);
   }else if(qType==4){ //inorder Traversal
   inorderTraversal(root);
   cout<<"\n";
   }else if(qType==5){ //preorder Traversal
    preorderTraversal(root);
   cout<<"\n";
   }else{             // postorder Traversal
   postorderTraversal(root);
   cout<<"\n";
   }
}

}
