#include "stdio.h"

#define MAX 5
typedef int Itemtype;
typedef struct {
  Itemtype item[MAX];
  int count;
  int front;
  int rear;
} Queue;

typedef struct {
  Itemtype item[MAX];
  int count;
} Stack;

void qInisialisasi(Queue *q) {
  q->count = 0;
  q->front = 0;
  q->rear = 0;
}

int qKosong(Queue *q) { return (q->count == 0); }
int qPenuh(Queue *q) { return (q->count == MAX); }

void qEnqueue(Queue *q, Itemtype x) {
  if (qPenuh(q))
    printf("Queue Penuh, Data tidak dapat disimpan\n");
  else {
    q->item[q->rear] = x;
    q->rear = (q->rear + 1) % MAX;
    q->count++;
  }
}

Itemtype qDequeue(Queue *q) {
  Itemtype temp = -1;
  if (qKosong(q)) {
    printf("Queue Kosong, tidak dapat mengambil data\n");
    return ' ';
  } else {
    temp = q->item[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return (temp);
  }
}

void sInisialisasi(Stack *s) { s->count = 0; }
int sPenuh(Stack *s) { return (s->count == MAX); }
int sKosong(Stack *s) { return (s->count == 0); }

void Push(Stack *s, Itemtype x) {
  if (sPenuh(s))
    printf("Stack Penuh\n");
  else {
    s->item[s->count] = x;
    s->count++;
  }
}
Itemtype Pop(Stack *s) {
  Itemtype temp = -1;
  if (sKosong(s))
    printf("Stack Kosong\n");
  else {
    s->count--;
    temp = s->item[s->count];
  }
  return temp;
}

int main(int argc, char *argv[]) {
  int counter = 1, no, ans3;
  char ans1, ans2;
  Queue antrian;
  Stack tumpukan;
  qInisialisasi(&antrian);
  sInisialisasi(&tumpukan);

  do {
    fflush(stdin);
    printf("1. Tambah Mobil\n");
    printf("2. Keluarkan Mobil\n");
    printf("Pilihan: ");
    scanf(" %c", &ans1);

    switch (ans1) {
    case '1':
      printf("Masukkan nomor antrian: ");
      scanf("%d", &no);
      qEnqueue(&antrian, no);

      printf("Daftar antrian: ");
      for (int i = 0; i < counter; i++) {
        printf("%d ", antrian.item[i]);
      }
      counter++;
      break;
    case '2':
      printf("Indeks keberapa: ");
      scanf("%d", &ans3);
      for (int i = 0; i <= ans3; i++) {
        Push(&tumpukan, qDequeue(&antrian));
      }
      Pop(&tumpukan);
      while (!sKosong(&tumpukan)) {
        qEnqueue(&antrian, Pop(&tumpukan));
      }

      printf("Daftar antrian: ");
      while (!qKosong(&antrian)) {
        printf("%d ", qDequeue(&antrian));
      }
      break;
    default:
      printf("Pilihan salah");
    }

    printf("\nLakukan lagi?(y/t)");
    scanf(" %c", &ans2);
  } while (ans2 == 'y');

  return 0;
}
