#include<iostream>
using namespace std;

void secondLargest(int* arr, int size){
    int* max = &arr[0];
    int* secondMax = &arr[1];

    *max = *(arr + 0);
    *secondMax = *(arr + 1);

    if(*secondMax > *max){
        swap(*max, *secondMax);
    }

    for(int i = 0; i < size; i++){
        if(*(arr + i) > *max){
            *secondMax = *max;
            *max = *(arr + i);
        }
        else if(*(arr + i) > *secondMax && *(arr + i) < *max){
            *secondMax = *(arr + i);
        }
    }

    cout<<"Second Largest: "<<*secondMax<<endl;
}

void countEvenOdd(int* arr, int size, int*& oddCountPtr, int*& evenCountPtr){
    for(int i = 0; i < size; i++){
        if(*(arr + i) % 2 != 0){
            *oddCountPtr = *oddCountPtr + 1;
        }
        else{
            *evenCountPtr = *evenCountPtr + 1;
        }
    }

    cout<<"Odd Count: "<<*oddCountPtr<<endl;
    cout<<"Even Count: "<<*evenCountPtr<<endl;
}

bool isPrime(int n){
    bool isPrimeNumber = true;

    for(int i = 2; i < n; i++){
        if(n % i == 0){
            isPrimeNumber = false;
            break;
        }
    }

    return isPrimeNumber;
}

int sumOfPrimes(int* arr, int size){
    int sum = 0;

    for(int i = 0; i < size; i++){
        if(*(arr + i) <= 1) continue;

        if(isPrime(*(arr + i))){
            sum += *(arr + i);
        }
    }

    return sum;
}

void rotateArray(int* arr, int size, int k){
    int temp;
    for(int i = 0; i < k; i++){
        if(i == 0){
            swap(*(arr+i), *(arr + size - k));
        }
        else if(i == 1){
            swap(*(arr+i), *(arr + size - k + 1));
        }
        else{
            swap(*(arr+i), *(arr + i - k));
        }
    }

    cout<<"Rotated Array: ";
    for(int i = 0; i < size; i++){
        cout<<*(arr+i)<<endl;
    }

}

int main(){
    int size = 5;
    cout<<"Enter size of array: ";
    cin>>size;
    int arr[size] = {3, 4, 7, 8, 11};

    cout<<"Enter Values: ";

    for(int i = 0; i < size; i++){
        cin>>*(arr + i);
    }
    
    int oddCount = 0, evenCount = 0;
    int* oddCountPtr = &oddCount;
    int* evenCountPtr = &evenCount;
    cout<<"24P-3077"<<endl;
    
    secondLargest(arr, size);
    countEvenOdd(arr, size, oddCountPtr, evenCountPtr);
    cout<<"Sum of Prime Numbers: "<<sumOfPrimes(arr, size)<<endl;
    rotateArray(arr, size, 2);
    
}