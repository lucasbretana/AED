#include <stdio.h>
#include <stdlib.h>

typedef short TKey;

typedef struct _Node{
  TKey key;
  struct _Node *left, *right, *top;
}Node;

void insertNode(Node **root, TKey n);
void removeNode(Node **root, TKey n);
void listPreOrder(Node *Root);
int High(Node *n);
int FB(Node *n);
void RSD(Node *n1, Node *n2);
void RSE(Node *n1, Node *n2);
void bal(Node *n);

int main(){
  Node **tree;
  Node *t;
  t = NULL;
  tree = &t;

  insertNode(tree, 1);
  insertNode(tree, 5);
  insertNode(tree, 10);
  listPreOrder(*tree);

  bal(*tree);

  printf("\n");
  listPreOrder(*tree);
  return 0;
}

int FB(Node *n){
  if(n == NULL)
    return 0;
  return High((*n).left) - High((*n).right);
}

int High(Node *n){
  if(n == NULL)
    return 0;
  int esq = 0, dir = 0;
  esq = High((*n).left);
  dir = High((*n).right);
  if(esq > dir)
    return esq + 1;
  else
    return dir + 1;
}

void bal(Node *n){
  int v = FB((*n).left) - FB((*n).right);
  printf("\nDEBUG: %d\n", v);
  if(v >= 1){
    RSD(n, (*n).left);
  }else if(v <= -1){
    RSE(n, (*n).right);
  }
}

void RSD(Node *n1, Node *n2){
  (*n1).top = n2;
  (*n1).left = NULL;
  (*n2).right = n1;
}

void RSE(Node *n1, Node *n2){
  (*n1).top = n2;
  (*n1).right = NULL;
  (*n2).left = n1;
}

void removeNode(Node **root, TKey n){
  if(*root == NULL){
    printf("Not Found!");
    return;
  }
}


void insertNode(Node **root, TKey n){
  if(*root == NULL){
    Node *aux = malloc(sizeof(Node));
    (*aux).key = n;
    (*aux).left = NULL;
    (*aux).right = NULL;
    (*aux).top = NULL;
    *root = aux;
    return;
  }

  if(n < (**root).key){ // insere a esquerda
    if((**root).left != NULL){
      insertNode(&(**root).left, n);
    }else{
      Node *aux = malloc(sizeof(Node));
      (*aux).key = n;
      (*aux).left = NULL;
      (*aux).right = NULL;
      (*aux).top = *root;
      (**root).left = aux;
    }
  }else{ // insere a direita
    if((**root).right != NULL){
      insertNode(&(**root).right, n);
    }else{
      Node *aux = malloc(sizeof(Node));
      (*aux).key = n;
      (*aux).left = NULL;
      (*aux).right = NULL;
      (*aux).top = *root;
      (**root).right = aux;
    }
  }
}

void listPreOrder(Node *Root){
  if(Root == NULL) return;

  printf(" ( ");
  printf(" %hi [%d]", (*Root).key, FB(Root));
  listPreOrder((*Root).left);
  printf(" ");
  listPreOrder((*Root).right);
  printf(" ) ");

}
