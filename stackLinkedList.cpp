#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }
};

class Stack{
    private:
        Node* head;
        int size, val;

    public:
        Stack(){
            head = NULL;
            size = 0, val = 0;
        }

        void push(int val){
            Node* newNode = new Node(val);

            if(head == NULL){
                head = newNode;
            }
            else{
                newNode->next = head;
                head = newNode;
            }

            size++;
        }

        bool isEmpty(){
            if(head == NULL){
                return true;
            }
            else{
                return false;
            }
        }

        int pop(){
            if(isEmpty()){
                cout<<"Nothing to remove";
                return -1;
            }
            else{
                Node* temp = head;
                head = head->next;
                val = temp->data;
                delete temp;
                size--;
                return val;
            }
        }

        void display(){
            Node* temp = head;

            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    
    s.display();
}