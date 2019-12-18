// problem link - https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

#include<bits/stdc++.h>
using namespace std;



struct node{
  int data;
  node *next;
};

// time complexity  - O(n)
// space complexity - O(1)

bool findLoop(node *root){



         node *slow=root,*fast=root;
         while(slow && fast && fast->next ){
             slow=slow->next;
             fast=fast->next->next;

         if(slow==fast)
           return true;

         }
         return false;

}
