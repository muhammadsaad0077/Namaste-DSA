#include<iostream>
#include<string>
using namespace std;

struct Action {
    char type;
    string text;
};

class ActionStack {
private:
    Action items[1000];
    int top;
public:
    ActionStack() {
        top=-1;
    }
    bool isEmpty() {
        return top==-1;
    }
    bool isFull() {
        return top==999;
    }
    void push(Action a) {
        if(isFull()) {
            cout<<"Stack overflow"<<endl;
        } else {
            top++;
            items[top]=a;
        }
    }
    Action pop() {
        if(isEmpty()) {
            return Action{'N',""};
        } else {
            Action val=items[top];
            top--;
            return val;
        }
    }
    Action peek() {
        if(isEmpty()) return Action{'N',""};
        return items[top];
    }
    void clear() {
        top=-1;
    }
};

void displayText(const string &text) {
    cout<<"Current text: "<<text<<endl;
}

void performInsert(string &text, ActionStack &undoStack, ActionStack &redoStack, const string &s) {
    text+=s;
    Action a;
    a.type='I';
    a.text=s;
    undoStack.push(a);
    redoStack.clear();
    displayText(text);
}

void performDelete(string &text, ActionStack &undoStack, ActionStack &redoStack, int k) {
    if(k<=0) {
        cout<<"Nothing to delete."<<endl;
        return;
    }
    if(k> (int)text.size()) k=text.size();
    string removed=text.substr(text.size()-k,k);
    text.erase(text.size()-k,k);
    Action a;
    a.type='D';
    a.text=removed;
    undoStack.push(a);
    redoStack.clear();
    displayText(text);
}

void performUndo(string &text, ActionStack &undoStack, ActionStack &redoStack) {
    if(undoStack.isEmpty()) {
        cout<<"Nothing to undo."<<endl;
        return;
    }
    Action a=undoStack.pop();
    if(a.type=='I') {
        int len=a.text.size();
        if(len> (int)text.size()) len=text.size();
        text.erase(text.size()-len,len);
        redoStack.push(a);
    } else if(a.type=='D') {
        text+=a.text;
        redoStack.push(a);
    }
    displayText(text);
}

void performRedo(string &text, ActionStack &undoStack, ActionStack &redoStack) {
    if(redoStack.isEmpty()) {
        cout<<"Nothing to redo."<<endl;
        return;
    }
    Action a=redoStack.pop();
    if(a.type=='I') {
        text+=a.text;
        undoStack.push(a);
    } else if(a.type=='D') {
        int len=a.text.size();
        if(len> (int)text.size()) len=text.size();
        text.erase(text.size()-len,len);
        undoStack.push(a);
    }
    displayText(text);
}

void demoSequence() {
    cout<<"--- Demo sequence start ---"<<endl;
    string text="";
    ActionStack undoStack;
    ActionStack redoStack;
    cout<<"Step 1: Type \"Hello\""<<endl;
    performInsert(text,undoStack,redoStack,"Hello");
    cout<<"Step 2: Type \" World\""<<endl;
    performInsert(text,undoStack,redoStack," World");
    cout<<"Step 3: Delete last 6 characters"<<endl;
    performDelete(text,undoStack,redoStack,6);
    cout<<"Step 4: Undo (should restore \" World\")"<<endl;
    performUndo(text,undoStack,redoStack);
    cout<<"Step 5: Undo (should remove \" World\")"<<endl;
    performUndo(text,undoStack,redoStack);
    cout<<"Step 6: Redo (should reapply \" World\")"<<endl;
    performRedo(text,undoStack,redoStack);
    cout<<"Step 7: Type \"!!!\""<<endl;
    performInsert(text,undoStack,redoStack,"!!!");
    cout<<"Step 8: Undo (removes \"!!!\")"<<endl;
    performUndo(text,undoStack,redoStack);
    cout<<"Step 9: Redo (reapplies \"!!!\")"<<endl;
    performRedo(text,undoStack,redoStack);
    cout<<"--- Demo sequence end ---"<<endl;
}

int main() {
    string text="";
    ActionStack undoStack;
    ActionStack redoStack;
    int choice;
    cout<<"Saad Bin Sharif"<<endl;
    cout<<"24P-3077"<<endl;
    while(true) {
        cout<<endl;
        cout<<"1. Type text (append)"<<endl;
        cout<<"2. Delete last k characters"<<endl;
        cout<<"3. Undo"<<endl;
        cout<<"4. Redo"<<endl;
        cout<<"5. Display current text"<<endl;
        cout<<"6. Run demo sequence"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice==1) {
            string s;
            cout<<"Enter text to append: ";
            cin.ignore();
            getline(cin,s);
            performInsert(text,undoStack,redoStack,s);
        } else if(choice==2) {
            int k;
            cout<<"Enter number of characters to delete: ";
            cin>>k;
            performDelete(text,undoStack,redoStack,k);
        } else if(choice==3) {
            performUndo(text,undoStack,redoStack);
        } else if(choice==4) {
            performRedo(text,undoStack,redoStack);
        } else if(choice==5) {
            displayText(text);
        } else if(choice==6) {
            demoSequence();
        } else if(choice==7) {
            cout<<"Exiting program..."<<endl;
            break;
        } else {
            cout<<"Invalid choice. Try again."<<endl;
        }
    }
    return 0;
}
