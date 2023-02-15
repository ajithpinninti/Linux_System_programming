#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

const char *file_name = "/tmp/lock_test.txt";

int main(void){

    int file_desc;
    int res;

    file_desc = open(file_name, O_CREAT|O_RDWR, 0666);
    struct flock test_region;

    test_region.l_type = F_RDLCK;
    test_region.l_whence = SEEK_SET;
    test_region.l_start = 10;
    test_region.l_len = 5;

    printf("%d trying to FD_LCK the region %d to %d \n",getpid(),(int)test_region.l_start,(int)( test_region.l_start+test_region.l_len ));
    res = fcntl(file_desc,F_SETLK,&test_region);
    if(res == -1){
        printf("process %d - Locking failed \n",getpid());
    }
    else{
        printf("Process %d - Obtained lock region \n",getpid());
    }

    test_region.l_type = F_UNLCK;
    test_region.l_whence = SEEK_SET;
    test_region.l_start = 10;
    test_region.l_len = 5;

    printf("%d trying to UN_LCK the region %d to %d \n",getpid(),(int)test_region.l_start,(int)( test_region.l_start+test_region.l_len ));
    res = fcntl(file_desc,F_SETLK,&test_region);
    if(res == -1){
        printf("process %d - UnLocking failed \n",getpid());
    }
    else{
        printf("Process %d - Unlock region \n",getpid());
    }

    test_region.l_type = F_UNLCK;
    test_region.l_whence = SEEK_SET;
    test_region.l_start = 0;
    test_region.l_len = 50;

    printf("%d trying to FD_LCK the region %d to %d \n",getpid(),(int)test_region.l_start,(int)( test_region.l_start+test_region.l_len ));
    res = fcntl(file_desc,F_SETLK,&test_region);
    if(res == -1){
        printf("process %d - UnLocking failed \n",getpid());
    }
    else{
        printf("Process %d - Unlocked region \n",getpid());
    }

    test_region.l_type = F_WRLCK;
    test_region.l_whence = SEEK_SET;
    test_region.l_start = 16;
    test_region.l_len = 5;

    printf("%d trying to F_WRLCK the region %d to %d \n",getpid(),(int)test_region.l_start,(int)( test_region.l_start+test_region.l_len ));
    res = fcntl(file_desc,F_SETLK,&test_region);
    if(res == -1){
        printf("process %d - Locking failed \n",getpid());
    }
    else{
        printf("Process %d - Obtained lock region \n",getpid());
    }

    test_region.l_type = F_RDLCK;
    test_region.l_whence = SEEK_SET;
    test_region.l_start = 40;
    test_region.l_len = 10;

    printf("%d trying to F_RDLCK the region %d to %d \n",getpid(),(int)test_region.l_start,(int)( test_region.l_start+test_region.l_len ));
    res = fcntl(file_desc,F_SETLK,&test_region);
    if(res == -1){
        printf("process %d - Locking failed \n",getpid());
    }
    else{
        printf("Process %d - Obtained lock region \n",getpid());
    }

    test_region.l_type = F_WRLCK;
    test_region.l_whence = SEEK_SET;
    test_region.l_start = 16;
    test_region.l_len = 5;

    printf("%d trying to F_WRLCK with wait, the region %d to %d \n",getpid(),(int)test_region.l_start,(int)( ( test_region.l_start+test_region.l_len ) ));
    res = fcntl(file_desc,F_SETLKW,&test_region);
    if(res == -1){
        printf("process %d - Locking failed \n",getpid());
    }
    else{
        printf("Process %d - Obtained lock region \n",getpid());
    }

    printf("Process %d ending\n",getpid());
    close(file_desc);
    exit(EXIT_SUCCESS);







    exit(EXIT_SUCCESS);
}