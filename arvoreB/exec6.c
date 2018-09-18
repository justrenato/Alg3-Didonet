#include <stdio.h>
#include <stdlib.h>

int insercaoIterativa(tipoNo *raiz, int chave){
	tipoNo *noAtual;
	*noAtual = raiz;

	while(noAtual!=NULL){
		if (chave<noAtual->chave)
		{
			noAtual=noAtual->esq;
		}
		if (chave>noAtual->chave)
		{
			noAtual=noAtual->dir;
		}
		if (chave == noAtual->chave){
			return 0
		}
	}
	noAtual=(tipoNo *)malloc(sizeof(tipoNo));
}


int main(int argc, char const *argv[])
{
	return 0;
}