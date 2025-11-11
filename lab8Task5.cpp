#include<iostream>
using namespace std;

int recursiveSumRow(int* arr, int size, int index){
    if(index == size){
        return 0;
    }

    return arr[index] + recursiveSumRow(arr, size, ++index);
}

int recursiveSum(int** arr, int row, int* sizes, int index){
    if(index == row){
        return 0;
    }

    return recursiveSumRow(arr[index], sizes[index], 0) + recursiveSum(arr, row, sizes, ++index);
}

int main(){
    int row = 3;
    int** arr = new int*[row];
    int sizes[3] = {4, 3, 2};

    for(int i = 0; i < row; i++){
        *(arr + i) = new int[sizes[i]];
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < sizes[i]; j++){
           *(*(arr + i) + j)  = i + j;
        }
    }

    

    cout<<"Saad Bin Sharif"<<endl;
    cout<<"24P-3077"<<endl<<endl;
    cout<<"Array "<<endl;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < sizes[i]; j++){
           cout<<*(*(arr + i) + j)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Total Sum: "<<recursiveSum(arr, row, sizes, 0);

    
}