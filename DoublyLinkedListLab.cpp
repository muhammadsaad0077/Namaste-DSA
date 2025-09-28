#include<iostream>
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

class Doubly{
    private:
        Node* head, *tail;
        int size;

    public:
        Doubly(){
            head = tail = NULL;
            size = 0;
        }

        void append(int val){
            Node* newNode = new Node(val);

            if(head == NULL){
                head = tail = newNode;
                cout<<"Node is added at Head"<<endl;
            }
            else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
                cout<<"Node is added at Tail"<<endl; 
            }
            size++;
        }

        void prepend(int val){
            if(head == NULL){
                this->append(val);
            }
            else{
                Node* newNode = new Node(val);
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
                size++;
                cout<<"Node is prepended at Head"<<endl;
            }
        }
        
        void addAtIndex(int index, int val){
            if(index < 0 || index > size){
                cout<<"Invalid index"<<endl;
                return;
            }
            else if(index == 0){
                this->prepend(val);
            }
            else if(index == size){
                this->append(val);
            }
            else{
                Node* prevNode, *current = head, *newNode = new Node(val);

                for(int i = 0; i < index; i++){
                    prevNode = current;
                    current = current->next;
                }

                prevNode->next = newNode;
                newNode->prev = prevNode;
                newNode->next = current;
                current->prev = newNode;
                size++;
                cout<<"Node added at index"<<endl;
            }
        }

        void deleteAtHead(){
            if(!head){
                cout<<"List is empty"<<endl;
                return;
            }
            if(head == tail){ 
                delete head;
                head = tail = NULL;
            } else {
                Node* temp = head;
                head = head->next;
                head->prev = NULL;
                delete temp;
            }
            size--;
            cout<<"Node deleted at Head"<<endl;
        }

        void deleteAtTail(){
            if(!tail){
                cout<<"List is empty"<<endl;
                return;
            }
            if(head == tail){ 
                delete tail;
                head = tail = NULL;
            } else {
                Node* temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
            }
            size--;
            cout<<"Node deleted at Tail"<<endl;
        }

        void deleteAtIndex(int index){
            if(!head || index < 0 || index >= size){
                cout<<"Invalid Index"<<endl;
                return;
            }
            else if(index == 0){
                this->deleteAtHead();
            }
            else if(index == size - 1){
                this->deleteAtTail();
            }
            else{
                Node* prevNode = NULL, *current = head;

                for(int i = 0; i < index; i++){
                    prevNode = current;
                    current = current->next;
                }

                prevNode->next = current->next;
                current->next->prev = prevNode;

                delete current;
                size--;
                cout<<"Node deleted at index"<<endl;
            }
        }

        void search(int val){
            Node* temp = head;
            int index = 0;
            while(temp){
                if(temp->data == val){
                    cout<<"Value "<<val<<" found at index "<<index<<endl;
                    return;
                }
                temp = temp->next;
                index++;
            }
            cout<<"Value "<<val<<" not found"<<endl;
        }

        void reverse(){
            if(!head) return;

            Node* current = head;
            Node* temp = NULL;

            while(current){
                temp = current->prev;
                current->prev = current->next;
                current->next = temp;
                current = current->prev;
            }

            if(temp){
                head = temp->prev; 
            }

            Node* t = head;
            head = tail;
            tail = t;

            cout<<"List reversed"<<endl;
        }

        void display(){
            Node* temp = head;

            cout<<"Original Linked List: "<<endl;
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }

            temp = tail;
            cout<<"\nReverse Linked List: "<<endl;
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->prev;
            }
            cout<<endl;
        }
};

int main(){
    Doubly d;
    d.append(10);
    d.append(20);
    d.append(30);
    d.append(40);
    d.display();

    d.search(20);
    d.search(100);

    d.addAtIndex(2, 25);
    d.display();

    d.deleteAtIndex(0);
    d.deleteAtIndex(3);
    d.display();

    d.reverse();
    d.display();
}
