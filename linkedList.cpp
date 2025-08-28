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
<<<<<<< HEAD
=======

 void getElem(int index){
    Node *current = head;
    int count = 0;

    while(count != index){
        current = current->next;
        count++;
    }

    cout<<current->val;
 }
 void deleteNode(int index){
    int count = 0;
    Node* current = head;

    while(count != index){
        current = current->next;
        count++;
    }

    current = NULL;
 }
>>>>>>> 60f1b06 (LinkedList1)
};


int main() {
    LinkedList* list = new LinkedList;
    list->addAtTail(5);
    list->addAtTail(15);
    list->addAtTail(20);
<<<<<<< HEAD
    
    list->addAtHead(0);

    list->printList();
=======
    list->addAtTail(25);
    
    list->getElem(2);
    //list->deleteNode(2);

    //list->printList();
>>>>>>> 60f1b06 (LinkedList1)
    

    return 0;
}
