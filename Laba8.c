#include <stdio.h> 
// ����������� ������������� �������� 
#define YES 1 
#define N 5 
#define NO 0 
#define MAXLINE 1000 
void process_line(char buffer[]);
void main(void)
{
	char line[MAXLINE];

	printf("Enter the line: ");
	fgets(line, 1000, stdin);
	process_line(line);
	printf("\n Now line looks like: ");
	puts(line);
	getchar();
}
void process_line(char buffer[])
{
	char *buf_ptr; // ��������� �� ������� ������ ������ 
	char *end; // ��������� �� ����� ����� 
	char *begin; // ��������� �� ������ ����� 
	char c; // ������� ������ 
	char prev_c; // ���������� ������ 
	int flag; // ������� ����� 
	int len; // ����� ����� 
	int word; // ������������ ���������� �����
	char *dst;
	char *src;
	// ��������� ������������ (������������� ����������) 
	flag = NO;
	len = 0;
	prev_c = ' ';
	buf_ptr = buffer;
	begin = buffer;
	end = buffer;
	// ���� ������ �������� �� ������ 
	do
	{
		c = *buf_ptr; // ����� ������� ������ �� ������ 
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0') // ������ ����������� 
		{
			if ((len > N)&&(word == YES)) // ����� ������ ������ � ��� ������ �����
			{
				end = buf_ptr - 1; // ��������� ��������� �� ����� ����� 
				src = end + 1;
				dst = begin;
				while ((*dst++ = *src++) != '\0'); // �������� ����� (������� ���������� ����� ������) 
				buf_ptr = begin; // ������ ��������� ������ � ������������ ��������� 
			}
			flag = NO;
			word = NO;
			len = 0;
		}
		else // ������� ����� 
		{
			if ((c >= '0') && (c <= '9')) // ���� �����
				word = NO; // ��� �� �����
			if (flag == NO)
			{
				begin = buf_ptr; // ��������� ��������� �� ������ ����� 
				word = YES;
			}
			flag = YES;
		}
		buf_ptr++; // ���������� ����� ��������� �� ������� ������ 
		len++; // ��������� ����� ����� 
	} while (c != '\0');
}

