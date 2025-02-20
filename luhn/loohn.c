#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check(char* iarg);

void usage(char* prog);

int main(int argc, char* argv[])
{
	if(argc != 2)
		usage(argv[0]);
	check(argv[1]);
	printf("The number is valid!\n");
	return 0;
}

void usage(char* prog)
{
	printf("usage: check if number is valid\nsyntax: %s <credit card number>\n", prog);
	exit(1);
}

void check(char* iarg)
{
	for(int i = 0; i != strlen(iarg); i++)
		if(iarg[i] - '0' < 0 || iarg[i] - '0' > 10)
		{
			fprintf(stderr, "Enter the number with digits only, %c is not allowed\n", iarg[i]);
			exit(1);
		}
	unsigned short duo[strlen(iarg)];
	for(int i = 0; i != strlen(iarg); i++)
	{
		if(i % 2 != 0)
		{
			duo[i] = iarg[i] - '0';
		}
		else
		{
			duo[i] = 2 * (iarg[i] - '0');
			if(duo[i] > 9)
				duo[i] = duo[i] - 9;
		}
	}
	int num = 0;
	for(int i = 0; i != strlen(iarg); i++)
	{
		num += duo[i];
	}
	if(num % 10 != 0)
	{
		fprintf(stderr, "Number doesn't follow Luhn algrothim; the number is not valid!\n");
		exit(1);
	}
}
