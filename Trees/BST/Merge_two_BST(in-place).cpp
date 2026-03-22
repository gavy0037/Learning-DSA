#include<iostream>
#include<vector>

using namespace std ;

class Node
{
    public:
    int val;
    Node *left;
    Node *right;

    Node(int val) {
        val = val;
        left = right = NULL;
    }
};

void bstToDLL(Node* root, Node*& head, Node*& prev) {
    if (!root) return;

    bstToDLL(root->left, head, prev);

    if (!prev)
        head = root;
    else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    bstToDLL(root->right, head, prev);
}


Node* mergeDLL(Node* h1, Node* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    Node* head = NULL;
    Node* tail = NULL;

    while (h1 && h2) {
        Node* temp;
        if (h1->val < h2->val) {
            temp = h1;
            h1 = h1->right;
        } else {
            temp = h2;
            h2 = h2->right;
        }

        temp->left = temp->right = NULL;

        if (!head) {
            head = tail = temp;
        } else {
            tail->right = temp;
            temp->left = tail;
            tail = temp;
        }
    }

    Node* rem = (h1) ? h1 : h2;
    while (rem) {
        tail->right = rem;
        rem->left = tail;
        tail = rem;
        rem = rem->right;
    }

    return head;
}


int countNodes(Node* head) {
    int cnt = 0;
    while (head) {
        cnt++;
        head = head->right;
    }
    return cnt;
}

Node* sortedDLLToBST(Node*& head, int n) {
    if (n <= 0 || !head) return NULL;

    Node* left = sortedDLLToBST(head, n / 2);

    Node* root = head;
    root->left = left;

    head = head->right;

    root->right = sortedDLLToBST(head, n - n / 2 - 1);
    return root;
}

