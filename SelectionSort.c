/*
  @author: Lucas E. Bretana
  WORKING on 18/05 - 14:37
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

void SelectionSort(int *vet, int ini, int fim);
void PrintVet(int *v, int i, int f);

int main(int argc, char *argv[]){
  srand(time(NULL));
  int n = TAM;
  if(argc > 1) n = atoi(argv[1]);
  int i, *vet;
  vet = malloc(sizeof(int) * n);
  for(i=0;i<n;i++)
    vet[i] = rand() % n;

  printf("ANTES\n");
  PrintVet(vet, 0, n);

  SelectionSort(vet, 0, n);
  printf("PRONTO\n");
  PrintVet(vet, 0, n);
  return 0;
}

void SelectionSort(int *vet, int ini, int fim){
  int i, j, small, small_ind;
  for( i=ini ; i<fim ; i++){ // 
    small = vet[i];
    small_ind = i;
    for( j=i ; j<fim ; j++ ){
      if( vet[j] < small ){
        small = vet[j];
        small_ind = j;
      }
    }
    vet[small_ind] = vet[i];
    vet[i] = small
    PrintVet(vet, ini, fim);
  }
}

void PrintVet(int *v, int i, int f){
  int l;
  for( l=i ; l<f; l++)
    printf("%d ", v[l]);
  printf("\n");
}
