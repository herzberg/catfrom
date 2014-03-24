CC = gcc
CFLAGS = -wall

all: catfrom
	./catfrom catfrom.c 10
	
catfrom: catfrom.c
	$(CC) $(CFLAGS) -o catfrom catfrom.c

	

