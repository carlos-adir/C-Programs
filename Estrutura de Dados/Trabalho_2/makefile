all: programa clean

programa: main.o organiza.o opcoes.o arvore.o input.o entrada.o info.o professor.o lista.o
	gcc main.o organiza.o opcoes.o arvore.o input.o entrada.o info.o professor.o lista.o -o executavel

info.o:
	gcc -c info.c

professor.o: info.o
	gcc -c professor.c

lista.h: professor.o
	gcc -c lista.c

arvore.o: lista.o
	gcc -c arvore.c
	
input.o: lista.o
	gcc -c input.c

entrada.o:
	gcc -c entrada.c 

opcoes.o: arvore.o entrada.o
	gcc -c opcoes.c

organiza.o: arvore.o 
	gcc -c organiza.c

main.o: main.c organiza.o opcoes.o input.o
	gcc -c main.c

clean:
	rm *.o