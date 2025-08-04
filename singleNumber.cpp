#include<iostream>
using namespace std;

int main(){
	int nums[5] = {1, 2, 1, 2, 3};
	int single = 0;
	
	for(int i = 0; i < 5; i++){
		single = single ^ nums[i];
	}
	
	cout<<single;
}
