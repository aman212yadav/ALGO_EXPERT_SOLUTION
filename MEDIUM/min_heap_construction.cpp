// problem link  - https://www.geeksforgeeks.org/building-heap-from-array/


#include<bits/stdc++.h>
using namespace std;

class minHeap {
   private :
   vector<int> heap;
   public:
   minHeap( vector<int> a){
     heap=makeHeap(a);
   }
   bool isEmpty(){
     return heap.size()==0;
   }
   vector<int> makeHeap(vector<int> &a){
      int sz=a.size()-1;
      for(int i=(sz-1)/2;i>=0;i--){
         shiftDown(i,sz,a);
      }
      return a;
   }
   void shiftDown(int currentIdx,int lastIdx,vector<int> &a){
              int firstChild = currentIdx*2+1, idxToSwap;
              if( firstChild <= lastIdx){
                    int secondChild=firstChild+1;
                    if(secondChild <=lastIdx && a[firstChild] > a[secondChild] ){
                        idxToSwap=secondChild;
                    }
                    else{
                       idxToSwap=firstChild;
                    }

                    if(a[idxToSwap] < a[currentIdx]){
                        swap(a[idxToSwap],a[currentIdx]);
                        shiftDown(idxToSwap,lastIdx,a);
                    }
              }
   }

   void shiftUp(int currentIdx,vector<int> &heap){
        int parentIdx=(currentIdx-1)/2;
        while(currentIdx>0 && heap[parentIdx] > heap[currentIdx]){
           swap(heap[parentIdx],heap[currentIdx]);
           currentIdx=parentIdx;
           parentIdx=(currentIdx-1)/2;
        }
   }
   int peek(){
      return heap[0];
   }
   void remove(){
     int sz=heap.size();
     swap(heap[0],heap[sz-1]);
     heap.pop_back();
     shiftDown(0,heap.size()-1,heap);

   }
   void insert(int value){
    heap.push_back(value);
    shiftUp(heap.size()-1,heap);
   }
};



using namespace std;
int main(){
    int n;
cin>>n;
vector<int> v(n);
for(int i=0;i<n;i++){
  cin>>v[i];
}
minHeap m(v);
m.insert(45);
while(!m.isEmpty()){
    cout<<m.peek()<<" -> ";
    m.remove();
}


}
