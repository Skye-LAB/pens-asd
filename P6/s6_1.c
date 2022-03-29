#include "stdio.h"
#include "stdlib.h"
#include <bits/pthreadtypes.h>

typedef struct simpul Node;
struct simpul {
  int konstanta;
  int pangkat;
  Node *next;
};

Node *baru, *head = NULL;
void allocate_node(int konst, int pkt) {
  baru = (Node *)malloc(sizeof(Node));
  if (baru == NULL) {
    printf("Alokasi gagal\n");
    exit(1);
  } else {
    baru->konstanta = konst;
    baru->pangkat = pkt;
    baru->next = NULL;
  }
}

void sisip_awal() {
  baru->next = head;
  head = baru;
}

void sisip_sebelum(int x) {
  Node *before = head;
  if (head == NULL) {
    head = baru;
  } else if (head->pangkat == x) {
    sisip_awal();
  } else {
    while (before != NULL && before->next->pangkat != x)
      before = before->next;
    if (before == NULL)
      printf("Simpul tidak tersedia\n");
    else {
      baru->next = before->next;
      before->next = baru;
    }
  }
}

void sisip_akhir() {
  Node *tail = head;
  while (tail->next != NULL) {
    tail = tail->next;
  }
  tail->next = baru;
}

void sisip_urut() {
  Node *before = head;
  if (head == NULL) {
    head = baru;
  } else if (baru->pangkat < head->pangkat) {
    sisip_awal();
  } else {
    while (before != NULL && baru->pangkat > before->pangkat)
      before = before->next;
    if (before == NULL)
      sisip_akhir();
    else if (baru->pangkat == before->pangkat)
      printf("Duplikat data\n");
    else
      sisip_sebelum(before->pangkat);
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

void hapus(int x) {
  Node *hapus = head, *before = head;
  if (hapus->pangkat == x) {
    hapus_awal();
  } else {
    while (hapus != NULL && hapus->pangkat != x) {
      before = hapus;
      hapus = hapus->next;
    }

    if (hapus == NULL)
      printf("Simpul tidak tersedia\n");
    else {
      before->next = hapus->next;
      free_node(hapus);
    }
  }
}

void cetak() {
  Node *p = head;
  printf("P = ");
  while (p != NULL) {
    if (p->next != NULL)
      printf("%dx%d + ", p->konstanta, p->pangkat);
    else
      printf("%dx%d\n", p->konstanta, p->pangkat);
    p = p->next;
  }
}

int main(int argc, char *argv[]) {
  int pilih, konst, pkt;
  char lagi = 'y';

  while (lagi == 'y') {
    printf("1. Sisip Urut\n");
    printf("2. Hapus\n");
    printf("Pilihan: ");
    fflush(stdin);
    scanf("%d", &pilih);
    switch (pilih) {
    case 1:
      printf("Masukkan konstanta dan pangkat: ");
      scanf("%d %d", &konst, &pkt);
      allocate_node(konst, pkt);
      sisip_urut();
      break;
    case 2:
      printf("Masukkan pangkat yang dihapus: ");
      scanf("%d", &pkt);
      hapus(pkt);
      break;
    }

    cetak();
    printf("Lagi? ");
    fflush(stdin);
    scanf(" %c", &lagi);
  }
  return 0;
}
