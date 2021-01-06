/*-----------------------------------------------------------*/
/* Nome: Eduardo Avelar Ciqueira Campos RA: 17153230
Opcionais funcionando: nenhum opcional colocado
Valor do projeto: 5 pontos
*/
/*----------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//struct que ira conter informações dos animais
struct no{
    char nome[10], especie[10], raca[10], caracteristica[40];
    char sexo;
    int idade, cod;
    struct no *prox;
};

// ================FUNÇÕES INICIAIS======================

// ==============INCLUIR NOVOS ANIMAIS OK
int incluir(struct no **inicio, int cod){
    printf("\n");

    struct no *novo;
    novo=(struct no*)malloc(sizeof(struct no));
    if(novo==NULL){
        printf("  Nenhum animal cadastrado!! \n");
        return -1;
    }else{

        novo->cod = cod;
        printf("  Codigo: %d \n", novo->cod);

        printf("  Digite o nome do animal: ");
        fflush(stdin);
        gets(novo->nome);

        printf("  Digite a idade do animal: ");
        scanf("%d", &novo->idade);

        printf("  Digite a especie do animal: ");
        fflush(stdin);
        gets(novo->especie);

        printf("  Digite a raca do animal: ");
        fflush(stdin);
        gets(novo->raca);

        printf("  Digite o sexo do animal 'M/F': ");
        fflush(stdin);
        scanf("%c", &novo->sexo);

        printf("  Digite as caracteristicas do animal: ");
        fflush(stdin);
        gets(novo->caracteristica);

        novo->prox=*inicio;
        (*inicio)=novo;
    }
    return 1;
}


// ==============LISTAGEM DE TODOS OS ANIMAIS CADASTRADOS OK
void imprimir(struct no *inicio){
    if(inicio != NULL){
            printf("\n  |=======Animais cadastrados=======| ");

            while(inicio!=NULL){
                printf("\n");
                printf("  Codigo: %d \n", inicio->cod);
                printf("  Nome: %s \n", inicio->nome);

                if(inicio->idade == 1){
                    printf("  Idade: %d ano\n", inicio->idade);
                }else{
                    printf("  Idade: %d anos \n", inicio->idade);
                }

                printf("  Especie: %s \n", inicio->especie);
                printf("  Raca: %s \n", inicio->raca);
                printf("  Sexo: %c \n", inicio->sexo);
                //printf("  Caracteristica: %s \n", inicio->caracteristica);
                inicio=inicio->prox;
            }
    }else{
        printf("   Nenhum animal cadastrado!!! ");
    }

    printf("\n");
}

// ==============REMOVER ANIMAIS OK
void remover(struct no **inicio){

    struct no *aux;
    if(*inicio == NULL){
        printf("  Nenhum animal cadastrado!!! \n");
    }
    else{
        printf(" Removendo o animal: %s \n", (*inicio)->nome);
        aux=(*inicio);
        (*inicio)=(*inicio)->prox;
        free(aux);
    }
}

// ALTERAÇÃO DE INFORMAÇÕES
int altInfo(struct no **inicio){

    struct no *alt=(*inicio);
    int num=0, op;
    //alt=(struct no*)malloc(sizeof(struct no));

    //seria uma busca por um determinado animal e a partir dai efetuar a alteração de um campo especifico

    if(alt == NULL){
        printf("  Nenhum animal cadastrado!!! \n");
        return 0;

    }else{
        printf("  Digite o codigo do animal que deseja alterar: ");
        scanf("%d", &num);

        do{
            if(num == alt->cod){
                printf("\n  Campos que deseja alterar  \n");
                printf("  1 - Nome\n");
                printf("  2 - Idade\n");
                printf("  3 - Especie\n");
                printf("  4 - Raca\n");
                printf("  5 - Sexo\n");
                printf("  6 - Caracteristica\n");
                printf("  0 - Digite zero para sair \n");

                printf("\n  Digite uma opcao: ");
                scanf("%d", &op);

                switch(op){

                    case 1:
                        printf(" Nome atual: %s \n", alt->nome);
                        printf(" Digite o novo nome: ");
                        fflush(stdin);
                        gets(alt->nome);
                        printf("  Novo nome eh: %s \n", alt->nome);
                        break;

                    case 2:
                        printf(" Idade atual: %d \n", alt->idade);
                        printf(" Digite a nova idade: ");
                        fflush(stdin);
                        scanf("%d", &alt->idade);
                        printf("  Nova idade eh: %d \n", alt->idade);
                        break;

                    case 3:
                        printf(" Especie atual: %s \n", alt->especie);
                        printf(" Digite a nova especie: ");
                        fflush(stdin);
                        gets(alt->especie);
                        printf("  Nova especie eh: %s \n", alt->especie);
                        break;

                    case 4:
                        printf(" Raca atual: %s \n", alt->raca);
                        printf(" Digite a nova raca: ");
                        fflush(stdin);
                        gets(alt->raca);
                        printf("  Nova raca eh: %s \n", alt->raca);
                        break;

                    case 5:
                        printf(" Sexo atual: %c \n", alt->sexo);
                        printf(" Digite o novo sexo 'm/f': ");
                        fflush(stdin);
                        scanf("%c", &alt->sexo);
                        printf("  Novo sexo eh: %c \n", alt->sexo);
                        break;

                     case 6:
                        printf(" Caracteristas atuais: %s \n", alt->caracteristica);
                        printf(" Digite as novas caracteristicas: ");
                        fflush(stdin);
                        gets(alt->caracteristica);
                        printf("  Novas caracteristicas sao: %s \n", alt->caracteristica);
                        break;
                }
            }
        }while(op != 0);
        alt=alt->prox;
        return 1;
    }
}

// BUSCA DE ANIMAIS POR NOME
void buscaPorNome(struct no *inicio){

    struct no *aux = inicio;
    char nome[20];

    if(aux == NULL){
        printf("  Nenhum animal cadastrado \n\n");
    }else{
        printf("\n Digite o nome que deseja: ");
        fflush(stdin);
        gets(nome);

        while(aux != NULL){

            if(strcmp(aux->nome, nome) == 0){
                strcpy(nome, aux->nome);
                printf(" O nome solicitado foi: %s \n", nome);

            }else{
                printf(" Nome nao encontrado   \n");

            }
            aux = aux->prox;
        }
    }
}



// BUSCA DE ANIMAIS POR ESPECIE
int buscaPorEspecie(struct no *inicio){

    struct no *aux = inicio;
    char especie[20];

    if(aux==NULL){
        printf("  Nenhum animal cadastrado!! \n\n");
    }else{
        printf("\n Digite o especie que deseja: ");
        fflush(stdin);
        gets(especie);

        while(aux != NULL){

            if(strcmp(aux->especie, especie) == 0){
                strcpy(especie, aux->especie);
                printf("  A especie solicitada esta no cadastro \n", especie);
                return 1;
            }else{
                printf(" Especie nao encontrada   \n");
                return 0;
            }
            aux=aux->prox;
        }
    }
}



// BUSCA DE ANIMAIS POR ESPECIE RAÇA
void buscaPorEspecieRaca(struct no *inicio){

    struct no *aux = inicio;
    char especie[20], raca[20];

    if(aux==NULL){
        printf("  Nenhum animal cadastrado!!!  \n\n");
    }else{

        printf("  Digite a especie: ");
        fflush(stdin);
        gets(especie);

        printf("  Digite a raca: ");
        fflush(stdin);
        gets(raca);

        while(aux != NULL){

            if( (strcmp(aux->especie,especie) == 0) && (strcmp(aux->raca,raca) == 0) ){

                printf(" A especie e raca solicitados estao no cadastro \n");

            }else{
                printf(" Especie e Raca nao encontrados  \n");
            }
            aux=aux->prox;
        }
    }
}



// BUSCA DE ANIMAIS POR ESPECIE, RAÇA E SEXO
void buscaPorEspecieRacaSexo(struct no *inicio){

    struct no *aux = inicio;
    char especie[20], raca[20], sexo;

    if(aux==NULL){
        printf("  Nenhum animal cadastrado!!! \n\n");
    }else{

        printf("  Digite a especie: ");
        fflush(stdin);
        gets(especie);

        printf("  Digite a raca: ");
        fflush(stdin);
        gets(raca);

        printf("  Digite o sexo: ");
        fflush(stdin);
        scanf("%c", &sexo);

        while(aux != NULL){

            if( (strcmp(aux->especie,especie) == 0) && (strcmp(aux->raca,raca) == 0) && (aux->sexo == sexo) ){
                printf("  A especie, raca e sexo solicitados estao no cadastro \n");

            }else{
                printf("\n  Especie, Raca e Sexo nao encontrados  \n");
            }
            aux=aux->prox;
        }
    }
}



// CONTAGEM DA QUANTIDADE DE ANIMAIS
int contagemDeAnimais(struct no *inicio){

    //se a lista estiver vazia
    if(inicio == NULL){
        return 0;
    }

    int tamanho=0;
    struct no *aux=inicio;
    while(aux != NULL){
        aux=aux->prox;
        tamanho++;
    }
    return tamanho;
}



// CONTAGEM POR ESPECIE
int contagemPorEspecie(struct no *inicio){

    if(inicio == NULL){
        return 0;
    }

    int tam=0;
    struct no *aux=inicio;
    while( aux->especie != ""){
        tam++;
    }

    return tam;
    inicio=inicio->prox;
}



int main()
{
    struct no *inicio=NULL;
    char nome[20];
    int cod=0;


    printf("\n");

    int op, n;
    do{
        //menu de navegação
       printf("\n\t |=========| CADASTRO DE PETS |=========|\n");
       printf("  1- Inserir um novo animal \n");
       printf("  2- Remover um animal \n");
       printf("  3- Alteracao de informacoes \n");
       printf("  4- Busca de um animal a partir do seu nome \n");
       printf("  5- Busca de animais por especie \n");
       printf("  6- Busca de animais por especie e raca \n");
       printf("  7- Busca de animais por especie, raca e sexo \n");
       printf("  8- Contagem (quantidade de animais) \n");
       printf("  9- Contagem por especie \n");
       printf("  10- Listagem de todos os animais cadastrados \n");
       printf("  0- Digite zero para sair \n");
       printf("\n  Digite uma opcao: ");
       scanf("%d", &op);

       switch(op){
           case 1: printf("\n  Inclusao de novos animais \n");
                cod++;
               incluir(&inicio, cod);
           break;

           case 2: printf("\n Remocao de animais \n");
               remover(&inicio);
           break;

           case 3: printf("\n  Alteracao de Informacoes  \n");
               altInfo(&inicio);
           break;

           case 4: printf("\n  Busca de um animal a partir do seu nome  \n");
               buscaPorNome(inicio);
           break;

           case 5: printf("\n  Busca de animais por especie  \n");
               buscaPorEspecie(inicio);
           break;

           case 6: printf("\n Busca de animais por especie e raca  \n");
               buscaPorEspecieRaca(inicio);
           break;

           case 7: printf("\n  Busca de animais por especie, raca e sexo  \n");
               buscaPorEspecieRacaSexo(inicio);
           break;

           case 8: printf("\n  Quantidade da animais cadastrados \n ");
                if(contagemDeAnimais(inicio) == 0){
                    printf(" Nao ha nenhum animal cadastrado ");
                }else{
                    printf(" Existem %d  animais cadastrados  \n", contagemDeAnimais(inicio));
                }
            break;

            case 9: printf("\n  |=====Contagem por especie=====|  \n\n");
               if(contagemPorEspecie(inicio)==0){
                    printf(" Nenhuma especie encontrada!!! \n");
               }else{
                   printf("  Existem %d especieis cadastradas!!", contagemPorEspecie(inicio));
               }
           break;

           case 10: printf("\n  Listagem de todos animais cadastrados  \n");
                imprimir(inicio);
            break;
       }
    }while(op != 0);
}
