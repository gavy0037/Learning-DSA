#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
};
// Convert a given tree to a tree where every node contains sum of values of
// nodes in left and right subtrees in the original tree (in this problem at end
// node should not contain it's own value)

int sum(Node *root) {
  if (root == nullptr)
    return 0;

  int val = root->data, left = sum(root->left), right = sum(root->right);

  root->data = left + right;

  return val + left + right;
}
void toSumTree(Node *node) {
  // Your code here
  sum(node);
}