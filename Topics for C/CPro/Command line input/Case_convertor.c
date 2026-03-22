#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc , char* argv[]){
    if(argc == 1) return 1; 

    for(int i = 1 ; i < argc ; i++){
        printf("WORD %d : Upper case: " , i);
        for(int j = 0 ; argv[i][j] != '\0' ; j++) printf("%c",toupper(argv[i][j]));

        printf("\n         Lower Case: ");

        for(int j = 0 ; argv[i][j] != '\0' ; j++) printf("%c",tolower(argv[i][j]));
        printf("\n");
    }

    return 0; 
}