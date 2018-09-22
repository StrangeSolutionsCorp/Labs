#include <stdio.h>
// ����������� ������������� ��������
#define YES 1
#define N 5
#define NO 0
#define MAXLINE 1000
void process_line( char buffer[] );
void main( void )
{
	char line[MAXLINE];

	printf("Enter the line: ");
	gets( line );
	process_line( line );

	printf("\n Now line looks like: ");
	puts( line );
}
void process_line( char buffer[] )
{
	char *buf_ptr; // ��������� �� ������� ������ ������
	char *end; // ��������� �� ����� �����
	char *begin; // ��������� �� ������ �����
	char c; // ������� ������
	char prev_c; // ���������� ������
	int flag; // ������� �����
	int len; // ����� �����
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
		if( c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0') // ������ �����������
		{
			if( len > N ) // ����� ������ ������
			{
				end = buf_ptr - 1; // ��������� ��������� �� ����� �����
				src = end + 1;
				dst = begin;
				while( (*dst++ = *src++ ) != '\0' ); // �������� ����� (������� ���������� ����� ������)
				buf_ptr = begin; // ������ ��������� ������ � ������������ ���������
			}
		flag = NO;
		len = 0;
		}
		else // ������� �����
		{
			if( flag == NO )
			begin = buf_ptr; // ��������� ��������� �� ������ �����
			flag = YES;
		}
		buf_ptr++; // ���������� ����� ��������� �� ������� ������
		len++; // ��������� ����� �����
		}
	while( c != '\0' );
}