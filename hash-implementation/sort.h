#ifndef __SORT__
#define __SORT__

#include "hash.h"

int sort(item_t** vet, int a, int b);

void insert(item_t** vet, int a, int b);

int search(int x, item_t** vet, int a, int b);

void shift(item_t** vet, int a, int b);

#endif