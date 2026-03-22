#include<stdio.h>
#include<stdlib.h>

int dfs(int parent , int size[] , int *arr[] , int ans[]){
    int s = size[parent];
    for(int i = 0 ; i < size[parent]; i++){
        s+=dfs(arr[parent][i] , size , arr,ans);
    }
    ans[parent] = s ;
    return s;
}

int main(){
    int n;
    scanf("%d",&n);
    int *arr[n+1],size[n+1] , ans[n+1];
    for(int i = 0 ; i <= n ; i++){ // 1 is the parent of every one
        arr[i] = (int*)malloc(sizeof(int));
        size[i] = 0 ;
    }
    for(int i = 2 ; i <= n; i++){
        int parent ;
        scanf("%d",&parent);
        // we get parent of i
        int s = size[parent];
        size[parent]++;
        if(size[parent] > 1) arr[parent] = realloc(arr[parent] , (s+1)*sizeof(int));
        arr[parent][s] = i ;
    }

    // for(int i = 1 ; i <= n ; i++){
    //     for(int j = 0 ; j < size[i] ; j++) printf("%d ",arr[i][j]);
    //     printf("\n");
    // }

    dfs(1 , size , arr ,ans);

    for(int i = 1 ; i <= n ; i++) printf("%d ",ans[i]);
    return 0 ;
}