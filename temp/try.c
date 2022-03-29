#include <stdio.h>
#include <stdlib.h>
typedef struct simpul Node;
struct simpul {
  int data;
  Node *next;
};

Node *head = NULL, *baru;
void alokasi_simpul(int x) {
  baru = (Node *)malloc(sizeof(Node));
  if (baru == NULL) {
    printf("Alokasi gagal\n");
    exit(1);
  } else {
    baru->data = x;
    baru->next = NULL;
  }
}

void cetak() {
  Node *p = head;
  while (p != NULL) {
    printf("%d", p->data);
    p = p->next;
  }
  printf("\n");
}

void sisip_awal() {
  baru->next = head;
  head = baru;
}

void sisip_akhir() {
  Node *tail = head;
  while (tail->next != NULL) {
    tail = tail->next;
  }
  tail->next = baru;
}

void sisip_sebelum(int x) {
  Node *before = head;
  while (before->next->data != x) {
    before = before->next;
  }
  baru->next = before->next;
  before->next = baru;
}

void sisip_setelah(int x) {
  Node *after = head;
  while (after->data == x) {
    after = after->next;
  }
  baru->next = after->next;
  after->next = baru;
}

void free_node(Node *p) {
  free(p);
  p = NULL;
}

void hapus_awal() {
  Node *hapus = head;
  head = hapus->next;
  free(hapus);
}

void hapus_akhir() {
  Node *hapus = head;
  Node *before = head;
  while (hapus->next != NULL) {
    before = hapus;
    hapus = hapus->next;
  }
  before->next = NULL;
  free(hapus);
}

void hapus_tengah(int x) {
  Node *hapus = head;
  Node *before = head;
  while (hapus->data != x) {
    before = hapus;
    hapus = hapus->next;
  }
  before->next = hapus->next;
  free(hapus);
}

int main(int argc, char *argv[]) {

  int data;

  printf("Masukkan data: ");
  scanf("%d", &data);
  alokasi_simpul(data);
  sisip_awal();
  cetak();

  return 0;
}
