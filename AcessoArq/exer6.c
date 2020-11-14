#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define MAX 1000

int main (int argc, char **argv)
{
	if (argc != 3)
	{
		perror ("Numero errado de argumentos");
		exit (1);
	}
	FILE *arq;
	arq = fopen (argv[1],"r");

	if (! arq)
	{
		perror ("Arquivo nao encontrado");
		exit (1);
	}

	char *string;
	string = (char *) malloc ((MAX+1)*(sizeof(char)));
	int slen = strlen (argv[2]);
	int llen;
	int i,j;
	int igual;

	fgets (string,MAX+1,arq);
	llen = strlen (string);
	while (! feof (arq))/*(string[llen-1] != EOF)*/
	{
		for (i=0 ; i<llen ; i++)
		{
			if (string[i] == argv[2][0])
			{
				igual = 1;
				j=1;
				if (i+slen-1 > llen)
					igual = 0;
				else
				{
					while ((j < slen)&&(i+j < llen)&&(igual))
					/*enquanto j for menor q o tamanho da string procurada, enquanto a string nao acabar e ainda estiver igual*/
					{
						if (string[i+j] != argv[2][j])
							igual = 0;
						j++;
					}
				}
			}
		}
		if (igual)									
                	printf ("%s",string); /*se encontrar a string, imprime a linha*/
                fgets (string,MAX+1,arq);
                llen = strlen (string);
	}

	fclose (arq);
	exit (0);	
}
