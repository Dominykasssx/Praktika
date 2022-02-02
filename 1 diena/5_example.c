#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *buffer;
    buffer = malloc(25);
    strcpy(buffer, "Some random text");
    text_printer(buffer);
    free(buffer);
    return 0;
}

void text_printer(char *msg)
{
    printf("%s\n", msg);
    free(msg);
}