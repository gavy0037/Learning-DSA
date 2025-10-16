#include<stdio.h>
#include<limits.h>
#include<math.h>

void towerOfHanoi(int n , char from , char aux , char to){
    if(n == 1){
        printf("Shift disk 1 from %c to %c\n" , from , to);
        return ;
    }
    towerOfHanoi(n-1 , from , to , aux);
    printf("Shift disk %d form %c to %c\n",n,from , to);
    towerOfHanoi(n-1 , aux , from , to);
}

