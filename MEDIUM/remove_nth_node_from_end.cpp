// problem link -  https://www.geeksforgeeks.org/delete-nth-node-from-the-end-of-the-given-linked-list/

#include<bits/stdc++.h>
using namespace std;
struct node {
   int value;
   node * next;

};
// time complexity  - O(N)
// space complexity - O(1)
// assumming n is always valid

node* removeNthNodeFromEnd(node *root ,int n){

      if(root==NULL){
         return root;
      }
      node  *first=root,*second=root;
      int counter=0;
      while(counter<n){
         second=second->next;
         counter++;
      }
      if(second==NULL){
        root=root->next;
        return root;
      }
      while(second->next !=NULL){
         second=second->next;
         first=first->next;
      }
      first->next=first->next->next;
      return root;
}
int main(){
node *root=new node();
root->value=1;
root->next=new node();
root->next->value=2;
root->next->next=new node();
root->next->next->value=3;
root->next->next->next=new node();
root->next->next->next->value=4;
root=removeNthNodeFromEnd(root ,2);
while(root!=NULL){
  cout<<root->value<<" ";
  root=root->next;
}

}
