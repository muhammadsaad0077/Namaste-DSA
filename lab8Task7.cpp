#include<iostream>
using namespace std;

// Structure definition for each node in the binary tree
struct Node {
    char data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive Preorder Traversal function
void preorder(Node* root) {
    if(root == NULL) {
        return;
    }

    // Step 1: Visit the current node first (root)
    cout<<root->data<<" ";   // Print the current node value

    // Step 2: Then go to the left subtree
    // (Recursion dives deeper into left child first)
    preorder(root->left);

    // Step 3: After finishing left subtree, go to right subtree
    preorder(root->right);
}

int main() {
    // Manually creating the binary tree shown in the image
    //          A
    //        /   \
    //       B     C
    //      / \     \
    //     D   E     F
    //        / \
    //       G   H

    Node* A = createNode('A');
    Node* B = createNode('B');
    Node* C = createNode('C');
    Node* D = createNode('D');
    Node* E = createNode('E');
    Node* F = createNode('F');
    Node* G = createNode('G');
    Node* H = createNode('H');

    // Linking nodes as per given diagram
    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->right = F;
    E->left = G;
    E->right = H;

    cout<<"Saad Bin Sharif"<<endl;
    cout<<"24P-3077"<<endl;
    cout<<"Preorder Traversal: ";

    // Preorder traversal always follows: Root → Left → Right
    preorder(A);

    cout<<endl;

    return 0;
}
