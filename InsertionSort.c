/*
  @author: Lucas E. Bretana
  WORKING on 18/05 - 11:25
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

void InsertionSort(int *vet, int ini, int fim);
void PrintVet(int *v, int i, int f);

int main(int argc, char *argv[]){
  srand(time(NULL));
  int n = TAM;
  if(argc > 1) n = atoi(argv[1]);
  int i, *vet;
  vet =(int*) malloc(sizeof(int) * n);
  for(i=0;i<n;i++)
    vet[i] = rand() % n;

  InsertionSort(vet, 0, n);
  printf("PRONTO\n");
  PrintVet(vet, 0, n);
  return 0;
}

void InsertionSort(int *vet, int ini, int fim){
  int j, i, aux;
  for(i = ini+1 ; i<fim ; i++){               // n
    j = i;                                    // n - 1
    aux = vet[j];                             // n - 1
    while((vet[j] < vet[j-1]) && (j > ini)){  // n * t
      vet[j] = vet[j-1];                      // n * (t - 1)
      vet[j-1] = aux;
      j--;
    }
    PrintVet(vet, ini, fim);
  }
}

void PrintVet(int *v, int i, int f){
  int l;
  for( l=i ; l<f; l++)
    printf("%d ", v[l]);
  printf("\n");
}
