#include <iostream>
using namespace std;

void removeDuplicates(int* arr, int &size){
    bool check;
    int x = 0;
    
    for(int i = 0; i < size; i++){
        check = false;
        for(int j = 0; j < x; j++){
            if(arr[i] == arr[j]){
                check = true;
                break;
            }
        }
        
        if(!check){
            arr[x] = arr[i];
            x++;
        }
    }
    
    size = x;
}

void printArray(int* arr, int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
}

int main() {
    int size = 5;
    int arr[size] = {6, 3, 3, 6, 5};
    
    removeDuplicates(arr, size);
    printArray(arr, size);

    return 0;
}
