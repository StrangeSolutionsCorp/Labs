#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#define YES 1 
#define NO 0
#define MAXLEN 1000

void main(void)
{
	
	HANDLE hStdout;
	FILE *in;
	char line[MAXLEN];
	char word[MAXLEN];
	char word1[MAXLEN];
	char word3[MAXLEN];
	char words[MAXLEN][MAXLEN];
	char word2[] = "#define";
	int i, l, g, w, a, com, m;
	char c;
	int prevfl, flag, flw, fl2, flagprint, flagis, flagioni, flagionio, flagininio;
	char *ptr;
	WORD foregroundColor0;
	WORD foregroundColor1;
	WORD foregroundColor;
	WORD backgroundColor;
	WORD textAttribute;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	foregroundColor0 = FOREGROUND_INTENSITY | 15;
	foregroundColor1 = FOREGROUND_INTENSITY | 4;
	SetConsoleTextAttribute(hStdout, foregroundColor0);
	if ((in = fopen("IN.txt", "r+")) == NULL)
	{
		fprintf(stdout, "File was not existed\n");
		return 0;
	}
	w = 0;
	com = 0;
	flagininio = NO;
	while (!feof(in))
	{
		ptr = fgets(line, MAXLEN, in);
		if (ptr == NULL)
			break;
		i = 0;
		if (com == 1)
		{
			com = 0;
			flagininio = NO;
		}
		flagprint = NO;
		flagionio = NO;
		flagis = NO;
		l = YES;
		if (com == 1)
		{
			com = 0;
			flagininio = NO;
		}
		word[0] = '\0';
		word1[0] = '\0';
		flw = fl2 = NO;
		prevfl = flag = YES;
		while (*ptr != 0)
		{
			c = *ptr;
			if ((c == ' ') || (c == ';') || (c == ',') || (c == '.')||(c == '\n')||(c =='\t') || (c == '/') || (c == '*') || (c == '(') || (c == ')') || (c == '='))
			{
				flag = NO;
				if (c == '/')
				{
					ptr++;
					c = *ptr;
					if (((c == '/') || (c == '*')) && (com == 0))
					{
						flagionio = YES;
						flagininio = YES;
						if (c == '/')
							com = 1;
						if (c == '*')
							com = 2;
						ptr--;
						c = '/';
					}
					else
					{
						if ((c == '/') && (com == 2))
						{
							flagininio = NO;
							com = 0;
						}
						ptr--;
						c = '/';
					}
				}
				if (c == '*')
				{
					if (flagininio == YES)
					{
						ptr++;
						c = *ptr;
						if (c == '/')
						{
							flagininio = NO;
							com = 0;
						}
						ptr--;
						c = '*';
					}

				}
				if (flagionio == NO)
				{
					if (flw == YES)
					{
						strcpy(word1, word);
						flw = NO;
						fl2 = YES;
						word1[i] = '\0';
					}
					for (g = 0; g < 7; g++)
						if (word[g] != word2[g])
							l = NO;
					if (l == YES)
						flw = YES;
					if (fl2 == YES)
						if (((word[1] == '0') && (word[2] == 'x')) && (((word[3] >= '0') && (word[4] <= '9')) || ((word[4] >= 'a') && (word[4] <= 'z')) || ((word[4] >= 'A') && (word[4] <= 'Z'))) && (fl2 == YES))
							flagprint = YES;
						else
							flagis = YES;
				}
			}
			else
			{
				flag = YES;
			}

			if (prevfl != flag)
			{
				if (flagininio == YES)
					flagionio = YES;
				word[i] = '\0';
				a = 0;
				flagioni = NO;
				if (flagionio == NO)
				{
					while (words[a][0] >= 0)
					{
						words[a][0] = word[0];
						if (strcmp(word, words[a]) == 0)
							flagioni = YES;
						a++;
					}
				}
				if (flagioni == YES)
				{
					if (word[0] != ' ')
					{
						foregroundColor = foregroundColor0;
						textAttribute = foregroundColor;
						SetConsoleTextAttribute(hStdout, textAttribute);
						printf("%c", word[0]);
						word[0] = ' ';
					}
					foregroundColor = foregroundColor1;
					textAttribute = foregroundColor;
					SetConsoleTextAttribute(hStdout, textAttribute);
					printf("%s", word);
				}
				else 
				{
					foregroundColor = (flagprint == NO) ?
						foregroundColor0 :
						foregroundColor1;
					textAttribute = foregroundColor;
					SetConsoleTextAttribute(hStdout, textAttribute);
					if (fl2 == NO)
					{
						printf("%s", word);
						flagis = NO;
					}
					else
					{
						if (flagprint == YES)
						{
							printf("%s", word1);
							foregroundColor = foregroundColor0;
							textAttribute = foregroundColor;
							SetConsoleTextAttribute(hStdout, textAttribute);
							printf("%s", word);
							strcpy(words[w], word1);
							w++;
							flagis = NO;
						}
					}
				}
				strcpy(word3, word);
				if (flagininio == NO)
					flagionio = NO;
				i = 0;
			}
			word[i] = c;
			ptr++;
			i++;
		}
		if (i != 0)
		{
			if (flagininio == YES)
				flagionio = YES;
			word[i] = '\0';
			if (flagionio == NO)
			{
				foregroundColor = (flagprint == NO) ?
					foregroundColor0 :
					foregroundColor1;
			}
			else
			{
				foregroundColor = foregroundColor0;
			}
			textAttribute = foregroundColor;
			SetConsoleTextAttribute(hStdout, textAttribute);
			if (fl2 == YES)
			{
				if (flagis == YES)
				{
					printf("%s", word1);
					printf("%s", word3);
				}

			}
			printf("%s", word);
			if (flagininio == NO)
				flagionio = NO;
			i = 0;
		}
	}
	printf("\n");
	SetConsoleTextAttribute(hStdout, 7);

	system("pause");
}
