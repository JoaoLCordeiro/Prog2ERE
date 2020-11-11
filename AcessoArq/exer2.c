#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define max 100

int main ()
{
	FILE *arq;
	arq = fopen ("arquivo2.txt","r");

	if (! arq)
	{
		perror ("Erro ao abrir arquivo");
		exit (1);
	}
	
	int i=0;
	float num;
	float soma = 0;

	while (! feof(arq))
	{
		fscanf (arq,"%f \n",&num);
		soma = soma + num;
		i++;
	}

	printf ("%f \n", soma/i);
	fclose (arq);
	exit (0);
}	
