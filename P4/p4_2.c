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
    printf("%d ", p->data);
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
  while (tail->next != NULL)
    tail = tail->next;
  tail->next = baru;
}
void sisip_sebelum(int x) {
  Node *before = head;
  while (before->next->data != x)
    before = before->next;
  baru->next = before->next;
  before->next = baru;
}
void sisip_urut() {
  Node *p;
  if (head == NULL) {
    head = baru;
  } else if (head->data > baru->data) {
    sisip_awal();
  } else {
    p = head;
    while (p != NULL && baru->data > p->data)
      p = p->next;
    if (p == NULL)
      sisip_akhir();
    else if (baru->data == p->data)
      printf("Simpul sudah ada\n");
    else
      sisip_sebelum(p->data);
  }
}
void free_node(Node *p) {
  free(p);
  p = NULL;
}
void hapus_awal() {
  Node *hapus = head;
  head = hapus->next;
  free_node(hapus);
}
void hapus_akhir() {
  Node *hapus = head, *before;
  while (hapus->next != NULL) {
    before = hapus;
    hapus = hapus->next;
  }
  before->next = NULL;
  free_node(hapus);
}
void hapus_tengah(int x) {
  Node *hapus = head, *before;
  while (hapus->data != x) {
    before = hapus;
    hapus = hapus->next;
  }
  before->next = hapus->next;
  free_node(hapus);
}
void hapus_x(int x) {
  Node *hapus = head;
  if (head->data == x)
    hapus_awal();
  else {
    while (hapus != NULL && hapus->data != x)
      hapus = hapus->next;
    if (hapus == NULL)
      printf("Simpul tidak ada\n");
    else if (hapus->next == NULL)
      hapus_akhir();
    else
      hapus_tengah(x);
  }
}
int main() {
  int dt, pilih, hps;
  char lagi = 'y';
  while (lagi == 'y') {
    printf("1. Sisip urut\n");
    printf("2. Hapus\n");
    printf("Pilihan: ");
    fflush(stdin);
    scanf("%d", &pilih);

    switch (pilih) {
    case 1:
      printf("Masukkan data: ");
      scanf("%d", &dt);
      alokasi_simpul(dt);
      sisip_urut();
      break;

    case 2:
      printf("Masukkan data: ");
      scanf("%d", &hps);
      hapus_x(hps);
    }

    cetak();
    printf("Lagi? ");
    fflush(stdin);
    scanf(" %c", &lagi);
  }
}
