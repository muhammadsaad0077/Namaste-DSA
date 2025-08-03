#include<iostream>
using namespace std;

int main(){
	int nums[5] = {0,1,0,3,12};
	int count = 0;
	for(int i = 0; i < 5; i++){
		if(nums[i] != 0){
			swap(nums[i], nums[count]);
			count++;
		}
	}
	
	for(int i = 0; i < 5; i++){
		cout<<nums[i]<<endl;
	}
}
