#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int chave;
	struct no *dir;
	struct no *esq;
	
}tipoNo;
 
tipoNo *criaNo(int chave){
	tipoNo *no;
	no = malloc (sizeof (tipoNo));
	no->chave = chave;
	no->dir = NULL;
	no->esq = NULL;
	return no;
}

tipoNo *inicializar(int chave){
	return criaNo(chave);
}

void inclui(int chave, tipoNo *noAtual){

}

int main(int argc, char const *argv[])
{
	printf("oi rs\n");
	return 0;
}