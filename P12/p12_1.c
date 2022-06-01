#include "stdio.h"

#define MAX 100
#define N 5
#define M 1000

typedef int Itemtype;
typedef struct {
  Itemtype item[MAX];
  int count;
  int front;
  int rear;
} Queue;

void Inisialisasi(Queue *q) {
  q->count = 0;
  q->front = 0;
  q->rear = 0;
}

int Kosong(Queue *q) { return (q->count == 0); }

int Penuh(Queue *q) { return (q->count == MAX); }

void Enqueue(Queue *q, Itemtype x) {
  if (Penuh(q))
    printf("Queue Penuh, Data tidak dapat disimpan\n");
  else {
    q->item[q->rear] = x;
    q->rear = (q->rear + 1) % MAX;
    q->count++;
  }
}

Itemtype Dequeue(Queue *q) {
  Itemtype temp;
  if (Kosong(q)) {
    printf("Queue Kosong, tidak dapat mengambil data\n");
    return ' ';
  } else {
    temp = q->item[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return (temp);
  }
}

int ada_di_queue(Queue *q, int i) {
  int ada = 0, pos = q->front;

  while (!ada && pos != q->rear) {
    if (q->item[pos] == i + 1)
      ada = 1;
    pos = (pos + 1) % MAX;
  }

  return ada;
}

void InitDjiktra(int q[], int r[], int asal) {
  for (int i = 0; i < N; i++) {
    if (i == asal - 1)
      q[i] = 0;
    else
      q[i] = M;
    r[i] = 0;
  }
}

void cetak(int data[N], char *judul) {
  printf("%s\n", judul);
  for (int i = 0; i < N; i++)
    if (data[i] < M)
      printf("%d ", data[i]);
    else
      printf("M ");
  printf("\n");
}

int main(int argc, char *argv[]) {
  int input[N][N] = {{M, 1, 3, M, M},
                 {M, M, 1, M, 5},
                 {3, M, M, 2, M},
                 {M, M, M, M, 1},
                 {M, M, M, M, M}};;
  int asal, tujuan, q[N], r[N], CN, i;
  Queue antrian;
  Inisialisasi(&antrian);

  printf("Masukkan asal dan tujuan: ");
  scanf("%d %d", &asal, &tujuan);

  InitDjiktra(q, r, asal);
  Enqueue(&antrian, asal);

  while (!Kosong(&antrian)) {
    CN = Dequeue(&antrian) - 1;

    for (int i = 0; i < N; i++) {
      if (input[CN][i] != M)
        if (q[CN] + input[CN][i] < q[i]) {
          q[i] = q[CN] + input[CN][i];
          r[i] = CN + 1;

          if (i != asal - 1 && i != tujuan - 1 && !ada_di_queue(&antrian, i)) {
            Enqueue(&antrian, i + 1);
          }
        }
    }
  }

  cetak(q, "Beban");
  cetak(r, "Rute");

  int j = 0;
  int counter = 0;

  printf("Rute = ");
  do {
    if (r[j] == 0)
      counter++;
    if (counter == 2)
      break;
    if (r[j] >= tujuan)
      break;
    printf("%d - ", r[j] + 1);
    j++;
  } while (counter <= 1);
  return 0;
}
