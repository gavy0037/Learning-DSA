#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Atleast provide a single number\n");
        return 1;
    }

    int product = 1;
    for (int i = 1; i < argc; i++) {
        product *= atoi(argv[i]);
    }

    printf("Product = %d\n", product);
    return 0;
}
