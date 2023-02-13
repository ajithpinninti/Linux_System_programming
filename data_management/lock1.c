#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

int main(void){

    int file_desc;
    int save_err;

    file_desc = open("/tmp/LCK.test",O_RDWR|O_CREAT|O_EXCL, 0444);
    if( file_desc == -1){
        save_err = errno;
        printf("Open failed with error %d \n",save_err);
    }
    else{
        printf("Open Succeeded \n");
    }

    exit(EXIT_SUCCESS);
}