#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node ;

// Function to create a new Node
Node* newNode(int x) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main(){
    int n;
    scanf("%d", &n);  // Read the number of nodes

    int parent[n];
    Node* nodes[n];  // Array to store all nodes

    // Read the parent array
    for (int i = 0; i < n; i++) {
        scanf("%d", &parent[i]);
        nodes[i] = newNode(i);  // Create a node for each index
    }

    Node* root = NULL;

    // Construct the binary tree from the parent array
    for (int i = 0; i < n; i++) {
        if (parent[i] == -1) {
            root = nodes[i];  // Root node has no parent
        } else {
            Node* parentNode = nodes[parent[i]];
            if (parentNode->left == NULL) {
                parentNode->left = nodes[i];  // Assign left child
            } else if (parentNode->right == NULL) {
                parentNode->right = nodes[i];  // Assign right child
            }
        }

}