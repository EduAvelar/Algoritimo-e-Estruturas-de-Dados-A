#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct no {
    int codigo;
    time_t timeDeEntrada, timeDeSaida;
    struct no *prox;
};

// FUNÇÕES

// INSERIR UM CLIENTE NA FILA
void insereCliente(struct no **inicio, struct no **fim){

    struct tm data;

    time_t atual;
    time(&atual);

    struct no *aux;
    aux=(struct no*)malloc(sizeof(struct no));

    if(aux!=NULL){
        aux->timeDeEntrada = atual;
        aux->prox = NULL;

        if((*inicio)==NULL){
            (*inicio)=aux;
        }else {
            (*fim)->prox = aux;
        }
        (*fim)=aux;
    }else{
        printf(" Fila cheia \n\n");
    }

}

// REMOVER UM CLIENTE DA FILA
int removerUltimo(struct no **inicio, struct no **fim, int timeRemove){

    struct no *aux;
    int n;
    time_t time_atual;
    time(&time_atual);

    if((int)difftime((*inicio)->timeDeEntrada, time_atual) > timeRemove){
        n=(*inicio)->codigo;
        aux=(*inicio);
        (*inicio)=(*inicio)->prox;

        if((*inicio)==NULL){
            (*fim)=NULL;
            return -1;
        }

        free(aux);

        return n;
    }
}

// FUNÇÃO PRINCIPAL

int main(){
    printf("\n\t PROGRAMA DE SIMULACAO DE FILA DE ATENDIMENTO\n\n");

    int duracao, timeExec=5, timeRemove=8;
    int count1=0, count2=0, count3=0;

    time_t time_inicio, time_atual;

    time(&time_atual);

    struct no *fila1=NULL;
    struct no *fila2=NULL;
    struct no *fila3=NULL;

    struct no *inicio1=fila1;
    struct no *fim1=fila1;

    struct no *inicio2=fila2;
    struct no *fim2=fila2;

    struct no *inicio3=fila3;
    struct no *fim3=fila3;


    printf("\n\t Digite o tempo de execucao: ");
    scanf("%d", &duracao);

    printf("\n\n");

    time(&time_inicio);

    printf("\n\t Execucao do programa\n\n");
    while(difftime(time_atual, time_inicio) <= duracao){

        // INSERE NA FILA
        if((int)difftime(time_atual, time_inicio) % timeExec == 0 && (int)difftime(time_atual, time_inicio)> 0){

            insereCliente(&inicio1, &fim1);
            count1++;


            insereCliente(&inicio2, &fim2);
            count2++;

            insereCliente(&inicio3, &fim3);
            count3++;
        }
        printf("\n %d clientes na fila 1 \n", count1);
        printf("\n %d clientes na fila 2 \n", count2);
        printf("\n %d clientes na fila 3 \n", count3);

        // REMOVE DA FILA
        if((int)difftime(time_atual, time_inicio)% timeRemove == 0 && (int)difftime(time_atual, time_inicio)>0){

            removerUltimo(&inicio1, &fim1, timeRemove);
            count1--;

            removerUltimo(&inicio2, &fim2, timeRemove);
            count2--;

            removerUltimo(&inicio3, &fim3, timeRemove);
            count3--;
        }
        printf("\n %d saiu da fila 1 \n", count1);
        printf("\n %d saiu da fila 2 \n", count2);
        printf("\n %d saiu da fila 3 \n", count3);


        _sleep(800);
        system("cls");
        time(&time_atual);
    }

    printf("\n\t Quantidade de clientes na fila 1: %d \n", count1);
    printf("\n\t Quantidade de clientes na fila 2: %d \n", count2);
    printf("\n\t Quantidade de clientes na fila 3: %d \n", count3);
    printf("\n\n");

    return (1);
}
