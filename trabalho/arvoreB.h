#ifndef __ARVOREB__
#define __ARVOREB__

typedef struct tipoNoB
{
	int chave;
	struct tipoNoB *esq;
	struct tipoNoB *dir;
}tipoNoB;

typedef struct tipoNoA
{
	struct tipoNoA *pai;
	struct tipoNoA *esq;
	struct tipoNoA *dir;
	int chave;
	int index;
	struct tipoNoB *arvSec;
}tipoNoA;

tipoNoA *incluiA(int chave, tipoNoA **noAtual, tipoNoA *pai, int index);
tipoNoB *incluiB(int index, tipoNoB **noAtual);
void imprimirB( tipoNoB *noAtual);
void imprimirA( tipoNoA *noAtual);
tipoNoA *buscaA(tipoNoA *noAtual, int valor, int imprimir);
void lerInst(int valores[], int *j, int *index);
tipoNoA *maximo(tipoNoA *noAtual);
tipoNoA *antecessor(tipoNoA *noAtual);
void exclusaoA(tipoNoA **noAtual, tipoNoA *excluido, int index);
int insercaoB (tipoNoA **noAtual);
void lerArq(tipoNoA **noAtual);

#endif