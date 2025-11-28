#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void *a , const void *b){
    const char *s1 = *(char **)a ;
    const char *s2 = *(char **)b ;
    return strcmp(s1,s2) ;
}

int main(){
    char* arr[201];
    int size = 0 ;
    char s[201];
    fgets(s , 201 , stdin);
    s[strcspn(s , "\n")] = 0 ;
    char *temp = strtok(s , " ");
    while(temp != NULL){
        arr[size++] = temp ;
        temp = strtok(NULL , " ");
    }
    qsort(arr , size , sizeof(char*) , cmp);

    for(int i = 0 ; i < size ; i++){
        printf("%s\n",arr[i]);
    }
    return 0 ;
}