#include <stdio.h>

void quickSort(int *vet, int left, int dir);

int main(int argc, char const *argv[]) {
  int vet[] = {4,1,2,3,5,6,0};

	quickSort(vet, 0, 7);

  return 0;
}

/*
  O que caracteriza o quickSort é a divisao em relação ao pivo, sendo
  a esquerda os menores que o pivo
  a direira os maiores que o pivo
  A recursao para cada uma desses vetores
*/
void quickSort(int *vet, int left, int right){
  if(left == right) return; // parada da recursão
  // int pivo = (left + right) / 2;
  int pivo = left;
  int i;
  for(i=right;i>left+1;i--){
    if(){

    }
  }
}
