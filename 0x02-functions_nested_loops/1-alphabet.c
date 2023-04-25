#include <stdio.h>

void print_alphabet(void);

int main(void)
{
    print_alphabet();
    return 0;
}

void print_alphabet(void)
{
    int start = 'a';
    int end = 'z';
    
    for (int c = start; c <= end; c++) 
    {
        putchar(c);
    }
}
