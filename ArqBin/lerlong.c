#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define MAX 1000
#define DEZM 10000000

int main ()
{
	FILE *arq;
	arq = fopen ("dezmilhaolong.txt","r");

	if (! arq)
	{
		perror ("Erro ao ler arquivo");
		exit (1);
	}

	long num;
	int i;
	for (i=0 ; i<DEZM ; i++)
	{
		/*fscanf (arq,"%ld",&num);*/
		fread (&num,sizeof(long),1,arq);
		printf ("%ld\n",num);
	}

	fclose (arq);
	exit(0);
}
