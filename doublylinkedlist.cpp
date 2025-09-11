#include <iostream>
using namespace std;

class Node{
    public:
        Node* next, *prev;
        int data;
        
        Node(int val){
            next=prev=NULL;
            data = val;
        }
};

class LinkedList{
    private:
        Node* head, *current;
        int size;
        
    public:
        LinkedList(){
            head=current=NULL;
            size = 0;
        }
        
        void addAtHead(int val){
            Node* newNode = new Node(val);
            
            if(head == NULL){
                head = current = newNode;
            }
            else{
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            size++;
        }
        
        void addAtTail(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = current = newNode;
            }
            else{
                current->next = newNode;
                newNode->prev = current;
                current = newNode;
            }
            size++;
        }
        
        void deleteNode(){
            if(head == NULL){
                cout<<"Nothing to delete";
                return;
            }
            else if(head->next == NULL){
                delete head;
                head = current = NULL;
                
            }
            else{
                Node* temp = current;
                current = current->prev;
                current->next = NULL;
                delete temp;
                size--;
            }
        }
        
        
        
        void displayList(){
            Node* temp = head;
            
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
        
    
};

int main() {
    LinkedList l1;
    l1.addAtHead(10);
    l1.addAtTail(20);
    l1.addAtTail(30);
    l1.addAtTail(40);
    l1.deleteNode();
    l1.deleteNode();
    l1.deleteNode();
    l1.deleteNode();
    l1.displayList();

    return 0;
}