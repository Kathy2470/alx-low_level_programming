#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
  * main - prints the alpabet in lowercase
  * follwed by a new line, except q and e
  * Return: 0 (Success)
  */
int main(void)
{
	int i;

	for (i = 97; i < 123; i++)
	{
		if (i != 101 && i != 113)
		{
			putchar(i);
		}
	}

	putchar('\n');
	return (0);
}
