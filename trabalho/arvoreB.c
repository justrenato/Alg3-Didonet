#include <stdio.h>
#include <stdlib.h>
// typedef struct tipoNoB
// {
// 	struct tipoNoB *esq;
// 	struct tipoNoB *dir;
// 	int chave;
// }tipoNoB;

typedef struct tipoNoA
{
	struct tipoNoA *pai;
	struct tipoNoA *esq;
	struct tipoNoA *dir;
	int chave;
	// struct tipoNoB *chave;
}tipoNoA;
 
void criaArvoreA(int chave, tipoNoA **raiz, int argc, tipoNoA *pai){
	(*raiz) = (tipoNoA*)(malloc (sizeof(tipoNoA)));
	(*raiz)->pai = pai;
	(*raiz)->esq = NULL;
	(*raiz)->dir = NULL;
	(*raiz)->chave = chave;

	// if (argc > 1){
		printf("Criei arvore com nó: %d\n", (*raiz)->chave);
	// }
}

void inclui(int chave, tipoNoA **noAtual, int argc, tipoNoA *pai){
	if (*noAtual==NULL)
	{
		criaArvoreA(chave, noAtual, argc, pai);

		// if (argc > 1)
		// {
			printf("inseri chave %d\n",(*noAtual)->chave );
			printf("pai: %d\n",(*noAtual)->pai->chave);
		// }

	}
	else {
		if (chave <= (*noAtual)->chave){
			inclui(chave,&((*noAtual)->esq),argc , (*noAtual));
		} 
		else {
			inclui(chave,&((*noAtual)->dir), argc,(*noAtual));
		}
	}
}

void imprimirEmOrdem( tipoNoA *noRaiz){
	if (noRaiz!=NULL)
	{
		imprimirEmOrdem(noRaiz->esq);
		printf(" %d ",noRaiz->chave );
		imprimirEmOrdem(noRaiz->dir);
	}
}

int altura(tipoNoA *noRaiz){
	int ae, ad;
	if (noRaiz==NULL){
		return 1;
	}
	ae = altura(noRaiz->esq);
	ad = altura(noRaiz->dir);

	if (ae>ae)
	{
		return ae+1;
	}
	else
		return ad+1;
}

tipoNoA *busca(tipoNoA *raiz, int valor){
	tipoNoA *encontrado;
	if (raiz==NULL)	
	{
		return NULL;
	}
	if (valor < raiz->chave)
	{
		printf("valor percorrido: %d\n",raiz->chave );
		encontrado = busca(raiz->esq, valor);
		return encontrado;
	}
	if (raiz->chave == valor)
	{
		return raiz;
	}
	if (valor > raiz->chave){
		printf("valor percorrido: %d\n",raiz->chave );
		encontrado = busca(raiz->dir,valor);
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
	if (((*noAtual)->dir == NULL) && ((*noAtual)->esq==NULL)) //se for nó folha
	{
		if ((*noAtual)->chave <= (*noAtual)->pai->chave) //se for filho da esquerda
		{
			excluido = *(*noAtual)->pai->esq; //salvando valor para indicar qual nó foi excluido
			aux = (*noAtual)->pai; //aponta para o pai para poder liberar memoria e apontar para NULL
			free((*noAtual)->pai->esq); //libera memoria 
			aux->esq = NULL; //aponta para null
			return excluido; //retorna o nó excluido
		} else { //se for filho da direita
			excluido = *(*noAtual)->pai->dir;
			aux = (*noAtual)->pai;
			free((*noAtual)->pai->dir);
			aux->dir = NULL;
			return excluido;
		}
	}
	else if (((*noAtual)->dir != NULL) && ((*noAtual)->esq==NULL) || //se tiver um filho
			((*noAtual)->dir == NULL) && ((*noAtual)->esq!=NULL))
	{
	}
	else if (((*noAtual)->dir != NULL) && ((*noAtual)->esq!=NULL)) // se tiver dois filhos
	{
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

	printf("nó excluido: %d\n",(exclusao(&(raiz)->esq->esq)).chave );;
	printf("minimo da arvore: %d\n",(minimo(raiz))->chave );
	return 0;
}