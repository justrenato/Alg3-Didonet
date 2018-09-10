#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int chave;
	struct tipoNo *dir;
	struct tipoNo *esq;
	
}tipoNo;
 
tipoNo *criaNo(int chave){
	tipoNo *no;
	no = malloc (sizeof (tipoNo));
	no->chave = chave;
	no->dir = NULL;
	no->esq = NULL;

	#ifdef debug
		printf("Criei no\n");
	#endif
	
	return no;
}

void criaArvore(int chaveRaiz, tipoNo *raiz){

	raiz = malloc(sizeof(tipoNo));

	raiz->chave = chaveRaiz;
	raiz->esq = NULL;
	raiz->dir = NULL;

	#ifdef debug
		printf("Criei arvore\n");
	#endif
}

void inclui(int chave, tipoNo *noRaiz){
	tipoNo *noAtual = noRaiz;
		printf("nova Chave %d\n",chave);
		printf("atual-chave %d\n",noRaiz->chave);
	if (chave <= noAtual->chave){
		printf("to aqui\n");
		noAtual = noAtual->esq;
	} 
	// else {
	// 	noAtual = noAtual->dir;
	// }


	#ifdef debug
		printf("inclui no\n");
	#endif
}

tipoNo raiz;
int main(int argc, char const *argv[])
{
	int chave;

	printf("Digite a primeira chave: \n");
	scanf("%d",&chave);
	printf("Primeira chave: %d\n",chave);

	criaArvore(chave, &raiz);

	printf("Digite a segunda chave: \n");
	scanf("%d",&chave);

	inclui(chave,&raiz);
	return 0;
}