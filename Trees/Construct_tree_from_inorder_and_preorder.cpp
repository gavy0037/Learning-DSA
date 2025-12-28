#include <vector>

using namespace std ;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int idx = 0 ;
Node *f(vector<int> &in, vector<int> &pre , vector<bool> &used){
    if(idx >= pre.size()) return NULL ;
    int idx_in ;
    for(int i = 0 ; i < in.size() ; i++){
        if(in[i] == pre[idx]){
            idx_in = i ;
            break ;
        }
    }
    Node *newnode = new Node(pre[idx]);
    idx++;
    used[idx_in] = true ;
    
    Node *right , *left ;
    if(idx_in-1 < 0 || used[idx_in-1] == true) left = NULL ;
    else{
        left = f(in , pre , used);
    }
    if(idx_in+1 >= pre.size() || used[idx_in+1] == true) right = NULL ;
    else{
        right = f(in , pre , used);
    }
    newnode->left = left ;
    newnode->right = right ;
    
    return newnode ;
}
Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
    // code here
    int n = inorder.size();
    vector<bool>b(n , false);
    return f(inorder , preorder , b);
}