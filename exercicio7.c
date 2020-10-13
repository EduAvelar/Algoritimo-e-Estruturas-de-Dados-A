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
void remover(struct no **);
int removerUltimo(struct no **);
int verifica(struct no *);
void insereNo(struct no **);

int main(){
  struct no *inicio = NULL;
  int i, num; // opçao do usuario
  do{
    printf("\n PROGRAMA DE MANIPULACAO DE LISTA \n\n");

    printf(" 1. inserir no inicio \n");
    printf(" 2. imprimir a lista \n");
    printf(" 3. inserir no final \n");
    printf(" 4. remover o primeiro \n");
    printf(" 5. remover o ultimo \n");
    printf(" 6. verificar um valor n na lista \n");
    printf(" 7. insercao de um no em uma lista ordenada \n");
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
        case 4: remover(&inicio);
                break;
        case 5: num = removerUltimo(&inicio);
                if(num==-1) printf("\n Lista vazia \n");
                else printf("\n Elemento removido: %d \n", num);
                break;
        case 6: if(verifica(inicio)==1){
                    printf("\n Elemento encontrado \n");
                }else{
                    printf("\n Elemento nao encontrado \n");
                }
                break;
        case 7: insereNo(&inicio);
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
        printf(" Digite o numero: ");
        scanf("%d", &aux->codigo);
        aux->prox=(*inicio);
        (*inicio)=aux;
    }
}

// imprimir lista
void imprime(struct no *inicio){
    printf("\n Numero dentro da lista \n");
    printf("\n");
    while(inicio != NULL){
        printf(" %d  ", inicio->codigo);
        inicio=inicio->prox;
    }
    printf("\n");
}

//inserir no final da lista
void inserefinal(struct no **inicio){
    struct no *aux2 = (struct no *)malloc(sizeof(struct no));
    if(aux2!=NULL){
        printf(" Digite um valor: ");
        scanf("%d", &aux2->codigo);
        aux2->prox=NULL;
        if(*inicio==NULL){
            (*inicio)=aux2;
        }
        else{
            struct no *aux=(*inicio);
            while(aux->prox!=NULL) aux=aux->prox;
            aux->prox = aux2;
        }
    }else{
        printf("heapoverflow\n");
    }
}

//remover o primeiro
void remover(struct no **inicio){
    struct no *aux;
    if(*inicio == NULL){
        printf(" Lista vazia\n");
    }else{
        printf("\n Removendo o no com chave %d \n", (*inicio)->codigo);
        aux=(*inicio);
        (*inicio)=(*inicio)->prox;
        free(aux);
    }
}

//remove o ultimo
int removerUltimo(struct no **inicio){

    int n;
    struct no *aux=(*inicio);

    if(*inicio==NULL) return (-1);

    if((*inicio)->prox==NULL){
        n=(*inicio)->codigo;
        free(*inicio);
        (*inicio)=NULL;
        return (n);
    }

    while(aux->prox->prox!=NULL) aux=aux->prox;
    n=aux->prox->codigo;
    free(aux->prox);
    aux->prox=NULL;
    return (n);
}

//verifica um determinado numero na lista
int verifica(struct no *inicio){
    int n;
    printf(" Digite um numero que deseja verificar: ");
    scanf("%d", &n);

    while(inicio!=NULL){
        if(inicio->codigo == n){
            return 1;
        }else{
            inicio=inicio->prox;
        }
        return 0;
    }
}

//inserção de um nó em uma lista ordenada
void insereNo(struct no **inicio){
    int n;
    struct no *aux, *aux2;

    printf(" Digite um numero: ");
    scanf("%d", &n);

    if((*inicio)->codigo != NULL){
        aux2 = (struct no*)malloc(sizeof(struct no));
        aux2->codigo=n;
        aux2->prox=NULL;
        (*inicio)=aux2;
    }else if(n < (*inicio)->codigo){
        aux2 = (struct no*)malloc(sizeof(struct no));
        aux2->codigo=n;
        aux2->prox=(*inicio);
    }else if(n > (*inicio)->codigo){
        aux2 = (struct no*)malloc(sizeof(struct no));
        aux=(*inicio)->codigo;
        aux2->codigo=n;
    }
}
