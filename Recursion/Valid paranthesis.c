#include<stdio.h>

void brackets(int n, int open , int close ,int idx , char str[]){
    
    if(open<close) return;
    if(open>n)     return;
    if(close>n)    return;

    if(idx == 2*n){
        if(str[0] != '(')    return ;
        if(str[2*n-1] != ')') return ;

        if(open == close){
            str[2*n] = '\0';
            printf("%s\n",str);
            return ;
        }
        return ;
    }

    str[idx] = '(';
    brackets(n , open+1 , close , idx+1 , str);
    str[idx] = ')';
    brackets(n , open , close+1 , idx +1 , str);
}

int main(){
    int n ;
    scanf("%d",&n);
    char str[2*n+1];
    brackets(n, 0 , 0 , 0 , str);

    return 0 ;
}
