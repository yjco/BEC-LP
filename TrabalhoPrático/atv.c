#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define LEN(x) (sizeof(x) / sizeof((x)[0]))

#define BUFFER 64

// Divide uma string str usando espaços e tabs como delimitadores e aloca suas partes em arr removendo quebras de linha
void dividir (char *str, char *arr[]) 
{
	char cpy[BUFFER];
	// A variável flag indica que o loop chegou/está em um espaço
	int flag = 0;
	int index = 0;
	int j = 0;
	for (int i = 0; i < BUFFER; i++)
	{
		if (str[i] == ' ' || str[i] == '\t' && flag == 0)
		{
			cpy[j] = '\0';
			arr[index] = malloc(BUFFER);
			strcpy(arr[index++], cpy);
			j = 0;
			flag = 1;
			continue;
		}
		else if (flag == 1 && str[i] != ' ' && str[i] != '\t')
			flag = 0;
		
		if (str[i] == '\0' || str[i] == '\n')
		{
			cpy[j] = '\0';
			arr[index] = malloc(BUFFER);
			strcpy(arr[index], cpy);
			break;
		}
		cpy[j++] = str[i];
	}
}

// Retorna 1 se todos os caracteres de da string str forem maiúsculos, senão 0
int isstrupper (char *str) {
	for (int i = 0; i < strlen(str); i++)
		if (!isupper(str[i]))
			return 0;
	return 1;
}

int main (int argc, char *argv[])
{

	// Verificando o que é necessário para ler o arquivo
	if (argc < 2) 
	{
		fprintf(stderr, "ERRO: É preciso informar o caminho para o arquivo.\n");
		exit(1);
	} 
	else if (!strcmp("--help", argv[1]) || !strcmp("-h", argv[1]))
	{
		printf("%s <ARQUIVO>\n", argv[0]);
		exit(0);
	}
	else if (argc > 2)
	{
		fprintf(stderr, "ATENÇÃO: O programa requer apenas um argumento, considerando apenas o primeiro.\n", argv[1]);
	}
	FILE *arquivo = fopen(argv[1], "r");
	if (arquivo == NULL) 
	{
		fprintf(stderr, "ERRO: Arquivo não existe.\n");
		exit(1);
	}

	printf("Yuri Jorge\n");
	printf("yuri.jcotofuji@senacsp.edu.br\n");

	// Lendo arquivo linha por linha e escrevendo a saída
	int i = 0;
	char *arr[BUFFER];
	char *linha = malloc(BUFFER);
	char *categoria = malloc(BUFFER);
	int num_itm;
	int itm_total = 0;
	float soma_total = 0.0f;
	int num_cat = (fgets(linha, BUFFER, arquivo))[0] - '0';
	while (fgets(linha, BUFFER, arquivo) != NULL)
	{
		// arr[0]=categoria arr[1]=número de categorias
		dividir(linha, arr);

		// Se for uma categoria seu nome será totalmente maiúsculo
		if (isstrupper(arr[0]))
		{
			printf("\n");
			// A variável num_cat recebe o número definido de categorias
			if (num_cat == 0)
			{
				fprintf(stderr, "ATENÇÃO: Mais categorias definidas do que especificadas, ignorando-as.\n");
				continue;
			}
			strcpy(categoria, arr[0]);
			num_itm = atoi(arr[1]);
			itm_total += num_itm;
			printf("%s\n", categoria);
			num_cat--;
			float soma = 0.0f;
			while (num_itm != 0)
			{
				if ((fgets(linha, BUFFER, arquivo)) == NULL)
				{
					fprintf(stderr, "ERRO: Arquivo acabou previamente.\n");
					exit(1);
				}
				// arr[0]=item arr[1]=quantia arr[2]=unidade arr[3]=moeda arr[4]=valor
				dividir(linha, arr);
				printf("* %s: R$ %s (%s %s)\n", arr[0], arr[4], arr[1], arr[2]);
				soma += atof(arr[4]);
				num_itm--;
			}
			printf("** TOTAL %s: R$ %.2f\n", categoria, soma);
			soma_total += soma;
		}
		// Um array de 5 elementos só pode ser um item
		else if (LEN(arr) == 5)
		{
			fprintf(stderr, "ATENÇÃO: Mais itens definidos do que especificados, ingnorando-os.\n");
		}
	}
	fclose(arquivo);
	float desconto = soma_total * (atof(arr[0]) / 100.0f);
	float valor = soma_total - desconto;
	printf("\nTOTAL DE ITENS: %d\n", itm_total);
	printf("\nVALOR TOTAL: R$ %.2f\n", soma_total);
	printf("\nDESCONTO: %s%\n", arr[0]);
	printf("\nVALOR DO DESCONTO: %.2f\n", desconto);
	printf("\nVALOR A PAGAR: %.2f\n", valor);

	if (arr[1][0] == 'P')
	{
		float parcelas = round(valor / atof(arr[3]));
		printf("\nPARCELAS: %.0f\n", parcelas);
		printf("\nVALOR DA PARCELA: %.2f\n", valor / parcelas);
	}
	
	return 0;

}
