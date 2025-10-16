#include<stdio.h>
#include<string.h>

void permutations(int n ,int str[] ,int arr[],int pos){
    if(pos == n){
        for(int i = 0 ; i < n ; i++){
            printf("%d ",str[i]);
        }
        printf("\n");
        return ;
    }


    for(int i = 0 ; i < n ; i++){
        if(arr[i]){
            arr[i] = 0 ;
            str[pos] = i+1;
            permutations(n , str , arr , pos+1);
            arr[i] = 1 ;
        }
    }
}


int main(){
    int n ;
    scanf("%d", &n);
    int arr[n];
    int str[n];
    for(int i = 0 ; i < n ; i++){
        arr[i] = 1 ;
    }
    permutations(n,str,arr,0);
}