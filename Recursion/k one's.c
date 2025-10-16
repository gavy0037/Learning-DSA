#include<stdio.h>
#include<string.h>

void bin(int n , int k , char str[] , int pos , int target){
    if(pos == n){
        
        if(k == target){
            str[pos] = '\0' ;
            printf("%s\n",str);
        }
        return ;
    }

    str[pos] = '0';
    bin(n , k , str , pos+1 , target);

    str[pos] = '1' ;
    bin(n , k+1 , str , pos+1 , target);
}


int main(){
    int n  = 3 ;
    char str[4] ;
    bin(n , 0 , str , 0 , 2);
}