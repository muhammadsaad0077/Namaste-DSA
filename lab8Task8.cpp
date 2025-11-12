#include<iostream>
using namespace std;

// Structure definition for each node in the binary tree
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

// Recursive Postorder Traversal function
void postorder(Node* root) {
    if(root == NULL) {
        return;
    }

    // Step 1: Go to the left subtree first
    postorder(root->left);

    // Step 2: Then go to the right subtree
    postorder(root->right);

    // Step 3: Finally, visit (print) the current node
    cout<<root->data<<" ";
}

int main() {
    // Manually creating the given binary tree
    //              30
    //            /    \
    //          20      90
    //         /  \    /  \
    //        9   29  50  120
    //                     /
    //                   100

    Node* n30 = createNode(30);
    Node* n20 = createNode(20);
    Node* n90 = createNode(90);
    Node* n9  = createNode(9);
    Node* n29 = createNode(29);
    Node* n50 = createNode(50);
    Node* n120 = createNode(120);
    Node* n100 = createNode(100);

    // Linking nodes according to diagram
    n30->left = n20;
    n30->right = n90;
    n20->left = n9;
    n20->right = n29;
    n90->left = n50;
    n90->right = n120;
    n120->left = n100;

    cout<<"Saad Bin Sharif"<<endl;
    cout<<"24P-3077"<<endl;
    cout<<"Postorder Traversal: ";

    // Postorder traversal always follows: Left → Right → Root
    postorder(n30);

    cout<<endl;

    return 0;
}
