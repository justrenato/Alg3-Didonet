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

void inclui(int chave, tipoNo *noAtual){
	if (noAtual==NULL)
	{
		noAtual = malloc(sizeof(tipoNo));
		noAtual->chave = chave;
		noAtual->esq = NULL;
		noAtual->dir = NULL;
		printf("inseri chave %d\n",noAtual->chave );
	}
	else {
		if (chave < noAtual->chave){
			inclui(chave,noAtual->esq );
		} 
		else {
			inclui(chave,noAtual->dir );
		}
	}

	#ifdef debug
		printf("inclui no\n");
	#endif
}

void imprimir( tipoNo *noRaiz){
	// if ((noRaiz->esq == NULL) && (noRaiz->dir == NULL))
	// {
	// 	printf(" %d ",noRaiz->chave );
	// }
	// if (noRaiz->esq !=NULL)
	// {
	// 	imprimir(noRaiz->esq);
	// }
	// else{
	// 	printf(" %d ",noRaiz->chave );
	// }
	// if (noRaiz->dir!=NULL){
	// 	imprimir(noRaiz->dir);
	// }
	// else{
	// 	printf(" %d ",noRaiz->chave );
	// }
	// printf("\n");
}


tipoNo raiz;
int main(int argc, char const *argv[])
{
	int chave;

	printf("Digite a raiz: \n");
	scanf("%d",&chave);

	criaArvore(chave, &raiz);

	int continuar;
	printf("Deseja inserir mais nós? 1-Sim 0-Não : ");
	scanf("%d",&continuar);
	while (continuar){
		printf("Digite a nova chave: \n");
		scanf("%d",&chave);
		inclui(chave,&raiz);
		printf("Deseja inserir mais nós? 1-Sim 0-Não : ");
		scanf("%d",&continuar);
	}
	imprimir(&raiz);

	return 0;
}