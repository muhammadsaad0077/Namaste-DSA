#include <iostream>
using namespace std;

int main() {
    int arr[5] = {4, 1, 3, 5, 2 };
    int temp, j;
    
    for(int i = 1; i < 5; i++){
        temp = arr[i];
        j = i - 1;
        
        while( j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = temp;
    }
    
    for(int i = 0; i < 5; i++){
        cout<<arr[i]<<endl;
    }
    

    return 0;
}
