#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "sort.h"

int main()
{
	item_t** t1 = hash_init(M);
	item_t** t2 = hash_init(M);
	item_t** aux = hash_init(M*2);

    int value;

	char c;
	scanf("%c", &c);
	while (!feof(stdin))
	{
		if (c == 'i')
		{
			scanf(" %d", &value);
			hash_insert(t1, t2, value);
		}
		else if (c == 'r')
		{
			scanf(" %d", &value);
			hash_remove(t1, t2, value);
		}
		scanf("%c", &c);
	}

	int index = hash_merge(t1, t2, aux);
	sort(aux, 0, index);
	hash_print(aux);
    hash_delete(t1);
	hash_delete(t2);
	free(aux);

	return 0;
}