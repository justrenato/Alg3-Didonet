#include <stdio.h>
#include <stdlib.h>
typedef struct tipoNo{
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
	// raiz = malloc(sizeof(tipoNo)); (ta bugando o codigo e fazendo sair da função com valor 0 na chave)
	raiz->chave = chaveRaiz;
	raiz->esq = NULL;
	raiz->dir = NULL;

	#ifdef debug
		printf("Criei arvore com raiz: %d\n", raiz->chave);
	#endif
}

void inclui(int chave, tipoNo *noRaiz){
	tipoNo *noAtual;
	noAtual = noRaiz;
	if (noRaiz==NULL)
	{
		noRaiz = malloc(sizeof(tipoNo));
		noRaiz->chave = chave;
		noRaiz->esq = NULL;
		noRaiz->dir = NULL;
		printf("inseri chave %d\n",noRaiz->chave );
	}
	else {
		if (chave < noRaiz->chave){
			inclui(chave,noRaiz->esq );
		} 
		else {
			inclui(chave,noRaiz->dir );
		}
	}

	#ifdef debug
		printf("inclui no\n");
	#endif
}

tipoNo raiz;
int main(int argc, char const *argv[])
{
	int chave;

	printf("Digite a raiz: \n");
	scanf("%d",&chave);

	criaArvore(chave, &raiz);

	printf("Digite a nova chave: \n");
	scanf("%d",&chave);

	inclui(chave,&raiz);
	return 0;
}