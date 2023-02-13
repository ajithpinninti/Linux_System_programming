#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

const char *file_name = "/tmp/lock_test.txt";
int main(void){

    char *byte_to_write = "A";
    
    int file_desc;
    struct flock flock_region_1;
    struct flock flock_region_2;
    int result;
    /*Opening the file and writing data to it*/
    file_desc = open(file_name,O_CREAT|O_RDWR,0666);
    if(!file_desc){
        fprintf(stderr,"Unable to open %s for read/write \n",file_name);
    }

    //writing data to it
    for(int i=0;i<100;i++){
        (void)write(file_desc,byte_to_write,1);
    }

    // lcoking of the file between 10 to 30 bytes
    flock_region_1.l_type = F_RDLCK ;
    flock_region_1.l_whence = SEEK_SET;
    flock_region_1.l_start = 10;
    flock_region_1.l_len = 20;
    // lokcing of the file between 40 to 50
    flock_region_2.l_type = F_WRLCK;
    flock_region_2.l_whence = SEEK_SET;
    flock_region_2.l_start = 40;
    flock_region_2.l_len = 10;

    printf("Proces %d locking the file \n",getpid());
    result = fcntl(file_desc,F_SETLK,&flock_region_1);
    if(result == -1) fprintf(stderr, "Failed to lock the region 1 \n");
    result = fcntl(file_desc,F_SETLK,&flock_region_2);
    if(result == -1) fprintf(stderr, "failed to lock the region 2 \n");
    printf("Process %d locked the file successfullly \n",getpid());
    // wait for some time
    sleep(60);

    printf("Process %d closing the file \n",getpid());

    close(file_desc);

    exit(EXIT_SUCCESS);
}