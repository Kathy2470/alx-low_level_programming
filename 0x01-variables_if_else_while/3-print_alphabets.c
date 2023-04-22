#include <stdio.h>

/**
  * main - print the alphabet of lowercase and uppercase
  * Return: 0 no error, non zero if error
  */
int main(void)
{
	char i;
	char j;

	for (i = 'a'; i < 'Z'; i++)
	{
		putchar(i);
	}
	for (j = 'A'; j < = 'Z'; j++)
	{
		putchar(j);
	}
	putchar('\n');
	return (0);
}
