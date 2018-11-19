#include <stdio.h>
#include <stdlib.h>
// #include "arvoreB.h"


#define FILHOESQ2 (noAtual)->esq
#define FILHODIR2 (noAtual)->dir
#define FILHOESQ (*noAtual)->esq
#define FILHODIR (*noAtual)->dir
#define PAI (*noAtual)->pai
#define CHAVE (*noAtual)->index
#define UNICOFILHODIR ((FILHODIR2 != NULL) && (FILHOESQ2==NULL))
#define UNICOFILHOESQ ((FILHODIR2 == NULL) && (FILHOESQ2!=NULL))

typedef struct tipoNoB
{
	int index;
	struct tipoNoB *esq;
	struct tipoNoB *dir;
	struct tipoNoB *indexB;
}tipoNoB;

typedef struct tipoNoA
{
	struct tipoNoA *pai;
	struct tipoNoA *esq;
	struct tipoNoA *dir;
	int index;
	struct tipoNoB *arvSec;
}tipoNoA;

tipoNoA *incluiA(int index, tipoNoA **noAtual, tipoNoA *pai){
	if (*noAtual==NULL)
	{
		(*noAtual) = (tipoNoA*)(malloc (sizeof(tipoNoA)));
		(*noAtual)->pai = pai;
		(*noAtual)->esq = NULL;
		(*noAtual)->dir = NULL;
		(*noAtual)->index = index;
		// printf("inseri index %d\n",(*noAtual)->index );
		// printf("pai: %d\n",(*noAtual)->pai->index);
		return (*noAtual);
	}
	else {
		if (index <= (*noAtual)->index){
			incluiA(index,&((*noAtual)->esq) , (*noAtual));
		} 
		else {
			incluiA(index,&((*noAtual)->dir),(*noAtual));
		}
	}
}
tipoNoB *incluiB(int index, tipoNoB **noAtual){
	if (*noAtual==NULL)
	{
		(*noAtual) = (tipoNoB*)(malloc (sizeof(tipoNoB)));
		(*noAtual)->esq = NULL;
		(*noAtual)->dir = NULL;
		(*noAtual)->index = index;
		// printf("inseri index %d\n",(*noAtual)->index );
		return (*noAtual);
	}
	else {
		if (index <= (*noAtual)->index){
			incluiB(index,&((*noAtual)->esq));
		} 
		else {
			incluiB(index,&((*noAtual)->dir));
		}
	}
}
void imprimirEmOrdem( tipoNoA *noAtual, tipoNoB *subArvore){
	if (noAtual!=NULL)
	{
		imprimirEmOrdem(noAtual->esq);
		printf(" %d ",noAtual->index );
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
	if (valor < noAtual->index)
	{
		printf("valor percorrido: %d\n",noAtual->index );
		encontrado = busca(noAtual->esq, valor);
		return encontrado;
	} else
	if (noAtual->index == valor)
	{
		return noAtual;
	} else
	if (valor > noAtual->index){
		printf("valor percorrido: %d\n",noAtual->index );
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
void exclusao(tipoNoA **noAtual, int index){
	tipoNoA *aux, *excluido;
	excluido = busca((*noAtual), index);
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
			}else if ((excluido)->index <= (excluido)->pai->index) //se for filho da esquerda
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
				if (excluido->pai->index <= (excluido)->index) //se NO excluido for filho da direita	
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
				if (excluido->pai->index > (excluido)->index) //se NO excluido for filho da esquerda	
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

int insercaoB (tipoNoA **noAtual){
	int index = 0, i=0,j=0, valores[100];
	char c = getchar ()/*ler espaço*/, f = feof (stdin),num[8];
	f = feof (stdin); //verifica se é o final do arquivo
	tipoNoA *novoNo;
	while ((c!='\n')&& (!f)){ //enquanto nao for proxima instrução nem final do arquivo
		c = getchar (); 

		if((c!= '(' ) && (c!=')') && (c!= '\n')){ //se nao for parenteses nem quebra de linha
			num[i]=c;
			i++;
		} else if (((c=='(')||(c==')')) && (i!=0)){ //se for parenteses E nao for inicio da leitura da subArvore (i!=0)
			num[i]='\0';
			int valor = atoi(num);
			valores[j]=valor;
			index = index + valor;
			printf("valor: %d\n",valor );
			i=0;
			j++;
		}
		f = feof (stdin);
	}
	valores[j]=0;
	j=0;
	novoNo = incluiA(index,noAtual, NULL);

	while (valores[j]!= 0){
		incluiB(valores[j],&(novoNo)->arvSec);
		j++;
	}
	j=0;

	printf("index: %d\n",index);
	printf("\n");
	return index;

}

void lerArq(tipoNoA **noAtual){
	char c, f = feof (stdin);

	while (!f){
		c = getchar (); //identifica qual é a instrução da vez
		f = feof (stdin); //analisa se ja é fim de arquivo

		switch(c){
			case 'i':
				insercaoB(noAtual);
			break;
			case 'b':
				printf("busca\n");
			break;
			case 'r':
				printf("remoção\n");		
			break;
		}
	}
}

tipoNoA *raiz;

int main(int argc, char const *argv[])
{
	// // tipoNoB *index = NULL;

	// int index;
	// int valor;
	// int buscar;

	// //criação da arvore
	// // if (argc>1)
	// // {
	// 	// printf("Digite a raiz: \n");
	// 	scanf("%d",&index);
	// // }

	// criaArvoreA(index, &raiz, argc, NULL);

	// int continuar;
	// // printf("\nDeseja inserir mais nós? 1-Sim 0-Não : ");
	// scanf("%d",&continuar);
	// while (continuar){
	// 	// printf("Digite a nova index: \n");
	// 	scanf("%d",&index);
	// 	incluiA(index,&raiz,argc, NULL);
	// 	// printf("\nDeseja inserir mais nós? 1-Sim 0-Não : ");
	// 	scanf("%d",&continuar);
	// }

	// //impressão
	// printf("\nimpressao da arvore:\n");
	// imprimirEmOrdem(raiz);
	// printf("\n");
	// //altura
	// // printf("altura: %d\n", altura(raiz));

	// //busca
	// // printf("voce deseja buscar algum valor?\n");
	// scanf("%d",&buscar);
	// tipoNoA *encontrado;
	// while(buscar){
	// 	// printf("voce deseja buscar qual valor?\n");
	// 	scanf("%d",&valor);

	// 	encontrado = busca(raiz,valor);
	// 	if (encontrado!=NULL){
	// 		// printf("valor %d encontrado\n",encontrado->index );
	// 	}else{
	// 		// printf("valor nao encontrado\n");
	// 	}

	// 	// printf("deseja buscar mais algum valor? 1-sim 0-nao:\n");
	// 	scanf("%d",&buscar);
	// }

	// // printf("minimo da arvore: %d\n",(minimo(raiz))->index );
	// // printf("maximo da arvore: %d\n",(maximo(raiz))->index );
	// // printf("antecessor da arvore: %d\n",(antecessor(raiz))->index );
	// // printf("sucessor da arvore: %d\n",(sucessor(raiz))->index);

	// printf("\nimpressao da arvore pré exclusão:\n");
	// imprimirEmOrdem(raiz);
	// printf("\n");
	// // printf("nó excluido: %d\n",(exclusao(raiz)).index );;
	// int excluir = 6;
	// printf("excluir: %d\n",excluir );
	// exclusao(&raiz,excluir);
	// return 0;

	lerArq(&raiz);
	printf("\nimpressao da arvore:\n");
	imprimirEmOrdem(raiz);
	printf("\n");
}