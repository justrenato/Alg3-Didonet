#include <stdio.h>
#include <stdlib.h>
typedef struct tipoNo{
	int chave;
	struct tipoNo *dir;
	struct tipoNo *esq;
}tipoNo;
 
void criaArvore(int chaveRaiz, tipoNo **raiz){
	// raiz = malloc(sizeof(tipoNo)); (ta bugando o codigo e fazendo sair da função com valor 0 na chave)
	(*raiz) = (tipoNo*)(malloc (sizeof(tipoNo)));
	(*raiz)->chave = chaveRaiz;
	(*raiz)->esq = NULL;
	(*raiz)->dir = NULL;

	#ifdef debug
		printf("Criei arvore com raiz: %d\n", (*raiz)->chave);
	#endif
}

void inclui(int chave, tipoNo **noAtual){
	if (*noAtual==NULL)
	{
		(*noAtual) = (tipoNo *) malloc(sizeof(tipoNo));
		(*noAtual)->chave = chave;
		(*noAtual)->esq = NULL;
		(*noAtual)->dir = NULL;
		#ifdef debug
			printf("inseri chave %d\n",(*noAtual)->chave );
		#endif
	}
	else {
		if (chave <= (*noAtual)->chave){
			inclui(chave,&((*noAtual)->esq) );
		} 
		else {
			inclui(chave,&((*noAtual)->dir) );
		}
	}
}

void imprimirEmOrdem( tipoNo *noRaiz){
	if (noRaiz!=NULL)
	{
		imprimirEmOrdem(noRaiz->esq);
		printf(" %d ",noRaiz->chave );
		imprimirEmOrdem(noRaiz->dir);
	}
}

int altura(tipoNo *noRaiz){
	int ae, ad;
	if (noRaiz==NULL){
		return 0;
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

tipoNo *busca(tipoNo *raiz, int trajeto, int valor){
	if (raiz==NULL)	
	{
		return NULL;
	}
	if (trajeto==1)
	{
		if (valor < raiz->chave)
		{
			printf("valor percorrido: %d\n",raiz->chave );
			busca(raiz->esq, trajeto, valor);
		}
		if (raiz->chave == valor)
		{
			return raiz;
		}
		if (valor > raiz->chave){
			printf("valor percorrido: %d\n",raiz->chave );
			busca(raiz->dir,trajeto,valor);
		}
	}
	if (trajeto==2)
	{
		if (raiz->chave == valor)
		{
			return raiz;

		}
		if (valor < raiz->chave)
		{
			printf("valor percorrido: %d\n",raiz->chave );
			busca(raiz->esq, trajeto, valor);
		}
		if (valor > raiz->chave){
			printf("valor percorrido: %d\n",raiz->chave );
			busca(raiz->dir,trajeto,valor);
		}
	}
	if (trajeto==3)
	{
		if (valor < raiz->chave)
		{
			printf("valor percorrido: %d\n",raiz->chave );
			busca(raiz->esq, trajeto, valor);
		}
		if (valor > raiz->chave){
			printf("valor percorrido: %d\n",raiz->chave );
			busca(raiz->dir,trajeto,valor);
		}
		if (raiz->chave == valor)
		{
			return raiz;

		}
	}
}

tipoNo *antecessor(tipoNo *noAtual, int passagem){
	if (passagem == 0){
		if (noAtual->esq == NULL){
			return NULL;
		} else{
			return antecessor(noAtual->esq, passagem+1);
		}
	}else{
		if (noAtual->dir==NULL)
		{
			return noAtual;
		} else{
			return antecessor(noAtual->dir, passagem+1);
		}
	}
}

tipoNo *raiz;
int main(int argc, char const *argv[])
{
	int chave;
	int valor;
	int trajeto;
	int buscar;

//criação da arvore
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
//impressão
	printf("\nimpressao da arvore:\n");
	imprimirEmOrdem(raiz);
	printf("\n");
//altura
	printf("altura: %d\n", altura(raiz));

//busca
	printf("voce deseja buscar algum valor?\n");
	scanf("%d",&buscar);
	tipoNo *buscado;
	while(buscar){
		printf("voce deseja buscar qual valor?\n");
		scanf("%d",&valor);
		printf("Digite 1 para buscar em ordem - 2 pré ordem - 3 pós ordem\n");
		scanf("%d",&trajeto);

		// *buscado = *busca(raiz, trajeto,valor);
		if (buscado!=NULL){
			printf("valor %d encontrado\n",buscado->chave );
		}else{
			printf("valor nao encontrado\n");
		}

		printf("deseja buscar mais algum valor? 1-sim 0-nao:\n");
		scanf("%d",&buscar);
	}

	// int passagem = 0;
	// tipoNo *ant = antecessor(buscado,passagem);
	// if ((buscado!=NULL) && (ant != NULL))
	// {
	// 	printf("antecessor: %d\n",ant->chave );
	// }else{
	// 	printf("não ha antecessor\n");
	// }	

	return 0;
}