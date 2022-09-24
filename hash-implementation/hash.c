#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hash.h"

int h1(int value)
{
    return value % M; 
}

int h2(int value)
{
    return floor(M * ((value * 0.9) - floor(value * 0.9)));
}

int hash_search(item_t** t1, item_t** t2, int value)
{
    int index1 = h1(value);
    int index2 = h2(value);
    if (t1[index1] == NULL)
        return -1;
    else if (t1[index1]->value == value && !t1[index1]->removed)
        return index1;
    else if (t2[index2] != NULL && t2[index2]->value == value && !t2[index2]->removed)
        return index2;
    return -1;
}

item_t** hash_init(int size)
{
    item_t** t = malloc(sizeof(item_t*) * size);
    for (int i = 0; i < size; i++)
        t[i] = NULL;
    return t;
}

item_t* item_init(int value, int index, char* table)
{
    item_t* aux = malloc(sizeof(item_t));
    aux->removed = 0;
    aux->value = value;
    aux->table = table;
    aux->index = index;
    return aux;
}

void hash_insert(item_t** t1, item_t** t2, int value)
{
    int index = h1(value);
    if (t1[index] == NULL)
        t1[index] = item_init(value, index, "T1");
    else if (t1[index]->removed)
    {
        t1[index]->value = value;
        t1[index]->removed = 0;
        t1[index]->index = index;
    }
    else
    {
        int index2 = h2(t1[index]->value);
        if (t2[index2] == NULL)
            t2[index2] = item_init(t1[index]->value, index2, "T2");
        else if (t2[index2]->removed)
        {
            t2[index2]->value = t1[index]->value;
            t2[index2]->removed = 0;
            t2[index2]->index = index2;
        }
        t1[index]->value = value;
    }
}

void hash_remove(item_t** t1, item_t** t2, int value)
{
    int index1 = h1(value);
    int index2 = h2(value);
    if (t2[index2] != NULL && t2[index2]->value == value)
    {
        t2[index2]->removed = 1;
        free(t2[index2]);
        t2[index2] = NULL;
    }
    else if (t1[index1] != NULL && t1[index1]->value == value)
        t1[index1]->removed = 1;
}

void hash_delete(item_t** t)
{
    for (int i = 0; i < M; i++)
        if (t[i] != NULL)
            free(t[i]);
    free(t);
}

void hash_print(item_t** aux)
{
    for (int i = 0; i < M*2; i++)
        if (aux[i] != NULL)
            printf("%d,%s,%d\n", aux[i]->value, aux[i]->table, aux[i]->index);
}

int hash_merge(item_t** t1, item_t** t2, item_t** aux)
{
    int j = 0;
    for (int i = 0; i < M; i++)
        if ((t1[i] != NULL) && (t1[i]->removed == 0))
        {
            aux[j] = t1[i];
            j++;
        }
    for (int i = 0; i < M; i++)
        if ((t2[i] != NULL) && (t2[i]->removed == 0))
        {
            aux[j] = t2[i];
            j++;
        }
    return j-1;
}