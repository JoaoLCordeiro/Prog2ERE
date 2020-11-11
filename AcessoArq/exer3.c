#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define max 100

int main ()
{
	FILE *min;
	min = fopen ("minusc.txt","r");

	if (! min)
	{
		perror ("Erro ao abrir arquivo");
		exit (1);
	}		

	FILE *mai;
	mai = fopen ("maiusc.txt","w");	

	char c;
	while (! feof (min))
	{
		c = fgetc (min);
		if ((c >= 97)&&(c <= 122))
			c = c - 32;
		fprintf (mai,"%c",c);
	}

	fclose (min);
	fclose (mai);
	exit (0);
}	
