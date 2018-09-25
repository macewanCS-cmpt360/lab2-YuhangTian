#CMPT360
#Lab2
#Yuhang Tian
#3012401
#This is a makefile to compile all the working c files.

CC=gcc 
CFLAGS= -Wall -std=c99 -g  


all: q1 q2 q3 q7 shell

q1: q1.c 
	$(CC) $(CFLAGS) -o q1 q1.c

q2: q2.c  
	$(CC) $(CFLAGS) -o q2 q2.c

q3: q3.c  
	$(CC) $(CFLAGS) -o q3 q3.c 

q7: q7.c  
	$(CC) $(CFLAGS) -o q7 q7.c

shell: shell.c
	$(CC) $(CFLAGS) -o shell shell.c

clean: 
	rm -f *.o q1 q2 q3 q7 shell
