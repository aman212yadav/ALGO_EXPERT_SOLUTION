// suffix trie brute force construction

#include<bits/stdc++.h>
using namespace std;


// construction complexity - O(n^2)
// space complexity        - O(n^2)
// search complexity       - O(n)
struct node {
   char ch;
   map<char,node*> m;
   bool isTerminal;
   node(char c){
    ch=c;
    isTerminal=false;
   }
};

//suffix tree
class suffix_trie{
         node *root;
         public:
         suffix_trie(string s){
            root=new node(' ');
            for(int i=0;i<s.size();i++){
                   insert_suffix(s,i);
            }
         }
         void insert_suffix(string suffix,int i=0){
                node *temp=root;
                for(int j=i;j<suffix.size();j++){
                     if(temp->m.count(suffix[j])==1){
                          temp=temp->m[suffix[j]];
                     }
                     else{
                       temp->m[suffix[j]]=new node(suffix[j]);
                        temp=temp->m[suffix[j]];
                     }
                }
                temp->isTerminal=true;
         }

         // search complexity - O(n)
         bool isSuffix(string suffix){
             node *temp=root;
             for(auto k: suffix){
                 if(temp->m.count(k)==0){
                   return false;
                 }else{
                   temp=temp->m[k];
                 }
             }
             return temp->isTerminal;
         }
};
int main(){
string s;
cin>>s;
suffix_trie tri(s);
cout<<tri.isSuffix("an");

}
