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

        /*
        We start from the head and use a counter (count) to keep track of the current node index.
        If count == position, we update that node’s data with the new value. Otherwise, we keep moving forward.

        Head -> [10 | 0F] -> [20 | 0B] -> [30 | NULL]

        updateAtPosition(1, 99);

        First Iteration:

        Head -> [10 | 0F] -> [20 | 0B] -> [30 | NULL]


        Second Iteration:

        Head -> [10 | 0F] -> [99 | 0B] -> [30 | NULL]


        
        Head -> [10 | 0F] -> [99 | 0B] -> [30 | NULL]



        
        
        */
        
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

        /*
        
        Reverse Logic is working in  a way that we are using a prev Node type pointer which is intially NULL.
        As the program continue we are linking the nodes backward by storing the next node to the current in the
        temp, then making the previous as current's next, then pointing the prev to current and finally point current
        to temp and in the last pointing the head to previous.

Head ->[1, 0F] ->  [2, 0B]  ->  [3, NULL]

        First iteration:
        [1, NULL]  [2, B] -> [3, NULL]  

        Second Iteration:
        [1, NULL] <-- [2, 0F]   [3, NULL]

        Third Iteration:
        [1, NULL] <-- [2, 0F] <-- [3, 0B]  
        

        Head  -> [3, 0B]  --> [2, 0F]  -->  [1, NULL]
        
        */
       
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
    cout<<"24P-3077"<<endl;
    l1.append(10);
    l1.append(20);
    l1.append(30);
    l1.updateAtPosition(1, 100);
    l1.reverseList();
    l1.display();
   
} 