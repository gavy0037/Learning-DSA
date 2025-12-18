#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

class node{
    public :
    int key ;
    int val ;
    node *next , *prev ;

    node(int key , int val){
        this->key = key ;
        this->val = val ;
        next = prev = NULL ;
    }
} ;
class dll{
    public:
    node *head , *tail ;
    dll(){
        head = tail = NULL ;
    }
    node* push_front(int key , int val){
        node *new_node = new node(key , val);
        if(head == NULL){
            head = tail = new_node ;
            return new_node ;
        }
        new_node->next = head ;
        new_node->prev = NULL ;
        head->prev = new_node ;
        head = new_node ;

        return new_node ;
    }
    void remove_node(node *n){
        if(n == NULL || head == NULL ) return ;
        // not called when length is 1 only

        if(n == tail){
            node *temp = tail ;
            tail = tail->prev ;
            tail->next = NULL ;

        }else if(n == head){
            node *temp = head ;
            head = head->next ;
            head->prev = NULL ;
        }else{
            n->prev->next = n->next ;
            n->next->prev = n->prev ;
            n->next = n->prev = NULL ;
        }
        
    }

    void pop_back(){
        if(head == NULL) return ;
        if(head ->next == NULL){
            delete(head) ;
            head = tail = NULL ;
            return ;
        }

        node *new_tail = tail->prev ;
        new_tail->next = NULL ;
        delete(tail);
        tail = new_tail ;
    }   

    void make_recent(node *node){
        if(node == head) return ;
        if(head == NULL || head->next == NULL) return ;
        remove_node(node);

        node->next = head ; 
        node->prev = NULL ;
        head->prev = node ;
        head = node ;
    }
};

class LRUCache {
public:
    unordered_map<int , node* > mp ; // stores key node pairs
    // for maintaining least recently used history
    // we can use dll 
    // first node will be most recently used and last node will be last used node
    // when one of the node is used then i will delete it and make another node with same key and value and push front it
    // when capacity is reached then i will delete the tail and push front again
    int max_size  , current_size = 0 ;
    dll list ;
    LRUCache(int cap) {
        max_size = cap ;
    }
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1 ;
        list.make_recent(mp[key]);
        return mp[key]->val ;
    }
    
    void put(int key, int val){
        if(mp.find(key) == mp.end()){ // key does not exist
            if(current_size < max_size){
                mp[key] = list.push_front(key , val);
                current_size++;
                return ;
            }else{
                int old_key = list.tail->key;
                mp.erase(old_key);
                list.pop_back();
                mp[key] = list.push_front(key , val);
            }
        }else{ // found in current data
            list.make_recent(mp[key]);
            mp[key]->val = val ;
        }
    }
};