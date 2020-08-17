#include<stdio.h>
#include<stdlib.h>

typedef struct dadosPeso{
	char nome[20];
	float peso;
	float altura;
} cadastro;

int main(){
	
	cadastro vet[5];
	int i; 
	float imc[5];
	
	
	for(i=0; i<5; i++){
		fflush(stdin);
		printf("\nDigite o nome: ");
		gets(vet[i].nome);
		printf("\nDigite o peso: ");
		scanf("%f", &vet[i].peso);
		printf("\nDigite a altura: ");
		scanf("%f", &vet[i].altura);		
	}
	printf("\n\n");
	
	
	for(i=0; i<3; i++){
		imc[i] = (vet[i].peso/(vet[i].altura*vet[i].altura));
	}
	
	printf("\n ================= Niveis de IMC =====================\n");
	
	for(i=0; i<5; i++){
		if(imc[i] < 18.5){
			printf(" Abaixo do peso ideal\n");
			printf(" Nome: %s IMC = %.2f", vet[i].nome, imc[i]);
		} 
		else if(imc[i] >= 18.5 && imc[i] < 25){
				printf(" Peso ideal \n");
				printf(" Nome: %s IMC = %.2f", vet[i].nome, imc[i]);
		} 
		else if(imc[i] >= 25 && imc[i] < 30){
				printf(" Sobrepeso \n");
				printf(" Nome: %s IMC = %.2f", vet[i].nome, imc[i]);
		} 
		else if(imc[i] >= 30 && imc[i] < 35){
				printf(" Obesidade grau I \n");
				printf(" Nome: %s IMC = %.2f", vet[i].nome, imc[i]);
		} 
		else if(imc[i] >= 35 && imc[i] < 40){
				printf(" Obesidade grau II \n");
				printf(" Nome: %s IMC = %.2f", vet[i].nome, imc[i]);
		}
		else if(imc[i] >= 40){
				printf(" Obesidade grau III \n");
				printf(" Nome: %s IMC = %.2f ", vet[i].nome, imc[i]);
		}
		printf("\n =================\n");
		//imc[i] = vet[i].peso / (vet[i].altura*vet[i].altura );
		//printf(" \n Nome: %s IMC = %.2f \n", vet[i].nome, imc[i]);
	}
	
	getchar();
	
}

/*
	printf("\nDigite o nome: ");
	gets(peso.nome);
	printf("\nDigite o peso: ");
	scanf("%f", &peso.peso);
	printf("\nDigite a altura: ");
	scanf("%f", &peso.altura);
	
	printf("\n\t Nome: %s \n\t Peso: %.2f \n\t Altura: %.2f\n", peso.nome, peso.peso, peso.altura);
*/
