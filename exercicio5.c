#include <stdio.h>
#include <stdlib.h>

struct no {
  int codigo;
  struct no *prox;
};

//PROTOTIPOS DAS FUNÇÕES
void insere(struct no **);
void imprime(struct no *);
void inserefinal(struct no **);

int main(){
  struct no *inicio = NULL;
  int i; // opçao do usuario
  do{
    printf("\n PROGRAMA DE MANIPULACAO DE LISTA \n\n");

    printf(" 1. inserir no inicio \n");
    printf(" 2. imprimir a lista \n");
    printf(" 3. inserir no final \n");
    printf(" 0. para sair \n");

    printf(" Digita uma opcao: ");
    scanf("%d", &i);

    switch(i){
        case 1: insere(&inicio);
                break;
        case 2: imprime(inicio);
                break;
        case 3: inserefinal(&inicio);
                break;
    }

  }while(i != 0);

  return (1);
}

//inserir no inicio da lista
void insere(struct no **inicio){
    struct no *aux;

    aux = (struct no *) malloc (sizeof (struct no));
    if(aux!=NULL){
        printf(" Inserindo no inicio \n");
        printf(" Digite o numero: ");
        scanf("%d", &aux->codigo);
        aux->prox=(*inicio);
        (*inicio)=aux;
    }
}

void imprime(struct no *inicio){
    printf("\n Numeros dentro da lista \n");
    while(inicio != NULL){
        printf(" %d  ", inicio->codigo);
        inicio=inicio->prox;
    }
}

void inserefinal(struct no **inicio){
    struct no *aux2 = (struct no *)malloc(sizeof(struct no));
    printf(" Inserindo no final \n ");
    if(aux2!=NULL){
        printf(" Digite um valor: ");
        scanf("%d", &aux2->codigo);
        aux2->prox=NULL;
        if(*inicio==NULL){
            (*inicio)=aux2;
        }
        else{
              struct no *aux=(*inicio);
              while(aux->prox!=NULL){
                aux=aux->prox;
              }
              aux->prox = aux2;
            }
    }
    else{
        printf("heapoverflow");
    }
}

/*
O programa deve ficar em um loop, apresentando opções de operações de manipulação de listas ligadas ao usuário, lendo sua opção e
a função ou procedimento adequado.

Para testar, implemente pelo menos as seguintes funções:

1.	Inserção de um novo nó no início da lista ligada;
2.	Inserção de um novo nó no final da lista ligada;
3.	Impressão dos valores de todos os nós da lista.
*/
