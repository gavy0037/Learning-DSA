#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool isoperator(char c){ return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'||c == '^'; }


int weight(char a){
    if(a == '^') return 3 ;
    else if(a == '*' || a == '/') return 2 ;
    return 1 ;
}

void infix_to_postfix(int n , char *s){

    char st[n];
    int top = -1 ;
    for(int i = 0 ; i < n ; i++){
        if(!isoperator(s[i])) printf("%c",s[i]);
        else{
            if(s[i] == '(') st[++top] = s[i];
            else if(s[i] == ')'){
                while(top > -1 && st[top] != '('){
                    printf("%c",st[top--]);
                }
                top--;// to remove the remaining (
            }else{
                while(top > -1){
                    int curr = weight(s[i]);
                    int t = weight(st[top]);

                    if(s[i] == '^'){
                        if(t > curr){
                            printf("%c",st[top--]);
                        }else{
                            break ;
                        }
                    }else{
                        if(t >= curr){
                            printf("%c",st[top--]);
                        }else{
                            break ;
                        }
                    }
                }

                st[++top] = s[i];
            }

        }
    }
}


int main(){
    infix_to_postfix(9 , "a*(b+c)/d\0");

    return 0 ;
}