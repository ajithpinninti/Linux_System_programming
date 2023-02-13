#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

const char *lock_file = "/tmp/Lock_file.test";

int main(void){
    
    int file_desc;
    int tries = 10;

    while (tries--)
    {
        file_desc = open(lock_file,O_CREAT|O_EXCL|O_RDWR,0444);
        if ( file_desc == -1){
            printf("%d - Lock already present \n",getpid());
            sleep(3);
        }
        else{

            /*Critical section start here*/
            printf("%d - I have exclusive access \n",getpid());
            sleep(1);
            (void)close(file_desc);
            (void)unlink(lock_file);
            /*critical section end here*/
            sleep(2);
        }
    }
    
    exit(EXIT_SUCCESS);
}