#include <stdio.h>
#include <string.h>

int main(void)
{
    char buffer[20];
    strcpy(buffer, "Copy this text to the buffer variable");
    printf("%s\n", buffer);
    return 0;
}