#include <stdio.h>
#include <stdlib.h>
typedef struct simpul DNode;
struct simpul {
  int data;
  DNode *next;
  DNode *prev;
};

DNode *head = NULL, *tail = NULL, *baru;
void alokasi_Dnode(int x) {
  baru = (DNode *)malloc(sizeof(DNode));
  if (baru == NULL) {
    printf("Alokasi gagal\n");
    exit(1);
  } else {
    baru->data = x;
    baru->next = NULL;
    baru->prev = NULL;
  }
}
void cetak_headtail() {
  DNode *p = head;
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}
void sisip_awal() {
  baru->next = head;
  head->prev = baru;
  head = baru;
}
void sisip_akhir() {
  baru->prev = tail;
  tail->next = baru;
  tail = baru;
}
void sisip_sebelum_simpul(int x) {
  DNode *before = head;
  while (before->data != x)
    before = before->next;
  baru->next = before;
  baru->prev = before->prev;
  before->prev->next = baru;
  before->prev = baru;
}
void sisip_urut() {
  DNode *p;
  if (head == NULL) {
    head = baru;
    tail = baru;
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
      sisip_sebelum_simpul(p->data);
  }
}
void free_node(DNode *p) {
  free(p);
  p = NULL;
}
void hapus_awal() {
  DNode *hapus = head;
  head = head->next;
  if (head != NULL) {
    head->prev = NULL;
  } else {
    tail = NULL;
  }
  free_node(hapus);
}
void hapus_akhir() {
  DNode *hapus = tail;
  tail = tail->prev;
  tail->next = NULL;
  free_node(hapus);
}
void hapus_tengah(int x) {
  DNode *hapus = head;
  while (hapus->data != x)
    hapus = hapus->next;
  hapus->next->prev = hapus->prev;
  hapus->prev->next = hapus->next;
  free_node(hapus);
}
void hapus_x(int x) {
  DNode *hapus = head;
  if (hapus->data == x)
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
int main(int argc, char *argv[]) {
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
      alokasi_Dnode(dt);
      sisip_urut();
      break;

    case 2:
      printf("Masukkan data: ");
      scanf("%d", &hps);
      hapus_x(hps);
    }

    cetak_headtail();
    printf("Lagi? ");
    fflush(stdin);
    scanf(" %c", &lagi);
  }

  return 0;
}
