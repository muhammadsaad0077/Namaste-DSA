#include <iostream>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int** goldbach_pairs(int* even_numbers, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int num = *(even_numbers + i);
        for (int a = 2; a <= num / 2; a++) {
            int b = num - a;
            if (isPrime(a) && isPrime(b)) {
                count++;
            }
        }
    }

    int** result = new int*[count + 1];
    for (int i = 0; i < count + 1; i++) {
        result[i] = new int[2];
    }

    int idx = 0;
    for (int i = 0; i < n; i++) {
        int num = *(even_numbers + i);
        for (int a = 2; a <= num / 2; a++) {
            int b = num - a;
            if (isPrime(a) && isPrime(b)) {
                result[idx][0] = a;
                result[idx][1] = b;
                idx++;
            }
        }
    }

    result[idx][0] = -1;
    result[idx][1] = -1;

    return result;
}

int main() {
    int cap = 100;
    int* arr = new int[cap];
    int n = 0, x;
    cout<<"24P-3077"<<endl;
    while (cin>>x && x != -1) {
        *(arr + n) = x;
         n++;
    }

    int** res = goldbach_pairs(arr, n);

    for (int i = 0; ; i++) {
        if (res[i][0] == -1 && res[i][1] == -1) {
            cout << "(-1,-1)" << endl;
            delete[] res[i];
            break;
        }
        cout<<"("<<res[i][0]<<", "<<res[i][1]<<") ";
        delete[] res[i];
    }

    delete[] res;
    delete[] arr;
    return 0;
}
