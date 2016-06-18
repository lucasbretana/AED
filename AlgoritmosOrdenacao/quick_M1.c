#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void imprime(int tamanho,int *vetor);
void preenche(int tamanho,int *vetor);
void InsertionSort(int *vetor, int tamanho);
void quick(int *vet, int esq, int dir);
int complementoquick(int *vet, int esq, int dir);
int main(){
	int vetor[100],tamanho=100;
	preenche(tamanho,vetor);
	printf("Vetor sem ordenar:\n");
	imprime(tamanho,vetor);
	quick(vetor,0,tamanho-1);
	printf("Vetor ordenado:\n");
	imprime(tamanho,vetor);
	return 0;
}
void imprime(int tamanho,int *vetor){
	int i;
	for(i=0;i<tamanho-1;i++){
		printf("%d-",vetor[i]);
	}
	printf("%d\n\n\n",vetor[i]);
}
void preenche(int tamanho,int *vetor){
	 int i;
	 srand(time(NULL));
   for (i = 0; i < 100; i++)
   {
      vetor[i]=rand() % 10000;
   }
}

void quick(int *vet, int esq, int dir){
    int pivo;
    pivo=complementoquick(vet,esq,dir);
    if(pivo-1 > esq && pivo>0){
	/*(&&pivo>0) foi colocado ali para que o programa possa rodar mesmo sem que a fun��o complementoquick estivesse sido
	 implementada, n�o interfere em nada na execu��o do programa, j� que o vetor s� vai assumir valores positivos
	 */
    	 quick(vet,esq,pivo-1);

    }
    if(pivo+1 < dir && pivo>0){
    /*(&&pivo>0) foi colocado ali para que o programa possa rodar mesmo sem que a fun��o complementoquick estivesse sido
	implementada, n�o interfere em nada na execu��o do programa, j� que o vetor s� vai assumir valores positivos
	 */
        quick(vet,pivo+1,dir);
    }
 }
int complementoquick(int *vet, int esq, int dir){
	//pick a pivot
	int pivot = esq;
	int i = esq, aux; // i usado para percorrer o vetor, aux e usado para trocar os elementos
	int j; // usado para percorrer os elementos na hora de reordernar
	while( i<=dir ){
		if(vet[pivot] > vet[i]){
			// fazer rearranjo e troca
			aux = vet[i];
			j = i;
			while( j > pivot ){ // loop descendente ate pivot
				vet[j] = vet[j-1];
				j--;
			}
			vet[j] = aux;
			pivot++;
		}
		i++;
	}

  return pivot;
	/*-10 n�o pertence a fun��o de ordena��o, est� ali apenas para que o programa possa rodar sem que a fun��o
	complementoquick estiver devidamente construida, este return deve retornar o valor do pivo da fun��o quick
	*/
}
