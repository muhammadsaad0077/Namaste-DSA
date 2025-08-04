#include<iostream>
using namespace std;
void totalSum(int a, int n, int* sum){
	if(a > n) return;
	*sum += a;
	a++;
	totalSum(a, n, sum);
}

int main(){
	int n = 6;
	int sum = 0;
	
	totalSum(1, n, &sum);
	cout<<sum;
}
