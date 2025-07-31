#include<iostream>
using namespace std;

int main(){
    int arr[7] = {1, 2, 1, 3, 2, 4, 3};
    int val = 3;
    int count = 0;

    for(int i = 0; i < 7; i++){
        if(arr[i] != val){
        	arr[count] = arr[i];
            count++;
        }
    }

    for(int i = 0; i < 7; i++){
    	cout<<arr[i]<<endl;
	}
}
