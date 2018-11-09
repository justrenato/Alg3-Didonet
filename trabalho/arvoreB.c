#include <stdio.h>
#include <stdlib.h>
typedef struct tipoNoB
{
	struct tipoNoB *esq;
	struct tipoNoB *dir;
	int chave;
}tipoNoB;

typedef struct tipoNoA
{
	struct tipoNoA *pai;
	struct tipoNoA *esq;
	struct tipoNoA *dir;
	struct tipoNoB *chave;
}tipoNoA;
 
void criaArvoreA(tipoNoB *chave, tipoNoA **raiz){
	(*raiz) = (tipoNoA*)(malloc (sizeof(tipoNoA)));
	(*raiz)->pai = NULL;
	(*raiz)->esq = NULL;
	(*raiz)->dir = NULL;
	(*raiz)->chave = chave;

	#ifdef debug
		printf("Criei arvore com raiz: %d\n", (*raiz)->chave);
	#endif
}

// void inclui(int chave, tipoNoA **noAtual){
// 	if (*noAtual==NULL)
// 	{
// 		(*noAtual) = (tipoNoA *) malloc(sizeof(tipoNoA));
// 		(*noAtual)->chave = chave;
// 		(*noAtual)->esq = NULL;
// 		(*noAtual)->dir = NULL;
// 		#ifdef debug
// 			printf("inseri chave %d\n",(*noAtual)->chave );
// 		#endif
// 	}
// 	else {
// 		if (chave <= (*noAtual)->chave){
// 			inclui(chave,&((*noAtual)->esq) );
// 		} 
// 		else {
// 			inclui(chave,&((*noAtual)->dir) );
// 		}
// 	}
// }

// void imprimirEmOrdem( tipoNoA *noRaiz){
// 	if (noRaiz!=NULL)
// 	{
// 		imprimirEmOrdem(noRaiz->esq);
// 		printf(" %d ",noRaiz->chave );
// 		imprimirEmOrdem(noRaiz->dir);
// 	}
// }

// int altura(tipoNoA *noRaiz){
// 	int ae, ad;
// 	if (noRaiz==NULL){
// 		return 0;
// 	}
// 	ae = altura(noRaiz->esq);
// 	ad = altura(noRaiz->dir);

// 	if (ae>ae)
// 	{
// 		return ae+1;
// 	}
// 	else
// 		return ad+1;
// }

// tipoNoA *busca(tipoNoA *raiz, int trajeto, int valor){
// 	if (raiz==NULL)	
// 	{
// 		return NULL;
// 	}
// 	if (trajeto==1)
// 	{
// 		if (valor < raiz->chave)
// 		{
// 			printf("valor percorrido: %d\n",raiz->chave );
// 			busca(raiz->esq, trajeto, valor);
// 		}
// 		if (raiz->chave == valor)
// 		{
// 			return raiz;
// 		}
// 		if (valor > raiz->chave){
// 			printf("valor percorrido: %d\n",raiz->chave );
// 			busca(raiz->dir,trajeto,valor);
// 		}
// 	}
// 	if (trajeto==2)
// 	{
// 		if (raiz->chave == valor)
// 		{
// 			return raiz;

// 		}
// 		if (valor < raiz->chave)
// 		{
// 			printf("valor percorrido: %d\n",raiz->chave );
// 			busca(raiz->esq, trajeto, valor);
// 		}
// 		if (valor > raiz->chave){
// 			printf("valor percorrido: %d\n",raiz->chave );
// 			busca(raiz->dir,trajeto,valor);
// 		}
// 	}
// 	if (trajeto==3)
// 	{
// 		if (valor < raiz->chave)
// 		{
// 			printf("valor percorrido: %d\n",raiz->chave );
// 			busca(raiz->esq, trajeto, valor);
// 		}
// 		if (valor > raiz->chave){
// 			printf("valor percorrido: %d\n",raiz->chave );
// 			busca(raiz->dir,trajeto,valor);
// 		}
// 		if (raiz->chave == valor)
// 		{
// 			return raiz;

