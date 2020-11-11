#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define MAX 100

int main ()
{
	char *string = (char *) malloc ((MAX+1)*sizeof(char));
	fgets (string,MAX+1,stdin);
	int tam=0;
	while (string[tam] != '\0')
	{
		tam++;
	}
	tam--;
	printf ("%d \n",tam);
	free (string);
	return 0;
}
