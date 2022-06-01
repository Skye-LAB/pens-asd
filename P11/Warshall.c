#include<stdio.h>
#define N 5
#define M 1000
#define MAX 50
typedef int Itemtype;
typedef struct {
    Itemtype item[MAX];
    int count;
} Stack;
void Inisialisasi(Stack *s)
{
    s->count = 0;
}
int Penuh(Stack *s)
{
    return (s->count==MAX);
}
int Kosong(Stack *s)
{
    return (s->count==0);
}
void Push(Stack *s, Itemtype x)
{
    if(Penuh(s)) printf("Stack penuh\n");
    else{
        s->item[s->count] = x;
        s->count++;
    }
}
Itemtype Pop (Stack *s)
{
    Itemtype temp=-1;
    if (Kosong(s)) printf("Stack kosong\n");
    else{
        s->count--;
        temp = s->item[s->count];
    }
    return temp;
}
void cetak(int A[N][N], char *judul)
{
    int i, j;
    printf("%s\n",judul);
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            if(A[i][j]<M)
                printf("%d ",A[i][j]);
            else
                printf("M ");
        printf("\n");
    }
}
void warshall(int Q[N][N], int P[N][N], int R[N][N])
{
    int k, i, j;
    for(k=0;k<N;k++)
        for(i=0;i<N;i++)
            for(j=0;j<N;j++){
                if(Q[i][k]+Q[k][j]<Q[i][j]){
                    Q[i][j] = Q[i][k] + Q[k][j];
                    if(R[k][j]==0)
                        R[i][j] = k+1;
                    else
                        R[i][j] = R[k][j];
                }
                P[i][j] = P[i][j] | (P[i][k] & P[k][j]);
            }
}
main()
{
    int Q[N][N] = {M,1,3,M,M,
                   M,M,1,M,5,
                   3,M,M,2,M,
                   M,M,M,M,1,
                   M,M,M,M,M};
    int P[N][N] = {0,1,1,0,0,
                   0,0,1,0,1,
                   1,0,0,1,0,
                   0,0,0,0,1,
                   0,0,0,0,0};
    int R[N][N] = {M,0,0,M,M,
                   M,M,0,M,0,
                   0,M,M,0,M,
                   M,M,M,M,0,
                   M,M,M,M,M};
    int asal, tujuan, kolom;
    Stack tump;
    Inisialisasi(&tump);
    printf("Sebelum Warshall:\n");cetak(Q,"Beban");cetak(P,"Jalur");cetak(R,"Rute");
    warshall(Q,P,R);
    printf("Setelah Warshall:\n");cetak(Q,"Beban");cetak(P,"Jalur");cetak(R,"Rute");
    printf("Masukkan rute asal dan tujuan: ");scanf("%d %d",&asal,&tujuan);
    kolom=tujuan;
    while(R[asal-1][kolom-1]!=0){
        Push(&tump,R[asal-1][kolom-1]);
        kolom = R[asal-1][kolom-1];
    }
    printf("Rute = %d - ", asal);
    while(!Kosong(&tump))
        printf("%d - ",Pop(&tump));
    printf("%d\n", tujuan);
    printf("Beban dari %d ke %d = %d\n", asal, tujuan, Q[asal-1][tujuan-1]);
}
