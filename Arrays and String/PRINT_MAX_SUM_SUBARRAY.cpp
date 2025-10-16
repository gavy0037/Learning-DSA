#include<iostream>
#include<climits>
using namespace std ;




int main(){
    int n ;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        scanf("%d",&arr[i]);
    }    
    int st= 0 , end , sum = 0 , ans = INT_MIN ;
    for(int i = 0 ; i < n ; i++){
        sum+=(arr[i]);
        if(ans<sum){
            ans = sum ;
            end = i ;
        }
        
        if(sum<0){
            sum = 0 ;
            st = i+1 ;
        }
    }

    for(int i = st ; i <= end ;i++){
        printf("%d ",arr[i]);
    }
}