#include <unistd.h>
#include<stdlib.h>
#include <stdio.h>

#define A_MB (1024 * 1024)
#define PHY_MEM_MEGS 1024

int main(){
    char *some_memory;
    int msg_obtained = 0;
    while ((1))
    {
    
    
    while (1)
    {
        some_memory = (char *)malloc(A_MB);
        if(some_memory != NULL){
            msg_obtained++;
            sprintf(some_memory,"Hello World");
            printf("%s - now allocated %d Megabytes\n",some_memory,msg_obtained);
        }
        else{
            exit(EXIT_FAILURE);
        }
    }
    }
    
    exit(EXIT_SUCCESS);

}