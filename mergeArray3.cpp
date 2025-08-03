#include<iostream>
using namespace std;

int main(){
	int m = 3, n = 3;
	int nums1[m+n] = {2, 5, 6, 0, 0, 0};
	int nums2[n] = {1, 2, 3};
	int p1 = m - 1, p2 = n - 1;
	
	for(int i = 0; i < m+n; i++){
		if(p2 < 0 || p1 < 0){
				break;
			}
		if(nums1[p1] < nums2[p2]){
			
				nums1[m+n-1-i] = nums2[p2];
				p2--;
			
		}
		else{
			nums1[m+n-1-i] = nums1[p1];
			p1--;
		}
	}
	
	for(int i = 0; i < m+n;i++){
		cout<<nums1[i]<<endl;
	}
}
