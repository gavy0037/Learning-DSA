#include<stdio.h>
#include<stdlib.h>

int main(){
    int size = 0 , capacity = 1 ;
    int *arr = (int*)malloc(capacity*sizeof(int));
    while(1){
        int o ;
        printf("1.Enter element\n2.Stop\nEnter your choice: ");
        scanf("%d",&o);
        if(o == 2) break ;
        else if(o == 1){
            printf("Enter number: ");
            int n ;
            scanf("%d",&n);
            if(size+1>=capacity){
                capacity*=2;
                arr = realloc(arr , capacity*sizeof(int));
            }
            arr[size] = n ;
            size++;
        }
    }

    for(int i = size-1 ; i >=0 ; i--){
        printf("%d ",arr[i]);
    }

    free(arr);

    return 0;
}