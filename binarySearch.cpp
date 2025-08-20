#include<iostream>
using namespace std;

int binary(int nums[], int target){
	int left = 0, right = 5 - 1, middle;
        while(right >= left){
        	middle = (left + right) / 2;
        	
            if(target == nums[middle]){
                return middle;
            }
            else if(target > nums[middle]){
                left = middle + 1;
                
            }
            else{
                right = middle - 1;
            }
        }
        return -1;
}
int main(){
	int nums[5] = {3, 4, 5, 6, 7};
	cout<<binary(nums, 4);
	
}
