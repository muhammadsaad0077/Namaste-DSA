// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next, *prev;
        
        Node(int val){
            data = val;
            next = prev = NULL;
        }
};

class DoublyLinkedList{
    private:
        int size;
        Node* head, *tail;
        
    public:
        DoublyLinkedList(){
            head=tail= NULL;
            size = 0;
        }
        
        void add(int val){
            Node* newNode = new Node(val);
            
            if(head == NULL){
                head = tail = newNode;
            }
            else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
                
            }
            size++;
        }
        
        void remove(int index){
            if(index < 0 || index >= size){
                cout<<"Invalid index";
                return;
            }
            else if(index == 0 && size > 1){
                Node* temp = head;
                head = head->next;
                head->prev = NULL;
                delete temp;
            }
            else if(index == 0){
                delete head;
                head = tail = NULL;
            }
            else if(index == size - 1){
                Node* temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                
                delete temp;
            }
            else{
                Node *prevNode = NULL, *current = head, *temp;
                
                for(int i = 0; i < index; i++){
                    prevNode = current;
                    current = current->next;
                }
                
                temp = current->next;
                prevNode->next = temp;
                temp->prev = prevNode;
                
                delete current;
            }
            size--;
        }
        
        void display(){
            Node* temp = tail;
            
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->prev;
            }
        }
};

int main() {
    DoublyLinkedList d;
    d.add(10);
    d.add(20);
    d.add(30);
    d.remove(2);
    d.display();

    return 0;
}