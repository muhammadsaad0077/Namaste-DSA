#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int v): data(v), next(NULL), prev(NULL) {}
};

void insertEnd(Node*& head, int val){
    Node* n = new Node(val);
    if(!head){
        head = n;
        head->next = head;
        head->prev = head;
        return;
    }
    Node* tail = head->prev;
    tail->next = n;
    n->prev = tail;
    n->next = head;
    head->prev = n;
}

void printList(Node* head){
    if(!head){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* t = head;
    do{
        cout<<t->data<<" ⇔ ";
        t = t->next;
    } while(t != head);
    cout<<"(back to "<<head->data<<")"<<endl;
}

Node* extractAlternate(Node*& head){
    if(!head || head->next == head) return NULL;

    int n = 1;
    Node* tmp = head->next;
    while(tmp != head){
        n++;
        tmp = tmp->next;
    }

    int removals = n / 2;
    Node* altHead = NULL;
    Node* altTail = NULL;
    Node* p = head;

    for(int i = 0; i < removals; i++){
        Node* rem = p->next;

        p->next = rem->next;
        rem->next->prev = p;

        if(!altHead){
            altHead = rem;
            altHead->next = altHead;
            altHead->prev = altHead;
            altTail = altHead;
        } else {
            altTail->next = rem;
            rem->prev = altTail;
            rem->next = altHead;
            altHead->prev = rem;
            altTail = rem;
        }

        p = p->next;
    }

    return altHead;
}

Node* reverseCircularDoubly(Node* head){
    if(!head || head->next == head) return head;
    Node* curr = head;
    do{
        Node* tmp = curr->next;
        curr->next = curr->prev;
        curr->prev = tmp;
        curr = tmp;
    } while(curr != head);
    return head->prev;
}

void appendLists(Node*& head, Node* altHead){
    if(!head){
        head = altHead;
        return;
    }
    if(!altHead) return;
    Node* tail1 = head->prev;
    Node* tail2 = altHead->prev;

    tail1->next = altHead;
    altHead->prev = tail1;
    tail2->next = head;
    head->prev = tail2;
}

int main(){
    Node* head = NULL;
    int arr[] = {10, 4, 9, 1, 3, 5, 9, 4};
    int len = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < len; i++) insertEnd(head, arr[i]);

    cout<<"Original List:"<<endl;
    printList(head);

    Node* alt = extractAlternate(head);
    alt = reverseCircularDoubly(alt);
    appendLists(head, alt);

    cout<<"Final List:"<<endl;
    printList(head);

    return 0;
}
