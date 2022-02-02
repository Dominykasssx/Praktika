#include <stdio.h>

int main(void)
{
    char *buffer;
    buffer = malloc(15);
    strcpy(buffer, "Some random text");
    printf("%s\n", buffer);
    return 0;
}