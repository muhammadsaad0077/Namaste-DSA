#include<iostream>
using namespace std;

int main(){
	
	int arr[8] = {1, 1, 2, 2, 2, 3, 4, 4};
	int x = 0;	
	
	for(int i = 0; i < 8; i++){
		if(arr[i] > arr[x]){
			x++;
			arr[x] = arr[i];
		}
	}
	
	for(int i = 0; i < 8; i++){
		cout<<arr[i]<<endl;
	}
	
	cout<<x+1;
}
