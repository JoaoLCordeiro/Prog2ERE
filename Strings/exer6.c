#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define MAX 100

int main ()
{
	char *string = (char *) malloc ((MAX+1)*sizeof(char));
	fgets (string,MAX,stdin);
	int i=0;
	int j;
	int tam = strlen (string);
	while (i<tam)
	{
		if (string[i] == string[i+1])
		{
			for (j=i ; j<tam ; j++)
				string[j] = string[j+1];
			tam--;
		}
		else
			i++;
	}
	printf ("%s",string);
	free (string);
	return 0;
}
