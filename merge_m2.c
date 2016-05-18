#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<math.h>
void imprime(int tamanho,int *vetor);
void preenche(int tamanho,int *vetor);
void mergeSort(int *V, int inicio, int fim);
void merge (int *V, int inicio, int meio, int fim);
int main(){
	int vetor[100],tamanho=100;
	preenche(tamanho,vetor);
	printf("Vetor sem ordenar:\n");
	imprime(tamanho,vetor);
	mergeSort(vetor,0,tamanho);
	printf("Vetor ordenado:\n");
	imprime(tamanho,vetor);

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
void mergeSort(int *V, int inicio, int fim){
	int meio;
	if(inicio<fim){
		meio=floor((inicio+fim)/2);//floor � a uma fun��o da biblioteca math.h que arredonda para baixo o resultado da divis�o, isso serve para descobrir o meio do vetor
		mergeSort(V,inicio,meio);
		mergeSort(V,meio+1,fim);
		merge(V,inicio,meio,fim);
	}
}
void merge (int *V, int inicio, int meio, int fim){

}
