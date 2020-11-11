#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define max 100

int main ()
{
	char *string = (char *) malloc ((MAX+1)*sizeof(char));
	fgets (string,MAX+1,stdin);
	int tam = strlen (string);
	int i;
	for (i=tam-1 ; i>=0 ; i--)
	{
		printf("%c",string[i]);
	}
	printf ("\n");
	free (string);
	return 0;
}
