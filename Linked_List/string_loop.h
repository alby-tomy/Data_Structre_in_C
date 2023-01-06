#include <stdio.h>
#include <string.h>

int main() {
  int size;
  printf("Enter the number of names to print: ");
  scanf("%d", &size);

  for (int i = 0; i < size; i++) {
    char name[100];  // buffer to store the name

    printf("Enter a name: ");
    fgets(name, sizeof(name), stdin);  // read the name from the user

    // Remove the newline character from the end of the string
    name[strcspn(name, "\n")] = 0;

    printf("Name %d: %s\n", i + 1, name);  // print the name
  }

  return 0;
}
