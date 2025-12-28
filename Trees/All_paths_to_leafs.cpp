/*
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

*/

#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void f(TreeNode *root, vector<string> &ans, string curr_path) {
  if (root->left == NULL && root->right == NULL) {
    ans.push_back(curr_path);
    return;
  }
  if (root->left != NULL)
    f(root->left, ans, curr_path + "->" + to_string(root->left->val));

  if (root->right != NULL)
    f(root->right, ans, curr_path + "->" + to_string(root->right->val));
}
vector<string> binaryTreePaths(TreeNode *root) {
  vector<string> ans;
  string c = to_string(root->val);

  f(root, ans, c);

  return ans;
}