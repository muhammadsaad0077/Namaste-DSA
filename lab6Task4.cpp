#include<iostream>
using namespace std;

class Node {
public:
    string regNo;
    string arrivalTime;
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

    void push(string regNo,string time) {
        Node* newNode=new Node;
        newNode->regNo=regNo;
        newNode->arrivalTime=time;
        newNode->next=top;
        top=newNode;
        cout<<"Car "<<regNo<<" arrived at "<<time<<" and parked."<<endl;
    }

    Node* pop() {
        if(isEmpty()) {
            cout<<"No cars in parking lane."<<endl;
            return NULL;
        } else {
            Node* temp=top;
            top=top->next;
            return temp;
        }
    }

    string peekRegNo() {
        if(isEmpty()) {
            return "";
        } else {
            return top->regNo;
        }
    }

    void display() {
        if(isEmpty()) {
            cout<<"Parking lane is empty."<<endl;
        } else {
            cout<<"Current parking order (top = nearest to exit):"<<endl;
            Node* temp=top;
            while(temp!=NULL){
                cout<<"Car "<<temp->regNo<<" (Arrival Time: "<<temp->arrivalTime<<")"<<endl;
                temp=temp->next;
            }
        }
    }
};

int main() {
    Stack parking;
    Stack temp;
    int choice;
    cout<<"Saad Bin Sharif"<<endl;
    cout<<"24P-3077"<<endl;
    
    while(true){
        cout<<endl;
        cout<<"1. Car Arrival"<<endl;
        cout<<"2. Car Departure"<<endl;
        cout<<"3. Display Parking Order"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice==1){
            string regNo,time;
            cout<<"Enter car registration number: ";
            cin>>regNo;
            cout<<"Enter arrival time: ";
            cin>>time;
            parking.push(regNo,time);
        }

        else if(choice==2){
            if(parking.isEmpty()){
                cout<<"Parking lane is empty."<<endl;
                continue;
            }
            string regNo;
            cout<<"Enter registration number of car to leave: ";
            cin>>regNo;

            bool found=false;
            while(!parking.isEmpty()){
                if(parking.peekRegNo()==regNo){
                    Node* leavingCar=parking.pop();
                    cout<<"Car "<<leavingCar->regNo<<" has left the parking."<<endl;
                    delete leavingCar;
                    found=true;
                    break;
                } else {
                    temp.push(parking.pop()->regNo,"temp");
                }
            }

            if(!found){
                cout<<"Car "<<regNo<<" not found in parking lane."<<endl;
            }

            while(!temp.isEmpty()){
                Node* moveBack=temp.pop();
                parking.push(moveBack->regNo,moveBack->arrivalTime);
                delete moveBack;
            }

            parking.display();
        }

        else if(choice==3){
            parking.display();
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
