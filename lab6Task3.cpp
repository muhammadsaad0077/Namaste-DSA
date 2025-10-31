#include<iostream>
using namespace std;

class Node {
public:
    int id;
    string name;
    string severity;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top=NULL;
    }

    bool isEmpty() {
        return top==NULL;
    }

    void push(int id,string name,string severity) {
        Node* newNode=new Node;
        newNode->id=id;
        newNode->name=name;
        newNode->severity=severity;
        newNode->next=top;
        top=newNode;
        cout<<"Patient "<<name<<" added to emergency room."<<endl;
    }

    void pop() {
        if(isEmpty()) {
            cout<<"No patients waiting. Emergency room is empty."<<endl;
        } else {
            Node* temp=top;
            cout<<"Doctor is now attending patient: "<<top->name<<" (ID: "<<top->id<<", Severity: "<<top->severity<<")"<<endl;
            top=top->next;
            delete temp;
        }
    }

    void display() {
        if(isEmpty()) {
            cout<<"No patients currently waiting."<<endl;
        } else {
            cout<<"Patients currently waiting:"<<endl;
            Node* temp=top;
            while(temp!=NULL){
                cout<<"ID: "<<temp->id<<", Name: "<<temp->name<<", Severity: "<<temp->severity<<endl;
                temp=temp->next;
            }
        }
    }
};

int main() {
    Stack emergencyRoom;
    int choice;
    cout<<"Saad Bin Sharif"<<endl;
    cout<<"24P-3077"<<endl;

    while(true){
        cout<<endl;
        cout<<"1. Add new patient"<<endl;
        cout<<"2. Attend next patient"<<endl;
        cout<<"3. Display waiting patients"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice==1){
            int id;
            string name,severity;
            cout<<"Enter patient ID: ";
            cin>>id;
            cout<<"Enter patient name: ";
            cin>>name;
            cout<<"Enter severity level (Low/Medium/High): ";
            cin>>severity;
            emergencyRoom.push(id,name,severity);
        }
        else if(choice==2){
            emergencyRoom.pop();
        }
        else if(choice==3){
            emergencyRoom.display();
        }
        else if(choice==4){
            cout<<"Exiting program..."<<endl;
            break;
        }
        else{
            cout<<"Invalid choice. Try again."<<endl;
        }
    }

    return 0;
}
