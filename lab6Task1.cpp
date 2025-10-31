#include<iostream>
using namespace std;

class Stack {
private:
    string items[100];
    int top;
public:
    Stack() {
        top=-1;
    }

    void push(string id) {
        top++;
        items[top]=id;
    }

    string pop() {
        string val=items[top];
        top--;
        return val;
    }

    string peek() {
        return items[top];
    }

    bool isEmpty() {
        return top==-1;
    }

    int getTop() {
        return top;
    }
};

int main() {
    Stack containers;
    Stack temp;
    int n;
    cout<<"Saad Bin Sharif"<<endl;
    cout<<"24P-3077"<<endl;
    cout<<"Enter number of containers to load: ";
    cin>>n;

    for(int i=0;i<n;i++){
        string id;
        cout<<"Enter container ID "<<i+1<<": ";
        cin>>id;
        containers.push(id);
    }

    string target;
    cout<<"Enter container ID to unload: ";
    cin>>target;

    int count=0;
    bool found=false;

    while(!containers.isEmpty()){
        if(containers.peek()==target){
            cout<<"Container "<<target<<" found at top and unloaded."<<endl;
            containers.pop();
            found=true;
            break;
        } else {
            cout<<"Temporarily removing container: "<<containers.peek()<<endl;
            temp.push(containers.pop());
            count++;
        }
    }

    if(!found){
        cout<<"Container "<<target<<" not found in stack."<<endl;
    } else {
        cout<<"Now placing back temporarily removed containers..."<<endl;
        while(!temp.isEmpty()){
            cout<<"Placing back container: "<<temp.peek()<<endl;
            containers.push(temp.pop());
        }
        cout<<"Total temporarily removed containers: "<<count<<endl;
    }

    return 0;
}
