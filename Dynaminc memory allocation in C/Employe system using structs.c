#include<stdio.h>
#include<stdlib.h>

typedef struct emp{
    char *name ;
    float salary ;
    int noofprojects ;
    char **projects ;
}emp ;

    void show(emp* a){
        printf("Name : %s\n",a->name);
        //free(a->name);
        printf("Salary: %.02f\n",a->salary);
        if(a->noofprojects){
            printf("Projects :\n");
            for(int i = 0 ; i < a->noofprojects ; i++){
                printf("%d. %s\n",i+1,a->projects[i]);
            }
        }else{
            printf("No projects\n");
        }
        printf("\n");
        //free(a->projects);
        //free(a);
    }

int main(){
    int n ;
    scanf("%d",&n);
    getchar();//remove the space from the input buffer after entering the number

    emp **list = malloc(sizeof(emp*)*n);
    for(int i = 0 ; i < n ; i++){
        printf("Enter data for employe no %d\n",i+1);
        emp *newemp = malloc(sizeof(emp));
        
        char a ;
        printf("Enter name: ");
        int size = 0 ;
        newemp->name = malloc(sizeof(char));
        while((a = getchar()) != '\n'){//see if the current input is new line or not
            newemp->name = realloc(newemp->name , sizeof(char)*(size+1));
            newemp->name[size++] = a ;
        }
        newemp->name[size] = '\0';


        printf("Enter salary: ");
        scanf("%f",&(newemp->salary));

        printf("Enter number of projects: ");
        scanf("%d",&(newemp->noofprojects));

        getchar();//to remove the extra newline from the buffer after entering no of projects


        newemp->projects = malloc(sizeof(char*)*(newemp->noofprojects));
        for(int i = 0 ; i < newemp->noofprojects ; i++){
            
            printf("Enter project %d's name : ",i+1);
            size = 0 ;
            char* nam = malloc(1*sizeof(char));
            while((a = getchar()) != '\n'){
                nam = realloc(nam , sizeof(char)*(size+1));
                nam[size++] = a ;
            }
            nam[size] = '\0';
            
            newemp->projects[i] = nam ;
        }

        list[i] = newemp ;
    }


    printf("\n********* Data of all employes *********\n");

    
    for(int i = 0 ; i < n ; i++){
        show(list[i]);
        free(list[i]);
    }
    free(list);

    return 0;

}