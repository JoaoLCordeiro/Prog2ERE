#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define MAX 100

int main ()
{
	char *string = (char *) malloc ((MAX+1)*sizeof(char));
	fgets (string,MAX+1,stdin);
	int tam = strlen (string);
	int i;
	for (i=0 ; i<tam ; i++)
	{
		if ((string[i] >= 65)&&(string[i] <= 90))
		{
			string[i] = string[i] + 32;
		}
	}
	printf("%s \n",string);
	free (string);
	return 0;
}
