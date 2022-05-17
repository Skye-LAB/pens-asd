#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define N 50

int sequential(int data[], int target) {
  int i = 0, ketemu = 0;
  while (i < N && !ketemu) {
    if (data[i] == target)
      ketemu = 1;
    else
      i++;
  }
  if (ketemu)
    return i;
  else
    return -1;
}

int sequential_sorted(int data[], int target) {
  int i = 0, ketemu = 0;
  while (i < N && !ketemu) {
    if (data[i] == target)
      ketemu = 1;
    else if (data[i] > target) {
      printf("\nBerhenti di indeks ke-%d", i);
      return -1;
    } else
      i++;
  }
  if (ketemu)
    return i;
  else
    return -1;
}

int binary(int data[], int target) {
  int l = 0, r = N - 1, m, ketemu = 0;
  while (l <= r && !ketemu) {
    m = (l + r) / 2;
    if (data[m] == target)
      ketemu = 1;
    else if (target < data[m])
      r = m - 1;
    else
      l = m + 1;
  }
  if (ketemu)
    return m;
  else
    return -1;
}

void merge(int data[], int l, int m, int r) {
  int kiri1, kanan1, kiri2, kanan2, temp[N], k;
  kiri1 = l;
  kanan1 = m;
  kiri2 = m + 1;
  kanan2 = r;
  k = l;

  while (kiri1 <= kanan1 && kiri2 <= kanan2) {
    if (data[kiri1] < data[kiri2]) {
      temp[k] = data[kiri1];
      kiri1++;
    } else {
      temp[k] = data[kiri2];
      kiri2++;
    }
    k++;
  }

  while (kiri1 <= kanan1) {
    temp[k] = data[kiri1];
    kiri1++;
    k++;
  }

  while (kiri2 <= kanan2) {
    temp[k] = data[kiri2];
    kiri2++;
    k++;
  }

  k = l;
  while (k <= r) {
    data[k] = temp[k];
    k++;
  }
}

void merge_sort(int data[], int l, int r) {
  int m;
  if (l < r) {
    m = (l + r) / 2;
    merge_sort(data, l, m);
    merge_sort(data, m + 1, r);
    merge(data, l, m, r);
  }
}

int main(int argc, char *argv[]) {
  int data[N], pilih, target, indeks;
  char lagi = 'y';

  // loop until N
  for (int i = 0; i < N; i++) {
    // make a diff number when generating
    srand(time(NULL) * (i + 1));
    // get 1 - 100
    data[i] = rand() % 100 + 1;
    printf("%d ", data[i]);
  }

  while (lagi == 'y') {
    target = rand() % 100;
    printf("\nTarget: %d\n", target);

    printf("1. Sequential Sort\n");
    printf("2. Sequential Sort(sorted)\n");
    printf("3. Binary Sort\n");
    printf("Pilihan: ");
    fflush(stdin);
    scanf("%d", &pilih);

    switch (pilih) {
    case 1:
      indeks = sequential(data, target);
      break;
    case 2:
      merge_sort(data, 0, N - 1);
      for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
      }
      indeks = sequential_sorted(data, target);
      break;
    case 3:
      merge_sort(data, 0, N - 1);
      for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
      }
      indeks = binary(data, target);
      break;
    }

    if (indeks >= 0) {
      printf("\nData ditemukan pada indeks: %d", indeks);
    } else {
      printf("\nData tidak ditemukan");
    }

    printf("\nLagi? ");
    fflush(stdin);
    scanf(" %c", &lagi);
  }
}
