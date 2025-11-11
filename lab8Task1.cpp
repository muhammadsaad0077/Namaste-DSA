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
                size++;
                return;
            }
           
        }

        void reverseList(Node* current){
            if(current == NULL){
                return;
            }
            else{
                reverseList(current->next);
                cout<<current->data<<" ";
            }
        }

        void callReverse(){
            Node* temp = head;
            reverseList(temp);
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

};

int main()
{

    LinkedList l1;
    cout<<"Saad Bin Sharif"<<endl;
    cout<<"24P-3077"<<endl;
    l1.append(10);
    l1.append(20);
    l1.append(30);
    l1.append(40);
    l1.append(50);
    l1.callReverse();
   
} 