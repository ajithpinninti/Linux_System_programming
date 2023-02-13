#include<stdlib.h>
#include<stdio.h>

#define ONE_kb (1024)

int main(void){

    char *some_memory;
    int exit_code = EXIT_FAILURE;

    some_memory = (char *)malloc(ONE_kb);
    if(some_memory !=NULL){
        free(some_memory);
            printf("Memory allocated and free again");
            exit_code = EXIT_SUCCESS;
        }
    

    exit(exit_code);
}