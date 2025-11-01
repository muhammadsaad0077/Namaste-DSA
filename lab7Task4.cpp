#include<iostream>
using namespace std;

class Node{
    public:
    
    int orderId, requestAmountA, requestAmountB, requestAmountC;
    string status;
    Node* next;

    Node(int oID,int rAmountA,int rAmountB,int rAmountC){
        orderId = oID;
        requestAmountA = rAmountA;
        requestAmountB = rAmountB;
        requestAmountC = rAmountC;
        status = "";
    }
};

class Warehouse{
    public:
    
    Node* front, *rear;
    int itemA, itemB, itemC;

    Warehouse(){
        front = rear = NULL;
        itemA = 20;
        itemB = 30;
        itemC = 50;
    }

    void addOrder(int oID,int rAmountA,int rAmountB,int rAmountC){
        Node* newOrder = new Node(oID, rAmountA, rAmountB, rAmountC);

        if(!front){
            front = rear = newOrder;
        }
        else{
            rear->next = newOrder;
            rear = newOrder;
        }
    }

    void moveOrder(int oID){
        if(!front || front == rear) return;  

        Node* current = front;
        Node* prev = NULL;

        
        while(current && current->orderId != oID){
            prev = current;
            current = current->next;
        }

        if(!current) return; 

        
        if(current == rear) return;

        if(current == front)
            front = front->next;
        else
            prev->next = current->next;

        current->next = NULL;
        rear->next = current;
        rear = current;
}

    Node* removeOrder(){
        if(!front){
            return NULL;
        }
        else{
            Node* temp = front;
            front = front->next;

            if(!front){
                rear = NULL;
            }

            return temp;
        }
    }

    void completeOrder(){
    Node* order;
    int fulfilled = 0, deferred = 0, cancelled = 0;

    while((order = removeOrder()) != NULL){
        if(order->status == "deferred" && 
          ((order->requestAmountA > itemA) || (order->requestAmountB > itemB) || (order->requestAmountC > itemC))){
            order->status = "cancelled";
            cancelled++;
        }
        else if((order->requestAmountA > itemA) || (order->requestAmountB > itemB) || (order->requestAmountC > itemC)){
            order->status = "deferred";
            this->moveOrder(order->orderId);
            deferred++;
        }
        else{
            order->status = "fulfilled";
            fulfilled++;
            itemA -= order->requestAmountA;
            itemB -= order->requestAmountB;
            itemC -= order->requestAmountC; 
        }

        cout<<"\n--- Summary ---"<<endl;
        cout<<"Order ID: "<<order->orderId<<endl;
        cout<<"RequestAmountA: "<<order->requestAmountA<<endl;
        cout<<"RequestAmountB: "<<order->requestAmountB<<endl;
        cout<<"RequestAmountC: "<<order->requestAmountC<<endl;
        cout<<"Order Status: "<<order->status<<endl;

        if(order->status == "deferred" || order->status == "cancelled"){
            cout<<"Item A Available: "<<itemA<<endl;
            cout<<"Item B Available: "<<itemB<<endl;
            cout<<"Item C Available: "<<itemC<<endl;
        }
    }

    cout<<"\n=== Final Summary ==="<<endl;
    cout<<"Total Deferred Orders: "<<deferred<<endl;
    cout<<"Total Cancelled Orders: "<<cancelled<<endl;
    cout<<"Total Fulfilled Orders: "<<fulfilled<<endl;
}

};

int main(){
    Warehouse w;
    
    cout<<"Saad Bin Sharif"<<endl;
    cout<<"24p-3077"<<endl;
    w.addOrder(01, 3, 4, 4);
    w.addOrder(02, 2, 5, 2);
    w.addOrder(03, 1, 3, 4);
    w.addOrder(04, 20, 25, 30);
    w.addOrder(05, 15, 23, 24);

    w.completeOrder();
}