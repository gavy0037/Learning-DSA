/*
DEPOSIT [name] [amount]
Finds (or creates) the account for [name].
Adds the integer [amount] to the account's balance.

WITHDRAW [name] [amount]
Finds (or creates) the account for [name].
Checks if the account has sufficient funds (i.e., balance >= amount).
If sufficient, subtract [amount] from the balance.
If insufficient (i.e., balance < amount), print -1 and do not change the balance.

CHECK [name]
Finds (or creates) the account for [name].
Prints the current integer balance.

TRANSFER [from_name] [to_name] [amount]
Finds (or creates) both accounts.
Checks if the [from_name] account has sufficient funds (i.e., balance >= amount).
If sufficient, subtract [amount] from [from_name] and add [amount] to [to_name].
If insufficient (i.e., balance < amount), print -1 and do not change either balance.

*/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct acc{
    char name[51] ;
    long long amount ;
}acc ;

int main(){
    int q ;
    scanf("%d",&q);
    int size = 0;
    acc **list = malloc(sizeof(acc*));
    while(q--){
        char op[9];
        scanf("%s ",op);//scaning the operation to be done
        if(strcmp("DEPOSIT",op) == 0){
            char nam[51] ;
            long long amm ;
            scanf("%s %lld",nam , &amm);
            int found = 0 ;
            for(int i = 0 ; i < size ; i++){
                if(strcmp(list[i]->name , nam) == 0){
                    found = 1 ;
                    list[i]->amount += amm ;
                    break ; 
                }
            }
            if(found == 0){
                acc* new = malloc(sizeof(acc));
                strcpy(new->name , nam);
                new->amount = amm ;
                list = realloc(list , sizeof(acc*)*(size+1));
                list[size] = new ;
                size++;
            }
        }else if(strcmp("CHECK",op) == 0){
            char nam[51] ;
            scanf("%s",nam );
            int found = 0 ;
            for(int i = 0 ; i < size ; i++){
                if(strcmp(list[i]->name , nam) == 0){
                    found = 1 ;
                    printf("%lld\n",list[i]->amount);
                    break ; 
                }
            }
            if(found == 0){
                acc* new = malloc(sizeof(acc));
                strcpy(new->name , nam);
                new->amount = 0 ;
                list = realloc(list , sizeof(acc*)*(size+1));
                list[size] = new ;
                size++;
                printf("0\n");
            }
        }else  if(strcmp("WITHDRAW",op) == 0){
            char nam[51] ;
            long long amm ;
            scanf("%s %lld",nam , &amm);
            int found = 0 ;
            for(int i = 0 ; i < size ; i++){
                if(strcmp(list[i]->name , nam) == 0){
                    found = 1 ;
                    if(list[i]->amount - amm >=0) list[i]->amount -= amm ;
                    else{
                        printf("-1\n");
                    }
                    break ; 
                }
            }
            if(found == 0){
                acc* new = malloc(sizeof(acc));
                strcpy(new->name , nam);
                new->amount = 0 ;
                list = realloc(list , sizeof(acc*)*(size+1));
                list[size] = new ;
                size++;
                printf("-1\n");
            }
        }else{
            char nam1[51],nam2[51] ;//nam1 is from and nam2 is to
            long long amm ;
            scanf("%s %s %lld",nam1 ,nam2 , &amm);
            int f1 = 0 , f2 = 0 , exit = 0 ;
            for(int i = 0 ; i < size ; i++){
                if(strcmp(list[i]->name , nam1) == 0){
                    f1 = 1 ;
                    if(list[i]->amount >= amm){
                        list[i]->amount -= amm ; 
                    }else{
                        printf("-1\n");
                        exit = 1 ;
                    }
                    break ;
                }
            }
            if(exit == 0){
                for(int i = 0 ; i < size ; i++){
                if(strcmp(list[i]->name , nam2) == 0){
                    f2 = 1 ;
                    list[i]->amount += amm ;
                }
                }
            }
            if(f1 == 0){
                acc *new = malloc(sizeof(acc));
                    strcpy(new->name ,nam1) ;
                    new->amount = 0 ;
                    list = realloc(list , sizeof(acc*)*(size+1));
                    list[size] = new ;
                    size++;
            }
            if(f2 == 0){
                acc *new = malloc(sizeof(acc));
                    strcpy(new->name ,nam2) ;
                    if(exit == 0) new->amount = amm ;
                    else{
                        new->amount = 0 ;
                    }
                    list = realloc(list , sizeof(acc*)*(size+1));
                    list[size] = new ;
                    size++;
            }
        }
    }

    return 0 ;
}