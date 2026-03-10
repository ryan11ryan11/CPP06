#include <stdio.h>
#include <stdlib.h>

int var[10];  /* Uninitialized, so in the .bss segment */

int main()
{
    var[0] = 20; /* Initializing at runtime */
    printf("var[0] = %d\n", var[0]);
    return 0;
}
