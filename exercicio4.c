#include<stdio.h>
#include<stdlib.h>

struct no{
    int cod;
    struct no *prox;
};

int main(){
    struct no *aux, *inicio=NULL;
    int n;
    printf(" Digite um numero: ");
    scanf("%d", &n);
    printf("\n");

    while(n!=0){
        aux=(struct no*)malloc(sizeof(struct no));
        aux->cod=n;
        printf("| %d ", aux->cod);
        n--;
        aux->prox=inicio;
        inicio=aux;
    }
    printf("\n");
}
