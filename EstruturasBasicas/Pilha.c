#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10

typedef unsigned short int Age;

typedef struct _Aluno{
  Age ra;
  char nome[50];
}Aluno;

typedef struct _Pilha{
  Aluno alunos[MAX];
  int topo;
  int base;
  int limite;
}Pilha;

void Reset(Pilha *pilha);
bool Empty(Pilha *pilha);
bool Full(Pilha *pilha);
bool PUSH(Pilha *pilha, Aluno *item);
void POP(Pilha *pilha, Aluno *aluno);
void Listar(Pilha *pilha);

int main(int argc, char *argv[]){
  Pilha myP;
  Reset(&myP);

  Aluno lucas;
  lucas.ra = 22;
  strcpy(lucas.nome, "Lucas");

  Aluno alana;
  alana.ra = 21;
  strcpy(alana.nome, "Alana");

  PUSH(&myP, &lucas);
  PUSH(&myP, &alana);

  Listar(&myP);
  printf("%d", Empty(&myP));
}

void Reset(Pilha *pilha){
  pilha->topo = 0;
  pilha->base = 0;
  pilha->limite = MAX;
}

bool Empty(Pilha *pilha){
  return pilha->topo == 0;
}

bool Full(Pilha *pilha){
  return pilha->topo == MAX;
}

bool PUSH(Pilha *pilha, Aluno *item){
  if (!Full(pilha)){
    pilha->alunos[pilha->topo] = *item;
    pilha->topo++;
    return true;
  }else{
    return false;
  }
}

void POP(Pilha *pilha, Aluno *aluno){
  if (pilha->topo == 0)
    return;

  pilha->topo--;
  *aluno = pilha->alunos[pilha->topo];
}

void Listar(Pilha *pilha){
  Aluno a;
  Pilha p;
  Reset(&p);
  for(;!Empty(pilha);){
    POP(pilha, &a);
    printf("Nome: %s\nIdade: %d\n\n", a.nome, a.ra);
    PUSH(&p, &a);
  }

  for(;!Empty(&p);){
    POP(&p, &a);
    PUSH(pilha, &a);
  }
}
