#include<iostream>
using namespace std;

int main(){
	int m = 3, n = 3, size = m + n;
	int nums1[size] = {1, 2, 3, 0, 0, 0};
	int nums2[n] = {2, 5, 6};
	int temp = 0;
	
	for(int i = m; i < size; i++){
		nums1[i] = nums2[i - m];
	}
	
	for(int i = 0; i < size - 1; i++){
		for(int j = 0; j < size - 1 - i; j++){
			if(nums1[j] > nums1[j+1]){
				temp = nums1[j];
				nums1[j] = nums1[j+1];
				nums1[j+1] = temp;
			}
		}
	}
	
	for(int i = 0; i < size; i++){
		cout<<nums1[i]<<endl;
	}
}
