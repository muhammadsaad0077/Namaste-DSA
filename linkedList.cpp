// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class LinkedList{

public:
	int size;
	LinkedList(): size(0){
	}
struct Node{
    int val;
    Node* next;

    Node(int v): val(v), next(nullptr){
    }
};

	Node* head;

void addAtHead(int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    size++;
}

void addAtTail(int val){
    Node* newNode = new Node(val);
    
    if(head == nullptr){
        head = newNode;
    }
    else{
        Node* current = head;
       while(current->next != nullptr){
        current = current->next;
        }
        current->next = newNode;
    }
    
    size++;

}

void addAtIndex(int index, int val){
	int count = 0;
	Node* current = head;
	
	if(index == 0){
		addAtHead(val);
	}
	else if(index > size - 1){
		addAtTail(val);
	}
	else{
		while(count != index - 1){
			current = current->next;
			count++;
		}
	
		Node* newNode = new Node(val);
		newNode->next = current->next;
		current->next = newNode;	
	}	
	size++;
	
}
 void printList(){
 	Node* current = head;
    
    while(current != nullptr){
        cout<<current->val<<endl;
        current = current->next;
    }
 }


 void getElem(int index){
    if(index < 0 || index >= size){
        cout<<("Index Invalid");
    } 
    else{
        Node *current = head;
        int count = 0;

        while(count != index){
            current = current->next;
            count++;
        }

    cout<<current->val;
    }
 }
 
 void deleteNode(int index){
    if(index < 0 || index >= size){
        cout<<"Invalid Index";
    }
    else if(index == 0){
        head = head->next;
            size--;

    }
    else{
        int count = 0;
    Node* current = head;

    while(count != index - 1){
        current = current->next;
        count++;
    }

    current->next = current->next->next;
        size--;

    }
    }
};


int main() {
    LinkedList* list = new LinkedList;
    list->addAtHead(0);
    list->addAtTail(5);
    list->addAtTail(15);
    list->addAtTail(20);
    list->addAtTail(25);
    
   // list->getElem(9);
    list->deleteNode(0);

    list->printList();
    

    return 0;
}
