#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define max 100

int main ()
{
	FILE *arq;
	arq = fopen ("arquivo1.txt","r");

	if (! arq)
	{
		perror ("Erro ao abrir arquivo");
		exit (1);
	}						

	char c;
	int i=0;
	c = fgetc (arq);
	while (c != EOF)
	{
		i++;
		c = fgetc (arq);
	}

	printf ("%d \n",i);
	fclose (arq);
	exit (0);
}
