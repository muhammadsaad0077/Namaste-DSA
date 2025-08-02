#include<iostream>
using namespace std;

int main(){
	int m = 3, n = 3, p1= 0, p2 = 0;
	int num1[m+n] = {1,2,3,0,0,0};
	int num2[n] = {2,5,6};
	int num3[m];
	
	for(int i = 0; i < m; i++){
		num3[i] = num1[i];
	}
	
	for(int i = 0; i < m+n; i++){
		if(p2 >= n || ( p1 < m && num3[p1] < num2[p2])){
			num1[i] = num3[p1];
			p1++;
		}
		else{
			num1[i] = num2[p2];
			p2++;
		}
	}
	
	for(int i = 0; i < m+n; i++){
		cout<<num1[i]<<endl;
	}
}
