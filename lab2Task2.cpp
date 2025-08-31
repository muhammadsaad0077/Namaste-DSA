#include <iostream>
using namespace std;

int* findIntersection(int** arr1,int** arr2,int row1,int row2,int col1,int col2){
    int size = 0;
    int* resultArray = new int[size];
    
    for(int i = 0; i < row1*col1; i++){
        for(int  j = 0; j < row2*col2){
            if(*(arr + i) == *(arr + j)){
                *(resultArray + ++size) = *(arr + i);
                break;
            }
        }
    }
    
    for(int i = 0; i < size; i++){
        cout<<*(resultArray + i)<<" ";
    }
    
    
    
}

int main() {
    int row1 = 2, col1 = 2, row2 = 2, col2 = 2;
    
    int** arr1 = new int*[row1];
    int** arr2 = new int*[row2];
    
    for(int i = 0; i < row1; i++){
        *(arr1 + i) = new int[col1];
    }
    
    for(int i = 0; i < row2; i++){
        *(arr2 + i) = new int[col2];
    }
    
    for(int i = 0; i < row2; i++){
        for(int j = 0; j < col2){
            
        }
    }
    
    findIntersection(arr1, arr2, row1, row2, col1, col2);
    
    
    for(int i = 0; i < row1; i++){
        delete[] *(arr1 + i);
    }
    
    for(int i = 0; i < row2; i++){
        delete[] *(arr2 + i);
    }
    
    delete[] arr1, arr2;
    

    return 0;
}