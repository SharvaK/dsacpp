#include <iostream>
#include<vector>
using namespace std ; 

void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp ;
}

// function to heapify the tree
void heapify(vector<int> &hT, int i ){
    int size = hT.size();

    // find the largest among root,left child and right child 
    
    int largest  = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < size && hT[l] > hT[largest])
        largest = l;
    if(r < size && hT[r] > hT[largest])
        largest = r;

      // swap and continue heapifying if root is not largest

    if (largest != i){
         swap( &hT[i] , &hT[largest]);
            heapify( hT, largest);
    }      
}

// function to insert element 

void insert(vector <int> &hT,int newNum){
    int size  = hT.size();
    if(size == 0){
        hT.push_back(newNum);
        size += 1;
    }else{
        hT.push_back(newNum);
        size += 1;
        for( int i = size/2 -1 ; i>=0 ; i--){
            heapify( hT , i);
        }
    }
}

// function to delete element 

void deleteRoot( vector<int> &hT, int num){
    int size = hT.size();
    int i;
    for(i=0 ; i<size ; i++){
        if(num == hT[i])
           break;
    }

    swap(&hT[i] , &hT[size-1]);
    hT.pop_back();
    for(int i = size/2 -1 ; i >= 0; i--){
        heapify(hT, i);
    }
}

 void printArrray(vector<int> &hT ){
        for(int i=0 ; i < hT.size(); ++i ){
            printf("%d", hT[i]);
        printf("\n");    
        }
    }

int main(){
    vector<int> heapTree;

    insert(heapTree, 2);
    insert(heapTree,3);
    insert(heapTree,5);
    insert(heapTree,7);
    insert(heapTree,9);

    cout<< "Max-heap array: ";
    printArrray(heapTree);

    deleteRoot(heapTree,5);

    cout<< "After deleting an element: ";
    printArrray(heapTree);
}    





