# AVL Tree

This project implements an AVL tree with basic operations such as insertion and deletion, and it prints the tree in in-order traversal. The implementation is written in C and includes a main function that reads commands from the standard input to manipulate the tree.

## Files

- `main.c`: Contains the main function that reads commands and performs operations on the AVL tree.
- `libavl.h`: Header file for the AVL tree functions.
- `libavl.c`: Implementation of the AVL tree functions.

## Usage

### Compilation

To compile the project, run the command `make`.

### Execution

To execute the program, run the following command: `./avl_tree`.

### Input Format

The program reads commands from the standard input. Each command is a single character followed by an integer (for insert and remove operations).

- `i <value>`: Insert a node with the given value into the AVL tree.
- `r <value>`: Remove a node with the given value from the AVL tree.

**Example:**

```sh
i 10
i 20
i 30
r 20
```

### Output

The program performs an in-order traversal of the AVL tree and prints the values in sorted order. After the commands are processed, the tree is deleted to free the allocated memory.

## Functions

`nodo_t* inserir_nodo(nodo_t* raiz, int valor);`

Inserts a node with the given value into the AVL tree and returns the new root of the tree.

`nodo_t* remover_nodo(nodo_t* raiz, int valor);`

Removes a node with the given value from the AVL tree and returns the new root of the tree.

`void emordem(nodo_t* raiz, int nivel);`

Performs an in-order traversal of the AVL tree and prints the values.

`void deletar_arvore(nodo_t* raiz);`

Deletes the AVL tree and frees the allocated memory.
