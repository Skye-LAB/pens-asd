#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul DNode;
struct simpul {
  int nrp;
  int kelas;
  char nama[20];
  DNode *next;
  DNode *prev;
};

DNode *head = NULL, *tail = NULL, *baru;
void alokasi_Dnode(int nrp, char nama[], int kelas) {
  baru = (DNode *)malloc(sizeof(DNode));
  if (baru == NULL) {
    printf("Alokasi gagal\n");
    exit(1);
  } else {
    baru->nrp = nrp;
    strcpy(baru->nama, nama);
    baru->kelas = kelas;
    baru->next = NULL;
    baru->prev = NULL;
  }
}
void cetak_headtail() {
  DNode *p = head;
  printf("\n");
  while (p != NULL) {
    printf("NRP: %d, Nama: %s, Kelas: %d \n", p->nrp, p->nama, p->kelas);
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
  while (before->nrp != x)
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
  } else if (head->nrp > baru->nrp) {
    sisip_awal();
  } else {
    p = head;
    while (p != NULL && baru->nrp > p->nrp)
      p = p->next;
    if (p == NULL)
      sisip_akhir();
    else if (baru->nrp == p->nrp)
      printf("Simpul sudah ada\n");
    else
      sisip_sebelum_simpul(p->nrp);
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
  while (hapus->nrp != x)
    hapus = hapus->next;
  hapus->next->prev = hapus->prev;
  hapus->prev->next = hapus->next;
  free_node(hapus);
}
void hapus_x(int x) {
  DNode *hapus = head;
  if (hapus->nrp == x)
    hapus_awal();
  else {
    while (hapus != NULL && hapus->nrp != x)
      hapus = hapus->next;
    if (hapus == NULL)
      printf("Simpul tidak ada\n");
    else if (hapus->next == NULL)
      hapus_akhir();
    else
      hapus_tengah(x);
  }
}
void update_x(int x, char nama[], int kelas) {
  DNode *p;
  if (head->nrp == x) {
    head->kelas = kelas;
    strcpy(head->nama, nama);
  } else {
    p = head;
    while (p != NULL && p->nrp != x)
      p = p->next;
    if (p->next == NULL) {
      tail->kelas = kelas;
      strcpy(tail->nama, nama);
    } else if (p->nrp == x) {
      p->kelas = kelas;
      strcpy(p->nama, nama);
    } else
      printf("Simpul tidak ada");
  }
}

int main(int argc, char *argv[]) {
  int nrp, kelas, pilih, hps;
  char nama[20];
  char lagi = 'y';
  while (lagi == 'y') {
    printf("1. Sisip urut\n");
    printf("2. Hapus\n");
    printf("3. Update\n");
    printf("Pilihan: ");
    fflush(stdin);
    scanf("%d", &pilih);

    switch (pilih) {
    case 1:
      printf("Masukkan NRP: ");
      scanf("%d", &nrp);
      printf("Masukkan Nama: ");
      scanf("%s", nama);
      printf("Masukkan Kelas: ");
      scanf("%d", &kelas);
      alokasi_Dnode(nrp, nama, kelas);
      sisip_urut();
      break;

    case 2:
      printf("Masukkan NRP yang dihapus: ");
      scanf("%d", &hps);
      hapus_x(hps);
      break;

    case 3:
      fflush(stdin);
      printf("Nomor NRP yang ingin diubah: ");
      scanf("%d", &nrp);
      printf("Ubah nama: ");
      scanf("%s", nama);
      printf("Ubah kelas: ");
      scanf("%d", &kelas);
      update_x(nrp, nama, kelas);
      break;
    }

    cetak_headtail();
    printf("Lagi? ");
    fflush(stdin);
    scanf(" %c", &lagi);
  }

  return 0;
}
