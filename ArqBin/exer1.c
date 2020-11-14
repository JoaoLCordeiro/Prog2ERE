#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#define MAX 1000
#define DEZM 10000000

int main ()
{
	FILE *arq;
	long *longv;
	longv = (long *) malloc ((DEZM)*sizeof(long));

	srand (clock());

	arq = fopen ("dezmilhaolong.txt","w");

	int i;
	for (i=0 ; i<DEZM ; i++)
	{
		longv[i] = rand();
	}

	int nblocos;

	nblocos = fwrite (longv,sizeof(long), DEZM, arq);

	if (nblocos)
		printf ("Gravou %d blocos com sucesso!\n",nblocos);
	else
		printf ("Erro ao  gravar os blocos\n");

	fclose (arq);
	exit (0);
}
