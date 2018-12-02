#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <string.h> 
#include <malloc.h> 
#include <stdlib.h>

int main()
{
	FILE *in, *out;
	char **mass;

	int i, j, k, flag;

	if ((out = fopen("out.txt", "w")) == NULL)
	{
		printf("File createment was broken\n");
		system("pause");
		return 1;
	}
	if ((in = fopen("in.txt", "r")) == NULL)
	{
		printf("File was broken or not existed\n");
		fprintf(out,"File was broken or not existed\n");
		system("pause");
		return 1;
	}
	i = 0;
	j = 0;
	flag = 0;

	mass = (char**)malloc(sizeof(char*) * 1);
	mass[0] = (char*)malloc(sizeof(char) * 1);

	while (!feof(in))
	{
		do
		{
			mass[i][j] = fgetc(in);
			if ((mass[i][j] >= 33) && (mass[i][j] <= 127))
				flag = 1;
			j++;
			mass[i] = (char*)realloc(mass[i], sizeof(char) * (j + 1));
		} while ((mass[i][j - 1] != '\n') && (!feof(in)));
		if (feof(in))
		{
			mass[i][j - 1] = '\n';
		}
		mass[i][j] = '\0';
		j = 0;
		i++;
		mass = (char**)realloc(mass, sizeof(char*) * (i + 1));
		mass[i] = (char*)malloc(sizeof(char) * 1);
	}
	if (flag == 0)
	{
		fprintf(out ,"File was empty\n");
		printf("Fail!\n");
		system("pause");

		return 1;
	}
	for (k = i - 1; k >= 0; k--)
	{
		fputs(mass[k], out);
	}


	for (k = i - 1; k >= 0; k--)
	{
		free(mass[k]);
	}
	free(mass);
	printf("Success!\n");
	system("pause");

	return 0;
}

