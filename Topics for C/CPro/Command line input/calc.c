#include<stdio.h>
#include<stdlib.h>

int main(int argc , char* argv[]){
    if(argc != 4) return 1 ;

    float a = atof(argv[1]);
    float b = atof(argv[3]);

    char op = argv[2][0];

    switch(op){
        case '+':
        printf("%.2f\n",a+b);
        break ;

        case '-':
        printf("%.2f\n",a-b);
        break ;

        case 'x':
        printf("%.2f\n",a*b);
        break ;

        case '/':
        if(b == 0){
            printf("Invalid input\n");
            return 0 ;
        }
        printf("%.2f\n",a/b);
        break ;

        default:
        printf("Invalid input\n");
        
    }
    return 0 ;
}