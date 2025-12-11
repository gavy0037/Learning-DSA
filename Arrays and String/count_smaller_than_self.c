#include<stdio.h>

void merge(int n , int arr[][2] , int st , int mid , int end , int ans[]){
    int i =st, j = mid+1 , temp[end-st+1][2] , idx = 0 ,count_of_smaller = 0 ;
    while (i<=mid && j<= end){
        if(arr[i][0]<=arr[j][0]){
            temp[idx][0] = arr[i][0];
            temp[idx][1] = arr[i][1];
            ans[arr[i][1]]+=count_of_smaller ;
            idx++;i++;
        }else{
            count_of_smaller++;

            temp[idx][0] = arr[j][0];
            temp[idx][1] = arr[j][1];

            idx++;j++;
        }
    }

    while(i<=mid){
        ans[arr[i][1]] += count_of_smaller ;
        temp[idx][0] = arr[i][0];
        temp[idx][1] = arr[i][1];

        idx++;i++;
    }
    while(j<=end){
        temp[idx][0] = arr[j][0];
        temp[idx][1] = arr[j][1];

        idx++;j++;
    }
    i = 0 ;
    for(i = 0 ; i < end-st+1 ; i++){
        arr[i+st][0] = temp[i][0];
        arr[i+st][1] = temp[i][1];
    }
}

void sort(int n , int arr[][2] , int st , int end , int ans[]){
    if(st<end){
        int mid = (st+end)/2 ;
        sort(n , arr , st , mid , ans);
        sort(n , arr , mid+1 , end , ans);

        merge(n , arr , st , mid , end, ans);
    }
}

int main(){
    int n; 
    scanf("%d",&n);
    int arr[n][2];
    for(int i = 0 ; i < n; i++){
        scanf("%d" , &arr[i][0]);
        arr[i][1] = i ;
    }

    int ans[n] ;
    for(int i = 0 ; i < n; i++) ans[i] = 0 ;

    sort(n ,arr , 0 , n-1 , ans);
    for(int i = 0 ; i < n; i++){
        printf("%d ",ans[i]);
    }
    return 0 ;
}