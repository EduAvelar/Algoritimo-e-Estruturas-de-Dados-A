#include<stdio.h>
#include<stdlib.h>

struct no{
    int cod;
    struct no *prox;

};

// INSERE NA PILHA (PUSH)
void push(struct no **inicio){
    struct no *aux;

    aux=(struct no*)malloc(sizeof(struct no));
    if(aux != NULL){
        printf(" Digite um numero: ");
        scanf("%d", &aux->cod);
        aux->prox=(*inicio);
        (*inicio)=aux;
    }
}


// REMOÇÃO DE UM ELEMENTO DA PILHA (POP)
void pop(struct no **inicio){
    struct no *aux;
    if(*inicio == NULL){
        printf(" Pilha vazia \n");
    }else{
        printf(" Removendo o elemento da pilha: | %d | \n", (*inicio)->cod);
        aux=(*inicio);
        (*inicio)=(*inicio)->prox;
        free(aux);
    }
}



// IMPRIMI A PILHA

void imprimePilha(struct no *inicio){
    printf("\n Numeros dentro da pilha  \n");
    printf("\n");
    while(inicio!=NULL){
        printf(" | %d |\n", inicio->cod);
        inicio=inicio->prox;
    }
}


int main(){

    struct no *inicio = NULL, *fim=NULL;
    int i, num; // opçao do usuario

    do{
      printf("\n PROGRAMA DE MANIPULACAO DE PILHAS \n\n");

      printf(" 1. inserir na pilha (push) \n");
      printf(" 2. remover (pop) \n");
      printf(" 3. imprimir pilha \n");
      printf(" 0. para sair \n");

      printf(" Digita uma opcao: ");
      scanf("%d", &i);

      switch(i){
         case 1: push(&inicio);
                 break;
         case 2: pop(&inicio);
                 break;
         case 3: imprimePilha(inicio);
                 break;
      }

     }while(i != 0);

}
