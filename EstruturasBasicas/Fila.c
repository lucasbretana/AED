#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef unsigned short int Age;

typedef struct _Cell{
  Age ra;
  char nome[50];
  struct _Cell *next;
} Cell;

typedef struct _Fila{
  Cell *first;
  Cell *last;
} Fila;

void Reset(Fila *fila);
bool Empty(Fila *fila);
bool Full(Fila *fila);
bool PUSH(Fila *fila, Cell *item); // COLOCA
bool POP(Fila *fila, Cell *item); // RETIRA
void Clear(Fila *fila);
void Listar(Fila *fila);

int main(int argc, char *argv[]){
  Fila myF;
  Reset(&myF);
  Cell *lucas;
  lucas = (void *) malloc(sizeof(Cell));
  strcpy((*lucas).nome, "Lucas");
  (*lucas).ra = 22;

  Cell *alana;
  alana = (void *) malloc(sizeof(Cell));
  strcpy((*alana).nome, "Alana");
  (*alana).ra = 21;

  PUSH(&myF, lucas);
  PUSH(&myF, alana);

  Listar(&myF);

  Cell novo;
  if(POP(&myF, &novo)){
    printf("\n\n\nO excluido! %p", &novo);
    printf("\nNome: %s", novo.nome);
    printf("\nIdade: %hu", novo.ra);
    printf("\n\n");
  }
  Listar(&myF);
  return 0;
}

void Reset(Fila *fila){
  Clear(fila);
  (*fila).first = NULL; // same as fila->first
  (*fila).last = NULL; // same as fila->last

}

void Clear(Fila *fila){
  if(Empty(fila)) {
    printf("\nEmpty!\n");
    return;
  }
  Cell *i; // just like the conter on a regular for
  i = malloc(sizeof(Cell));
  for( (*i)=*(*fila).first ; (*i).next != NULL ; (*i)=*(i.next) ){
    // printf("\nNome do aluno: %s", i.nome);
    // printf("\nIdade do aluno: %hu", i.ra);
    POP(fila, i);
  }
  // printf("\nNome do aluno: %s", i.nome);
  // printf("\nIdade do aluno: %hu", i.ra);
  POP(fila, i);
}

bool Empty(Fila *fila){
  return ((*fila).first == NULL) && ((*fila).last == NULL);
}

bool Full(Fila *fila){
  printf("\nIt uses dinamyc allocation! ''NEVER'' FULL!");
  return false;
}

bool PUSH(Fila *fila, Cell *item){
  // em todos os casos o proximo do novo é NULL
  (*item).next = NULL;
  // se ea fila esta vazia, pri e ult apontam para o novo elemento
  if(Empty(fila)){
    (*fila).first = item;
    (*fila).last = item;
    return true;
  }
  // se já tem algo na fila, o pri fica igual,
  // o ultimo que estava na fila aponta para o novo
  (*(*fila).last).next = item;
  // e o last aponta para o novo
  (*fila).last = item;
  return true;
}

bool POP(Fila *fila, Cell *item){
  Cell *aux;
  aux = (*fila).first;
  // se a fila esta vazia, nada a fazer
  if(Empty(fila)){
    printf("\nEmpty!\n");
    return false;
  }
  // senao, o item atual, recebe o primeiro da fila
  strcpy((*item).nome, (*(*fila).first).nome);
  (*item).ra = (*(*fila).first).ra;
  (*item).next = NULL;
  // o primeiro passa a apontar para o next do primeiro elemento
  (*fila).first = (*(*fila).first).next;
  // printf("\n\n\nO excluido %s -- %hu\n", (*item).nome, (*item).ra);
  free(aux);
  return true;
}

void Listar(Fila *fila){
  if(Empty(fila)) {
    printf("\nEmpty!\n");
    return;
  }
  Cell i; // just like the conter on a regular for
  for( i=*(*fila).first ; i.next != NULL ; i=*(i.next) ){
    printf("\nNome do aluno: %s", i.nome);
    printf("\nIdade do aluno: %hu", i.ra);
  }
  printf("\nNome do aluno: %s", i.nome);
  printf("\nIdade do aluno: %hu", i.ra);

}
