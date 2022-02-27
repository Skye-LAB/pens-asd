#include <math.h>
#include <stdio.h>
#include <string.h>
#define MAX 20

typedef int Itemtype;
typedef struct {
  Itemtype item[MAX];
  int count;
} Stack;

void inisialisasi(Stack *s) { s->count = 0; }
int Penuh(Stack *s) { return (s->count == MAX); }
int Kosong(Stack *s) { return (s->count == 0); }
void Push(Stack *s, Itemtype x) {
  if (Penuh(s))
    printf("Stack Penuh\n");
  else {
    s->item[s->count] = x;
    s->count++;
  }
}
Itemtype Pop(Stack *s) {
  Itemtype temp = -1;
  if (Kosong(s))
    printf("Stack Kosong\n");
  else {
    s->count--;
    temp = s->item[s->count];
  }
  return temp;
}

int main() {
  Stack a;
  char postfix[MAX];
  int i, opright, opleft, hasil;
  Itemtype temp;
  inisialisasi(&a);
  printf("Masukkan Notasi posfix = ");
  scanf("%s", &postfix);
  for (i = 0; i < strlen(postfix); i++) {
    if (postfix[i] >= '0' && postfix[i] <= '9')
      Push(&a, postfix[i] - 48);
    else if (postfix[i] == '^' || postfix[i] == '*' || postfix[i] == '/' ||
             postfix[i] == '+' || postfix[i] == '-') {
      opright = Pop(&a);
      opleft = Pop(&a);
      switch (postfix[i]) {
      case '^':
        hasil = (int)pow(opleft, opright);
        break;
      case '*':
        hasil = opleft * opright;
        break;
      case '/':
        hasil = (int)opleft / opright;
        break;
      case '+':
        hasil = opleft + opright;
        break;
      case '-':
        hasil = opleft - opright;
        break;
      default:
        printf("Operator Tidak dikenali\n");
        break;
      }
      Push(&a, hasil);
    }
  }
  while (!Kosong(&a))
    printf("hasil = %d\n", Pop(&a));
}
