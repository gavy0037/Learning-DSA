#include<iostream>
#include<vector>
#include<queue>

using namespace std ;

// parent nodes and children nodes
/*
 Binary trees: Where every parent has at most two children
 Leaf node : Parent node with no children
 Sibling nodes : Nodes with same parents

 Height of tree = Levels of tree
*/

/*
    General structure of recursion

    solve(root){
        sovle(left)
        solve(right)

        // solve for root
    }
*/

class node{
    public:
        int val ;
        node *left , *right ;

        node(int val){
            this->val = val ;
            left = right = NULL ;
        }
};


// Preorder sequence

/*
Root
left
right

-1 -> NULL
*/
int idx = 0 ;
node* build_tree(vector<int> pre_order_sequence){
    if(idx >= pre_order_sequence.size()) return NULL ;
    if(pre_order_sequence[idx] == -1){
        idx++;
        return NULL ;
    }
    node *newroot = new node(pre_order_sequence[idx]);
    idx++;

    newroot->left = build_tree(pre_order_sequence);
    newroot->right = build_tree(pre_order_sequence);

    return newroot ;
}


void preorder_transversal(node *root){
    if(root == NULL) return ;
    cout<<root->val <<' ';// visit root
    preorder_transversal(root->left); // visit left child
    preorder_transversal(root->right);// visit right child
}

void inorder_transversal(node *root){
    // visit order = left - parent - right
    if(root == NULL) return ;
    inorder_transversal(root->left);
    cout<<root->val<<' ';
    inorder_transversal(root->right);
}

//similarly postorder transversal -> left , right , root

// Level ordered transversal -> iterative and bfs
void level_ordered_transversal(node *root){
    queue<node*>q ;
    q.push(root);
    while(!q.empty()){
        node *curr = q.front();
        q.pop();
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

void level_Ordered_transversal_with_printing_levelwise(node *root){
    int count = 0 , target = 1; // this is my approach
    /*  To put this inside loop
        count++;
        if(count == target){
            cout<<endl ;
            target *= 2; 
            count = 0 ;
        }
    */
    // Another approach is to insert a additional null node into queue to mark end of a level
    queue<node*>q ;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *curr = q.front();
        q.pop();
        if(curr == NULL){
            if(!q.empty()){
                cout<<endl ;
                q.push(NULL);
                

                continue ;
            }else break ;
        }else{
            cout<<curr->val<<" ";
        }
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}


int main(){
    node *root = build_tree({10, 5, 3, -1, -1, 7, -1, -1, 20, 15, -1, -1, 25, -1, -1});

}