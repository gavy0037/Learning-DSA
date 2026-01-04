/*
Generate all numbers from 0 to N (inclusive)
Convert each number to its English word representation
Sort these numbers based on the alphabetical order of their English representations
Print the sorted numbers
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *arr[10]= {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

int min(int a, int b){
    return a < b ? a : b ;
}


int cmp(const void *a , const void *b){
    char *s1 = (char*)a;
    char *s2 = (char*)b;

    int len = min(strlen(s1) , strlen(s2));

    for(int i = 0 ;i < len ; i++){
        int a = strcmp(arr[s1[i]-'0'] , arr[s2[i]-'0']);
        if(a) return a ;
    }
    return 0;
}

int main(){
    int n ;
    scanf("%d",&n);
    char s[n+1][4];
    for(int i = 0 ; i <= n; i++){
        sprintf(s[i] , "%d" , i);
    }

    qsort(s , n+1 , sizeof(s[0]) , cmp);
    for(int i  = 0 ;i <= n ; i++) printf("%s\n",s[i]);
    return 0 ;
}