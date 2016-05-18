/*
  @author: Lucas E. Bretana
  WORKING on 18/05 - 11:25
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

void MergeSort(int *vet, int ini, int fim);
void PrintVet(int *v, int i, int f);

int main(int argc, char *argv[]){
  srand(time(NULL));
  int n = TAM;
  if(argc > 1) n = atoi(argv[1]);
  int i, *vet;
  vet = malloc(sizeof(int) * n);
  for(i=0;i<n;i++)
    vet[i] = rand() % n;

  MergeSort(vet, 0, n);
  printf("PRONTO\n");
  PrintVet(vet, 0, n);
  return 0;
}

void MergeSort(int *vet, int ini, int fim){
  
}

void PrintVet(int *v, int i, int f){
  int l;
  for( l=i ; l<f; l++)
    printf("%d ", v[l]);
  printf("\n");
}
