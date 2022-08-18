// Projeto feito por: Eduardo Stefanel Paludo - GRR20210581
// Fernando Gbur dos Santos - GRR20211761

#include <stdio.h>
#include <stdlib.h>

#include "libavl.h"

int main()
{
	nodo_t* raiz = NULL;
	int valor;
	char c;
	scanf("%c", &c);
	while (!feof(stdin))
	{
		if (c == 'i')
		{
			scanf(" %d", &valor);
			raiz = inserir_nodo(raiz, valor);
		}
		else if (c == 'r')
		{
			scanf(" %d", &valor);
			raiz = remover_nodo(raiz, valor);
		}
		scanf("%c", &c);
	}
	emordem(raiz, 0);
	deletar_arvore(raiz);
	return 0;
}