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

        void createFromArray(int arr[], int n){
            for(int i=0;i<n;i++){
                append(arr[i]);
            }
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

        void prepend(int val){
            Node* newNode = new Node(val);
            if(!head){
                head = tail = newNode;
                tail->next = head;
            }
            else{
                newNode->next = head;
                head = newNode;
                tail->next = head;
            }
            size++;
        }

        void addAtIndex(int index,int val){
            if(index<0 || index>size){
                cout<<"Invalid index"<<endl;
                return;
            }
            if(index==0){
                prepend(val);
                return;
            }
            if(index==size){
                append(val);
                return;
            }
            Node* newNode = new Node(val);
            Node* current = head;
            for(int i=0;i<index-1;i++){
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            size++;
        }

        void deleteVal(int val){
            if(!head) return;
            Node* current = head;
            Node* prev = tail;
            int count=0;
            do{
                if(current->data == val){
                    if(current==head){
                        head = head->next;
                        tail->next = head;
                    }
                    else if(current==tail){
                        tail = prev;
                        tail->next = head;
                    }
                    else{
                        prev->next = current->next;
                    }
                    delete current;
                    size--;
                    return;
                }
                prev = current;
                current = current->next;
                count++;
            }while(current!=head && count<=size);
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
};

int main(){
    int arr[5] = {3,1,2,5,8};
    cout<<"Original Array: ";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    Circular c;
    c.createFromArray(arr,5);
    c.display();

    c.append(9);
    c.addAtIndex(3,11);
    c.prepend(4);

    c.deleteVal(1);
    c.deleteVal(2);
    c.deleteVal(5);

    c.display();
}
