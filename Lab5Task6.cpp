#include<iostream>
#include<string>
using namespace std;

class Node{
public:
    string data;
    Node* next;
    Node* prev;
    Node(string val){
        data = val;
        next = prev = NULL;
    }
};

class DoublyLinkedList{
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList(){
        head = tail = NULL;
    }

    void append(string val){
        Node* newNode = new Node(val);
        if(!head){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->data;
            if(temp->next) cout<<" ⇔ ";
            temp = temp->next;
        }
        cout<<" ⇔ NULL"<<endl;
    }

    bool isPalindrome(){
        if(!head || !head->next) return true;

        Node* left = head;
        Node* right = tail;

        while(left != right && right->next != left){
            if(left->data != right->data){
                return false;
            }
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main(){
    DoublyLinkedList dll1;
    dll1.append("1");
    dll1.append("0");
    dll1.append("2");
    dll1.append("0");
    dll1.append("1");

    cout<<"List 1:"<<endl;
    dll1.display();
    if(dll1.isPalindrome())
        cout<<"Linked List is a Palindrome"<<endl;
    else
        cout<<"Linked List is NOT a Palindrome"<<endl;

    DoublyLinkedList dll2;
    dll2.append("B");
    dll2.append("O");
    dll2.append("R");
    dll2.append("R");
    dll2.append("O");
    dll2.append("W");
    dll2.append("O");
    dll2.append("R");
    dll2.append("R");
    dll2.append("O");
    dll2.append("B");

    cout<<"List 2:"<<endl;
    dll2.display();
    if(dll2.isPalindrome())
        cout<<"Linked List is a Palindrome"<<endl;
    else
        cout<<"Linked List is NOT a Palindrome"<<endl;
}
