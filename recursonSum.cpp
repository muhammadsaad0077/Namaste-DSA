#include<iostream>
using namespace std;
int totalSum(int n){
	if(n < 1) return 0;
	return n + totalSum(n-1);
}

int main(){
	int n = 4;
	cout<<totalSum(n);
}
