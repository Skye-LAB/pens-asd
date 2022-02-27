#include "stdio.h"
#include "string.h"
#define MAX 25

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

char Pop(Stack *s) {
  char temp = ' ';
  if (Kosong(s)) {
    printf("Stack Kosong, tidak dapat mengambil data\n");
    return ' ';
  } else {
    s->count--;
    temp = s->item[s->count];

    return temp;
  }
}

int main(int argc, char *argv[]) {
  Stack tumpuk;
  char str[MAX], temp;
  int j, counter;
  Inisialisasi(&tumpuk);

  printf("Enter a string : ");
  fgets(str, MAX, stdin);

  j = strlen(str);

  for (int i = 0; i < j; i++) {
    Push(&tumpuk, str[i]);
  }

  for (int i = 0; i < j; i++) {
    printf("%c", Pop(&tumpuk));
  }

  return 0;
}
