#include <stdio.h>
#include <stdlib.h>
#define MAX 10 // tamanho maximo suportado pela pilha
// RESET,
// PUSH,
// POP,
// EMPTY,- topo = base
// CLEAR, free

typedef unsigned short int Size;

typedef struct _Stack{
  int val;
  Size topo;
  //Size base;
} Stack;

void reset(Stack *p);
void push();

int main(int argc, char *argv[]){
  Stack myS;

  reset(&myS);
  push();
  return 0;
}

void reset(Stack *p){
  p = (Stack *) malloc(sizeof(Stack));
  (*p).topo = 0;
}

void push(){

}
