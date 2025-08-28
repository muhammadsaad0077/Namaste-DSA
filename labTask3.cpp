#include<iostream>
using namespace std;

int main(){
    int rollNo = 10;
    int* teacher = &rollNo;
    int** classMonitor = &teacher;
    int*** principal = &classMonitor;

    cout<<"24p-3077"<<endl;
    cout<<"Roll No: "<<rollNo<<endl;
    cout<<"Roll No from Teacher: "<<*teacher<<endl;
    cout<<"Roll No from ClassMonitor: "<<**classMonitor<<endl;
    cout<<"Roll No from Principal: "<<***principal<<endl;
}