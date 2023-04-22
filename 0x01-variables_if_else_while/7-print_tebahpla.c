#include <stdio.h>

/**
  * main - print the lowercase alphabet in reverse
  * followed by a new line
  * Return: 0 (Success)
  */
int main(void)
{
	char ch;

	for (ch = 'Z'; ch > = 'a'; ch--)
	{
		putchar(ch);
	}
	putchar('\n');
	return (0);
}
