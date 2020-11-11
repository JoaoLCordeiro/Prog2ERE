#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define MAX 100

int main ()
{
	char ** mstring = (char **) malloc ((MAX)*sizeof(char *));
	int i=0;
	mstring[i] = (char *) malloc ((MAX+1)*sizeof(char));
	fgets (mstring[i],MAX+1,stdin);
	while (mstring[i][0] != '\n')
	{
		i++;
		mstring[i] = (char *) malloc ((MAX+1)*sizeof(char));
		fgets (mstring[i],MAX,stdin);
	}

	int troca = 1;
	int tam = i;		 /* guarda quantas strings temos*/
	int j;
	char * reserva;
	while (troca == 1)
	{
		troca = 0;
		for (i=0 ; i<tam ; i++)
		{
			j = 0;
			while ((mstring[i][j] == mstring[i+1][j])&&(mstring[i][j] != '\0')&&(mstring[i+1][j] != '\0')) 
			/*chega até a primeira letra diferente das duas palavras comparadas*/
			{
				j++;
			}
			if (mstring[i][j] > mstring[i+1][j])
			{
				reserva = mstring[i+1];
				mstring[i+1] = mstring[i];
				mstring[i] = reserva;
				troca = 1;
			}
		}
	}
	for (i=0 ; i<=tam ; i++)
	{
		printf ("%s",mstring[i]);
		free (mstring[i]);
	}
	free (mstring);
	return 0;
}
