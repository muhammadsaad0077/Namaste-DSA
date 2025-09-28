#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node *head, *tail;
    int size;

public:
    LinkedList() {
        head = tail = NULL;
        size = 0;
    }

    void append(int val) {
        Node *newNode = new Node(val);

        if (!head) {
            head = tail = newNode;
            tail->next = head;
            cout<<"Node is appended at Head" << endl;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
            cout<<"Node is appended at Tail" << endl;
        }
        size++;
    }

    void prepend(int val) {
        if (!head) {
            append(val);
        } else {
            Node *newNode = new Node(val);
            newNode->next = head;
            head = newNode;
            tail->next = head;
            size++;
            cout<<"Node is prepended at Head" << endl;
        }
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            cout<<"Invalid Index" << endl;
            return;
        } else if (index == 0) {
            prepend(val);
        } else if (index == size) {
            append(val);
        } else {
            Node *newNode = new Node(val);
            Node *prev = NULL, *current = head;
            int i = 0;

            while (i < index) {
                prev = current;
                current = current->next;
                i++;
            }
            prev->next = newNode;
            newNode->next = current;
            size++;
            cout<<"Node added at index "<<index<<endl;
        }
    }

    void deleteAtHead() {
        if (!head) {
            cout<<"Nothing to delete"<<endl;
            return;
        }
        if (head == tail) { 
            delete head;
            head = tail = NULL;
        } else {
            Node *temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
        size--;
        cout<<"Node deleted at Head"<<endl;
    }

    void deleteAtTail() {
        if (!head) {
            cout<<"Nothing to delete"<<endl;
            return;
        }
        if (head == tail) { 
            delete head;
            head = tail = NULL;
        } else {
            Node *current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = head;
        }
        size--;
        cout<<"Node deleted at Tail"<<endl;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            cout<<"Invalid Index"<<endl;
            return;
        } else if (index == 0) {
            deleteAtHead();
        } else if (index == size - 1) {
            deleteAtTail();
        } else {
            Node *prev = NULL, *current = head;
            int i = 0;

            while (i < index) {
                prev = current;
                current = current->next;
                i++;
            }

            prev->next = current->next;
            delete current;
            size--;
            cout<<"Node deleted at index "<<index<<endl;
        }
    }

    void searchElement(int val) {
        if (!head) {
            cout<<"List is empty"<<endl;
            return;
        }
        Node *temp = head;
        int index = 0;
        do {
            if (temp->data == val) {
                cout<<"Element "<<val<<" found at index "<<index<<endl;
                return;
            }
            temp = temp->next;
            index++;
        } while (temp != head);
        cout<<"Element "<<val<<" not found"<<endl;
    }

    void updateAtPosition(int position, int newVal) {
        if (position < 0 || position >= size) {
            cout<<"Invalid Index"<<endl;
            return;
        }
        Node *current = head;
        int count = 0;
        do {
            if (count == position) {
                current->data = newVal;
                cout<<"Value updated at index "<<position<<endl;
                return;
            }
            current = current->next;
            count++;
        } while (current != head);
    }

    void reverseList() {
        if (!head || head == tail) return;

        Node *prev = tail, *current = head, *nextNode = NULL;
        do {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        } while (current != head);

        tail = head;
        head = prev;

        cout<<"List reversed"<<endl;
    }

    void display() {
        if (!head) {
            cout<<"Nothing to display"<<endl;
            return;
        }
        Node *temp = head;
        cout<<"Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    LinkedList l1;
    l1.append(10);
    l1.append(20);
    l1.append(30);
    l1.append(40);

    l1.display();

    l1.searchElement(30);
    l1.searchElement(100);

    l1.addAtIndex(2, 25);
    l1.display();

    l1.deleteAtIndex(0);
    l1.deleteAtIndex(2);
    l1.display();

    l1.reverseList();
    l1.display();

    l1.updateAtPosition(1, 99);
    l1.display();
}
