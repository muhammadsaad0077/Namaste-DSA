#include<iostream>
using namespace std;

void reverseSentence(char* arr, int size){
    for(int i = 0; i < size / 2; i++){
        swap(arr[i], arr[size - 1 - i]);
    }
}

void reverseWordHelper(char* arr, int start, int end){
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void reverseWord(char* arr, int size){
    int start = 0;

    for(int i = 0; i <= size; i++){  
        if(arr[i] == ' ' || i == size){
            reverseWordHelper(arr, start, i - 1);
            start = i + 1;
        }
    }
}

void upperLowerCaseWords(char* arr, int size){
    for(int i = 0; i < size; i++){
        if((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z')){
            if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u' ||
               arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U'){
                if(arr[i] >= 'a' && arr[i] <= 'z'){
                    arr[i] -= 32;
                }
            }
            else{
                if(arr[i] >= 'A' && arr[i] <= 'Z'){
                    arr[i] += 32;
                }
            }
        }
    }
}

void removeSpaces(char* arr, int &size){
    int j = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] != ' '){
            arr[j++] = arr[i];
        }
    }
    size = j; 
    arr[size] = '\0'; 
}

void displayArray(char* arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i];
    }
    cout << endl;
}

int main(){
    char arr[] = "Hello World";  
    int size = 0;
    while(arr[size] != '\0') size++; 

    cout<<"24P-3077"<<endl;
    reverseSentence(arr, size);
    reverseWord(arr, size);
    upperLowerCaseWords(arr, size);
    removeSpaces(arr, size);
    displayArray(arr, size);
}
