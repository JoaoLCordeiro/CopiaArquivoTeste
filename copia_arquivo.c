#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BUFFER	64
#define TAM_MAIOR	1024

int main(){
	printf("Começa o programa\n");

	char nome1[TAM_MAIOR];
	char nome2[TAM_MAIOR];

	strcpy (nome2, "destino.png");
	scanf ("%s", nome1);

	char buffer[TAM_BUFFER];

	FILE* arquivo_origem	= fopen(nome1, "rb" );
	FILE* arquivo_destino	= fopen(nome2, "wb+");

	if ((arquivo_origem == NULL) || (arquivo_destino == NULL)){
		printf ("Algum fopen deu ruim\n");
		return 1;
	}

	int tam_lido = fread(buffer, sizeof(char), TAM_BUFFER - 1, arquivo_origem);
	int conta_lacos = 0;
	
	printf ("laço numero: %d\n", conta_lacos);

	while (tam_lido != 0){
		fwrite(buffer, sizeof(char), tam_lido, arquivo_destino);
		tam_lido = fread(buffer, sizeof(char), TAM_BUFFER - 1, arquivo_origem);
		conta_lacos++;
		printf ("laço numero: %d\n", conta_lacos);
	}

	return 1;
}