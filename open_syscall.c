#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
int main(void){
	int des = open("draft1.txt",O_RDWR);
	write(1,&des,1);

	exit(0);
}
