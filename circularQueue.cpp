// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class CircularQueue{
    public:
        int front, rear, len, size;
        int* arr;
        
        CircularQueue(int s){
            size = s;
            arr = new int[size];
            len = 0;
            front = rear = -1;
        }
        
        void enqueue(int val){
            if(len == size){
                cout<<"FULL queue"<<endl;
                return;
            }
            else{
                if(front == -1){
                    front = 0;
                }
                rear = (rear + 1) % size;
                arr[rear] = val;
                len++;
            }
        }
        
        int dequeue(){
            if(len == 0){
                cout<<"Nothing";
                return -1;
            }
            
            int temp = 0;
            temp = arr[front];
            front = (front + 1) % size;
            len--;
            
            if(len == 0){
                front = -1;
                rear = -1;
            }
            
            return temp;
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
c.display();

    
    
    
    

    return 0;
}