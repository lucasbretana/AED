#include <stdio.h>

void quickSort(int *vet, int left, int dir);

int main(int argc, char const *argv[]) {
  int vet[] = {4,1,2,3,5,6,0};

	quickSort(vet, 0, 7);
	

  return 0;
}

void quickSort(int *vet, int left, int right){
	int i, pivot = left, aux;
	for( i=left+1 ; i<right ; i++ ){
		aux = vet[pivot];
		if(vet[i] < vet[pivot]){
			for(int j = pivot+1 ; j < i ; j++){
				vet[j-1] = vet[j];
			}
			vet[i] = aux;
		}
	}

//	quickSort(vet, left-1, pivot);
//	quickSort(vet, pivot, right+1);
}
