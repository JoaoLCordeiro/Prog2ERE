#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define max 100

int main (int argc, char **argv)
{
	if (argc != 3)
	{
		perror ("Erro com quantia de argumentos");
		exit (1);
	}
	FILE *arq1;
	arq1 = fopen (argv[1],"r");

	if (! arq1)
	{
		perror ("Erro ao abrir arquivo");
		exit (1);
	}

	FILE *arq2;
	arq2 = fopen (argv[2],"r");

	if (arq2)
	{
		perror ("Erro: o arquivo do segundo argumento ja existe");
		exit (1);
	}

	arq2 = fopen (argv[2],"w");

	char c;
	while (! feof (arq1))
	{
		c = fgetc (arq1);
		fprintf (arq2,"%c",c);
	}

	exit (0);
}	
