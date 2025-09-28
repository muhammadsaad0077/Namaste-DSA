#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = prev = NULL;
    }
};

class DoublyLinkedList{
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList(){
        head = tail = NULL;
    }

    void append(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->data;
            if(temp->next) cout<<" ⇔ ";
            temp = temp->next;
        }
        cout<<" ⇔ NULL"<<endl;
    }

    void stablePartitionEvenOdd(){
        if(!head || !head->next) return;

        Node* evenHead = NULL;
        Node* evenTail = NULL;
        Node* oddHead = NULL;
        Node* oddTail = NULL;

        Node* current = head;
        while(current){
            if(current->data % 2 == 0){
                if(!evenHead){
                    evenHead = evenTail = current;
                } else {
                    evenTail->next = current;
                    current->prev = evenTail;
                    evenTail = current;
                }
            } else {
                if(!oddHead){
                    oddHead = oddTail = current;
                } else {
                    oddTail->next = current;
                    current->prev = oddTail;
                    oddTail = current;
                }
            }
            current = current->next;
        }

        if(!evenHead || !oddHead) return;

        evenTail->next = oddHead;
        oddHead->prev = evenTail;
        oddTail->next = NULL;

        head = evenHead;
        tail = oddTail;
    }
};

int main(){
    DoublyLinkedList dll;
    dll.append(17);
    dll.append(15);
    dll.append(8);
    dll.append(12);
    dll.append(10);
    dll.append(5);
    dll.append(4);
    dll.append(1);
    dll.append(7);
    dll.append(6);

    cout<<"Original List:"<<endl;
    dll.display();

    dll.stablePartitionEvenOdd();

    cout<<"Modified List:"<<endl;
    dll.display();
}
