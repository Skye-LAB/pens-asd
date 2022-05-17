#include "stdio.h"

#define N 5
#define M 1000

void cetak(int data[N][N], char *judul) {
  printf("%s\n", judul);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (data[i][j] < M)
        printf("%d\t", data[i][j]);
      else
        printf("M\t");
    }
    printf("\n");
  }
}

void warshall(int q[N][N], int p[N][N], int r[N][N]) {
  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) {
        if (q[i][k] + q[k][j] < q[i][j]) {
          q[i][j] = q[i][k] + q[k][j];
          if (r[k][j] == 0)
            r[i][j] = k + 1;
          else
            r[i][j] = r[k][j];
        }
        p[i][j] = p[i][j] || (p[i][k] && p[k][j]);
      }
}

int main(int argc, char *argv[]) {
  int q[N][N] = {{M, 1, 3, M, M},
                 {M, M, 1, M, 5},
                 {3, M, M, 2, M},
                 {M, M, M, M, 1},
                 {M, M, M, M, M}};

  int p[N][N] = {{0, 1, 1, 0, 0},
                 {0, 0, 1, 0, 1},
                 {1, 0, 0, 1, 0},
                 {0, 0, 0, 0, 1},
                 {0, 0, 0, 0, 0}};

  int r[N][N] = {{M, 0, 0, M, M},
                 {M, M, 0, M, 0},
                 {0, M, M, 0, M},
                 {M, M, M, M, 0},
                 {M, M, M, M, M}};

  printf("Sebelum:\n");
  cetak(q, "Beban");
  cetak(p, "Jalur");
  cetak(r, "Rute");
  warshall(q, p, r);
  printf("Sesudah:\n");
  cetak(q, "Beban");
  cetak(p, "Jalur");
  cetak(r, "Rute");

  return 0;
}
