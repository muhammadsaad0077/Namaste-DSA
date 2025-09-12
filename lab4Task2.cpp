#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class TicketSystem {
private:
    Node* head;
    Node* tail;
    int size;

public:
    TicketSystem() {
        head = tail = NULL;
        size = 0;
    }

    void joinNormal(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Ticket " << val << " joined at the end.\n";
        size++;
    }

    void joinVIP(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        cout << "VIP Ticket " << val << " joined at the front.\n";
        size++;
    }

    void joinAtPosition(int val, int pos) {
        if (pos <= 1) {
            joinVIP(val);
            return;
        }
        if (pos > size) {
            joinNormal(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Ticket " << val << " joined at position " << pos << ".\n";
        size++;
    }

    void cancelAtStart() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (!head) tail = NULL;
        cout << "Ticket " << temp->data << " cancelled from start.\n";
        delete temp;
        size--;
    }

    void cancelAtEnd() {
        if (!head) return;
        if (head == tail) {
            cout << "Ticket " << head->data << " cancelled from end.\n";
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            cout << "Ticket " << tail->data << " cancelled from end.\n";
            delete tail;
            tail = temp;
            tail->next = NULL;
        }
        size--;
    }

    void cancelAtPosition(int pos) {
        if (!head) return;
        if (pos <= 1) {
            cancelAtStart();
            return;
        }
        if (pos >= size) {
            cancelAtEnd();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        cout << "Ticket " << delNode->data << " cancelled from position " << pos << ".\n";
        delete delNode;
        size--;
    }

    void search(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == val) {
                cout << "Ticket " << val << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Ticket " << val << " not found.\n";
    }

    void display() {
        if (!head) {
            cout << "No tickets in queue.\n";
            return;
        }
        Node* temp = head;
        int pos = 1;
        cout << "Current Queue:\n";
        while (temp) {
            cout << pos << ": " << temp->data << endl;
            temp = temp->next;
            pos++;
        }
    }
};

int main() {
    TicketSystem ts;
    int choice, val, pos;

    while (true) {
        cout << "\n1. Join Normally\n2. Join VIP\n3. Join at Position\n4. Cancel from Start\n5. Cancel from End\n6. Cancel from Position\n7. Search Ticket\n8. Display Queue\n9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ticket number: ";
                cin >> val;
                ts.joinNormal(val);
                break;
            case 2:
                cout << "Enter ticket number: ";
                cin >> val;
                ts.joinVIP(val);
                break;
            case 3:
                cout << "Enter ticket number: ";
                cin >> val;
                cout << "Enter position: ";
                cin >> pos;
                ts.joinAtPosition(val, pos);
                break;
            case 4:
                ts.cancelAtStart();
                break;
            case 5:
                ts.cancelAtEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                ts.cancelAtPosition(pos);
                break;
            case 7:
                cout << "Enter ticket number: ";
                cin >> val;
                ts.search(val);
                break;
            case 8:
                ts.display();
                break;
            case 9:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
