#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }
};

class LinearQueue {
    Node* front;
    Node* rear;

    public:
        LinearQueue(){
            front=rear= NULL;
        }

        void enqueue(int val) {
            Node* newNode = new Node(val);

            if(rear == NULL) {
                front = rear = newNode;
            }
            else{
                rear->next = newNode;
                rear = newNode;
            }
        }
        void dequeue() {
            if(front == NULL){
                cout<<"Queue is empty"<<endl;
                return;
            }

            Node* temp = front;
            front = front->next;

            if(front == NULL){
                rear = NULL;
            }

            delete temp;
        }

        void display(){
            if(front == NULL){
                cout<<"Queue is empty"<<endl;
                return;
            }
            Node* temp = front;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};

int main() {
    LinearQueue q;
    cout<<"Saad Bin Sharif"<<endl;
    cout<<"24p-3077"<<endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
