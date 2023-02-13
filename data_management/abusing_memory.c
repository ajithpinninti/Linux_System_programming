#include <stdlib.h>
#include <stdio.h>
#define ONE_K (1024)

int main(void){

    char* some_memory;
    char* scan_ptr;

    some_memory = (char *)malloc(ONE_K);

    if(some_memory == NULL) exit(EXIT_FAILURE);
    *some_memory = '\0';
    scan_ptr = some_memory;
    // scan_ptr = (char *) 0;
    // sprintf("Hello",scan_ptr);

    for(int i=0;i<1000000;i++){
    scan_ptr++;
    *scan_ptr = 'A';
    printf("%d) address is %lu   ",i,scan_ptr);
    printf("value is %d  \n",sizeof(*scan_ptr));

    }

    exit(EXIT_SUCCESS);
}