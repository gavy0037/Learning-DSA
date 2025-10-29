/*
Farmer John has just arranged his N haybales (1≤N≤100,000) at various points along the one-dimensional road running across his farm. 
To make sure they are spaced out appropriately, please help him answer Q queries (1≤Q≤100,000), each asking for the number of haybales within a specific interval along the road.
INPUT FORMAT (file haybales.in):
The first line contains N and Q.
The next line contains N distinct integers, each in the range 0 , 1,000,000,000 , indicating that there is a haybale at each of those locations.

Each of the next Q lines contains two integers A and B (0≤A≤B≤1,000,000,000) giving a query for the number of haybales between A and B, inclusive.

OUTPUT FORMAT (file haybales.out):
You should write Q lines of output. For each query, output the number of haybales in its respective interval.
SAMPLE INPUT:
4 6
3 2 7 5
2 3
2 4
2 5
2 7
4 6
8 10
SAMPLE OUTPUT:
2
2
3
4
1
0
*/

#include <stdio.h>
#include <stdlib.h>

int abs(int n){
    return n > 0 ? n : -n ;
}
void merge(int n , int arr[] ,int st , int mid , int end){
    int i = st , j = mid+1 , temp[end-st+1] , idx = 0 ;

    while(i <= mid && j <= end){
        temp[idx++] = arr[i] < arr[j] ? arr[i++] : arr[j++]; 
    }
    while(i <= mid){
        temp[idx++] = arr[i++];
    }
    while(j <= end){
        temp[idx++] = arr[j++];
    }

    for(int i = 0 ; i < end-st+1 ; i++){
        arr[i+st] = temp[i];
    }
}

void sort(int n , int arr[] , int st , int end){
    if(st<end){
        int mid = st+(end-st)/2 ;
        sort(n , arr , st , mid);
        sort(n  , arr , mid+1 , end);

        merge(n , arr , st , mid , end);
    }
}

int search_no_of_smaller_elements(int n , int arr[] , int upper_bound){
    //return number of elements that are lower than the given number
    int x = upper_bound ;
    if(arr[0] > x) return 0 ;
    int st = 0 , end = n-1 ;
    int ans =  -1 ;
    while(st <= end){
        int mid = st+(end-st)/2 ;
        if(arr[mid] <= x){
            ans = mid ;
            st = mid+1 ;
        }
        else end = mid-1 ;
    }
    if(ans == -1) return 0 ;
    return ans+1 ;
}


int search(int n , int arr[] , int target){
    int st = 0 , end = n-1 ;
    while( st<= end){
        int mid = (st+end)/2;
        if(arr[mid] == target) return mid ;
        if(arr[mid] < target) st = mid+1 ;
        else end = mid-1 ;
    }
    return -1 ;
}

int main(){
    
    int n , q;
    scanf("%d %d",&n , &q);
    int arr[n];
    for(int i = 0 ; i < n ; i++) scanf("%d",&arr[i]);
    sort(n , arr , 0 , n-1);
    

    while(q--){
        int a , b ;
        scanf("%d %d",&a , &b);
        printf("%d\n",search_no_of_smaller_elements(n,arr , b) - search_no_of_smaller_elements(n ,arr , a-1));
    }
    return 0 ;
}
