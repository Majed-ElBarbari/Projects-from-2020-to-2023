// To Do:
// Pass gc through a filter for l array at line 53
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* cls = (char*) malloc(sizeof(char*)), *pi = (char*) malloc(sizeof(char*));
	char* pii = (char*) malloc(sizeof(char*)), *sw = (char*) malloc(sizeof(char*));
	char* ohw = (char*) malloc(sizeof(char*)), **ex = &pi, **sp = &pii, gc;
	do
	{
		printf("Type the right command to clear the screen on your system\n");
		scanf("%[^\n]%*c", cls);
	}
	while(system(cls));
	printf("Player 1 name: ");
	scanf("%[^\n]%*c", pi);
	system(cls);
	printf("Player 2 name: ");
	scanf("%[^\n]%*c", pii);
	while(1)
	{
		system(cls);
		strcpy(sw, "");
		printf("%s type secret word and hide it from %s: ", *ex, *sp);
		scanf(" %[^\n]%*c", sw);
		strcpy(ohw, "");
		for(int i = 0; i != strlen(sw); i++)
			strcat(ohw, "?");
		char l[6] = {'\0', '\0', '\0', '\0', '\0', '\0'};
		for(int i = 0; i != 6 && strcmp(ohw, sw); i++)
		{
			system(cls);
			printf("%i trails left\nGuess a letter in the secret word\n%s\n", 6-i, ohw);
			scanf(" %c", &gc);
			unsigned char b = 0;
			for(int j = strlen(sw); j >= 0; j--)
				if(gc == sw[j])
				{
					if(ohw[j] == gc)
						printf("Already entered letter!");
					else
						ohw[j] = gc;
					b = 1;
					break;
				}
			if(b)
				i--;
			else
			{
//				for(int j = strlen(ohw); j == 0; j--)
				l[i] = gc;
			}
		}
		if(*ex == pi)
			ex = &pii;
		else if(*ex == pii)
			ex = &pi;
		if(*sp == pi)
			sp = &pii;
		else if(*sp == pii)
			sp = &pi;
	}
}

