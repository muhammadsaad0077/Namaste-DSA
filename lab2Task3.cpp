#include <iostream>
using namespace std;

int main() {
    int rows, cols, addTop, addRight, addBottom, newRows, newCols;
    cout<<"24P-3077"<<endl;
    cout<<"Enter Rows: ";
    cin>>rows;
    cout<<"Enter Cols: ";
    cin>>cols;

    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin>>arr[i][j];
        }
    }

    addTop = arr[0][0];
    addRight = arr[0][cols - 1];
    addBottom = arr[rows - 1][0];

    newRows = rows + addTop + addBottom;
    newCols = cols + addRight;

    int** bigArr = new int*[newRows];
    for (int i = 0; i < newRows; i++) {
        bigArr[i] = new int[newCols];
        for (int j = 0; j < newCols; j++) {
            bigArr[i][j] = 0;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            bigArr[i + addTop][j] = arr[i][j];
        }
    }

    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < newCols; j++) {
            cout<<bigArr[i][j]<<" ";
        }
        cout<<endl;
    }

    for (int i = 0; i < rows; i++){
        delete[] arr[i];
    } 
    delete[] arr;

    for (int i = 0; i < newRows; i++){
        delete[] bigArr[i];
    } 
    delete[] bigArr;

    return 0;
}
