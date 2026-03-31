#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *a , const void *b){
    int *x = (int*)a ;
    int *y = (int*)b;

    return x[0]-y[0];
}

int main(){
    int t ;
    scanf("%d",&t);
    while(t--){
        int n ;
        scanf("%d",&n);
        int arr[2*n][2] ,ans[n] ;
        for(int i = 0 ; i < 2*n ; i+=2){
            scanf("%d %d",&arr[i][0],&arr[i+1][0]);
            arr[i][1] = arr[i+1][1] = i/2 ;
            ans[i/2] = 0 ;
        }
        qsort(arr , 2*n , sizeof(arr[0]) , cmp);
        int completed[n], count = 0;
        memset(completed , -1 , sizeof(completed));
        for(int i = 0 ; i < 2*n ; i++){
            if(completed[arr[i][1]] == -1) completed[arr[i][1]] = 1 ;
            else{
                ans[arr[i][1]] +=count ;
                count++;
            }
        }
        count = 0 ;
        memset(completed , -1 , sizeof(completed));
        for(int i = 2*n-1 ; i >= 0 ; i--){
            if(completed[arr[i][1]] == -1) completed[arr[i][1]] = 1 ;
            else{
                ans[arr[i][1]] +=count ;
                count++;
            }
        }
        for(int i = 0 ; i < n ; i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    return 0 ;
}