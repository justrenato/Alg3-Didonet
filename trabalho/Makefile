all: busca

busca: arvoreB.o funcs.o
	gcc arvoreB.o funcs.o -o busca -g

arvoreB.o: arvoreB.c arvoreB.h
	gcc -c arvoreB.c -o arvoreB.o -g

funcs.o: funcs.c arvoreB.h
	gcc -c funcs.c -o funcs.o -g

	
clean:
	-rm -f *.o

purge: clean
	-rm -f busca a.out