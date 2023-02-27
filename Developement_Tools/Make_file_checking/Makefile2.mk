all:myapp

# Which compiler
CC = gcc

#WHere to install
INSTDIR = /usr/local/bin

#Where are include files kept
INCLUDE=

#Options for developement
CFLAGS= -g -Wall -ansi

#Options for relese
 #CFLAGS= -O -Wall -ansi
myapp: main.o 2.o 3.o 
	$(CC) -o myapp main.o 2.o 3.o
main.o: main.c a.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main.c
2.o: 2.c a.h b.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c 2.c
3.o: 3.c b.h c.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c 3.c

clean:
	-rm main.o 2.o 3.o	
install:
	@if[ -d $(INSTDIR) ];  \
		cp myapp $(INSTDIR);\
		chmod a+x $(INSTDIR)/myapp;\
		chmod og-w $(INSTDIR)/myapp;\
		echo "Installed in $(INSTDIR)";\
	else \
		echo "Sorry, $(INSTDIR) does not exit";\
	fi

	