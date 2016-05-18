#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void imprime(int tamanho,int *vetor);
void preenche(int tamanho,int *vetor);
void InsertionSort(int *vetor, int tamanho);
int ComplementodoInsertionSort(int *vetor, int i);
int main(){
	int vetor[100],i,tamanho=100;
	preenche(tamanho,vetor);
	printf("Vetor sem ordenar\n");
	imprime(tamanho,vetor);
	InsertionSort(vetor,tamanho);
	printf("Vetor ordenado\n");
	imprime(tamanho,vetor);
	
}
void imprime(int tamanho,int *vetor){
	int i;
	for(i=0;i<tamanho-1;i++){
		printf("%d-",vetor[i]);
	}
	printf("%d",vetor[i]);
	printf("\n");
	printf("\n");
	printf("\n");
}
void preenche(int tamanho,int *vetor){
	 int i;
	 srand(time(NULL));
     for (i = 0; i < 100; i++)
     {
        vetor[i]=rand() % 10000;
     }
}
void InsertionSort(int *vetor, int tamanho){
	int i, j, atual;
	for (i = 1; i < tamanho; i++){
		atual = vetor[i];
    	j=ComplementodoInsertionSort(vetor,i);
		vetor[j + 1] = atual;
	}
}

int ComplementodoInsertionSort(int *vetor, int i){
	
}

