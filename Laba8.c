#include <stdio.h> 
// определение символических констант 
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
	char *buf_ptr; // указатель на текущий символ буфера 
	char *end; // указатель на конец слова 
	char *begin; // указатель на начало слова 
	char c; // текущий символ 
	char prev_c; // предыдущий символ 
	int flag; // признак слова 
	int len; // длина слова 
	int word; // соответствие параметрам слова
	char *dst;
	char *src;
	// начальные присваивания (инициализация переменных) 
	flag = NO;
	len = 0;
	prev_c = ' ';
	buf_ptr = buffer;
	begin = buffer;
	end = buffer;
	// цикл чтения символов из строки 
	do
	{
		c = *buf_ptr; // взять текущий символ из буфера 
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0') // найден разделитель 
		{
			if ((len > N)&&(word == YES)) // длина больше нужной и это именно слово
			{
				end = buf_ptr - 1; // запомнить указатель на конец слова 
				src = end + 1;
				dst = begin;
				while ((*dst++ = *src++) != '\0'); // удаление слова (перенос оставшейся части строки) 
				buf_ptr = begin; // начать обработку строки с перенесённого фрагмента 
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
				begin = buf_ptr; // запомнить указатель на начало слова 
				word = YES;
			}
			flag = YES;
		}
		buf_ptr++; // продвинуть вперёд указатель на текущий символ 
		len++; // увеличить длину слова 
	} while (c != '\0');
}

