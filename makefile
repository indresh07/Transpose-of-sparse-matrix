all: sparse.o main.o
	gcc -w -o sparse sparse.o main.o -Wno-deprecated

main.o: main.c
	gcc -c main.c -Wno-deprecated

sparse.o: sparse.h sparse.c
	gcc -c sparse.c -Wno-deprecated
clean:
	rm *.o
