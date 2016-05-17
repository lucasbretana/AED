#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 6

void escreve(int *vet, int ini, int end){
  int i;
  for(i=ini;i<=end;i++){
    printf("%d - ", vet[i]);
  }
  printf("\n");
}

void quick(int vet[], int esq, int dir){
    int pivo = esq,i,ch,j;
    for(i=esq+1;i<=dir;i++){
        j = i;
        if(vet[j] < vet[pivo]){
         ch = vet[j];
         while(j > pivo){
            vet[j] = vet[j-1];
            j--;
            // printf("LOOP\n");
            // escreve(vet, esq, dir);
         }
         vet[j] = ch;
         pivo++;
         printf("NOT loop\n");
         escreve(vet, esq, dir);
        }
    }
    if(pivo-1 >= esq){
        quick(vet,esq,pivo-1);
    }
    if(pivo+1 <= dir){
        quick(vet,pivo+1,dir);
    }
 }

int main(){
    srand(time(NULL));
    int vet[] = {4,1,2,3,5,0},i;

    // for(i=0;i<TAM;i++)
    //     vet[i] = rand() % TAM;

    escreve(vet, 0, TAM-1);
    quick(vet,0,TAM-1);

    for(i=0;i<TAM;i++)
        printf("%d ",vet[i]);
    printf("\n");
    return 0;
}
