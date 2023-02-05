#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

    char *var, *value;

    if( argc == 1 || argc >3){
        fprintf(stderr,"usage: environ var [value]\n");
        exit(1);
    }

    var = argv[1];
    value = getenv(var);

    if(value)
        printf("Variable %s has value %s\n", var, value);
    else
        printf("variable %s has no value \n",var);

    if(argc == 3){
        char *string;
        value = argv[2];
        string = malloc(strlen(var)+strlen(value)+2);

        if(!string){
            fprintf(stderr,"Out of Memory\n");
            exit(1);
        }
        //adding arg=val to string
        strcpy(string,argv[1]);
        strcat(string,"=");
        strcat(string,value);

        if(putenv(string) !=0){
            printf("putenv failed");
            free(string);
            exit(1);
        }
        value = getenv(var);
        if(value)
            printf("new value %s is %s \n",argv[1],argv[2]);
        else
            printf("New value of %s is null\n",var);
    }
        exit(0);
}
