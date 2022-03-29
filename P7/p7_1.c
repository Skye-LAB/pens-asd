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
void cetak_tailhead() {
  DNode *p = tail;
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->prev;
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
void sisip_setelah_simpul(int x) {
  DNode *after = head;
  while (after->data != x)
    after = after->next;
  baru->next = after->next;
  baru->prev = after;
  after->next->prev = baru;
  after->next = baru;
}
void free_node(DNode *p) {
  free(p);
  p = NULL;
}
void hapus_awal() {
  DNode *hapus = head;
  head = head->next;
  head->prev = NULL;
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
int main() {
  int pilih, dt, x;
  char lagi = 'y';
  alokasi_Dnode(10);
  head = tail = baru;
  printf("Head-tail: ");
  cetak_headtail();
  printf("Tail-head: ");
  cetak_tailhead();
  while (lagi == 'y') {
    printf("1.Sisip awal\n");
    printf("2.Sisip akhir\n");
    printf("3.Sisip sebelum simpul tertentu\n");
    printf("4.Sisip setelah simpul tertentu\n");
    printf("5.Hapus awal\n");
    printf("6.Hapus akhir\n");
    printf("7.Hapus tengah\n");
    printf("Pilihan: ");
    fflush(stdin);
    scanf("%d", &pilih);
    switch (pilih) {
    case 1:
      printf("Masukkan data: ");
      scanf("%d", &dt);
      alokasi_Dnode(dt);
      sisip_awal();
      break;
    case 2:
      printf("Masukkan data: ");
      scanf("%d", &dt);
      alokasi_Dnode(dt);
      sisip_akhir();
      break;
    case 3:
      printf("Masukkan data: ");
      scanf("%d", &dt);
      alokasi_Dnode(dt);
      printf("Sisip sebelum simpul: ");
      scanf("%d", &x);
      sisip_sebelum_simpul(x);
      break;
    case 4:
      printf("Masukkan data: ");
      scanf("%d", &dt);
      alokasi_Dnode(dt);
      printf("Sisip setelah simpul: ");
      scanf("%d", &x);
      sisip_setelah_simpul(x);
      break;
    case 5:
      hapus_awal();
      break;
    case 6:
      hapus_akhir();
      break;
    case 7:
      printf("Masukkan simpul yang dihapus : ");
      scanf("%d", &x);
      hapus_tengah(x);
      break;
    }
    printf("Head-tail: ");
    cetak_headtail();
    printf("Tail-head: ");
    cetak_tailhead();
    printf("Lagi? ");
    fflush(stdin);
    scanf(" %c", &lagi);
  }
}
