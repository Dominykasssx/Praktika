#include <stdio.h>


void number_printer(int *var)
{
    printf("Number is - %d\n", var);
}

int main(void)
{
    int var = 345;
    number_printer(&var);
    return 0;
}