#include "stdio.h"

int bil_pascal(int a, int b) {
  if (b == 0 || b == a)
    return 1;
  else
    return bil_pascal(a - 1, b - 1) + bil_pascal(a - 1, b);
}

int main(int argc, char *argv[]) {
  int batas;

  printf("Berapa baris: ");
  scanf("%d", &batas);

  int spasi = batas;

  for (int i = 0; i < batas; i++) {
    printf("F%d", i + 1);
    for (int j = 0; j <= spasi; j++)
      printf(" ");
    for (int k = 0; k <= i; k++) {
      printf("%d ", bil_pascal(i, k));
    }
    printf("\n");
    spasi--;
  }

  return 0;
}
