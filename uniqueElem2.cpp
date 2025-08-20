#include<iostream>
#include <unordered_map>
using namespace std;

int uniqueElem(int arr[], int size){
	int counter = 0;
	unordered_map<int, int> occurences;
	
	for(int i = 0; i < size; i++){
		occurences[arr[i]]++;
	}
	
	for(auto x: occurences){
		if(x.second == 1){
			counter++;
		}
	}
	return counter;
}

int main(){
	int arr[] = {1, 1, 2, 2, 3, 3, 4};
	int size = sizeof(arr) / sizeof(int);
	
	cout<<uniqueElem(arr, size);
}
