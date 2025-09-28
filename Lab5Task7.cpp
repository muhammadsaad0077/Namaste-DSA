#include<iostream>
#include<string>
using namespace std;

class Node{
public:
    string title;
    Node* next;
    Node* prev;
    Node(string t){
        title = t;
        next = prev = NULL;
    }
};

class Playlist{
private:
    Node* head;
    Node* tail;
public:
    Playlist(){
        head = tail = NULL;
    }

    void addSongEnd(string title){
        Node* newNode = new Node(title);
        if(!head){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout<<title<<" added at end"<<endl;
    }

    void addSongStart(string title){
        Node* newNode = new Node(title);
        if(!head){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout<<title<<" added at start"<<endl;
    }

    void insertSongAt(int pos,string title){
        if(pos<0){
            cout<<"Invalid position"<<endl;
            return;
        }
        if(pos==0){
            addSongStart(title);
            return;
        }
        Node* newNode = new Node(title);
        Node* current = head;
        int index = 0;
        while(current && index<pos){
            current = current->next;
            index++;
        }
        if(!current){
            addSongEnd(title);
            return;
        }
        Node* prevNode = current->prev;
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = current;
        current->prev = newNode;
        cout<<title<<" inserted at position "<<pos<<endl;
    }

    void deleteSong(string title){
        if(!head){
            cout<<"Playlist empty"<<endl;
            return;
        }
        Node* current = head;
        while(current && current->title!=title){
            current = current->next;
        }
        if(!current){
            cout<<title<<" not found"<<endl;
            return;
        }
        if(current==head && current==tail){
            head = tail = NULL;
        }
        else if(current==head){
            head = head->next;
            head->prev = NULL;
        }
        else if(current==tail){
            tail = tail->prev;
            tail->next = NULL;
        }
        else{
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        delete current;
        cout<<title<<" deleted"<<endl;
    }

    void traverseForward(){
        cout<<"Playlist forward: ";
        Node* temp = head;
        while(temp){
            cout<<temp->title;
            if(temp->next) cout<<" ⇔ ";
            temp = temp->next;
        }
        cout<<" ⇔ NULL"<<endl;
    }

    void traverseBackward(){
        cout<<"Playlist backward: ";
        Node* temp = tail;
        while(temp){
            cout<<temp->title;
            if(temp->prev) cout<<" ⇔ ";
            temp = temp->prev;
        }
        cout<<" ⇔ NULL"<<endl;
    }
};

int main(){
    Playlist pl;
    pl.addSongEnd("SongA");
    pl.addSongEnd("SongB");
    pl.addSongEnd("SongC");
    pl.traverseForward();

    pl.addSongEnd("SongD");
    pl.traverseForward();

    pl.addSongStart("SongX");
    pl.traverseForward();

    pl.deleteSong("SongB");
    pl.traverseForward();

    pl.traverseBackward();
}
