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

class Circular{
    private:
        Node* head;
        Node* tail;
        int size;
    public:
        Circular(){
            head = tail = NULL;
            size = 0;
        }

        void append(int val){
            Node* newNode = new Node(val);
            if(!head){
                head = tail = newNode;
                tail->next = head;
            }
            else{
                tail->next = newNode;
                tail = newNode;
                tail->next = head;
            }
            size++;
        }

        void display(){
            if(!head) return;
            Node* temp = head;
            cout<<"Circular Linked List: ";
            do{
                cout<<temp->data<<" ";
                temp = temp->next;
            }while(temp!=head);
            cout<<endl;
        }

        void rotate(int k){
            if(!head || k<=0 || k>=size) return;
            for(int i=0;i<k;i++){
                head = head->next;
                tail = tail->next;
            }
        }
};

int main(){
    Circular c;
    c.append(5);
    c.append(3);
    c.append(1);
    c.append(8);
    c.append(6);
    c.append(4);
    c.append(2);

    cout<<"Original"<<endl;
    c.display();

    int k;
    cout<<"Enter number of elements to move: ";
    cin>>k;

    c.rotate(k);

    cout<<"After rotation"<<endl;
    c.display();
}
