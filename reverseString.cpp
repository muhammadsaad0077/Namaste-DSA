#include<iostream>
using namespace std;

int main(){
	char name[5] = {'s', 'a', 'a', 'd', 'i'};
	char temp;
	int left = 0;
	int right = sizeof(name) / sizeof(name[0]) - 1;
	
	while(left < right){
		temp = name[left];
		name[left] = name[right - left];
		name[right - left] = temp;
		left++;
		right--;
	}
	
	cout<<name;
}
