CC=gcc
AR=ar
FLAGS=-g -Wall

all: matrix connections

connections: main.o libclassmat.a
	$(CC) $(FLAGS) -o connections main.o libclassmat.a
matrix: libclassmat.a
libclassmat.a: my_mat.o
	$(AR) -rcs -o libclassmat.a my_mat.o

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c
main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c


.PHONY: clean all
clean:
	rm -f *.o *.a connections