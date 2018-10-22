#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define YES 1 
#define NO 0 
#define MAXLINE 1024
int main()
{
	FILE *in, *out;
	char line[MAXLINE];
	char *ptr;
	char *end;
	char *begin;
	char c;
	int flag; // признак слова 
	int len; // длина слова 
	int word; // соответствие параметрам слова
	char *dst;
	char *src;
	int i;

	in = fopen("IN.txt", "r");
	out = fopen("OUT.txt", "w");
	while (feof(in)==0)
	{

		if (fgets(line, MAXLINE, in) == NULL)
		{
			fprintf(out,"File was Empty\n");
			return 0;
		}
		ptr = line;
		begin = line;
		end = line;
		flag = NO;
		word = NO;
		len = 0;
		do
		{
			c = *ptr; // взять текущий символ из буфера 
			if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0') // найден разделитель 
			{
				if ((len % 2 == 0) && (word == YES)) // длина больше нужной и это именно слово
				{
					end = ptr - 1; // запомнить указатель на конец слова 
					src = end + 1;
					dst = begin;
					while ((*dst++ = *src++) != '\0'); // удаление слова (перенос оставшейся части строки) 
					ptr = begin; // начать обработку строки с перенесённого фрагмента 
				}
				flag = NO;
				word = NO;
				len = 0;
			}
			else // найдена буква 
			{
				if ((c >= '0') && (c <= '9')) // если цифра
					word = NO; // это не слово
				if (flag == NO)
				{
					begin = ptr; // запомнить указатель на начало слова 
					word = YES;
				}
				flag = YES;
				len++;
			}
			ptr++; // продвинуть вперёд указатель на текущий символ 
			 // увеличить длину слова 
		} while (c != '\0');
		fputs(line, out);
	}
	return 0;
}
