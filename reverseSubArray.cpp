#include <iostream>
using namespace std;

void reverseArrSub(int* arr, int size, int k){
    int* left = NULL, *right = NULL;

    for(int i = 0; i < size; i += k){
        left = arr + i;
        right = arr + i + k - 1;
        
        if(right >= arr + size){
            right--;
        }
        
        while(left < right){
            swap(*left, *right);
            left++;
            right--;
        }
    }
    
}
int main() {
    int size = 8, k = 3;
    int arr[size] = {1,2,3,4,5,6,7,8};
    
    reverseArrSub(arr, size, k);
    
    for(int i = 0; i < size; i++){
        cout<<*(arr + i)<<" ";
    }

    return 0;
}