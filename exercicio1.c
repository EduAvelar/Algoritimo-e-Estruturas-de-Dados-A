#include <stdio.h>
#include <stdlib.h>

int g1, g2;

int main() {
	
	int i, *pi;
	char c, *pc;
	float f, *pf;
	double d, *pd;
	
	int v[10];
	
	printf("\n|----------Tamanho de Variaveis------------|");
	printf("\n|  Tamanho de um inteiro: %d bytes", sizeof(i));
	printf("\n|  Tamanho de um char: %d bytes ", sizeof(c));
	printf("\n|  Tamanho de um float: %d bytes ", sizeof(float));
	printf("\n|  Tamanho de um double: %d bytes ", sizeof(d));
	printf("\n|  Tamanho de vetor v: %d bytes", sizeof(v));
	printf("\n|  Tamanho da posicao do vetor v[0]: %d bytes", sizeof(v[0]));
	printf("\n|  Tamanho de ponteiro: %d bytes", sizeof(pi));
	printf("\n\n");
	printf("\n|----------Endereco das Variaveis------------|");
	printf("\n| O endereco da varivel i: %u %x ", &i);
	printf("\n| O endereco da varivel c: %u %x ", &c);
	printf("\n| O endereco da varivel f: %u %x ", &f);
	printf("\n| O endereco da varivel d: %u %x ", &d);
	printf("\n| O endereco de vetor v: %u %x ", &v);
	printf("\n| O endereco da variavel global: %u %x ", &g1);
	printf("\n| O endereco da funcao main: %u %x ", main);
	
   /*
   		POR SE TRATAR DO TAMANHO DAS VARIAVEIS, ELE VAI IMPRIMIR UM VALOR INTEIRO, LOGO, DEVE-SE USAR %d, E ENTRE OS PARENTESES
   		O TIPO DA VARIAVEL, INT, FLOAT, CHAR, DOUBLE.
   */   
}
