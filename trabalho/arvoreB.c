#include <stdio.h>
#include <stdlib.h>
// #include "arvoreB.h"


#define FILHOESQ2 (noAtual)->esq
#define FILHODIR2 (noAtual)->dir
#define FILHOESQ (*noAtual)->esq
#define FILHODIR (*noAtual)->dir
#define PAI (*noAtual)->pai
#define CHAVE (*noAtual)->chave
#define UNICOFILHODIR ((FILHODIR2 != NULL) && (FILHOESQ2==NULL))
#define UNICOFILHOESQ ((FILHODIR2 == NULL) && (FILHOESQ2!=NULL))

typedef struct tipoNoB
{
	int chave;
	struct tipoNoB *esq;
	struct tipoNoB *dir;
	// struct tipoNoB *chave;
}tipoNoB;

typedef struct tipoNoA
{
	struct tipoNoA *pai;
	struct tipoNoA *esq;
	struct tipoNoA *dir;
	int chave;
	tipoNoB chave2;
	// struct tipoNoB *chave;
}tipoNoA;

void criaArvoreA(int chave, tipoNoA **noAtual, int argc, tipoNoA *pai){
	(*noAtual) = (tipoNoA*)(malloc (sizeof(tipoNoA)));
	PAI = pai;
	FILHOESQ = NULL;
	FILHODIR = NULL;
	CHAVE = chave;

	// if (argc > 1){
		// printf("Criei arvore com nó: %d\n", CHAVE);
	// }
}
void inclui(int chave, tipoNoA **noAtual, int argc, tipoNoA *pai){
	if (*noAtual==NULL)
	{
		criaArvoreA(chave, noAtual, argc, pai);

		// if (argc > 1)
		// {
			// printf("inseri chave %d\n",CHAVE );
			// printf("pai: %d\n",PAI->chave);
		// }

	}
	else {
		if (chave <= CHAVE){
			inclui(chave,&(FILHOESQ),argc , (*noAtual));
		} 
		else {
			inclui(chave,&(FILHODIR), argc,(*noAtual));
		}
	}
}
void imprimirEmOrdem( tipoNoA *noAtual){
	if (noAtual!=NULL)
	{
		imprimirEmOrdem(noAtual->esq);
		printf(" %d ",noAtual->chave );
		imprimirEmOrdem(noAtual->dir);
	}
}
int altura(tipoNoA *noAtual){
	int ae, ad;
	if (noAtual==NULL){
		return 0;
	}
	ae = altura(noAtual->esq);
	ad = altura(noAtual->dir);

	if (ae>ad)
	{
		return ae+1;
	}
	else
		return ad+1;
}
tipoNoA *busca(tipoNoA *noAtual, int valor){
	tipoNoA *encontrado;
	if (noAtual==NULL)	
	{
		return NULL;
	}else
	if (valor < noAtual->chave)
	{
		printf("valor percorrido: %d\n",noAtual->chave );
		encontrado = busca(noAtual->esq, valor);
		return encontrado;
	} else
	if (noAtual->chave == valor)
	{
		return noAtual;
	} else
	if (valor > noAtual->chave){
		printf("valor percorrido: %d\n",noAtual->chave );
		encontrado = busca(noAtual->dir,valor);
		return encontrado;
	}
}
tipoNoA *minimo(tipoNoA *noAtual){
	if (noAtual->esq == NULL)
	{
		return noAtual;
	}
	else {
		minimo(noAtual->esq);
	}
}
tipoNoA *maximo(tipoNoA *noAtual){
	if (noAtual->dir == NULL)
	{
		return noAtual;
	}
	else {
		maximo(noAtual->dir);
	}
}
tipoNoA *antecessor(tipoNoA *noAtual){
	if (noAtual->esq != NULL)
	{
		return maximo(noAtual->esq);
	} else {
		return NULL;
	}
}
tipoNoA *sucessor(tipoNoA *noAtual){
	if (noAtual->dir != NULL)
	{
		return minimo(noAtual->dir);
	} else {
		return NULL;
	}
}

