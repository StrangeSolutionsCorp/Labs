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
	int flag; // ������� ����� 
	int len; // ����� ����� 
	int word; // ������������ ���������� �����
	char *dst;
	char *src;
	int flag1;


	if ((out = fopen("OUT.txt", "w")) == NULL)
	{
		printf("File creating was broke�\n");
		system("pause");
		return 0;
	}
	if ((in = fopen("IN.txt", "r+")) == NULL)
	{
		fprintf(out, "File was not existed\n");
		return 0;
	}

	flag1 = 0;

	while (feof(in) == 0)
	{
		fgets(line, MAXLINE, in);
		if (line[0] == -52)
		{
			fprintf(out, "File was Empty\n");
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
			c = *ptr; // ����� ������� ������ �� ������ 
			if ((c >= 33) && (c <= 127))
				flag1 = 1;
			if ((c == '.') || (c == ',') || (c == ' ') || (c == '\n') || (c == '\0') || (c == '\t') || (c == '?') || (c == '!') || (c == '#') || (c == '<') || (c == '>')) // ������ ����������� 
			{
				if ((len % 2 == 0) && (word == YES)) // ����� ������ � ��� ������ �����
				{
					end = ptr - 1; // ��������� ��������� �� ����� ����� 
					src = end + 1;
					dst = begin;
					while ((*dst++ = *src++) != '\0'); // �������� ����� (������� ���������� ����� ������) 
					ptr = begin; // ������ ��������� ������ � ������������ ��������� 
				}
				flag = NO;
				word = NO;
				len = 0;
			}
			else // ������� ����� 
			{
		
				if (flag == NO)
				{
					begin = ptr; // ��������� ��������� �� ������ ����� 
					word = YES;
				}
				if (((c < 'a') || (c > 'z')) && ((c < 'A') || (c > 'Z'))) // ���� �� �����
					word = NO; // ��� �� �����
				flag = YES;
				len++; // ��������� ����� ����
			}
			ptr++; // ���������� ����� ��������� �� ������� ������ 
		} while (c != '\0');
		fputs(line, out);
	}
	if (flag1 == 0)
	{
		fclose(out);
		if ((out = fopen("OUT.txt", "w")) == NULL)
		{
			printf("File creating was broke�\n");
			system("pause");
			return 0;
		}
		fprintf(out, "File was empty\n");
		printf("Fail!\n");
		system("pause");

		return 1;
	}
	return 0;
}