#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main(int argc, char* argv[])
{
	if(argc < 3)
		return 0;
	ifstream fi;
	fi.open(argv[1]);
	int oSpaces;
	int nSpaces;
	oSpaces = atoi(argv[2]);
	if(argv[3] != NULL)
		nSpaces = atoi(argv[3]);
	else
		if(oSpaces < 0)
			nSpaces = 4;
		else
			nSpaces = -1;
	char* is = (char* ) malloc(sizeof(char*));
	strcpy(is, "");
	for(string s; getline(fi, s); strcat(is, "\n"))
		for(char i : s)
			if(oSpaces < 0)
				for(int j = oSpaces; j != 0; j++)
					if(i != '\t')
					{
						strncat(is, &i, 1);
						break;
					}
					else
					{
						strncat(is, &i, 1);
						if(j == -1)
						{
							i = '\b';
							for(int k = oSpaces; k != 0; k++)
							{
								strncat(is, &i, 1);
							}
							if(nSpaces < 0)
							{
								i = '\t';
								for(int k = nSpaces; k != 0; k++)
									strncat(is, &i, 1);
							}
							else
							{
								i = ' ';
								for(int k = nSpaces; k != 0; k--)
									strncat(is, &i, 1);
							}
						}
					}
	fi.close();
	ofstream fo;
	fo.open(argv[1]);
	for(unsigned int i = 0; i != strlen(is); i++)
		fo << is[i];
	fo.close();
	fi.open(argv[1]);
	for(string s; getline(fi, s); cout << s << endl);
	return 0;
}

