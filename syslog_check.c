#include<syslog.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;

    f = fopen("not_here","r");

    if(f)
        syslog(LOG_ERR|LOG_USER,"ooops - %m\n");
 
    printf("completed");
    printf("completed too");
    
    
    exit(0);
}
