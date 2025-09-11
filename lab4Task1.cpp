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

class LinkedList{
    private:
        Node* head, *tail;
        int size;

    public:
        LinkedList(){
            head = tail = NULL;
            size = 0;
        }

        void append(int val){
            Node* newNode = new Node(val);

            if(head == NULL){
                head = tail = newNode;
                cout<<"Node is appended at Head"<<endl;
size++;
return;    
            }
            else{
                Node* temp = head;

                while(temp->next != NULL){
                    temp = temp->next;
                }

                temp->next = newNode;
                tail = newNode;
                cout<<"Node is appended at Tail"<<endl;
size++;
return;
            }
           
        }

        void addAtIndex(int index, int val){
            if(index < 0 || index > size){
                cout<<"Invalid Index"<<endl;
                return;
            }
            else if(head == NULL){
                this->append(val);
                return;
            }
            else if(index == 0){
                this->prepend(val);
                return;
            }
            else if(index == size){
                this->append(val);
                return;
            }
            else{
                Node* newNode = new Node(val);
                Node* prev = NULL, *current = head;
                int i = 0;

                while(i < index){
                    prev = current;
                    current = current->next;
                    i++;
                }

                prev->next = newNode;
                newNode->next = current;
                size++;
                cout<<"Node added at "<<index<<endl;
            }

        }

        void prepend(int val){
            if(head == NULL){
                this->append(val);
            }
            else{
                Node* newNode = new Node(val);
                newNode->next = head;
                head = newNode;
                cout<<"Node is prepended at Head"<<endl;
                size++;
            }
        }

        void deleteAtTail(){
            if(head == NULL){
                cout<<"Nothing to delete"<<endl;
                return;
            }
            else{
                Node* current = head, *prev = NULL;

                while(current->next != NULL){
                    prev = current;
                    current = current->next;
                }

                prev->next = NULL;
                tail = prev;
                delete current;
                cout<<"Node deleted at Tail"<<endl;
                size--;
            }
        }

        void deleteAtHead(){
            if(head == NULL){
                cout<<"Nothing to delete"<<endl;
                return;
            }
            else{
                Node* temp = head;
                head = head->next;
                delete temp;

                cout<<"Node deleted at Head"<<endl;
                size--;
            }
        }

        void deleteAtIndex(int index){
            if(index < 0 || index > size){
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
                Node* prev = NULL, *current = head;
                int i = 0;

                while(i < index){
                    prev = current;
                    current = current->next;
                    i++;
                }

                prev->next = current->next;

                delete current;
                cout<<"Node deleted at "<<index<<endl;
                size--;
            }

        }

        void searchElement(int val){
            Node* temp = head;
            bool find = false;

            while(temp->next != NULL){
                if(temp->data == val){
                    find = true;
                    break;
                }
            }

            if(find){
                cout<<"Element Found"<<endl;
            }
            else{
                cout<<"Element Not Found"<<endl;
            }
        }

        void display(){
            if(head == NULL){
                cout<<"Nothing to display"<<endl;
            }
            else{
                Node *temp = head;

                while(temp != NULL){
                    cout<<temp->data<<" ";
                    temp = temp->next;
                }
            }

        }
        
        void updateAtPosition(int position, int newVal){
            if(position < 0 || position > size){
                cout<<"Invalid Index"<<endl;
                return;
            }
            else{
                Node* current = head;
                int count = 0;
                
                while(current){
                    if(count == position){
                        current->data = newVal;
                        cout<<"Value Updated At "<<position<<endl;
                        break;
                    }
                    else{
                        current = current->next;
                        count++;
                    }
                }
            }
        }
       
        void reverseList(){
            Node* prev = NULL, *current = head, *temp;
            cout<<"Reverse Linked List: "<<endl;
            while(current){
                temp = current->next;
                current->next = prev;
                prev = current;
                current = temp;
            }
            head = prev;
        }



};

int main()
{

    LinkedList l1;
    l1.append(10);
    l1.append(20);
    l1.append(30);
    l1.updateAtPosition(1, 100);
    l1.display();
   
} 