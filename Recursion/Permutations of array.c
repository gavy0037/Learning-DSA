#include<stdio.h>
//asuming that array elements are all >-1
void permutations_of_arr1(int n , int arr[] , int temp[] , int pos){//
    
    if(pos == n){
        for(int i = 0 ; i < n ; i++){
            printf("%d ",temp[i]);
        }
        printf("\n");
        return ;
    }

    for(int i = 0 ; i < n ; i++){
        if(arr[i] != -1){
            int t = arr[i];
            arr[i] = -1 ;
            temp[pos] = t ;
            permutations_of_arr1(n , arr , temp ,pos+1);
            arr[i] = t ;
        }
    }
}

void print(int n , int arr[]){
    for(int i = 0 ; i < n ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void permutations_of_arr2(int n , int arr[] , int pos){//better space complexity 
    if(pos == n){
         print(n , arr);
         return ;
    }
    for(int i = pos ; i < n ;i++){
        int t = arr[pos];
        arr[pos] = arr[i];
        arr[i] = t ;

        permutations_of_arr2(n , arr , pos+1);

        int t2 = arr[i];
        arr[i] = arr[pos];
        arr[pos] = t2 ;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        scanf("%d",&arr[i]);
    }

    int temp[n];
    printf("Permutations of input array:\n");
    permutations_of_arr2(n , arr , 0);

    return 0 ;
}