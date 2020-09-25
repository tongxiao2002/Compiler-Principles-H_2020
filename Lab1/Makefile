CC = gcc -g
CFLAGS = -Wall

OBJS = sort.o

all = sort

sort: $(OBJS)
	cc -o sort $(OBJS)

sort.o: sort.c
	cc -c sort.c

clean:
	rm -f *~ *.o mmdrive
