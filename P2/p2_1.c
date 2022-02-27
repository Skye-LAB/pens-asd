#include "stdio.h"
#define MAX 5

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

void konversi(Stack *s, int des, int basis) {
  while (des > 0) {
    Push(s, des % basis);
    des /= basis;
  }

  while (!Kosong(s)) {
    printf("%d ", Pop(s));
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  Stack tumpuk;
  int des, basis;
  Inisialisasi(&tumpuk);

  printf("Masukkan bilangan desimal dan basis = "); scanf("%d %d", &des, &basis);
  konversi(&tumpuk, des, basis);

  return 0;
}
