#include<iostream>
#include<Stack>

using namespace std ;

class TreeNode{
public:
    int val ;
    TreeNode *left , *right , *next ;

};
class BSTIterator {
public:
    stack<TreeNode*>st ;
    void storeleft(TreeNode *root){
        while(root){
            st.push(root);
            root = root->left ;
        }
    }
    BSTIterator(TreeNode* root) {
        storeleft(root);
    }
    
    int next() {
        TreeNode *curr = st.top();
        int ans = curr->val ;
        st.pop();
        storeleft(curr->right);

        return ans;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

int main(){
    return 0 ;
}