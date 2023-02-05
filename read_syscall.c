#include<unistd.h>

int main(void){


	char buffer[20];
	int nread;

	nread = read(0, buffer, 20);
	if(nread == -1)
		write(1,"reading error has occured\n",26);
	if( (write(1,buffer,nread)) != nread)
		write(2,"A write error has occured\n",27);

	

	exit(0);
}
