#include "stdio.h"

#define N 2

void kali(int a[N][N], int b[N][N], int c[N][N]);
void tambah(int a[N][N], int b[N][N], int c[N][N]);
void kurang(int a[N][N], int b[N][N], int c[N][N]);

int main(int argc, char *argv[]) {
  int a[N][N] = {{1, 2}, {3, 4}};
  int b[N][N] = {{5, 6}, {7, 8}};
  int hasil[N][N], i, j;

  kali(a, b, hasil);
  printf("Hasil kali: \n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", hasil[i][j]);
    }
    printf("\n");
  }

  tambah(a, b, hasil);
  printf("Hasil Tambah: \n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", hasil[i][j]);
    }
    printf("\n");
  }

  kurang(a, b, hasil);
  printf("Hasil Kurang: \n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", hasil[i][j]);
    }
    printf("\n");
  }
  return 0;
}

void kali(int a[N][N], int b[N][N], int c[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        c[i][j] = a[i][k] * b[k][j];
      }
    }
  }
};

void tambah(int a[N][N], int b[N][N], int c[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }
};

void kurang(int a[N][N], int b[N][N], int c[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      c[i][j] = a[i][j] - b[i][j];
    }
  }
};
