// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

#define maxSize 7

class ListArray{
    private:
        int arr[maxSize + 1];
        int size;
        int* current;
        
    public:
        ListArray(): size(0), current(nullptr){}
        
        bool isFull(){
            if(size == maxSize){
                return true;
            }
            else{
                return false;
            }
        }
        
        bool isEmpty(){
            if(size == 0){
                return true;
            }
            else{
                return false;
            }
        }
        
        int listSize(){
            return size;
        }
        
        int maxListSize(){
            return maxSize;
        }
        
        int length(){
            return size;
        }
        
        void start(){
            if(isEmpty()){
                cout<<"List is Empty";
            }
            else{
                current = arr + 1;
            }
        }
        
        void end(){
            if(isEmpty()){
                cout<<"List is Empty";
            }
            else{
                current = arr + size;
            }
        }
        
        void next(){
            if(isEmpty() || current > arr + size){
                cout<<"Invalid Operation";
            }
            else{
                current = current + 1;
            }
        }
        
        void back(){
            if(isEmpty() || current < arr + 1){
                cout<<"Invalid Operation";
            }
            else{
                current = current - 1;
            }
        }
        
        int get(){
            if(isEmpty()){
                cout<<"No Element";
                return 0;
            }
            else{
                return *current;
            }
        }
        
        void update(int newVal){
            if(isEmpty()){
                cout<<"No Element";
                return;
            }
            else{
                *current = newVal;
            }
        }
        
        void add(int val){
            if(isFull()){
                cout<<"List is full";
                return;
            }
            else{
                size++;
                *(arr + size) = val;
                if(size == 1){
                    current = arr + 1;
                }
            }
        }
        
        void remove(){
            if(isEmpty()){
                cout<<"List is empty";
                return;
            }
            else{
                int* removeElem = current;
                int* i = removeElem;
                
                while(i < arr + size){
                    *i = *(i + 1);
                    i++;
                }
                size--;
                
                if(removeElem > arr + size){
                    current = arr + size;
                }
                else{
                    current = removeElem;
                }
            }
        }
        
        void clearList(){
            size = 0;
            current = nullptr;
        }
        
        void printList(){
            for(int i = 1; i <= size; i++){
                cout<<*(arr + i)<<" ";
            }
        }
        
        ListArray& operator=(ListArray& first){
                size = first.size;
                
                int* firstArrElem = first.arr + 1;
                int* secondArrElem = arr + 1;
                int* end = first.arr + size + 1;
                
                while(firstArrElem < end){
                    *secondArrElem = *firstArrElem;
                    firstArrElem++;
                    secondArrElem++;
                }
                
                return *this;
        }
};

int main() {
    ListArray l1;
    l1.add(10);
    l1.add(20);
    l1.add(30);
    l1.start();
    l1.next();
    l1.back();
    l1.remove();
    l1.printList();
    
    ListArray l2;
    l2 = l1;
    l2.printList();

    return 0;
}