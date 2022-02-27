#include "stdio.h"
#include <string.h>
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

int level(char op) {
  if (op == '^')
    return 4;
  else if (op == '*' || op == '/')
    return 3;
  else if (op == '+' || op == '-')
    return 2;
  else if (op == '(')
    return 1;
  else
    return 0;
}

int main(int argc, char *argv[]) {
  Stack t;
  char infix[MAX];
  int temp;
  Inisialisasi(&t);

  printf("Masukkan notasi infix: ");
  scanf("%s", &infix);
  for (int i = 0; i < strlen(infix); i++) {
    if (infix[i] >= '0' && infix[i] <= '9')
      printf("%c", infix[i]);
    else if (infix[i] == "(")
      Push(&t, infix[i]);
    else if (infix[i] == ")") {
      while (t.item[t.count - 1] != "(")
        printf("%c", Pop(&t));
      temp = Pop(&t);
    } else if (Kosong(&t) || level(infix[i]) > level(t.item[t.count - 1]))
      Push(&t, infix[i]);
    else {
      while (level(infix[i]) <= level(t.item[t.count - 1])) {
        printf("%c", Pop(&t));
      }
      Push(&t, infix[i]);
    }
  }

  while (!Kosong(&t))
    printf("%c", Pop(&t));

  return 0;
}
