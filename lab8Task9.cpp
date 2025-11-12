#include<iostream>
using namespace std;

// Structure definition for each node of the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive Inorder Traversal function
void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    // Step 1: Move to the left subtree first
    inorder(root->left);

    // Step 2: Visit the current node (after finishing left subtree)
    cout<<root->data<<" ";

    // Step 3: Now move to the right subtree
    inorder(root->right);
}

int main() {
    // Constructing the binary tree from the diagram
    //                  40
    //                /    \
    //              30      50
    //             / \     /  \
    //           25  35   45   60
    //          / \           / \
    //        15  28        55  70

    Node* n40 = createNode(40);
    Node* n30 = createNode(30);
    Node* n50 = createNode(50);
    Node* n25 = createNode(25);
    Node* n35 = createNode(35);
    Node* n45 = createNode(45);
    Node* n60 = createNode(60);
    Node* n15 = createNode(15);
    Node* n28 = createNode(28);
    Node* n55 = createNode(55);
    Node* n70 = createNode(70);

    // Linking nodes as per given diagram
    n40->left = n30;
    n40->right = n50;
    n30->left = n25;
    n30->right = n35;
    n50->left = n45;
    n50->right = n60;
    n25->left = n15;
    n25->right = n28;
    n60->left = n55;
    n60->right = n70;

    cout<<"Saad Bin Sharif"<<endl;
    cout<<"24P-3077"<<endl;
    cout<<"Inorder Traversal: ";

    // Inorder traversal always follows: Left → Root → Right
    inorder(n40);

    cout<<endl;

    return 0;
}
