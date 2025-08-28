#include <iostream>
using namespace std;

int main() {
    int rows = 2, cols = 3;

    // allocate contiguous memory
    int** arr = new int*[rows];
    arr[0] = new int[rows * cols];   // one block

    // set row pointers
    for (int i = 1; i < rows; i++) {
        arr[i] = arr[0] + i * cols;
    }

    // fill values
    int counter = 1;
    for (int i = 0; i < rows * cols; i++) {
        arr[0][i] = counter++;
    }

    // access with single loop
    for (int i = 0; i < rows * cols; i++) {
        cout << arr[0][i] << " ";
    }

    // cleanup
    delete[] arr[0];
    delete[] arr;

    return 0;
}
