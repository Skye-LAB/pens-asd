#include "stdio.h"

#define MAX 5
#define N 6
#define M 1000

typedef int Itemtype;
typedef struct {
  Itemtype item[MAX];
  int count;
} Stack;

void Inisialisasi(Stack *s) { s->count = 0; }

int Penuh(Stack *s) { return (s->count == MAX); }

int Kosong(Stack *s) { return (s->count == 0); }

void Push(Stack *s, Itemtype x) {
  if (Penuh(s))
    printf("Stack Penuh, Data tidak dapat disimpan\n");
  else {
    s->item[s->count] = x;
    s->count++;
  }
}

Itemtype Pop(Stack *s) {
  Itemtype temp = -1;
  if (Kosong(s)) {
    printf("Stack Kosong, tidak dapat mengambil data\n");
    return ' ';
  } else {
    s->count--;
    temp = s->item[s->count];

    return temp;
  }
}

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
  int q[N][N] = {{M, 4, 3, M, M, M},
                 {M, M, 5, 2, M, M},
                 {M, M, M, 7, M, M},
                 {M, M, M, M, 2, M},
                 {4, 4, M, M, M, 6},
                 {M, M, M, M, M, M}};

  int p[N][N] = {{0, 1, 1, 0, 0, 0},
                 {0, 0, 1, 1, 0, 0},
                 {0, 0, 0, 1, 0, 0},
                 {0, 0, 0, 0, 1, 0},
                 {1, 1, 0, 0, 0, 1},
                 {0, 0, 0, 0, 0, 0}};

  int r[N][N] = {{M, 0, 0, M, M, M},
                 {M, M, 0, 0, M, M},
                 {M, M, M, 0, M, M},
                 {M, M, M, M, 0, M},
                 {0, 0, M, M, M, 0},
                 {M, M, M, M, M, M}};

  printf("Sebelum:\n");
  cetak(q, "Beban");
  cetak(p, "Jalur");
  cetak(r, "Rute");

  warshall(q, p, r);

  printf("Sesudah:\n");
  cetak(q, "Beban");
  cetak(p, "Jalur");
  cetak(r, "Rute");

  Stack tump;
  Inisialisasi(&tump);
  int asal, tujuan, kolom;

  printf("Masukkan asal dan tujuan: ");
  scanf("%d %d", &asal, &tujuan);

  kolom = tujuan;
  while (r[asal - 1][kolom - 1] != 0) {
    Push(&tump, r[asal - 1][kolom - 1]);
    kolom = r[asal - 1][kolom - 1];
  }

  printf("Rute = %d - ", asal);
  while (!Kosong(&tump))
    printf("%d - ", Pop(&tump));
  printf("%d\n", tujuan);
  printf("Beban dari %d ke %d = %d\n", asal, tujuan, q[asal - 1][tujuan - 1]);

  return 0;
}
