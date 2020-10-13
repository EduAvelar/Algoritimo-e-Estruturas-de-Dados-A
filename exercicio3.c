#include<stdio.h>
#include<stdlib.h>

struct teste {
	int num;
};

void func(float , int [], struct teste *dado);

int main(){
	float f, *pf;
	struct teste dado, *pdado;
	int vet[1];

	pf=&f;
	pdado=&dado;

	//printf("\n Endereco de f atraves do pf = %d / f = %d ", pf, &f);
	printf("\n Declaracao antes da funcao\n");

	// variavel float recebendo um valor atraves do ponteiro pf
	*pf=4;
	printf("\n O valor de f antes da funcao: %.2f", *pf);

	//vetor com uma posição, recebendo um valor
	vet[0]=78;
	printf("\n O valor dentro da posicao 1 do vetor antes da funcao : %d ", vet[0]);

	// struct dado recebendo um valor atraves do ponteiro pdado
	pdado->num=3;
	printf("\n O valor de 'dado' antes da funcao: %d ", dado.num);



	func(f, vet, &dado);

	printf("\n\n Valores apos execucao da funcao \n");

	printf("\n O valor de f apos execucao da funcao: %2.f", f);
	printf("\n O valor dentro da posicao 1 do vetor apos execucao da funcao: %d", vet[0]);
	printf("\n O valor de 'dado' apos a execucao da funcao: %d ", dado.num);

}

void func(float f, int *vet, struct teste *dado){
	f=20.5;
	vet[0]=236;
	dado->num=5;

}
