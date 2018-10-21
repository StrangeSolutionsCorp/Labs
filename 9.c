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
	int flag;
	int len; 
	int word; 
	char *dst;
	char *src;

	in = fopen("IN.txt", "r");
	out = fopen("OUT.txt", "w");
	while (feof(in)==0)
	{
		fgets(line, MAXLINE, in);
		ptr = line;
		begin = line;
		end = line;
		flag = NO;
		word = NO;
		len = 0;
		do
		{
			c = *ptr; 
			if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0') 
			{
				if ((len % 2 == 0) && (word == YES)) 
				{
					end = ptr - 1;  
					src = end + 1;
					dst = begin;
					while ((*dst++ = *src++) != '\0');  
					ptr = begin; 
				}
				flag = NO;
				word = NO;
				len = 0;
			}
			else  
			{
				if ((c >= '0') && (c <= '9')) 
					word = NO; 
				if (flag == NO)
				{
					begin = ptr; 
					word = YES;
				}
				flag = YES;
				len++;
			}
			ptr++; 
		} while (c != '\0');
		fputs(line, out);
	}
}
