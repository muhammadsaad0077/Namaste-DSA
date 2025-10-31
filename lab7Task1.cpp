#include <iostream>
using namespace std;

class CircularQueue{
    public:
        int front, rear, len, size;
        int* arr;
        
        CircularQueue(int s){ // 3
            size = s;
            arr = new int[size]; // [ , ,  ]
            len = 0;
            front = rear = -1;
        }
        
        void enqueue(int val){  // 10  // 20  // 30    After dequeue then enqueue // 40
            if(len == size){  // false  // false  // false  // false
                cout<<"FULL queue"<<endl;
                return;
            }
            else{
                if(front == -1){
                    front = 0;
                }
                rear = (rear + 1) % size;  // -1 + 1 % 3  => 0 ,  0 + 1 % 3 => 1 ,   1 + 1 % 3 => 2,  After dequeue then enqueue -> 2 + 1 % 3 => 0
                arr[rear] = val;  // [10, 20, 30 ]  After dequeue then enqueue // [40, 20, 30]
                                  //  F       R                                    R    F
                len++; // 1  // 2   // 3                
                cout<<"Value Enqueued"<<endl;
            }
        }
        
        int dequeue(){
            if(len == 0){ // false
                cout<<"Nothing";
                return -1;
            }
            
            int temp = 0;
            temp = arr[front];  // temp = arr[0] => 10
            front = (front + 1) % size; // 0 + 1 % 3 => 1 -> Now front points to arr[1]
            len--; // 2
            
            if(len == 0){
                front = -1;
                rear = -1;
            }
            
            cout<<"Value Dequeued"<<endl;
            
            return temp; // 10
        }
        
        ~CircularQueue(){
            delete[] arr;
        }
        
        void display(){
            if(len == 0){
                cout<<"Nothing"<<endl;
                return;
            }  
                
            int count = 0, i = front;
            
            while(count < len){
                cout<<arr[i]<<" ";
                i = (i + 1) % size;
                count++;
            }
            
        }
};

int main() {
    CircularQueue c(3);
    c.enqueue(10);
    c.enqueue(20);
    c.enqueue(30);
    c.dequeue();
    c.enqueue(40);

    cout<<"Saad Bin Sharif"<<endl;
    cout<<"24p-3077"<<endl;

    c.display();

    
    
    
    

    return 0;
}