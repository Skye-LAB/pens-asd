#include "stdio.h"
#include "string.h"

struct simpul {
  int nrp;
  char nama[20];
  int nilai;
};

struct simpul mydata;

void tampil(struct tag *p) {
  printf("\n%d", p->nrp);
}
