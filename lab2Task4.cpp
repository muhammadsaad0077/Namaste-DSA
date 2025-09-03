#include <iostream>
#include <cstdlib>
using namespace std;

void findTopSellingProduct(int* arr, int size) {
    int maxVal = *arr;
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > maxVal) {
            maxVal = *(arr + i);
            maxIndex = i;
        }
    }
    cout<<"Top Selling Product: Product "<<maxIndex + 1 <<" with " <<maxVal<<" sales"<<endl;
}

int findSecondBestSeller(int* arr, int size) {
    int first = -1, second = -1;
    for (int i = 0; i < size; i++) {
        if (first == -1 || *(arr + i) > *(arr + first)) {
            second = first;
            first = i;
        } else if ((second == -1 || *(arr + i) > *(arr + second)) && *(arr + i) != *(arr + first)) {
            second = i;
        }
    }
    return second;
}

void sortByPopularity(int* arr, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(arr + j) > *(arr + i)) {
                temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}

int main() {
    int n;
    cout<<"24P-3077"<<endl;
    cout<<"Enter inventory size: ";
    cin>>n;

    int* stock = new int[n];
    for (int i = 0; i < n; i++) {
        *(stock + i) = rand() % 100 + 1;
    }

    cout<<"Inventory: ";
    for (int i = 0; i < n; i++) {
        cout << *(stock + i) << " ";
    }
    cout<<endl;

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(stock + i);
    }
    double avg = sum / n;
    cout<<"Average Stock Level: "<< avg << endl;

    int lowCount = 0;
    cout<<"Critical Products: ";
    for (int i = 0; i < n; i++) {
        if (*(stock + i) < avg) {
            cout<< "Product "<<i + 1<<" ";
            lowCount++;
        }
    }
    cout<<endl;
    cout<<"Total Critical Products: "<<lowCount<<endl;

    findTopSellingProduct(stock, n);

    int second = findSecondBestSeller(stock, n);
    if (second != -1) {
        cout<<"Second Best Selling Product: Product "<< second + 1<<" with "<<*(stock + second)<<" sales"<<endl;
    } else {
        cout<<"No Second Best Selling Product"<<endl;
    }

    sortByPopularity(stock, n);
    cout<<"Products Sorted by Popularity: ";
    for (int i = 0; i < n; i++) {
        cout<<*(stock + i)<<" ";
    }
    cout<<endl;

    delete[] stock;
    return 0;
}
