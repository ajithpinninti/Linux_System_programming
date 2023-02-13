#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

const char *file_name = "/tmp/lock_test.txt";
#define SIZE_TO_TRY 5
void show_lock_info(struct flock *to_show);

int main(void){

    int file_desc;
    int result;
    struct flock flock_region_to_test;
    int start_byte;

    /*Open file descriptor*/
    file_desc = open(file_name, O_RDWR | O_CREAT,0666);
    if(!file_desc){
        fprintf(stderr,"unable to open %s for read/write \n",file_name);
        exit(EXIT_FAILURE);
    }
    

    /*testing the lock on all the region */
    for(start_byte = 0; start_byte <99; start_byte += SIZE_TO_TRY){

        flock_region_to_test.l_type = F_WRLCK;
        flock_region_to_test.l_start = start_byte;
        flock_region_to_test.l_len = SIZE_TO_TRY;
        flock_region_to_test.l_whence =  SEEK_SET;
        flock_region_to_test.l_pid = -1;

        printf("testing F_WRLCK on region fromm %d to %d \n",start_byte,start_byte+SIZE_TO_TRY);
        result = fcntl(file_desc, F_GETLK,&flock_region_to_test);

        if( result == -1){
            printf(" F_GETLK failed \n");
            exit(EXIT_FAILURE);
        }

        if( flock_region_to_test.l_pid != -1){
            printf("Lock would fail F_GETLK returned:\n");
            show_lock_info(&flock_region_to_test);
        }
        else{
            printf("F_WRLCK - LOCK would succeed \n");
        }


        flock_region_to_test.l_type = F_RDLCK;
        flock_region_to_test.l_start = start_byte;
        flock_region_to_test.l_len = SIZE_TO_TRY;
        flock_region_to_test.l_whence = SEEK_SET;
        flock_region_to_test.l_pid = -1;

        printf(" Testing F_RDLCK on region from %d to %d \n",start_byte,start_byte+SIZE_TO_TRY);
        /* Test the lock file again*/
        result = fcntl(file_desc,F_GETLK,&flock_region_to_test);
        if(result == -1){
            fprintf(stderr,"F_GETLK failed \n");
            exit(EXIT_FAILURE);
        }
        if(flock_region_to_test.l_pid != -1){
            printf("Lock would fail. F_GETLK returned: \n");
            show_lock_info(&flock_region_to_test);
        }
        else{
            printf("F_RDLCK - Lock would succeed \n");
        }

    }

    close(file_desc);
    exit(EXIT_SUCCESS);

}

void show_lock_info(struct flock *toshow){

    printf("\tl_type %d, ", toshow->l_type);
    printf("l_whence %d, ", toshow->l_whence);
    printf("l_start %d, ",toshow->l_start);
    printf("l_len %d, ",toshow->l_len);
    printf("l_pid %d, \n",getpid());
}
