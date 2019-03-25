#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int input(char str[], int size) {
	int i = 0;
	char c = getchar();
	while (c != '\n') {
		if (size > 0) {
			str[i] = c;
			i++;
			size--;
		}
		c = getchar();
	}
	str[i] = '\0';
	return i;
}

void escreveArquivoDelimitador(char buffer[], FILE *p){
	fputs(buffer, p);
	fputs("|", p);
}

int main(){

	FILE *output;
	char nomeArquivo[20];
	char buffer[256];
	printf("Digite o nome do arquivo: ");
	input(nomeArquivo, 20);

	if(!(output = fopen(nomeArquivo, "w"))){
		printf("A abertura do arquivo FALHOU ! Encerrando o programa !\n");
		exit(1);
	}
	printf("\n\nSobrenome\n>>>");
	input(buffer, 256);
	while(strlen(buffer) > 0){
		escreveArquivoDelimitador(buffer, output);
		printf("Nome\n>>>");
		input(buffer, 256);
		escreveArquivoDelimitador(buffer, output);
		printf("Endereco\n>>>");
		input(buffer, 256);
		escreveArquivoDelimitador(buffer, output);
		printf("Cidade\n>>>");
		input(buffer, 256);
		escreveArquivoDelimitador(buffer, output);
		printf("Estado\n>>>");
		input(buffer, 256);
		escreveArquivoDelimitador(buffer, output);
		printf("CEP\n>>>");
		input(buffer, 256);
		escreveArquivoDelimitador(buffer, output);
		printf("Digite o sobrenome: ");
		input(buffer, 256);
	}

	return 0;
}