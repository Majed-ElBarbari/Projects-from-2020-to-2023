#include <stdio.h>
#include <stdlib.h>

void f(int cn, unsigned short card[15], int lim);

int main()
{
	unsigned short card[15];
	f(0, card, 15);
	for(int i=0; i!=sizeof(card); i++)
		printf("%i", card[i]);
	return 0;
}

void f(int cn, unsigned short card[15], int lim)
{
	for(int i=0; i!=10; i++)
	{
		card[cn] = i;
		for(int j=0; j!=15 && lim == 0; j++)
			printf("%i", card[j]);
		if(lim == 0)
			printf("\n");
		for(int j=0; j!=lim; j++)
			f(cn+1, card, lim-1);
		if(lim == 0)
			break;
	}
}

