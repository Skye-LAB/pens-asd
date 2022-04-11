#include "stdio.h"
#include "string.h"

struct simpul {
  int nrp;
  char nama[20];
  int nilai;
};

struct simpul data[10];
int j = 0;

void tambah() {
  char jawab;
  while (1) {
    fflush(stdin);
    printf("NRP: ");
    scanf("%d", &data[j].nrp);
    printf("Nama: ");
    scanf("%s", data[j].nama);
    printf("Nilai: ");
    scanf("%d", &data[j].nilai);

    printf("Lagi? ");
    fflush(stdin);
    scanf(" %c", &jawab);

    if (jawab == 'y') {
      j++;
      continue;
    } else {
      break;
    }
  }
}

void tampil() {
  printf("NRP\tNama\tNilai\n");
  for (int i = 0; i <= j; i++) {
    printf("%d\t%s\t%d\n", data[i].nrp, data[i].nama, data[i].nilai);
  }
}

int main(int argc, char *argv[]) {
  tambah();
  tampil();
  return 0;
}
