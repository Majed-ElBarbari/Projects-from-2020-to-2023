#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

//gr genrates random numbers and iterates according to the argument count
void gr(int count, int sides, int start)
{
	srand(time(0));
	for(unsigned long i = 1; i-1 != count; i++)
		if(sides > 0)
			printf("%lu:\t%u\n", i, (rand() % sides) + start);
		else
		{
			fprintf(stderr, "Can't have less than 1 possibility!");
			exit(1);
		}
}

void tc(int* tvar, int tval)
{
	if(tval < 0)
	{
		printf("Warning! You entered a negative number; this will "
			"cause an infinite loop.\nThe count will reach %lu "
			"and generate more values from 0 and repeat forever.\n"
			"Enter:\n\tq\tto quit the program with no errors\n\tp"
			"\tto convert to positive\n\tc\tto continue with the "
			"negative number\n", ULONG_MAX);
		char c = getchar();
		switch(c)
		{
			case 'q':
				exit(0);
			case 'p':
				*tvar = 0 - tval;
				break;
			case 'c':
				if(tval == -1)
					tval--;
				*tvar = tval;
				break;
			default:
				free(&c);
				tc(tvar, tval);
				break;
		}
	}
	else
		*tvar = tval;
}

