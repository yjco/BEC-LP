//[]--------------------------------------------------------------[]
//    Nome do arquivo: ex05.c
//    Importante: nao altere o nome do arquivo.
//[]--------------------------------------------------------------[]
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


//[]-------------------------------------------[]
//   Funcao: eh_palindromo()
//   Entrada: string s e o seu tamanho n
//   Saida: devolve 1 caso a string seja palindromo 
//          e devolve 0 caso contrário
//          ex: 
//           entrada:  "ovo" 
//           saida: 1
//
//           entrada: "Socorram-me, subi no onibus em Marrocos."
//           saida: 1
//
//           entrada: "Anotaram a data da maratona."
//           saida: 1
//[]-------------------------------------------[]
//
int eh_palindromo(char s[], int n){

	int j = 0, i = 0;
	char c[n];
	while (i < n) {

		switch (s[i]) {

			case ',' :
			case '.' :
			case '-' :
			case ' ' :
			case -61 :
				break;

			case -76 :
				c[j++] = 'o';
				break;

			case -95 :
			case -94 :
			case -93 :
				c[j++] = 'a';
				break;

			default :
				if (s[i] < 97) s[i] += 32;
				c[j++] = s[i];

		}
		i++;


	}
	c[j] = '\0';

	for (int i = 0; i <= floor(j / 2); i++) if (c[i] != c[j-1-i]) return 0;
	return (n == 0) ? 0 : 1;

}

//[]-------------------------------------------------------------[]
//   Função: testar()
//   Entrada: valor obtido da funcao, valor esperado
//   Saída: ok se obtido igual a esperado e nao ok caso contrario
//[]-------------------------------------------------------------[]
void testar(int obtido, int esperado){
   if (obtido == esperado)
	   printf("Parabens !!!");
   else
	   printf("Ainda nao !!!");
   printf(" obtido: %d  esperado: %d\n", obtido, esperado);
}


//[]-------------------------------------------------------------[]
//    Casos de testes
//[]-------------------------------------------------------------[]
void caso_de_teste01(){
  char s[80] = "i";
  testar(eh_palindromo(s, strlen(s)), 1);
}

void caso_de_teste02(){
  char s[80] = "ovo";
  testar(eh_palindromo(s, strlen(s)), 1);
}

void caso_de_teste03(){
  char s[80] = "arara";
  testar(eh_palindromo(s, strlen(s)), 1);
}

void caso_de_teste04(){
  char s[80] = "Socorram-me subi no ônibus em Marrocos.";
  testar(eh_palindromo(s, strlen(s)), 1);
}

void caso_de_teste05(){
  char s[80] = "abba baab";
  testar(eh_palindromo(s, strlen(s)), 0);
}

void caso_de_teste06(){
  char s[80] = "Anotaram a data da maratona.";
  testar(eh_palindromo(s, strlen(s)), 1);
}

void caso_de_teste07(){
  char s[80] = "";
  testar(eh_palindromo(s, strlen(s)), 0);
}

void caso_de_teste08(){
  char s[80] = "Ando muito completo de vazios";
  testar(eh_palindromo(s, strlen(s)), 0);
}

void caso_de_teste09(){
  char s[80] = "a a b  b â  abb aa      ";
  testar(eh_palindromo(s, strlen(s)), 1);
}

void caso_de_teste10(){
  char s[80] = "ã-a, á...â";
  testar(eh_palindromo(s, strlen(s)), 1);
}

int main(void) {
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
