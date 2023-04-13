#include <stdio.h>

int main()
{
    int ascii_codes[] = {72, 101, 108, 108, 111, 32, 87, 111, 114, 108, 100};
    int length = sizeof(ascii_codes) / sizeof(ascii_codes[0]);

    char hello_world[length + 1];
    for (int i = 0; i < length; i++)
    {
        hello_world[i] = (char)ascii_codes[i];
    }
    hello_world[length] = '\0';

    printf("%s\n", hello_world);

    return 0;
}