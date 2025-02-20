#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char*   inp = (char*)  malloc(sizeof(char*));
	char    op[50];
	int     num[50];
	char isNum  = 0, isOp  = 0;
	int  numMax = 0, opMax = 0;
	while(strcmp(inp, "="))
	{
		scanf("%s", inp);
		if(*inp >= '0' && *inp <= '9' && isNum == 0)
		{
			num[numMax] = atoi(inp);
			isNum = 1;
			isOp  = 0;
			numMax++;
		}
		else if((*inp < '0' || *inp > '9') && isNum == 1)
		{
			op[opMax] = *inp;
			isNum = 0;
			isOp  = 1;
			opMax++;
		}
		else return 1;
		if(isNum != 1 && *inp != '*' && *inp != '/' && *inp != '+' 
	 	 && *inp != '-' && *inp != '=')
			return 1;
	}
	numMax = 0;
	for(int i = 0;i <= opMax; i++)
	{
		if(op[i] == '*')
			num[numMax] *= num[numMax + 1];
		else if(op[i] == '/')
			num[numMax] /= num[numMax + 1];
		else
			continue;
		for(int j = numMax + 1; j != opMax + 1; j++)
			num[j] = num[j + 1];
		i--;
		numMax++;
	}
	numMax = 0;
	for(int i = 0; i <= opMax; i++)
	{
		if(op[i] == '+')
			num[numMax] += num[numMax + 1];
		else if(op[i] == '-')
			num[numMax] -= num[numMax + 1];
		else
			continue;
		for(int j = numMax + 1; j != opMax + 1; j++)
			num[j] = num[j + 1];
		i--;
		numMax++;
	}
	for(int i=0; i!= 10; i++)
		printf("%i ", num[i]);
	return 0;
}

