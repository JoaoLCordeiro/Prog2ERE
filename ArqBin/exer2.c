#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define MAX 1000
#define DEZM 10000000

int comparlong (const void *x,const void *y)
{
	if (x < y)
		return -1;
	else if (x > y)
		return 1;
	else
		return 0;
}

int main ()
{
	FILE *arq;
	arq = fopen ("dezmilhaolong.txt","r");

	if (! arq)
	{
		perror ("Erro ao abrir o arquivo");
		exit (1);
	}

	long *longv = (long *) malloc ((DEZM)*sizeof(long));

	fread (longv,sizeof(long),DEZM,arq);

	qsort (longv,DEZM,sizeof(long),comparlong);

	fclose (arq);
	arq = fopen ("dezmilhaolong.txt","w");

	fwrite (longv,sizeof(long),DEZM,arq);

	fclose (arq);
	exit (0);
}
