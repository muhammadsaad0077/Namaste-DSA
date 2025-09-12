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

class CanteenList{
    private:
        int size;
        Node* head, *tail;

    public:
        CanteenList(){
            size = 0;
            head = tail = NULL;
        }

        void joinTheLine(int val){
            Node* newCustomer = new Node(val);

            if(head == NULL){
                head = tail = newCustomer;
                cout<<"You have joined the line at the first. Your Token No is: "<<val<<endl;
            }
            else{
                tail->next = newCustomer;
                tail = newCustomer;
                cout<<"You have joined the line. Your Token No is: "<<val<<endl;
            }
            size++;
        }

        void joinAtFront(int val){
            if(head == NULL){
                this->joinTheLine(val);
            }
            else{
                Node* newCustomer = new Node(val);
                newCustomer->next = head;
                head = newCustomer;
                cout<<"You have joined the line at the front. Your Token No is: "<<val<<endl;
                size++;
            }
        }

        void tokenAtSpecific(){
            int pos, val;
            cout<<"Enter position to insert token (1-based): ";
            cin>>pos;
            cout<<"Enter token number: ";
            cin>>val;

            if(pos <= 1){  
                joinAtFront(val);
                return;
            }
            if(pos > size){  
                joinTheLine(val);
                return;
            }

            Node* newCustomer = new Node(val);
            Node* temp = head;

            for(int i = 1; i < pos-1; i++){
                temp = temp->next;
            }

            newCustomer->next = temp->next;
            temp->next = newCustomer;
            size++;

            cout<<"Token "<<val<<" inserted at position "<<pos<<endl;
        }

        void updateToken(){
            int pos, val;
            cout<<"Enter position to update: ";
            cin>>pos;
            cout<<"Enter new token number: ";
            cin>>val;

            if(pos < 1 || pos > size){
                cout<<"Invalid position!"<<endl;
                return;
            }

            Node* temp = head;
            for(int i = 1; i < pos; i++){
                temp = temp->next;
            }
            temp->data = val;

            cout<<"Token at position "<<pos<<" updated to "<<val<<endl;
        }

        void cancelTheToken(){
            int choice;
            cout<<"Cancel from: 1. Start  2. End  3. Specific Position: ";
            cin>>choice;

            if(head == NULL){
                cout<<"No tokens in line!"<<endl;
                return;
            }

            if(choice == 1){ // cancel from start
                Node* temp = head;
                head = head->next;
                cout<<"Token "<<temp->data<<" canceled from start"<<endl;
                delete temp;
                size--;
                if(size == 0) tail = NULL;
            }
            else if(choice == 2){ // cancel from end
                if(head == tail){
                    cout<<"Token "<<head->data<<" canceled"<<endl;
                    delete head;
                    head = tail = NULL;
                    size = 0;
                    return;
                }
                Node* temp = head;
                while(temp->next != tail){
                    temp = temp->next;
                }
                cout<<"Token "<<tail->data<<" canceled from end"<<endl;
                delete tail;
                tail = temp;
                tail->next = NULL;
                size--;
            }
            else if(choice == 3){ // cancel at specific pos
                int pos;
                cout<<"Enter position to cancel: ";
                cin>>pos;
                if(pos < 1 || pos > size){
                    cout<<"Invalid position!"<<endl;
                    return;
                }
                if(pos == 1){
                    cancelTheToken(); // reuse logic
                    return;
                }
                Node* temp = head;
                for(int i = 1; i < pos-1; i++){
                    temp = temp->next;
                }
                Node* toDelete = temp->next;
                temp->next = toDelete->next;
                if(toDelete == tail) tail = temp;
                cout<<"Token "<<toDelete->data<<" canceled from position "<<pos<<endl;
                delete toDelete;
                size--;
            }
        }

        void searchToken(){
            int val;
            cout<<"Enter token number to search: ";
            cin>>val;

            Node* temp = head;
            int pos = 1;
            while(temp){
                if(temp->data == val){
                    cout<<"Token "<<val<<" found at position "<<pos<<endl;
                    return;
                }
                temp = temp->next;
                pos++;
            }
            cout<<"Token "<<val<<" not found!"<<endl;
        }

        void displayToken(){
            if(head == NULL){
                cout<<"No tokens in line!"<<endl;
                return;
            }

            Node* temp = head;
            cout<<"Current Line: ";
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

        void reverseTheLine(){
            Node* prev = NULL, *curr = head, *next = NULL;
            tail = head;
            while(curr){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
            cout<<"Line reversed successfully!"<<endl;
        }
};

int main(){
    int check = 1, choice = 0, rand = 1;
    CanteenList c;

    while(check){
        cout<<"\n\t\tWelcome to Canteen"<<endl<<endl;
        cout<<"1- Join the Line"<<endl;
        cout<<"2- Join at the Front"<<endl;
        cout<<"3- Take a token at Specific Position"<<endl;
        cout<<"4- Update the Token"<<endl;
        cout<<"5- Cancel the Token"<<endl;
        cout<<"6- Search Token"<<endl;
        cout<<"7- Display all Tokens"<<endl;
        cout<<"8- Reverse the Line"<<endl;
        cout<<"9- Exit the System"<<endl;

        cout<<"\nEnter your Choice: ";
        cin>>choice;

        switch(choice){
            case 1: c.joinTheLine(rand++); break;
            case 2: c.joinAtFront(50); break;
            case 3: c.tokenAtSpecific(); break;
            case 4: c.updateToken(); break;
            case 5: c.cancelTheToken(); break;
            case 6: c.searchToken(); break;
            case 7: c.displayToken(); break;
            case 8: c.reverseTheLine(); break;
            case 9: check = 0; break;
            default: cout<<"Invalid Choice"<<endl;
        }
    }
}
