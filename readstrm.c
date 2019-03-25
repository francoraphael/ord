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

int main(){

	FILE *arq;
	char nomeArquivo[20];
	int i = 0;

	printf("Digite o nome do arquivo: ");
	input(nomeArquivo, 20);

	if(!(arq = fopen(nomeArquivo, "r"))){
		printf("A abertura do arquivo FALHOU ! Encerrando o programa !\n");
		exit(1);
	}

	char c = fgetc(arq);
	while(c != EOF){
		printf("Campo #%d: ", i);
		while(c != '|'){
			printf("%c", c);
			c = fgetc(arq);
		}
		printf("\n");
		c = fgetc(arq);
		i++;
	}

	return 0;
}