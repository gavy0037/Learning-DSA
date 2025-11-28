#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) a>b?a: b

int cmp(const void *a , const void *b){
    int *x = (int*)a ;
    int *y = (int*)b ;

    if(x[0] == y[0]) return x[1] - y[1];

    return x[0]-y[0];
}


int main(){
    int n ;
    scanf("%d",&n);
    int arr[2*n][2];
    int temp = n , i= 0;
    while(temp--){
        int a , b ;
        scanf("%d %d",&a,&b);
        arr[i][0] = a; 
        arr[i+1][0] = b ;

        arr[i][1] = 1 ;
        arr[i+1][1] = -1 ;

        i+=2 ;
    }
    qsort(arr , 2*n , sizeof(arr[0]) , cmp);
    int curr = 0 , ans = 0 ;
    for(int i =0 ; i < 2*n;  i++){
        curr+=arr[i][1];
        ans = MAX(ans, curr);
    }

    printf("%d\n",ans);
    return 0 ;
}