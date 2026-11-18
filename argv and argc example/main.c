#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int a;
	if(argc == 2)
	{
		a = atoi(argv[1]);
		if(a < 0)
		{
label:
			printf("The value entered%i would run an infinite loop\n", a);
			printf("Do you want to proceed?(y/n)");
			char c;
			scanf("%c", &c);
			switch(c)
			{
				case 'n':
					return 0;
				case 'y':
					break;
				default:
					goto label;
			}
		}
		for(int i = 1; i != a; i++)
			printf("%i x\t", i);
		printf("\n");
	}
}
