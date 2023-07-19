#include <stdio.h>
#include <string.h>

int main() {
    char input1[100];
    char input2[100];
    char result[200];

    printf("Enter the first input: ");
    scanf("%s", input1);

    printf("Enter the second input: ");
    scanf("%s", input2);

    strcpy(result, input1);
    strcat(result, input2);

    printf("Concatenated string: %s\n", result);

    return 0;

}