#include<iostream>
using namespace std;

int oddSum(int arr[], int size){
	if(size < 0) return 0;
	bool isOdd = arr[size] % 2 != 0;
	return (isOdd ? arr[size] + oddSum(arr, size - 1): 0 + oddSum(arr, size - 1)); 
	
}
int main(){
	int arr[5] = {1, 3, 5, 2, 4};
	int size = sizeof(arr) / sizeof(arr[0]);
	cout<<oddSum(arr, size - 1);
}
