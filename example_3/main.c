#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

  char str1[20];
  // the one is for security
  char str2[12] = "passwordone";
  int value;

  printf("Enter the password\n");
  while(value != 0) {
    printf("> ");

    // get the user input and strip the newline
    fgets(str1, 20, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    // cmp input to password
    value = strcmp(str1, str2);
  }
  
  printf("\nCorrect Password!\n");

  return 0;
}
