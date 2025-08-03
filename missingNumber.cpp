#include<iostream>
using namespace std;

int main(){
		int nums[6] = {0, 1, 2, 0, 3, 4};
		int size = 5;
		
        int totalSum = (size * (size + 1)) / 2, arrSum;

        for(int i = 0; i < 6; i++){
            arrSum += nums[i];
        }
        
        cout<<totalSum<<endl;
        cout<<arrSum;
}
