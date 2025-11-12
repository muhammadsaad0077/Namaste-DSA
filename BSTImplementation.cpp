#include<iostream>
using namespace std;

class Node{
public:
    int data;
    int count;
    Node* left;
    Node* right;
    Node(int value){
        data = value;
        count = 1;
        left = NULL;
        right = NULL;
    }
};

class BST{
public:
    Node* root;
    BST(){
        root = NULL;
    }

    Node* insert(Node* node, int value){
        if(node == NULL){
            node = new Node(value);
        }
        else if(value == node->data){
            node->count++;
        }
        else if(value < node->data){
            node->left = insert(node->left, value);
        }
        else{
            node->right = insert(node->right, value);
        }
        return node;
    }

    void insert(int value){
        root = insert(root, value);
    }

    Node* findMin(Node* node){
        while(node->left != NULL){
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* node, int value){
        if(node == NULL){
            return node;
        }
        if(value < node->data){
            node->left = deleteNode(node->left, value);
        }
        else if(value > node->data){
            node->right = deleteNode(node->right, value);
        }
        else{
            if(node->count > 1){
                node->count--;
                return node;
            }
            if(node->left == NULL && node->right == NULL){
                delete node;
                node = NULL;
            }
            else if(node->left == NULL){
                Node* temp = node;
                node = node->right;
                delete temp;
            }
            else if(node->right == NULL){
                Node* temp = node;
                node = node->left;
                delete temp;
            }
            else{
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->count = temp->count;
                temp->count = 1;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }

    void deleteValue(int value){
        root = deleteNode(root, value);
    }

    void inorder(Node* node){
        if(node != NULL){
            inorder(node->left);
            cout<<node->data<<"("<<node->count<<") ";
            inorder(node->right);
        }
    }

    void display(){
        inorder(root);
        cout<<endl;
    }
};

int main(){
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.insert(70);
    tree.insert(30);
    cout<<"Inorder Traversal: ";
    tree.display();
    cout<<"Deleting 20"<<endl;
    tree.deleteValue(20);
    tree.display();
    cout<<"Deleting 30"<<endl;
    tree.deleteValue(30);
    tree.display();
    cout<<"Deleting 50"<<endl;
    tree.deleteValue(50);
    tree.display();
    return 0;
}
