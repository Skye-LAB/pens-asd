#include "stdio.h"

int main(int argc, char *argv[]) {
  char awal[6] = {'p', 'e', 'n', 's', 'i', 't'};
  int j = 5;

  for (int i = 0; i < 3; i++) {
    char tmp = awal[i];
    awal[i] = awal[j];
    awal[j] = tmp;
    j--;
  }

  for (int i = 0; i < 6; i++) {
    printf("%c", awal[i]);
  }

  return 0;
}
