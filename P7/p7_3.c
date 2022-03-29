#include "stdio.h"
#include <math.h>
#include <stdlib.h>

typedef struct simpul DNode;
typedef int itemType;
struct simpul {
  itemType item;
  DNode *prev;
  DNode *next;
};
typedef struct {
  DNode *front;
  DNode *rear;
  int count;
} queue;

void inisialisasi(queue *q) {
  q->front = NULL;
  q->rear = NULL;
  q->count = 0;
}

int kosong(queue *q) { return (q->rear == NULL); }

void enqueue(queue *q, itemType x) {
  DNode *baru = (DNode *)malloc(sizeof(DNode));
  if (baru == NULL) {
    printf("Alokasi Gagal!!");
    exit(1);
  } else {
    baru->item = x;
    baru->next = NULL;
    baru->prev = q->rear;
    if (q->rear == NULL) {
      q->rear = baru;
      q->front = baru;
    } else {
      q->rear->next = baru;
      q->rear = baru;
      q->count++;
    }
  }
}

itemType dequeue(queue *q) {
  DNode *hapus;
  itemType temp;
  if (kosong(q)) {
    printf("Queue Kosong!!");
    return ' ';
  } else {
    temp = q->front->item;
    hapus = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
      q->rear = NULL;
    else
      q->front->prev = NULL;
    free(hapus);
    q->count--;
    return temp;
  }
}

int main(int argc, char *argv[]) {
  queue antrian;
  inisialisasi(&antrian);
  int des, des_awal, shift, i, hasil = 0;
  printf("Masukkan bil desimal= ");
  scanf("%d", &des_awal);
  printf("Masukkan jumlah shift= ");
  scanf("%d", &shift);
  des = des_awal;
  while (des > 0) {
    enqueue(&antrian, des % 2);
    des /= 2;
  }
  for (i = 0; i < shift; i++)
    enqueue(&antrian, dequeue(&antrian));
  i = 0;
  while (!kosong(&antrian)) {
    hasil += dequeue(&antrian) * (int)pow(2, i);
    i++;
  }
  printf("Hasil %d shift %d = %d\n", des_awal, shift, hasil);
  return 0;
}