void exclusao(tipoNoA **noAtual, int chave){
	tipoNoA *aux, *excluido;
	excluido = busca((*noAtual), chave);
	//(*noAtual) = excluido; // DESSA FORMA CONSEGUI MUDAR A RAIZ :o
	if (*noAtual == NULL)
	{
		printf("exclusão não foi possivel\n");
	}
	else{
		aux = antecessor (*noAtual);

		if ((excluido->dir == NULL) && (excluido->esq==NULL)) //se for nó folha
		{
			if (excluido->pai == NULL) //se for a raiz
			{
				free(*noAtual);
				(*noAtual)== NULL;
			}else if ((excluido)->chave <= (excluido)->pai->chave) //se for filho da esquerda
			{
				aux = (excluido)->pai; //aponta para o pai para poder liberar memoria e apontar para NULL
				free(aux->esq); //libera memoria 
				aux->esq = NULL; //aponta para null
			} else { //se for filho da direita
				aux = (excluido)->pai;
				free(aux->dir);
				aux->dir = NULL;
			}
		}
		else if ( ((excluido->esq != NULL) && (excluido->dir == NULL)) || 
				  ((excluido->esq == NULL) && (excluido->dir != NULL)) )//se tiver um filho
		{
			if (excluido->pai == NULL) // se for a raiz
			{
				if (excluido->esq != NULL)
				{
					excluido->esq->pai == NULL;
					free(*noAtual);
					(*noAtual)=aux;
				} else{
					excluido->dir->pai == NULL;
					(*noAtual)=(*noAtual)->dir;
					free(excluido);
				}
			}else if ((excluido->esq != NULL) && (excluido->dir == NULL)) //se o unico filho for o da esquerda
			{
				if (excluido->pai->chave <= (excluido)->chave) //se NO excluido for filho da direita	
				{
					aux = excluido;
					excluido->pai->dir = aux->esq;
					aux->esq->pai = aux->pai;
					free(excluido);
					excluido = NULL;
				} 
				else {
					aux = excluido;
					excluido->pai->esq = aux->esq;
					aux->esq->pai = aux->pai;
					free(excluido);
					excluido = NULL;
				}
			}
			else { // se o unico filho for o da direita
				if (excluido->pai->chave > (excluido)->chave) //se NO excluido for filho da esquerda	
				{
					aux = excluido;
					excluido->pai->esq = aux->dir;
					aux->dir->pai = aux->pai;
					free(excluido);
				} 
				else //se NO excluido for filho da direita 
				{  	
					aux = excluido;
					excluido->pai->dir = aux->dir;
					aux->dir->pai = aux->pai;
					free(excluido);
				}
			}
		}



		else if ((excluido->dir != NULL) && (excluido->esq!=NULL)) // se tiver dois filhos (escolhi trocar pelo antecessor e nao pelo sucessor)
		{
			aux = antecessor ((excluido));
			if ((excluido)->pai !=NULL) //se não for exclusao da raiz
			{
				if (excluido->pai->dir == excluido) //excluido for filho da direita
				{
					if ((excluido)->esq == aux) // caso antecessor seja filho direto
					{
						aux->dir = (excluido)->dir;
						(excluido)->pai->dir = aux;
						aux->pai = excluido->pai;
						aux->dir->pai = aux;
						free(excluido);
						excluido = NULL;
					} else{ //caso antecessor não seja filho direto
						aux->pai->dir = NULL;
						aux->pai = excluido->pai;
						aux->pai->dir = aux;
						excluido->esq->pai=aux; 
						aux->esq = excluido->esq;
						excluido->dir->pai = aux;
						aux->dir = excluido->dir;
						free(excluido);
						excluido=NULL;
					}
				} else { //excluido for filho da esquerda
					if ((excluido)->esq == aux) // caso antecessor seja filho direto
					{
						aux->dir = (excluido)->dir;
						(excluido)->pai->esq = aux;
						aux->pai = excluido->pai;
						aux->dir->pai = aux;
						free(excluido);
						excluido = NULL;
					} else{ //caso antecessor não seja filho direto
						aux->pai->dir = NULL;
						aux->pai = excluido->pai;
						aux->pai->esq = aux;
						excluido->esq->pai=aux; 
						aux->esq = excluido->esq;
						excluido->dir->pai = aux;
						aux->dir = excluido->dir;
						free(excluido);
						excluido=NULL;	
					}
				}

			} else{ //exclusao da raiz
				if ((excluido)->esq == aux) //caso antecessor seja filho direto
				{
					aux->pai = NULL;
					aux->dir = excluido->dir;
					excluido->dir->pai = aux;
					(*noAtual)= aux; //IMPORTANTISSIMO
					free(excluido);
					excluido = NULL;
				} else{ //caso antecessor não seja filho direto
					aux->pai->dir = NULL;
					aux->pai = NULL;
					aux->esq = excluido->esq;
					aux->esq->pai = aux;
					aux->dir= excluido->dir;
					aux->dir->pai = aux;
					(*noAtual)= aux; //IMPORTANTISSIMO
					free(excluido);
					excluido = NULL;
				}
			}
		}
	}
}

tipoNoA *raiz;

int main(int argc, char const *argv[])
{
	// tipoNoB *chave = NULL;

	int chave;
	int valor;
	int buscar;

	//criação da arvore
	// if (argc>1)
	// {
		// printf("Digite a raiz: \n");
		scanf("%d",&chave);
	// }

	criaArvoreA(chave, &raiz, argc, NULL);

	int continuar;
	// printf("\nDeseja inserir mais nós? 1-Sim 0-Não : ");
	scanf("%d",&continuar);
	while (continuar){
		// printf("Digite a nova chave: \n");
		scanf("%d",&chave);
		inclui(chave,&raiz,argc, NULL);
		// printf("\nDeseja inserir mais nós? 1-Sim 0-Não : ");
		scanf("%d",&continuar);
	}

	//impressão
	printf("\nimpressao da arvore:\n");
	imprimirEmOrdem(raiz);
	printf("\n");
	//altura
	// printf("altura: %d\n", altura(raiz));

	//busca
	// printf("voce deseja buscar algum valor?\n");
	scanf("%d",&buscar);
	tipoNoA *encontrado;
	while(buscar){
		// printf("voce deseja buscar qual valor?\n");
		scanf("%d",&valor);

		encontrado = busca(raiz,valor);
		if (encontrado!=NULL){
			// printf("valor %d encontrado\n",encontrado->chave );
		}else{
			// printf("valor nao encontrado\n");
		}

		// printf("deseja buscar mais algum valor? 1-sim 0-nao:\n");
		scanf("%d",&buscar);
	}

	// printf("minimo da arvore: %d\n",(minimo(raiz))->chave );
	// printf("maximo da arvore: %d\n",(maximo(raiz))->chave );
	// printf("antecessor da arvore: %d\n",(antecessor(raiz))->chave );
	// printf("sucessor da arvore: %d\n",(sucessor(raiz))->chave);

	printf("\nimpressao da arvore pré exclusão:\n");
	imprimirEmOrdem(raiz);
	printf("\n");
	// printf("nó excluido: %d\n",(exclusao(raiz)).chave );;
	int excluir = 6;
	printf("excluir: %d\n",excluir );
	exclusao(&raiz,excluir);
	printf("\nimpressao da arvore pós exclusão:\n");
	imprimirEmOrdem(raiz);
	printf("\n");
	return 0;
}