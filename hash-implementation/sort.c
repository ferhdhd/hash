#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int sort(item_t** vet, int a, int b)
{
	if (a >= b)
	    return 0;
	sort(vet, a, b-1);
	insert(vet, a, b);
	return 0;
}

void insert(item_t** vet, int a, int b)
{
	int p = search(vet[b]->value, vet, a, b-1);
	int i = b;
	while (i > p+1)
    {
		shift(vet, i, i-1);
		i = i-1;
	}
}

int search(int x, item_t** vet, int a, int b)
{
	if (a > b)
		return -1;
	if (vet[b]->value <= x)
		return b;
	return search(x, vet, a, b-1);
}

void shift(item_t** vet, int a, int b)
{
    item_t* aux;
    aux = vet[a];
    vet[a] = vet[b];
    vet[b] = aux;
}