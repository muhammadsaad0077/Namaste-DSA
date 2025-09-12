#include<iostream>
using namespace std;
#define maxSize 7

class Stack{
    private:
        int size;
        int arr[maxSize];

    public:
        Stack(){
            size = 0;
        }

        bool isFull(){
            if(size == maxSize){
                return true;
            }
            else{
                return false;
            }
        }

        bool isEmpty(){
            if(size == 0){
                return true;
            }
            else{
                return false;
            }
        }

        void push(int val){
            if(isFull()){
                cout<<"Array is full";
                return;
            }
            else{
                *(arr + size) = val;
                size++;
            }
        }

        int pop(){
            if(isEmpty()){
                cout<<"Nothing to pop";
                return -1;
            }
            else{
                return *(arr + size--);
            }
        }

        void display(){
            for(int i = 0; i < size; i++){
                cout<<*(arr + i)<<" ";
            }
        }



};

int main(){
    Stack s;
    s.push(5);
    s.push(7);
    s.push(8);
   
    
    

    s.display();
}