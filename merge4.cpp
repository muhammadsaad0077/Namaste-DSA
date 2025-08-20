#include<iostream>
#include<vector>
using namespace std;

vector<int> slicing(vector<int>& arr,
                    int X, int Y)
{

    // Starting and Ending iterators
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y + 1;

    // To store the sliced vector
    vector<int> result(Y - X + 1);

    // Copy vector using copy function()
    copy(start, end, result.begin());

    // Return the final sliced vector
    return result;
}

vector<int> merge(vector<int> arr, vector<int> arr2){
	vector<int> res;
	int i = 0, j = 0;
	
	while(i < arr.size() && j < arr2.size()){
		if(arr[i] < arr2[j]){
			res.push_back(arr[i]);
			i++;
		}
		else{
			res.push_back(arr2[j]);
			j++;
		}
	}
	
		while(i < arr.size()){
			res.push_back(arr[i]);
			i++;
		}
		while(j < arr2.size()){
			res.push_back(arr2[j]);
			j++;
		}
	
	return res;
}

vector<int> mergeSort(vector<int> arr){
	int mid;
	vector<int> res;
	
	vector<int> left;
	vector<int> right;
	
	if(arr.size() <= 1) return arr;
	
	mid = arr.size() / 2;
	
	left = mergeSort(slicing(arr, 0, mid - 1));
	
	right = mergeSort(slicing(arr, mid, arr.size() - 1));
	
	return merge(left, right);	
}

int main(){
	vector<int> arr = {7, 5, 1, 4};
	vector<int> sorted;
	
	sorted = mergeSort(arr);
	
	for(int x: sorted){
		cout<<x<<" ";
	}
	
	
}
