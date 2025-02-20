#include <stdio.h>
#include <stdlib.h>
#include "func.h"

short bol = 0;
int main(int argc, char* argv[])
{
	int times = 1, sides = 6, start = 1;
	if(argc > 1)
		tc(&times, atoi(argv[1]));
	if(argc > 2)
		sides = atoi(argv[2]);
	if(argc > 3)
		start = atoi(argv[3]);
	gr(times, sides, start);
	return 0;
}

