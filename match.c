#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE *arq1, *arq2, *saida;
	char buffer1[256], ant_buffer1[256], ant_buffer2[256], buffer2[256];
	int EXISTEM_MAIS_NOMES = 0, comp_result;

	arq1 = fopen("lista1.txt", "r");
	arq2 = fopen("lista2.txt", "r");
	saida = fopen("saida.txt", "w");
	EXISTEM_MAIS_NOMES = fgets(buffer1, 256, arq1) && fgets(buffer2, 256, arq2);
	strcpy(ant_buffer1, buffer1);	
	strcpy(ant_buffer2, buffer2);	
	while(EXISTEM_MAIS_NOMES){
		if(!(comp_result = strcmp(buffer1, buffer2))){
			fputs(buffer1, saida);
			EXISTEM_MAIS_NOMES = fgets(buffer1, 256, arq1) && fgets(buffer2, 256, arq2);
		}else if(comp_result < 0)
			EXISTEM_MAIS_NOMES = EXISTEM_MAIS_NOMES && fgets(buffer1, 256, arq1);
		else
			EXISTEM_MAIS_NOMES = EXISTEM_MAIS_NOMES && fgets(buffer2, 256, arq2);
	}

	fcloseall();
	return 0;
}