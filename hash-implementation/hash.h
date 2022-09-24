#ifndef __HASH__
#define __HASH__

#define M 11

typedef struct item
{
    int value;
    int removed;
    int index;
    char* table;
} item_t;

// Retorna um índice na tabela hash para uma dada chave
int h1(int key);

// Retorna um índice na tabela hash para uma dada chave
int h2(int key);

// Inicializa a tabela hash
item_t** hash_init(int size);

// Inicializa um item da tabela
item_t* item_init();

// Procura um valor na tabela
int hash_search(item_t** t1, item_t** t2, int value);

// Insere um valor na tabela
void hash_insert(item_t** t1, item_t** t2, int value);

// Remove um valor da tabela
void hash_remove(item_t** t1, item_t** t2, int value);

// Libera a memória ocupada pela tabela
void hash_delete(item_t** t);

// Imprime a tabela no formato valor, tabela, índice
void hash_print(item_t** aux);

// Une os itens de cada tabela em apenas uma
int hash_merge(item_t** t1, item_t** t2, item_t** aux);

#endif