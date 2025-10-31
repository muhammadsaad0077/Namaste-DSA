#include<iostream>
using namespace std;

class Stack {
private:
    int items[100];
    int top;
    int size;
public:
    Stack(int s=100) {
        top=-1;
        size=s;
    }

    bool isFull() {
        return top==size-1;
    }

    bool isEmpty() {
        return top==-1;
    }

    void push(int value) {
        if(isFull()) {
            cout<<"Stack overflow"<<endl;
        } else {
            top++;
            items[top]=value;
        }
    }

    int pop() {
        if(isEmpty()) {
            cout<<"Stack underflow"<<endl;
            return -1;
        } else {
            int val=items[top];
            top--;
            return val;
        }
    }

    void display() {
        if(isEmpty()) {
            cout<<"Stack is empty"<<endl;
        } else {
            for(int i=top;i>=0;i--){
                cout<<items[i]<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    Stack A, B;
    int n;
    cout<<"Saad Bin Sharif"<<endl;
    cout<<"24P-3077"<<endl;
    cout<<"Enter number of elements for Stack A: ";
    cin>>n;

    for(int i=0;i<n;i++){
        int val;
        cout<<"Enter element "<<i+1<<": ";
        cin>>val;
        A.push(val);
    }

    cout<<"Transferring elements from Stack A to Stack B..."<<endl;

    while(!A.isEmpty()){
        int x=A.pop();
        B.push(x);
    }

    cout<<"Contents of Stack A after transfer: ";
    A.display();

    cout<<"Contents of Stack B after transfer: ";
    B.display();

    return 0;
}
