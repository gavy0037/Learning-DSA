#include<stdio.h>

#define MAX(a , b) a>b?a:b

void pse(int n , int arr[] , long long ps[]){
    int stack[n], top = -1;
    for(int i = n-1 ; i >=0 ; i--){
        while(top > -1 && arr[stack[top]] < arr[i]) top--;

        if(top > -1) ps[stack[top]] = MAX(ps[stack[top]] , (long long)arr[stack[top]]*(long long)arr[i]); // do modification for long long

        stack[++top] = i ;
    }
}

void nse(int n , int arr[] , long long ns[]){
    int stack[n], top = -1;
    for(int i = 0 ; i < n ; i++){
        while(top > -1 && arr[stack[top]] < arr[i]) top--;

        if(top > -1) ns[stack[top]] = MAX(ns[stack[top]] , (long long)arr[stack[top]]*(long long)arr[i]);
        stack[++top] = i ;
    }
}

int main(){
    int t ;
    scanf("%d",&t);
    while(t--){
        int n ;
        scanf("%d",&n);
        int arr[n];
        long long ps[n] , ns[n];

        for(int i = 0 ; i < n ; i++){
            scanf("%d",&arr[i]);
            ps[i] = ns[i] = 0;
        }
        
        pse(n , arr , ps);
        nse(n , arr , ns);
        
        // for(int i = 0 ; i < n ; i++) printf("%d ",ps[i]);
        // printf("\n");
        // for(int i = 0 ; i < n ; i++) printf("%d ",ns[i]);
        // printf("\n");
        long long ans = 0 ;
        for(int i = 1 ; i < n-1 ; i++){
            if(ps[i] == 0 || ns[i] == 0) continue;
            ans = MAX(ans , ps[i] + ns[i]);
        }
        printf("%lld\n",ans);
    }
}