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
        
        void add(int val){
            Node* newNode = new Node(val);
            if(!head){
                head = tail = newNode;
                tail->next = head;
                head->prev = tail;
            }
            else{
                tail->next = newNode;
                head->prev = newNode;
                newNode->next = head;
                newNode->prev = tail;
                tail = newNode;
            }
            size++;
        }
        
        void remove(int index){
            Node* prev = NULL, *current = head, *temp;
            
            if(index == 0){
                temp = head;
                head = head->next;
                tail->next = head;
                head->prev = tail;
                delete temp;
                size--;
            }
            else if(size == 2 && index == 1){
                temp = head->next;
                tail = head;
                tail->next = head;
                head->prev = tail;
                delete temp;
                size--;
            }
            else if(index == size - 1){
                for(int i = 0; i < size; i++){
                    prev = current;
                    current = current->next;
                }
                tail = prev;
                tail->next = head;
                head->prev = tail;
                delete current;
                size--;
            }
            else{
                for(int i = 0; i < index; i++){
                    prev = current;
                    current = current->next;
                }
            
                prev->next = current->next;
                delete current;
                size--;
            }
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
    l.add(10);
    l.add(20);
    l.add(30);
    l.add(40);
    l.add(50);
    l.add(60);
    l.add(70);    
    l.remove(0);
    
    l.display();

    return 0;
}