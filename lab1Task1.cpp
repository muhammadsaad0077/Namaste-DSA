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

void countElemFrequency(int* arr, int size, int* unique, int* freq, int &uniqueCount){
    bool checked[size] = {false};
    int frequency = 0;
    uniqueCount = 0;
    
    for(int i = 0; i < size; i++){
        if(checked[i]){
            continue;
        }
        
        else{
        
        frequency = 1;
            
            for(int j = i + 1; j < size; j++){
                if(arr[i] == arr[j]){
                    frequency++;
                    checked[j] = true;
                }
            }
            
            unique[uniqueCount] = arr[i];
            freq[uniqueCount] = frequency;
            uniqueCount++;
        }
    }
}

void frequencySorted(int* unique, int* freq, int uniqueCount){
    for(int i = 0; i < uniqueCount - 1; i++){
        for(int j = 0; j < uniqueCount - 1 - i; j++){
            if(freq[j] == freq[j+1]){
                if(unique[j] > unique[j+1]){
                    swap(unique[j], unique[j+1]);
                    swap(freq[j], freq[j+1]);
                }
            }
            else if(freq[j] < freq[j+1]){
                swap(unique[j], unique[j+1]);
                swap(freq[j], freq[j+1]);
            }
        }
    }
}

void displayArr(int* arr, int* unique, int* freq, int size, int uniqueCount){
    cout<<"Frequences:"<<endl;
    for(int i = 0; i < uniqueCount; i++){
        cout<<unique[i]<<" -> "<<freq[i]<<" times"<<endl;
    }
}

int main() {
    int arr[] = {7, 3, 5, 7, 3};
    int size = sizeof(arr) / sizeof(int);
    int unique[size], freq[size];
    int uniqueCount;
    
    countElemFrequency(arr, size, unique, freq, uniqueCount);
    
    frequencySorted(unique, freq, uniqueCount);
    
    displayArr(arr, unique, freq, size, uniqueCount);
}
