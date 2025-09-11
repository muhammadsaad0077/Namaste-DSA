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
                cout<<"You have joined the line. Your Token No is: "<<val<<endl;
                return;
            }
            else if(head == tail){
                head->next = newCustomer;
                tail = newCustomer;
                cout<<"You have joined the line. Your Token No is: "<<val<<endl;
                return;
            }
            else{
                tail->next = newCustomer;
                tail = newCustomer;
                cout<<"You have joined the line. Your Token No is: "<<val<<endl;
            }
        }

        void joinAtFront(){}

        void tokenAtSpecific(){

        }

        void cancelTheToken(){}

        void reverseTheLine(){

        }

        void searchToken(){}

        void displayToken(){
            Node* temp = head;

            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
};

int main(){
    int check = 0, choice = 0, rand = 0;
    CanteenList c;

    while(check){
        cout<<"\t\tWelcome to Canteen"<<endl<<endl;
        cout<<"1- Join the Line"<<endl;
        cout<<"2- Join at the Front"<<endl;
        cout<<"3- Take a token"<<endl;
        cout<<"4- Update the Token"<<endl;
        cout<<"5- Cancel the Token"<<endl;
        cout<<"6- Search Token"<<endl;
        cout<<"7- Display all Token"<<endl;
        cout<<"8- Reverse the Line"<<endl;
        cout<<"9- Exit the System"<<endl;

        cout<<"\nEnter your Choice: ";
        cin>>choice;

        if(choice < 0 || choice > 9 || choice >= 'A' && choice <= 'Z' || choice >= 'a' && choice <= 'z'){
            cout<<"Invalid Choice";
            return;
        }
        else{
            switch(choice){
                case 1:
                 c.joinTheLine(rand + 10);
                 break;

                case 2:
                 joinAtFront();
                 break;

                case 3:
                 tokenAtSpecific();
                 break;

                case 4:
                 updateToken();
                 break;

                case 5:
                 cancelTheToken();
                 break;

                case 6:
                 searchToken();
                 break;

                case 7:
                 displayToken();
                 break;

                case 8:
                 reverseTheLine();
                 break;

                case 9:
                 check++;
                 break;
            }
        }

    }
}