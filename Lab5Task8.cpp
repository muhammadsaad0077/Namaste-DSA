/*

Part 1: Concatenating Two Doubly Circular Linked Lists (L and M)
We have two doubly circular linked lists:
    • L = headL … tailL
    • M = headM … tailM
Efficient Algorithm:
    1. If either list is empty, return the other list.
    2. Let tailL = headL->prev (since circular list).
Let tailM = headM->prev.
    3. Connect:
        ◦ tailL->next = headM
        ◦ headM->prev = tailL
        ◦ tailM->next = headL
        ◦ headL->prev = tailM
    4. Return headL as the head of the final list.
 This runs in O(1) time because only 4 pointer updates are needed.
Example:
L: 10 ⇔ 20 ⇔ 30 ⇔ (back to 10)
M: 40 ⇔ 50 ⇔ 60 ⇔ (back to 40)

Concatenated:
10 ⇔ 20 ⇔ 30 ⇔ 40 ⇔ 50 ⇔ 60 ⇔ (back to 10)

🔹 Part 2: Transforming a Single Circular Doubly Linked List 
Input:
10 ⇔ 4 ⇔ 9 ⇔ 1 ⇔ 3 ⇔ 5 ⇔ 9 ⇔ 4 ⇔ (back to 10)
Step 1 – Extract Alternate Nodes (starting from 2nd node)
    • Take nodes at positions 2, 4, 6 …
    • Extracted list: 4 ⇔ 1 ⇔ 5 ⇔ 4
Step 2 – Reverse Extracted List
    • Reverse: 4 ⇔ 5 ⇔ 1 ⇔ 4
Step 3 – Append to End of Original Remaining List
Remaining list (after removal):
10 ⇔ 9 ⇔ 3 ⇔ 9 ⇔ (back to 10)
Append reversed list:
10 ⇔ 9 ⇔ 3 ⇔ 9 ⇔ 4 ⇔ 5 ⇔ 1 ⇔ 4 ⇔ (back to 10)


*/


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

Node* concatenate(Node* L, Node* M){
    if(!L) return M;
    if(!M) return L;
    Node* tailL = L->prev;
    Node* tailM = M->prev;
    tailL->next = M;
    M->prev = tailL;
    tailM->next = L;
    L->prev = tailM;
    return L;
}

int main(){
    Node* L = NULL;
    Node* M = NULL;

    insertEnd(L, 10);
    insertEnd(L, 20);
    insertEnd(L, 30);

    insertEnd(M, 40);
    insertEnd(M, 50);
    insertEnd(M, 60);

    cout<<"List L:"<<endl;
    printList(L);
    cout<<"List M:"<<endl;
    printList(M);

    Node* finalList = concatenate(L, M);
    cout<<"After Concatenation:"<<endl;
    printList(finalList);

    return 0;
}
