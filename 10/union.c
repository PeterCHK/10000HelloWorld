#include <stdio.h>
#include <string.h>

union Message {
   int number;
   char greeting[20];
};

int main() {
   union Message message;
   message.number = 0;
   strcpy(message.greeting, "Hello World");
   printf("%d\n", message.number);
   printf("%s", message.greeting);

   return 0;
}