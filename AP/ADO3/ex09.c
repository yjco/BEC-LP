//[]--------------------------------------------------------------[]
//    Nome do arquivo: ex09.c
//    Importante: nao altere o nome do arquivo.
//[]--------------------------------------------------------------[]
#include<stdio.h>
#include<string.h>


//[]-------------------------------------------------------------[]
//   Função: conta_palavras()
//   Entrada: string s[], uma frase sem pontuação
//   Saída:   devolve a quantidade de palavras da string
//[]-------------------------------------------------------------[]
int conta_palavras(char s[]){

	int i = strlen(s) - 1;
	if (i == -1) return 0;

	int count = 0;
	for (int i = strlen(s) - 1; i >= 0; i--) if (s[i] == ' ') count++;
	return ++count;

}


//[]-------------------------------------------------------------[]
//   Função: testar()
//   Entrada: valor obtido da funcao, valor esperado
//   Saída: ok se obtido igual a esperado e nao ok caso contrario
//[]-------------------------------------------------------------[]
void testar(int obtido, int esperado){
   if (obtido == esperado)
	   printf("Parabéns !!!");
   else
	   printf("Ainda não !!!");
   printf(" obtido: %d  esperado: %d\n", obtido, esperado);
}

//[]-------------------------------------------------------------[]
//    Casos de testes
//[]-------------------------------------------------------------[]
void caso_de_teste01(){
   char s[50] = "o rato roeu a roupa do rei";
   testar(conta_palavras(s), 7);
}

void caso_de_teste02(){
   char s[50] = "ana gosta de banana";
   testar(conta_palavras(s), 4);  
}

void caso_de_teste03(){
   char s[50] = "juju gosta de chocolate branco";
   testar(conta_palavras(s), 5);
}

void caso_de_teste04(){
   char s[50] = "joao e o pe de feijao";
   testar(conta_palavras(s), 6);
}

void caso_de_teste05(){
   char s[50] = "alice no pais das maravilhas";
   testar(conta_palavras(s), 5);
}

void caso_de_teste06(){
   char s[50] = "a bela e a fera";
   testar(conta_palavras(s), 5);
}

void caso_de_teste07(){
   char s[10] = "e";
   testar(conta_palavras(s), 1);
}

void caso_de_teste08(){
   char s[10] = "";
   testar(conta_palavras(s), 0);
}

void caso_de_teste09(){
   char s[10] = "ah e";
   testar(conta_palavras(s), 2);
}

void caso_de_teste10(){
   char s[50] = "subi no onibus";
   testar(conta_palavras(s), 3);
}



//[]-------------------------------------------------------------[]
//    Casos de testes
//[]-------------------------------------------------------------[]
int main(){
   caso_de_teste01(); 
   caso_de_teste02(); 
   caso_de_teste03(); 
   caso_de_teste04(); 
   caso_de_teste05(); 
   caso_de_teste06(); 
   caso_de_teste07(); 
   caso_de_teste08(); 
   caso_de_teste09(); 
   caso_de_teste10(); 
   return 0;
}
