#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define MAX 100

int main ()
{
	char *string = (char *) malloc ((MAX+1)*sizeof(char));
	fgets (string,MAX+1,stdin);
	int i,j;
	int tam = strlen (string);
	i=0;
	while (i<tam)
	{
		if (!(((string[i] >= 48)&&(string[i] <= 57))||((string[i] >= 65)&&(string[i] <= 90))||((string[i] >= 97)&&(string[i] <= 122))))
		{
			for (j=i ; j<tam ; j++)
			{
				string[j] = string[j+1];
			}
			tam--;
		}
		else
			i++;
	}
	printf ("%s \n",string);
	free (string);
	return 0;
}
