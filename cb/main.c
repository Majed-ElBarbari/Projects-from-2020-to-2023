#include <stdio.h>
#include <stdlib.h>
#define bool _Bool

int m1();

int main(int argc, char* argv[])
{
	int m = atoi(argv[1]);
	if(m == 1)
	{
		int a = atoi(argv[2]);
		bool b = 1;
		if(a < 0)
		{
			printf("The value entered%i would run an infinite loop\n", a);
			printf("Do you want to proceed?(y/n)");
			char c;
			scanf("%c", &c);
			switch(c)
			{
				case 'n':
				b=0;
				break;
				case 'y':
				b=1;
				break;
			}
		}
		for(int i = 1; i <= a && b==1; i++)
		{
			printf("%i x\t", i);
		}
	}
}
