#include<iostream>
using namespace std;
int uniqueElem(int arr[], int size){
	int counter = 0;
	bool check;
	for(int i = 0; i < size; i++){
		check = true;
		for(int j = 0; j < size; j++){
			if(i == j){
				continue;
			}
			else if(arr[i] == arr[j]){
				check = false;
				break;
			}
		}
		if(check){
			counter++;
		}
		
		
	}
	return counter;
}

int main(){
	int arr[] = {1,1,2,2,3,3,4};
	int size = sizeof(arr) / sizeof(int);
	
	cout<<uniqueElem(arr, size);
	
	
	
	
}
