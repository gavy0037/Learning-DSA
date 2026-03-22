#include<iostream>

using namespace std ;


class Node{
    public:
    int val , height ;
    Node *left , *right ;

    Node(int val){
        this->val = val ;
        this->height = 1; 
        this->left = this->right = NULL ;
    }
};

int getHeight(Node *root){
    if(!root) return 0 ;
    return root->height ;
}

Node *RR_rotation(Node *root){
    if(root== NULL) return NULL ;

    Node *T1 = root->right ;
    Node *T2 = T1->left ;

    root->right= T2 ;
    T1->left = root ;

    root->height = 1+max(getHeight(root->left), getHeight(root->right));
    T1->height = 1+max(getHeight(T1->left) , getHeight(T1->right));

    return T1 ;
}


Node *LL_rotation(Node *root){
    if(root == NULL) return NULL ;

    Node *T1 = root->left ;
    Node *T2 = T1->right ;

    root->left = T2 ;
    T1->right = root ;
    
    root->height = 1+max(getHeight(root->left), getHeight(root->right));
    T1->height = 1+max(getHeight(T1->left) , getHeight(T1->right));

    return T1 ;
}
Node *RL_rotation(Node *root){
    root->right = LL_rotation(root->right);

    return RR_rotation(root);
}

Node *LR_rotation(Node *root){

    root->left = RR_rotation(root->left);
    return LL_rotation(root);

}


Node *insert(Node *root , int key){
    if(!root) return new Node(key);

    if(key < root->val){
        root->left = insert(root->left , key);
    }else if(key > root->val){
        root->right = insert(root->right, key);
    }

    // update the height
    int lh = root->left == NULL ? -1 : root->left->height ;
    int rh = root->right == NULL ? -1 : root->right->height ;
    root->height = 1+max(lh , rh);

    // check balancing
    int balance = lh - rh ;

    if(balance < -1){
        // unbalance right side
        if(key < root->right->val) root = RL_rotation(root);
        else root = RR_rotation(root);
    }else if(balance > 1){
        // unbalanced on left side
        if(key < root->left->val) root = LL_rotation(root);
        else root = LR_rotation(root);
    }

    return root ;
}

Node *delete_Node(Node *root , int key){
    if(!root) return NULL ;

    if(root->val < key){
        root->right = delete_Node(root->right, key);
    }else if(root->val > key){
        root->left = delete_Node(root->left , key);
    }else{
        if(root->left == NULL || root->right == NULL) return root->left == NULL ? root->right : root->left ;
        else{
            // For both children -> using succesor
            Node *temp = root->right ;
            while(temp && temp->left) temp = temp->left ;

            root->val = temp->val;

            root->right = delete_Node(root->right , temp->val);
        }
    }

    int lh = getHeight(root->left);
    int rh = getHeight(root->right);

    root->height = 1+max(lh ,rh);

    int balance = lh - rh ;
    // It is very important to do only single rotation like LL and RR when the other side's subtrees have same height like rrh = rlh and lrh = llh as if they have same height then doing LR and Rl will disbalance them
    if(balance < -1){
        // unbalanced toward right side so R
        int rrh = getHeight(root->right->right);
        int rlh = getHeight(root->right->left);

        if(rrh >= rlh) root = RR_rotation(root);
        else root = RL_rotation(root);
    }else if(balance > 1){
        int lrh = getHeight(root->left->right);
        int llh = getHeight(root->left->left);

        if(lrh <= llh) root = LL_rotation(root);
        else root = LR_rotation(root);
    }

    return root ;
}