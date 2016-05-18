#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CH 1

void test(int *vet, int a, int b);

int main(){
  int vet[] = {2,1,3,5,4};

  test(vet, 0, 5);

  for(int i=0 ; i<5 ; i++)
    printf(" < Vet[%d] = %d", i, vet[i]);

  return 0;
}

void test(int *vet, int a, int b){
  int i, j, aux, pivo = a;
  for( i=a+1 ; i<=b ; i++){
//    printf("\nVet[%d] = %d", i, vet[i]);
    if(vet[i] < vet[pivo]){
      j = i;
      aux = vet[j];
      // copia para cima, ou seja, vet[j] = vet[j-1]
      // ate encontrar com o pivo
      while( j > pivo ){
        vet[j] = vet[j-1];
        j--;
      }
      vet[j] = aux;
      pivo++;
    }
  }

  if(pivo-1 >= a)
    test(vet, a, pivo-1); // chama pra lista da esquerda
  if(pivo+1 <= b)
    test(vet, pivo+1, b); // chama pra listra da direira

}
