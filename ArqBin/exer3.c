#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define MAX 1000

int main ()
{
	FILE *arq;
	arq = fopen ("dezmilhaolong.txt","r");

	if (! arq)
	{
		perror ("Nao foi possivel ler o arquivo");
		exit (1);
	}
	long *longv1 = (long *) malloc (10*sizeof(long));
	long *longv2 = (long *) malloc (10*sizeof(long));

	fread (longv1,sizeof(long),10,arq);

	fseek (arq, -10*sizeof(long), SEEK_END);
	fread (longv2,sizeof(long),10,arq);

	int i;
	for (i=0 ; i<10 ; i++)
	{
		printf ("%ld\n",longv1[i]);
	}
	printf ("\n");
	for (i=0 ; i<10 ; i++)
        {
        	printf ("%ld\n",longv2[i]);
        }					

	fclose (arq);
	exit (0);
}
