#include <stdio.h>

typedef struct {
  float real;
  float im;
} Komplek;

Komplek Tambah(Komplek Kk1, Komplek Kk2) {
  Komplek hasil;
  hasil.real = Kk1.real + Kk2.real;
  hasil.im = Kk1.im + Kk2.im;
  return hasil;
}

Komplek Kurang(Komplek Kk1, Komplek Kk2) {
  Komplek hasil;
  hasil.real = Kk1.real - Kk2.real;
  hasil.im = Kk1.im - Kk2.im;
  return hasil;
}

Komplek Kali(Komplek Kk1, Komplek Kk2) {
  Komplek hasil;
  hasil.real = (Kk1.real * Kk2.real) - (Kk1.im * Kk2.im);
  hasil.im = (Kk1.real * Kk2.im) + (Kk1.im * Kk2.real);
  return hasil;
}

Komplek Bagi(Komplek Kk1, Komplek Kk2) {
  Komplek hasil;
  hasil.real = ((Kk1.real * Kk2.real) + (Kk1.im * Kk2.im)) /
               ((Kk1.real * Kk1.real) + (Kk1.im * Kk1.im));
  hasil.im = ((Kk1.im * Kk2.real) - (Kk1.real * Kk2.im)) /
             ((Kk2.real * Kk2.real) + (Kk2.im * Kk2.im));
  return hasil;
}

int main() {
  Komplek K1, K2, Hasil;
  printf("Masukkan K1 = ");
  scanf("%f %f", &K1.real, &K1.im);
  printf("Masukkan K2 = ");
  scanf("%f %f", &K2.real, &K2.im);

  Hasil = Tambah(K1, K2);
  printf("Hasil Tambah = %5.2f + %5.2fi\n", Hasil.real, Hasil.im);

  Hasil = Kurang(K1, K2);
  printf("Hasil Kurang = %5.2f - %5.2fi\n", Hasil.real, Hasil.im);

  Hasil = Kali(K1, K2);
  printf("Hasil Kali   = %5.2f X %5.2fi\n", Hasil.real, Hasil.im);

  Hasil = Bagi(K1, K2);
  printf("Hasil Bagi   = %5.2f : %5.2fi\n", Hasil.real, Hasil.im);
}
