#include <stdio.h>
#include <string.h>

char hello[12];

int main(void) {
    strcpy(hello, "Hello World");
    printf("%s", hello);
    return 0;
}