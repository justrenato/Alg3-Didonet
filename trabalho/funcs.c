#include <stdio.h>
#include <stdlib.h>
#include "arvoreB.h"

tipoNoA *incluiA(int chave, tipoNoA **noAtual, tipoNoA *pai, int index){
	if (*noAtual==NULL)
	{
		(*noAtual) = (tipoNoA*)(malloc (sizeof(tipoNoA)));
		(*noAtual)->pai = pai;
		(*noAtual)->esq = NULL;
		(*noAtual)->dir = NULL;
		(*noAtual)->chave = chave;
		(*noAtual)->index = index;
		return (*noAtual);
	}
	else {
		if (index <= (*noAtual)->index){
			incluiA(chave,&((*noAtual)->esq) , (*noAtual), index);
		} 
		else {
			incluiA(chave,&((*noAtual)->dir),(*noAtual), index);
		}
	}
}
tipoNoB *incluiB(int index, tipoNoB **noAtual){
	if (*noAtual==NULL)
	{
		(*noAtual) = (tipoNoB*)(malloc (sizeof(tipoNoB)));
		(*noAtual)->esq = NULL;
		(*noAtual)->dir = NULL;
		(*noAtual)->chave = index;
		return (*noAtual);
	}
	else {
		if (index <= (*noAtual)->chave){
			incluiB(index,&((*noAtual)->esq));
		} 
		else {
			incluiB(index,&((*noAtual)->dir));
		}
	}
}

void imprimirB( tipoNoB *noAtual){
	if (noAtual!=NULL)
	{
		printf("(");
		printf("%d",noAtual->chave );
		if ((noAtual->esq == NULL) && (noAtual->dir != NULL))
		{
			printf("()");
		}
		imprimirB(noAtual->esq);
		if ((noAtual->dir == NULL) && (noAtual->esq != NULL))
		{
			printf("()");
		}
		imprimirB(noAtual->dir);
		printf(")");
	}
}
void imprimirA( tipoNoA *noAtual){
	if (noAtual!=NULL)
	{
		printf("[");
		imprimirB(noAtual->arvSec);
		printf(" : %d ",noAtual->index );
		printf("\n");
		if ((noAtual->esq == NULL) && (noAtual->dir != NULL))
		{
			printf("[\n]\n");
		}else {
			imprimirA(noAtual->esq);
		}
		if ((noAtual->dir == NULL) && (noAtual->esq != NULL))
		{
			printf("[\n]\n");
		}else{
			imprimirA(noAtual->dir);
		}
		printf("]\n");
	}
}
tipoNoA *buscaA(tipoNoA *noAtual, int valor, int imprimir){
	tipoNoA *encontrado;
	if (noAtual==NULL)	
	{
		return NULL;
	}else
	if (valor < noAtual->index)
	{
		if (imprimir)
		{
			imprimirB(noAtual->arvSec);
			printf(" : %d\n",noAtual->index);
		}
		encontrado = buscaA(noAtual->esq, valor,imprimir);
		return encontrado;
	} else
	if (noAtual->index == valor)
	{
		if (imprimir)
		{
			imprimirB(noAtual->arvSec);
			printf(" : %d\n",noAtual->index);
		}
		return noAtual;
	} else
	if (valor > noAtual->index){
		if (imprimir)
		{
			imprimirB(noAtual->arvSec);
			printf(" : %d\n",noAtual->index);
		}
		encontrado = buscaA(noAtual->dir,valor,imprimir);
		return encontrado;
	}
}
void lerInst(int valores[], int *j, int *index){
	int i=0;
	char c = getchar ()/*ler espaço*/, f = feof (stdin),num[8];
	f = feof (stdin); //verifica se é o final do arquivo
	while ((c!='\n')&& (!f)){ //enquanto nao for proxima instrução nem final do arquivo
		c = getchar (); 

		if((c!= '(' ) && (c!=')') && (c!= '\n')){ //se nao for parenteses nem quebra de linha
			num[i]=c;
			i++;
		} else if (((c=='(')||(c==')')) && (i!=0)){ //se for parenteses E nao for inicio da leitura da subArvore (i!=0)
			num[i]='\0';
			int valor = atoi(num);
			valores[(*j)]=valor;
			*index = *index + valor;
			// printf("inserido: %d\n",valor );
			i=0;
			(*j)++;
		}
		f = feof (stdin);
	}
	valores[(*j)]=0;
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
void exclusaoA(tipoNoA **noAtual, tipoNoA *excluido, int index){
	tipoNoA *aux;
	//(*noAtual) = excluido; // DESSA FORMA CONSEGUI MUDAR A RAIZ :o
	if (excluido == NULL)
	{
		printf("exclusão não foi possivel\n");
	}
	else{
		aux = antecessor (excluido);

		if ((excluido->dir == NULL) && (excluido->esq==NULL)) //se for nó folha
		{
			if (excluido->pai == NULL) //se for a raiz
			{
				free(*noAtual);
				(*noAtual)= NULL;
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
					excluido->esq->pai = NULL;
					free(*noAtual);
					(*noAtual)=aux;
				} else{
					excluido->dir->pai = NULL;
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
			if ((excluido)->pai !=NULL) //se não for exclusaoA da raiz
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

			} else{ //exclusaoA da raiz
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
	int index = 0, j=0,valores[100];
	tipoNoA *novoNo;

	lerInst(valores, &j, &index);
	j=0;
	novoNo = incluiA(valores[0],noAtual, NULL,index);

	while (valores[j]!= 0){
		incluiB(valores[j],&(novoNo)->arvSec);
		j++;
	}
	j=0;

	// printf("index: %d\n",index);
	printf("\n");
	return index;
}

void lerArq(tipoNoA **noAtual){
	char c='\0', f = feof (stdin);
	int index = 0, j=0,valores[100];
	tipoNoA *excluido;
	while ((!f)){
		c = getchar (); //identifica qual é a instrução da vez
		f = feof (stdin); //analisa se ja é fim de arquivo

		switch(c){
			case 'i':
				// printf("\ninserção na arvore:\n");
				insercaoB(noAtual);
				imprimirA(*noAtual);
				printf("\n");
			break;
			case 'b':
				index = 0, j=0;
				lerInst(valores, &j, &index);
				// printf("\nimpressao da busca por %d:\n",index);
				buscaA(*noAtual, index,1);
				printf("\n");
			break;
			case 'r':
				index = 0, j=0;
				lerInst(valores, &j, &index);
				excluido = buscaA((*noAtual), index,0);
				// printf("remoção da arvore: %d\n",index);
				exclusaoA(noAtual, excluido,index);
				imprimirA(*noAtual);
				printf("\n");
			break;
		}
	}
}