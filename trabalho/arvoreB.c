#include <stdio.h>
#include <stdlib.h>
// #include "arvoreB.h"


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

void criaArvoreA(int chave, tipoNoA **noAtual, int argc, tipoNoA *pai){
	(*noAtual) = (tipoNoA*)(malloc (sizeof(tipoNoA)));
	PAI = pai;
	FILHOESQ = NULL;
	FILHODIR = NULL;
	CHAVE = chave;

	// if (argc > 1){
		printf("Criei arvore com nó: %d\n", CHAVE);
	// }
}
void inclui(int chave, tipoNoA **noAtual, int argc, tipoNoA *pai){
	if (*noAtual==NULL)
	{
		criaArvoreA(chave, noAtual, argc, pai);

		// if (argc > 1)
		// {
			printf("inseri chave %d\n",CHAVE );
			printf("pai: %d\n",PAI->chave);
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
tipoNoA exclusao(tipoNoA **noAtual){
	tipoNoA excluido, *aux;
	if ((FILHODIR == NULL) && (FILHOESQ==NULL)) //se for nó folha
	{
		if (CHAVE <= PAI->chave) //se for filho da esquerda
		{
			excluido = *PAI->esq; //salvando valor para indicar qual nó foi excluido
			aux = PAI; //aponta para o pai para poder liberar memoria e apontar para NULL
			free(PAI->esq); //libera memoria 
			aux->esq = NULL; //aponta para null
			return excluido; //retorna o nó excluido
		} else { //se for filho da direita
			excluido = *PAI->dir;
			aux = PAI;
			free(PAI->dir);
			aux->dir = NULL;
			return excluido;
		}
	}
	else if (UNICOFILHOESQ || UNICOFILHODIR)//se tiver um filho
	{
		if (UNICOFILHOESQ) //se o unico filho for o da esquerda
		{
			if (PAI->chave <= (*noAtual)->chave) //se NO excluido for filho da direita	
			{
				aux = *noAtual;
				excluido = *(*noAtual);
				PAI->dir = aux->esq;
				aux->esq->pai = aux->pai;
				free(*noAtual);
				return excluido;
			} 
			else {
				aux = *noAtual;
				excluido = *(*noAtual);
				PAI->esq = aux->esq;
				aux->esq->pai = aux->pai;
				free(*noAtual);
				return excluido;
			}
		} else { // se o unico filho for o da direita
			if (PAI->chave > (*noAtual)->chave) //se NO excluido for filho da esquerda	
			{
				aux = *noAtual;
				excluido = *(*noAtual);
				PAI->esq = aux->esq;
				aux->esq->pai = aux->pai;
				free(*noAtual);
				return excluido;
			} 
			else {  //se NO excluido for filho da direita	
				aux = *noAtual;
				excluido = *(*noAtual);
				PAI->dir = aux->esq;
				aux->esq->pai = aux->pai;
				free(*noAtual);
				return excluido;
			}
		}

	}
	else if ((FILHODIR != NULL) && (FILHOESQ!=NULL)) // se tiver dois filhos
	{
		excluido = *(*noAtual);
		printf("antecessor do nó %d: %d\n",(*noAtual)->chave, (antecessor (*noAtual))->chave);
		aux = antecessor ((*noAtual));
		if ((*noAtual)->pai !=NULL)
		{
			printf("\n\n\n\n\n\nponteiro esq do pai: %d\n",(*noAtual)->pai->esq->chave );
			(*noAtual)->pai->esq = aux;
			aux->pai = (*noAtual)->pai;
			aux->pai->dir = NULL;
			aux->esq = (*noAtual)->esq;
			aux->dir = (*noAtual)->dir;
			// free(*noAtual);
		} else{
			
		}
		return excluido;
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
		printf("Digite a raiz: \n");
		scanf("%d",&chave);
	// }

	criaArvoreA(chave, &raiz, argc, NULL);

	int continuar;
	printf("\nDeseja inserir mais nós? 1-Sim 0-Não : ");
	scanf("%d",&continuar);
	while (continuar){
		printf("Digite a nova chave: \n");
		scanf("%d",&chave);
		inclui(chave,&raiz,argc, NULL);
		printf("\nDeseja inserir mais nós? 1-Sim 0-Não : ");
		scanf("%d",&continuar);
	}

//impressão
	printf("\nimpressao da arvore:\n");
	imprimirEmOrdem(raiz);
	printf("\n");
//altura
	printf("altura: %d\n", altura(raiz));

//busca
	printf("voce deseja buscar algum valor?\n");
	scanf("%d",&buscar);
	tipoNoA *encontrado;
	while(buscar){
		printf("voce deseja buscar qual valor?\n");
		scanf("%d",&valor);

		encontrado = busca(raiz,valor);
		if (encontrado!=NULL){
			printf("valor %d encontrado\n",encontrado->chave );
		}else{
			printf("valor nao encontrado\n");
		}

		printf("deseja buscar mais algum valor? 1-sim 0-nao:\n");
		scanf("%d",&buscar);
	}

	printf("minimo da arvore: %d\n",(minimo(raiz))->chave );
	printf("maximo da arvore: %d\n",(maximo(raiz))->chave );
	printf("antecessor da arvore: %d\n",(antecessor(raiz))->chave );
	printf("sucessor da arvore: %d\n",(sucessor(raiz))->chave );

	printf("nó excluido: %d\n",(exclusao(&(raiz)->esq)).chave );;

	printf("\nimpressao da arvore pós exclusão:\n");
	imprimirEmOrdem(raiz);
	printf("\n");
	return 0;
}