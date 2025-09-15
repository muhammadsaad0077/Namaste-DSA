#include <iostream>
using namespace std;

class Node{
    public:
        Node* next, *prev;
        int data;
        
        Node(int val){
            next = prev = NULL;
            data = val;
        }
};

class circularLinkedList{
    private:
        int size;
        Node* head, *tail;
        
    public:
        circularLinkedList(){
            head = tail = NULL;
            size = 0;
        }
        
        void addAtHead(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = tail = newNode;
                tail->next = head;
                head->prev = tail;
            }
            else if(head->next == NULL){
                newNode->next = head;
                tail = head;
                head = newNode;
                tail->next = head;
                head->prev = tail;
            }
            
            else{
                newNode->next = head;
                head = newNode;
                head->prev = tail;
                tail->next = head;
            }
            size++;
        }
        
        void addAtTail(int val){
            Node* newNode = new Node(val);
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
            head->prev = head;
            size++;
        }
        
        void remove(int index){
            Node* prev = NULL, *current = head;
            
            for(int i = 0; i < index; i++){
                prev = current;
                current = current->next;
            }
            
            prev->next = current->next;
            delete current;
            current = NULL;
        }
        
        void josephus(int m){
            Node* temp = head;
            int count = 0;
            for(int i = 0; i < size - 1; i++){
                while(count < m){
                    temp = temp->next;
                    count++;
                }
                remove(m+1);
                count = 0;
            }
        }
        
        void display(){
            Node* temp = head;
            
            while(temp->next != head){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<temp->data;
        }
};


int main() {
    circularLinkedList l;
    l.addAtHead(10);
    l.addAtTail(20);
    l.addAtTail(30);
    l.addAtTail(40);
    l.addAtTail(50);
    l.addAtTail(60);
    l.addAtTail(70);
    l.josephus(3);
    
    
    
    l.display();

    return 0;
}