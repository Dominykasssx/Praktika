#include <stdio.h>
#include <stdlib.h>

void mem_alloc(char **buffer)
{
    *buffer = malloc(25 * sizeof(char));
}

int main(void)
{
    char *buffer = NULL;
    mem_alloc(&buffer);
    strcpy(buffer, "Some random text to be copied to the buffer");
    printf("%s\n", buffer);
    free(buffer);
    return 0;
}