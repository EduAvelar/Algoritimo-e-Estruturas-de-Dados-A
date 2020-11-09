#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no {
  int codigo;
  time_t horario;
  struct no *prox;
};

// FUNÇÕES

//INSERIR NO FINAL DA FILA
void insereFinal(struct no **inicio, struct no **fim){

    struct no *aux;
    aux=(struct no *)malloc(sizeof(struct no));
    time_t horaDeEntrada = time(NULL);

    if(aux!=NULL){
        printf(" Digite um valor: ");
        scanf("%d", &aux->codigo);
        aux->horario = horaDeEntrada;
        aux->prox = NULL;

        if((*inicio)==NULL){
            (*inicio)=aux;
        }else{
            (*fim)->prox = aux;
        }
        (*fim)=aux;
    }else{
        printf(" Fila cheia \n");
    }
}

// IMPRIME A FILA
void imprime(struct no *inicio){
    printf("\n ==FILA== \n");
    printf("\n");
    while(inicio != NULL){
        printf(" %d |", inicio->codigo);
        inicio=inicio->prox;
    }
    printf("\n");
}


// REMOVER NO FIM DA FILA
int removerUltimo(struct no **inicio, struct no **fim){

    struct no *aux;
    int n;
    time_t horaDeSaida;
    horaDeSaida = time(NULL);

    n=(*inicio)->codigo;
    aux=(*inicio);
    (*inicio)=(*inicio)->prox;

    if((*inicio)==NULL){
        (*fim)=NULL;
        return -1;
    }

    printf("\n Tempo de Espera na Fila: %d \n", (int)difftime(horaDeSaida,aux->horario));
    free(aux);

    return n;
}


int main(){

  struct no *inicio = NULL, *fim=NULL;
  int i, num; // opçao do usuario
  //time_t horaDeEntrada, horaDeSaida;

  //horaDeEntrada = time(NULL);



  do{
    printf("\n PROGRAMA DE MANIPULACAO DE FILAS \n\n");

    printf(" 1. INSERIR UM ELEMENTO NA FILA \n");
    printf(" 2. REMOVER UM ELEMENTO DA FILA \n");
    printf(" 3. IMPRIMIR A FILA \n");
    printf(" 0. SAIR \n");

    printf(" Digita uma opcao: ");
    scanf("%d", &i);

    switch(i){
        case 1: insereFinal(&inicio, &fim);
                break;
        case 2: num=removerUltimo(&inicio, &fim);
                if(num==-1){
                    printf(" NENHUM ELEMENTO NA FILA \n");
                }else{
                    printf(" ELEMENTO REMOVIDO DA FILA: %d  \n", num);

                }
                break;
        case 3: imprime(inicio);
                break;
    }

  }while(i != 0);

  printf("\n Voce encerrou a execucao do menu \n");
  return (1);
}


