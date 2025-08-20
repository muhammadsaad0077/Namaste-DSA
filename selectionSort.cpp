#include <iostream>
using namespace std;
  
  void selectionSort(int arr[], int n) {
    
  }
  
  int main() {
    int arr[] = {4, 5, 1, 3, 9};
    
    int n = sizeof(arr) / sizeof(arr[0]);
    int min;
    
    
    for (int i = 0; i < n - 1; i++) {
      min = i;
      for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[min]) {
          min = j;
        }
      }
      
      if (min != i) {
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
      }
    }
    
    
    
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    
    return 0;
  }
