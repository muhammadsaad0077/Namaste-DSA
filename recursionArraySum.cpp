#include<iostream>
using namespace std;

int sum(int* arr, int size){
	if(size < 0) return 0;
	return arr[size] + sum(arr, size-1);
}
int main(){
	int arr[5] = {1, 2, 3, 5, 4};
	int size = 5;
	cout<<sum(arr, size-1);
}
