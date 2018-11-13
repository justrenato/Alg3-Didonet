#ifndef __ARVOREB__
#define __ARVOREB__

#define FILHOESQ (*noAtual)->esq
#define FILHODIR (*noAtual)->dir
#define PAI (*noAtual)->pai
#define CHAVE (*noAtual)->chave
#define UNICOFILHODIR ((FILHODIR != NULL) && (FILHOESQ==NULL))
#define UNICOFILHOESQ ((FILHODIR == NULL) && (FILHOESQ!=NULL))

typedef struct tipoNoA
{
	struct tipoNoA *pai;
	struct tipoNoA *esq;
	struct tipoNoA *dir;
	int chave;
	// struct tipoNoB *chave;
}tipoNoA;

void criaArvoreA(int chave, tipoNoA **noAtual, int argc, tipoNoA *pai);
void inclui(int chave, tipoNoA **noAtual, int argc, tipoNoA *pai);
void imprimirEmOrdem( tipoNoA *noAtual);
int altura(tipoNoA *noAtual);
tipoNoA *busca(tipoNoA *noAtual, int valor);
tipoNoA *minimo(tipoNoA *noAtual);
tipoNoA *maximo(tipoNoA *noAtual);
tipoNoA *antecessor(tipoNoA *noAtual);
tipoNoA *sucessor(tipoNoA *noAtual);
tipoNoA exclusao(tipoNoA **noAtual);

#endif