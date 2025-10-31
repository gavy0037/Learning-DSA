#include<stdio.h>
#include<stdlib.h>

int main(){
    char *s ;
    int size = 0, capacity = 1 ;
    s = (char*)malloc(capacity*sizeof(char));
    char a ;
    scanf("%c",&a);
    while(a != '\n'){
        if(size+1 >= capacity){
            capacity*=2;
            s = (char*)realloc(s, capacity*sizeof(char));
            
        }
        s[size] =a ;
        size++;
        scanf("%c",&a);
    }
    s[size] = '\0';
    for(int i = size-1 ; i >=0 ; i--){
        printf("%c",s[i]);
    }
    free(s);
    return 0 ;
}