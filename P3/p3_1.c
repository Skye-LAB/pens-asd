#include "math.h"
#include "stdio.h"

#define MAX 100
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

int main(int argc, char *argv[]) {
  Queue antrian;
  Inisialisasi(&antrian);

  int des, des_awal, shift, i, hasil = 0;

  printf("Masukkan bilangan desimal: ");
  scanf("%d", &des_awal);
  printf("Masukkan shift: ");
  scanf("%d", &shift);

  des = des_awal;
  while (des > 0) {
    Enqueue(&antrian, des % 2);
    des /= 2;
  }

  for (i = 0; i < shift; i++)
    Enqueue(&antrian, Dequeue(&antrian));

  i = 0;
  while (!Kosong(&antrian)) {
    hasil += Dequeue(&antrian) * (int)pow(2, i);
    i++;
  }

  printf("Hasil %d shift %d = %d", des_awal, shift, hasil);

  return 0;
}
