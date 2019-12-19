// problem link - https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/

#include<bits/stdc++.h>
using namespace std;


// time  complexity - O(n)
// space complexity - O(number of all characters)
int longestSubstringWithoutDuplication(string s){

        int prevOccurrence[256];
        int longest=1,currentLength=1;
        for(int i=0;i<256;i++){
          prevOccurrence[i]=-1;
        }
        prevOccurrence[s[0]]=0;

        for(int i=1;i<s.size();i++){
           if(prevOccurrence[s[i]]==-1 || i-currentLength > prevOccurrence[s[i]]){
              currentLength++;
           } else {
           if(currentLength>longest)
              longest=currentLength;
            currentLength=i-prevOccurrence[s[i]];

           }
           prevOccurrence[s[i]]=i;
        }

         if(currentLength>longest)
              longest=currentLength;

        return longest;

}

int main(){
string s;
cin>>s;
cout<<longestSubstringWithoutDuplication(s)<<"\n";

}
