#include<iostream>
using namespace std;

int main(){
	int nums[6] = {1,0,1,1,0,1};
	int count = 0, max = 0;
	
	for(int i = 0; i < 6; i++){
		if(nums[i] == 1){
			count++;
		}
		else{
			max = count;
			count = 0;
		}
	} 
	
	cout<<max;
	

}
