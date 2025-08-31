#include <iostream>
using namespace std;

int calculateRowSum(int** arr, int row, int col, int& rowSum){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            rowSum += *(*(arr + i) + j);
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return rowSum;
}

int calculateColSum(int** arr, int row, int col, int& colSum){
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            colSum += *(*(arr + j) + i);
        }
    }
    
    return colSum;
}

int main() {
    int row, col, rowSum = 0, colSum = 0;
    cout<<"Enter No of Row: ";
    cin>>row;
    cout<<"Enter No of Column: ";
    cin>>col;
    
    int** arr = new int*[row];
    
    for(int i = 0; i < row; i++){
        *(arr + i) = new int[col];
    }
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            *(*(arr + i) + j) = i+1+j;
        }
    }
    
    cout<<"Row Sum: "<<calculateRowSum(arr, row, col, rowSum)<<endl;
    
    cout<<"Col Sum: "<<calculateColSum(arr, row, col, colSum);
    
    for(int i = 0; i < row; i++){
        delete[] *(arr + i);
    }
    
    delete[] arr;

    return 0;
}