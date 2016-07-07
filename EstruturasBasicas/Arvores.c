#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
  short high;
  int key;
  struct _Node *left;
  struct _Node *right;
} Node;

void addNode(int key);

Node *n0;
int main(){
  int k = 0;
  do{
    printf("\nDigite a chave do novo nodo: ");
    scanf("%d", &k);
    if(k != 0)
      addNode(k);
  }while(k != 0);



  return 0;
}

void addNode(int key){
  Node *n = (Node *) malloc(sizeof(Node));
  (*n).key = key;
  (*n).left = NULL;
  (*n).right = NULL;
  (*n0).high = 0;

  }

}

void printTree(void){

}
