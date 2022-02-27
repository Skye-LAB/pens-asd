#include "math.h"
#include "stdio.h"

#define N 10

float tambah(int a[], int b[], int x);
float kurang(int a[], int b[], int x);
float kali(int a[], int b[], int x);
float turun(int a[], int x);

int main(int argc, char *argv[]) {

  int p1[N] = {15, 0, 0, 1, 0, 5, 0, 8, 6, 0};
  int p2[N] = {10, 0, 2, 2, 3, 0, 0, 4, 0, 3};
  int p3[N] = {5, 0, 1, 0, 0, 0, 0, 0, 0, 0};

  float x, hasil;

  printf("Masukkan nilai x: ");
  scanf("%f", &x);

  hasil = tambah(p1, p2, x);
  printf("p1 + p2 = %.2f\n", hasil);

  hasil = kurang(p1, p2, x);
  printf("p1 - p2 = %.2f\n", hasil);

  hasil = kali(p1, p3, x);
  printf("p1 * p2 = %.2f\n", hasil);

  hasil = turun(p2, x);
  printf("p2' = %.2f\n", hasil);

  return 0;
}

float tambah(int a[], int b[], int x) {
  float hasil = 0.0;

  for (int i = 0; i < N; i++) {
    hasil += (a[i] + b[i]) * (float)pow(x, i);
  }

  return hasil;
}

float kurang(int a[], int b[], int x) {
  float hasil = 0.0;

  for (int i = 0; i < N; i++) {
    hasil += (a[i] - b[i]) * (float)pow(x, i);
  }

  return hasil;
}

float kali(int a[], int b[], int x) {
  float hasil = 0.0;

  for (int i = 0; i < N; i++) {
    hasil += (a[i] * b[i]) * (float)pow(x, i);
  }

  return hasil;
}

float turun(int a[], int x) {
    float hasil=0.0;

    for(int i=0; i<N; i++)
        hasil += a[i] * i * (float) pow(x,i-1);

    return hasil;
}
