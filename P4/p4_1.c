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
void sisip_setelah(int x) {
  Node *after = head;
  while (after->data != x)
    after = after->next;
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
int main() {
  int pilih, dt, x;
  char lagi = 'y';
  alokasi_simpul(10);
  head = baru;
  cetak();
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
      alokasi_simpul(dt);
      sisip_awal();
      break;
    case 2:
      printf("Masukkan data: ");
      scanf("%d", &dt);
      alokasi_simpul(dt);
      sisip_akhir();
      break;
    case 3:
      printf("Masukkan data: ");
      scanf("%d", &dt);
      alokasi_simpul(dt);
      printf("Sisip sebelum simpul: ");
      scanf("%d", &x);
      sisip_sebelum(x);
      break;
    case 4:
      printf("Masukkan data: ");
      scanf("%d", &dt);
      alokasi_simpul(dt);
      printf("Sisip setelah simpul: ");
      scanf("%d", &x);
      sisip_setelah(x);
      break;
    case 5:
      hapus_awal();
      break;
    case 6:
      hapus_akhir();
      break;
    case 7:
      printf("Hapus simpul: ");
      scanf("%d", &x);
      hapus_tengah(x);
      break;
    }
    cetak();
    printf("Lagi? ");
    fflush(stdin);
    scanf("%c", &lagi);
  }
}
