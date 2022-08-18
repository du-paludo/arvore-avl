#include <stdio.h>
#include <stdlib.h>
#include "libavl.h"

nodo_t* novo_nodo(int valor)
{
	nodo_t* aux = malloc(sizeof(nodo_t));
	aux->chave = valor;
	aux->altura = 0;
	aux->esq = aux->dir = NULL;
	return aux;
}

void deletar_arvore(nodo_t* nodo)
{
	if (nodo)
	{
		deletar_arvore(nodo->esq);
		deletar_arvore(nodo->dir);
		free(nodo);
	}
}

void emordem(nodo_t* nodo, int h_arvore)
{
    if (nodo != NULL)
    {
        emordem(nodo->esq, h_arvore+1);
        printf("%d,%d\n", nodo->chave, h_arvore);
        emordem(nodo->dir, h_arvore+1);
    }
}

nodo_t* nodo_max(nodo_t* nodo)
{
	if (nodo->dir)
		return nodo_max(nodo->dir);
	return nodo;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int altura(nodo_t* nodo)
{
	if (!nodo)
		return -1;
	return nodo->altura;
}

int fator_balanceamento(nodo_t* nodo)
{
	if (!nodo)
		return 0;
	return (altura(nodo->esq) - altura(nodo->dir));
}

nodo_t* rot_esq(nodo_t* x)
{
	nodo_t* y = x->dir;
	nodo_t* A2 = y->esq;

	y->esq = x;
	x->dir = A2;

	x->altura = max(altura(x->esq), altura(x->dir)) + 1;
	y->altura = max(altura(y->esq), altura(y->dir)) + 1;

	return y;
}

nodo_t* rot_dir(nodo_t* x)
{
	nodo_t* y = x->esq;
	nodo_t* A2 = y->dir;

	y->dir = x;
	x->esq = A2;

	x->altura = max(altura(x->esq), altura(x->dir)) + 1;
	y->altura = max(altura(y->esq), altura(y->dir)) + 1;
	
	return y;
}

nodo_t* inserir_nodo(nodo_t* nodo, int valor)
{
	// Se nodo for NULL, chegou na folha da árvore
	if (!nodo)
		return novo_nodo(valor);

	// Se o valor a ser inserido for menor que a chave do nodo atual,
	// insere o valor na subárvore da esquerda
	if (valor < nodo->chave)
		nodo->esq = inserir_nodo(nodo->esq, valor);

	// Caso contrário, insere na subárvore da direita
	else
		nodo->dir = inserir_nodo(nodo->dir, valor);
	
	// Atualiza a altura dos nodos anteriores ao que foi inserido
	nodo->altura = 1 + max(altura(nodo->esq), altura(nodo->dir));

	// Calcula a diferença de altura entre as subárvores da esquerda e da direita
	int fb = fator_balanceamento(nodo);

	// Zig-zig na esquerda
	if (fb > 1 && valor < nodo->esq->chave)
		return rot_dir(nodo);

	// Zig-zig na direita
	if (fb < -1 && valor > nodo->dir->chave)
		return rot_esq(nodo);

	// Zig-zag na esquerda
	if (fb > 1 && valor > nodo->esq->chave)
	{
		nodo->esq = rot_esq(nodo->esq);
		return rot_dir(nodo);
	}

	// Zig-zag na direita
	if (fb < -1 && valor < nodo->dir->chave)
	{
		nodo->dir = rot_dir(nodo->dir);
		return rot_esq(nodo);
	}

	return nodo;
}

nodo_t* remover_nodo(nodo_t* nodo, int valor)
{
	// Nodo não está na árvore
	if (!nodo)
		return nodo;

	// Se o valor a ser removido for menor que a chave do nodo atual,
	// procura o valor na subárvore da esquerda
	else if (valor < nodo->chave)
		nodo->esq = remover_nodo(nodo->esq, valor);

	// Caso seja maior, procura o valor na subárvore da direita
	else if (valor > nodo->chave)
		nodo->dir = remover_nodo(nodo->dir, valor);

	// Nodo foi encontrado
	else
	{
		// Caso o nodo tenha 0 ou 1 filhos
		if (nodo->esq == NULL)
		{
			nodo_t* aux = nodo->dir;
			free(nodo);
			return aux;
		}
		else if (nodo->dir == NULL)
		{
			nodo_t* aux = nodo->esq;
			free(nodo);
			return aux;
		}
		// Caso o nodo tenha 2 filhos
		else
		{
			nodo_t* aux = nodo_max(nodo->esq);
			nodo->chave = aux->chave;
			nodo->esq = remover_nodo(nodo->esq, aux->chave);
		}
	}

	// Atualiza a altura dos nodos anteriores ao que foi inserido
	nodo->altura = 1 + max(altura(nodo->esq), altura(nodo->dir));

	// Calcula a diferença de altura entre as subárvores da esquerda e da direita
	int fb = fator_balanceamento(nodo);

	// Zig-zig na esquerda
	if (fb > 1 && fator_balanceamento(nodo->esq) >= 0)
		return rot_dir(nodo);

	// Zig-zig na direita
	if (fb < -1 && fator_balanceamento(nodo->dir) >= 0)
		return rot_esq(nodo);

	// Zig-zag na esquerda
	if (fb > 1 && fator_balanceamento(nodo->esq) < 0)
	{
		nodo->esq = rot_esq(nodo->esq);
		return rot_dir(nodo);
	}

	// Zig-zag na direita
	if (fb < -1 && fator_balanceamento(nodo->dir) < 0)
	{
		nodo->dir = rot_dir(nodo->dir);
		return rot_esq(nodo);
	}

	return nodo;
}