// 		}
// 	}
// }
// tipoNoA *minimo(tipoNoA *noAtual){
// 	if (noAtual->esq == NULL)
// 	{
// 		return NULL;
// 	}
// 	else {
// 		minimo(noAtual->esq);
// 	}
// }
// tipoNoA *maximo(tipoNoA *noAtual){
// 	if (noAtual->dir == NULL)
// 	{
// 		return NULL;
// 	}
// 	else {
// 		maximo(noAtual->dir);
// 	}
// }

// tipoNoA *antecessor(tipoNoA *noAtual, int passagem){
// 	if (noAtual->esq != NULL)
// 	{
// 		return maximo(noAtual->esq);
// 	} 
// 	//else{} caso o antecessor seja o pai omg
// }


// // int alturaExecRecur(tipoNoA *raiz){
// // 	int ae,ad;
// // 	if (raiz == NULL)
// // 	{
// // 		return 0;
// // 	}
// // 	ae = alturaExecRecur(raiz->esq);
// // 	ad = alturaExecRecur(raiz->dir);
// // 	if (ae>ad)
// // 	{
// // 		return ae+=1;
// // 	}
// // 	 else
// // 	{
// // 		return ad+=1;
// // 	}
// // }

// void rotDir(tipoNoA **raiz){
// 	tipoNoA *aux;
// 	aux = (*raiz)->esq;
// 	(*raiz)->esq = aux->dir;
// 	aux->dir = (*raiz);
// 	// if ((*raiz)->dir->esq == NULL)
// 	// {
// 	// 	(*raiz)->dir->esq = (*raiz);
// 	// 	(*raiz)->dir ==NULL;
// 	// }
// 	// else{
// 	// 	tipoNoA *aux = (*raiz)->dir->esq;
// 	// 	(*raiz)->dir->esq = (*raiz);
// 	// 	(*raiz)->dir ==aux;

// 	// }
// }

tipoNoA *raiz;
int main(int argc, char const *argv[])
{
	tipoNoB *chave = NULL;
// 	int valor;
// 	int trajeto;
// 	int buscar;

// //criação da arvore
// 	printf("Digite a raiz: \n");
// 	scanf("%d",&chave);

	criaArvoreA(chave, &raiz);

// 	int continuar;
// 	printf("Deseja inserir mais nós? 1-Sim 0-Não : ");
// 	scanf("%d",&continuar);
// 	while (continuar){
// 		printf("Digite a nova chave: \n");
// 		scanf("%d",&chave);
// 		inclui(chave,&raiz);
// 		printf("Deseja inserir mais nós? 1-Sim 0-Não : ");
// 		scanf("%d",&continuar);
// 	}
// //impressão
// 	printf("\nimpressao da arvore:\n");
// 	imprimirEmOrdem(raiz);
// 	printf("\n");
// //altura
// // 	printf("altura: %d\n", altura(raiz));

// // //busca
// // 	printf("voce deseja buscar algum valor?\n");
// // 	scanf("%d",&buscar);
// // 	tipoNoA *buscado;
// // 	while(buscar){
// // 		printf("voce deseja buscar qual valor?\n");
// // 		scanf("%d",&valor);
// // 		printf("Digite 1 para buscar em ordem - 2 pré ordem - 3 pós ordem\n");
// // 		scanf("%d",&trajeto);

// // 		// *buscado = *busca(raiz, trajeto,valor);
// // 		if (buscado!=NULL){
// // 			printf("valor %d encontrado\n",buscado->chave );
// // 		}else{
// // 			printf("valor nao encontrado\n");
// // 		}

// // 		printf("deseja buscar mais algum valor? 1-sim 0-nao:\n");
// // 		scanf("%d",&buscar);
// // 	}

// 	// int passagem = 0;
// 	// tipoNoA *ant = antecessor(buscado,passagem);
// 	// if ((buscado!=NULL) && (ant != NULL))
// 	// {
// 	// 	printf("antecessor: %d\n",ant->chave );
// 	// }else{
// 	// 	printf("não ha antecessor\n");
// 	// }	
// 	printf("altura: %d \n",altura(raiz) );
// 	puts("rotaçao esq:\n");
// 	rotDir(&raiz);
// 	printf("altura: %d \n",altura(raiz) );
	return 0;
}