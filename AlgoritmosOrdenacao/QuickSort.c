#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

void quickSort(int *vet, int left, int dir);
void PrintVet(int *v, int i, int f);


int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int n = TAM;
  if(argc > 1) n = atoi(argv[1]);
  // int i, *vet;
  // vet = (int*) malloc(sizeof(int) * n);
  // for(i=0;i<n;i++)
  //   vet[i] = rand() % n;
  int vet[] = {3,0,1,8,7,2,5,4,9,6};

  PrintVet(vet, 0, n);
  quickSort(vet, 0, n);
  printf("PRONTO\n");
  PrintVet(vet, 0, n);

  return 0;
}

/*
  O que caracteriza o quickSort é a divisao em relação ao pivo, sendo
  a esquerda os menores que o pivo
  a direira os maiores que o pivo
  A recursao para cada uma desses vetores
*/
void quickSort(int *vet, int left, int right){
  if(left == right) return; // stop condition
  //pick a pivot
  int pivot = left;
}

void PrintVet(int *v, int i, int f){
  int l;
  for( l=i ; l<f; l++)
    printf("->[%d]%d ", l, v[l]);
  printf("\n");
}
