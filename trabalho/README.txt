////////////////////////////////////////////////////////////////////////////////
//                       Autor: Renato Ribeiro da Silva                       //
//                       GRR20172113                                          //
////////////////////////////////////////////////////////////////////////////////

	Para o inicio do trabalho, foi projetada inicialmente a estrutura e as funções de uma arvore binaria comum, com ponteiro para esquerda, direita, e uma chave int. Só depois de concluir todas essas tarefas é que foi adicionado um ponteiro para o pai, e seus respectivos ajustes, e também criado o ponteiro para a subArvore. 
	Para as manipulações que envolviam a subArvore, foi necessario a implementação de algumas outras funções. 

Descrição das funções:

	IncluiA: recebe a raiz da arvore como parametro, o ponteiro para o pai, e o index da subArvore. Quando evocada ela inclui ou cria uma raiz, na arvore principal.

	incluiB: recebe o index da subarvore como parametro, e onde sera criada a subArvore (dentro do nó da arvore principal). Quando evocada ela inclui ou cria uma raiz, na subArvore.

	imprimirA/imprimirB: recebe como parametro qual é a raiz da arvore a ser impressa. Quando evocada imprime em pré-ordem a subArvore, ou em ordem a arvore principal. 

	buscaA: recebe como parametro a raiz da arvore principal, qual index procurado, e um int que indica se a função deve ou não imprimir nós visitados (1-sim 0-não). Quando evocada retorna um ponteiro para tipoNoA, apontando para o nó buscado caso encontrado, ou para NULL caso não encontrado. 

	lerInst: recebe um vetor de inteiros como parametro, uma variavel int para controle dentro e fora da função do tamanho do vetor, e o index. Quando evocada acessa o arquivo de entrada padrão (stdin) e o fica lendo enquando não for sinalizada final de arquivo (caso instruções sejam digitadas no terminal, apertar ctrl+d para indicar fim de arquivo ao terminal). Dependendo de qual é a primeira das letras executa determinada função.

	maximo/antecessor: recebe o nó raiz da arvore principal como parametro. É usada para calcular nós que irão substituir nós que foram excluidos.

	exclusaoA: recebe o endereço da raiz da arvore principal, um ponteiro para qual sera o nó excluido, e o index da função. Quando evocada calcula qual é o tipo de nó que sera excluido, verifica uma série de variaveis como, se é raiz, se é filho da esquerda ou da direita, se é folha e etc, e exclui fazendo os ajustes necessarios para aquele tipo especifico de nó.

	inserçãoB: recebe como parametro qual é o nó em que a subArvore sera inserida. Quando evocada inclui os nós lidos na instrução vinda do arquivo, na subArvore.

	lerArq: recebe o emdereço da arvore principal onde sera criada a arvore principal. Quando evocada executa começa a rodar o programa que ira ler o arquivo ou a entrada padrão.
