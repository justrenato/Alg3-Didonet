#include <stdio.h>
#include <stdlib.h>
struct No
{
    int numero;
    struct No *esquerda;
    struct No *direita;
};
typedef struct No No; //typedef permite ao programador definir um novo nome para um determinado tipo.
void criarArvore(No **pRaiz)
{
    *pRaiz = NULL;
}
void insercao(No **pRaiz, int numero2)
{
	if (*pRaiz==NULL)
	{
	*pRaiz=(No *)malloc(sizeof (No));
	(*pRaiz)->esquerda=NULL;
	(*pRaiz)->direita=NULL;
	(*pRaiz)->numero=numero2;
	}
	else 
    {
		if (numero2<((*pRaiz)->numero))
		{
			insercao(&((*pRaiz)->esquerda), numero2);
		}
		else
		{
			insercao(&((*pRaiz)->direita), numero2);
		}
	}
}

No *MaiorDireita(No **no)
{
    if((*no)->direita != NULL)
    {
       return MaiorDireita(&(*no)->direita);
    }
    else
    {
       No *aux = *no;
       
       if((*no)->esquerda != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
        {
          *no = (*no)->esquerda;
        }
        else
        {
            *no = NULL;
            return aux;
        }
    }
        
}

No *MenorEsquerda(No **no)
{
    if((*no)->esquerda != NULL)
    {
       return MenorEsquerda(&(*no)->esquerda);
    }
    else
    {
        No *aux = *no; 
        if((*no)->direita != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
        {
          *no = (*no)->direita;
        }
        else
        {
          *no = NULL;
        }
        return aux;
    }
}

void exibirEmOrdem(No *pRaiz){
    if(pRaiz != NULL){
        exibirEmOrdem(pRaiz->esquerda);
        printf(" %i ", pRaiz->numero);
        exibirEmOrdem(pRaiz->direita);
    }
}
No *raiz;
int main(int argc, char const *argv[])
{
	criarArvore(&raiz);
	insercao(&raiz, 8);
	insercao(&raiz, 3);
	insercao(&raiz, 12);
	insercao(&raiz, 2);
	insercao(&raiz, 6);
	insercao(&raiz, 10);
	insercao(&raiz, 14);
	exibirEmOrdem(raiz);
	return 0;
}