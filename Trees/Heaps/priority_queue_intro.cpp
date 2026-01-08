#include<iostream>
#include<queue>


using namespace std ;

int main(){
    priority_queue<int>pq ;// by default it is max heap

    pq.push(1);
    pq.push(5);
    pq.push(4);
    pq.push(10);
    pq.push(45);

    cout<<"Element at top "<<pq.top()<<endl ;
    cout<<"Size: "<<pq.size()<<endl ;

    cout<<"Pq is empty: "<<pq.empty()<<endl ;


    // TO create a min heap
    priority_queue<int,vector<int> , greater<int>>minheap ;

    minheap.push(5);
    minheap.push(-2);
    minheap.push(4);
    minheap.push(12);
    minheap.push(-3);

    cout<<minheap.top()<<endl ;
    minheap.pop();
    cout<<minheap.top()<<endl ;

    return 0 ;
}