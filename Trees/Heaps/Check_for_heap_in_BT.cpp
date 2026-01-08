#include<queue>

using namespace std ;


class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

bool isHeap(Node* root) {
    // code here
    queue<Node*>q ;
    q.push(root);
    
    bool NULL_encountered = false ;
    
    while(!q.empty()){
        Node *curr = q.front();
        
        q.pop();
        if(curr->left){
            if(NULL_encountered || curr->data < curr->left->data) return false ;
            
            q.push(curr->left);
        }else NULL_encountered = true ;
        
        if(curr->right){
            if(NULL_encountered || curr->data < curr->right->data) return false ;
            
            q.push(curr->right);
        }else NULL_encountered = true ;
        
    }
    
    return true ;
}