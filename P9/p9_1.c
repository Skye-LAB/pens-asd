#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define N 20

void insertion(int data[]) {
  int i, j, key;
  i = 1;
  while (i < N) {
    key = data[i];
    j = i - 1;
    while (j >= 0 && data[j] > key) {
      data[j + 1] = data[j];
      j--;
    }
    data[j + 1] = key;
    i++;
  }
}

void insertion_desc(int data[]) {
  int i, j, key;
  i = 1;
  while (i < N) {
    key = data[i];
    j = i - 1;
    while (j >= 0 && data[j] < key) {
      data[j + 1] = data[j];
      j--;
    }
    data[j + 1] = key;
    i++;
  }
}

void selection(int data[]) {
  int i, j, min, temp;
  i = 0;
  while (i < N - 1) {
    min = i;
    j = i + 1;
    while (j < N) {
      if (data[j] < data[min])
        min = j;
      j++;
    }
    temp = data[i];
    data[i] = data[min];
    data[min] = temp;
    i++;
  }
}

void selection_desc(int data[]) {
  int i, j, min, temp;
  i = 0;
  while (i < N - 1) {
    min = i;
    j = i + 1;
    while (j < N) {
      if (data[j] > data[min])
        min = j;
      j++;
    }
    temp = data[i];
    data[i] = data[min];
    data[min] = temp;
    i++;
  }
}

void bubble(int data[]) {
  for (int i = 1; i < N - 1; i++) {
    for (int j = N - 1; j >= i; j--) {
      if (data[j] < data[j - 1]) {
        int temp;
        temp = data[j];
        data[j] = data[j - 1];
        data[j - 1] = temp;
      }
    }
  }
}

void bubble_desc(int data[]) {
  for (int i = 0; i <= N - 1; i++) {
    for (int j = N; j >= i; j--) {
      if (data[j] > data[j - 1]) {
        int temp;
        temp = data[j];
        data[j] = data[j - 1];
        data[j - 1] = temp;
      }
    }
  }
}

void bubble_flag(int data[]) {
  int did_swap = 1;
  for (int i = 1; did_swap && i < N - 1; i++) {
    did_swap = 0;
    for (int j = N - 1; j >= i; j--) {
      if (data[j] < data[j - 1]) {
        int temp;
        temp = data[j];
        data[j] = data[j - 1];
        data[j - 1] = temp;
      }
    }
  }
}

void shell(int data[]) {
  int jarak, did_swap, temp;
  jarak = N;
  while (jarak >= 1) {
    jarak /= 2;
    did_swap = 1;
    while (did_swap) {
      did_swap = 0;
      for (int i = 0; i < N - jarak; i++) {
        if (data[i] > data[i + jarak]) {
          temp = data[i];
          data[i] = data[i + jarak];
          data[i + jarak] = temp;
          did_swap = 1;
        }
      }
    }
  }
}

void shell_desc(int data[]) {
  int jarak, did_swap, temp;
  jarak = N;
  while (jarak >= 1) {
    jarak /= 2;
    did_swap = 1;
    while (did_swap) {
      did_swap = 0;
      for (int i = 0; i < N - jarak; i++) {
        if (data[i] < data[i + jarak]) {
          temp = data[i];
          data[i] = data[i + jarak];
          data[i + jarak] = temp;
          did_swap = 1;
        }
      }
    }
  }
}

int partisi(int data[], int p, int r) {
  int pivot, i, j, temp;
  pivot = data[p];
  i = p;
  j = r;
  while (i < j) {
    while (data[i] < pivot)
      i++;
    while (data[j] > pivot)
      j--;
    if (i < j) {
      temp = data[i];
      data[i] = data[j];
      data[j] = temp;
    } else
      return j;
  }
  return j;
}

void quick(int data[], int p, int r) {
  int q;
  if (p < r) {
    q = partisi(data, p, r);
    quick(data, p, q);
    quick(data, q + 1, r);
  }
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
  int awal[N], data[N], pilih;
  char lagi = 'y';

  // loop until N
  for (int i = 0; i < N; i++) {
    // make a diff number when generating
    srand(time(NULL) * (i + 1));
    // get 1 - 100
    awal[i] = rand() % 100 + 1;
    printf("%d ", awal[i]);
  }

  printf("\n");

  while (lagi == 'y') {
    // copy awal to data
    for (int i = 0; i < N; i++) {
      data[i] = awal[i];
    }
    printf("1. Insertion Sort\n");
    printf("2. Insertion Sort(desc)\n");
    printf("3. Selection Sort\n");
    printf("4. Selection Sort(desc)\n");
    printf("5. Bubble Sort\n");
    printf("6. Bubble Sort(flag)\n");
    printf("7. Bubble Sort(desc)\n");
    printf("8. Shell Sort\n");
    printf("9. Shell Sort(desc)\n");
    printf("10. Quick Sort\n");
    printf("11. Quick Sort(desc)\n");
    printf("12. Merge Sort\n");
    printf("13. Merge Sort(desc)\n");
    printf("Pilihan: ");
    fflush(stdin);
    scanf("%d", &pilih);

    switch (pilih) {
    case 1:
      insertion(data);
      break;
    case 2:
      insertion_desc(data);
      break;
    case 3:
      selection(data);
      break;
    case 4:
      selection_desc(data);
      break;
    case 5:
      bubble(data);
      break;
    case 6:
      bubble_flag(data);
      break;
    case 7:
      bubble_desc(data);
      break;
    case 8:
      shell(data);
      break;
    case 9:
      shell_desc(data);
      break;
    case 10:
      quick(data, 0, N - 1);
      break;
    case 11:
      quick(data, 0, N - 1);
      break;
    case 12:
      merge_sort(data, 0, N - 1);
      break;
    case 13:
      merge_sort(data, 0, N - 1);
      break;
    }

    // print data
    for (int i = 0; i < N; i++) {
      printf("%d ", data[i]);
    }
    printf("\nLagi? ");
    fflush(stdin);
    scanf(" %c", &lagi);
  }

  return 0;
}
