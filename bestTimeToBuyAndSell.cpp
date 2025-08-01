#include<iostream>
using namespace std;

int main(){
	int arr[6] = {7,1,5,3,6,4};
	int min = arr[0], profit = 0;
	
	for(int i = 0; i < 6; i++){
		for(int j = i + 1; j < 6; j++){
			if(arr[j] - arr[i] > profit){
				profit = arr[j] - arr[i];
			}
		}
	}
	
	cout<<profit<<endl;
	
	// Optimal Solution
	
	profit = 0;
	
	for(int i = 0; i < 6; i++){
		if(arr[i] - min > profit){
			profit = arr[i] - min;
		}
		
		if(arr[i] < min){
			min = arr[i];
		}
	}
	
	cout<<profit;
	
	
	
}
