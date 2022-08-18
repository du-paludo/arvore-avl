#ifndef _LIBAVL_
#define _LIBAVL_

struct nodo
{
	int chave;
	int altura;
	struct nodo *esq, *dir;
};
typedef struct nodo nodo_t;

// Aloca um novo nodo, o inicializa e o retorna
nodo_t* novo_nodo(int valor);

// Deleta a árvore da memória
void deletar_arvore(nodo_t* nodo);

// Imprime a árvore pela travessia emordem, junto com a altura relativa à raiz
void emordem(nodo_t* nodo, int h_arvore);

// Retorna o nodo com valor máximo da árvore com raiz nodo
// Usada para achar o antecessor
nodo_t* nodo_max(nodo_t* nodo);

// Retorna o maior valor entre a e b
int max(int a, int b);

// Retorna a altura do nodo ou -1 se o nodo não existir
int altura(nodo_t* nodo);

// Retorna a diferença de altura entre as subárvores da esquerda e da direita
// Fb positivo indica árvore pesada na esquerda
// Fb negativo indica árvore pesada na direita
int fator_balanceamento(nodo_t* nodo);

// Rotaciona o nodo x para a esquerda do seu filho direito (e o retorna)
nodo_t* rot_esq(nodo_t* x);

// Rotaciona o nodo x para a direita do seu filho esquerdo (e o retorna)
nodo_t* rot_dir(nodo_t* x);

// Insere um nodo na AVL e faz o balanceamento
nodo_t* inserir_nodo(nodo_t* nodo, int valor);

// Remove um nodo da AVL e faz o balanceamento
nodo_t* remover_nodo(nodo_t* nodo, int valor);

#endif