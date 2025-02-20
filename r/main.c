#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("...");
	int i;
	scanf(" %i", &i);
	char c;
	scanf(" %c", &c);
	for(int j = 0; j <= i; j++)
	{
		for(int k = 0; k != j; k++)
			printf("%c", c);
		printf("\n");
	}
	exit(0);
}