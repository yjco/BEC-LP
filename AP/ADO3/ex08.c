//[]--------------------------------------------------------------[]
//    Nome do arquivo: ex08.c
//    Importante: nao altere o nome do arquivo.
//[]--------------------------------------------------------------[]
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define btoa(x) x ? "true" : "false" 


//[]-------------------------------------------------------------[]
//   Função: tem_vogais()
//   Entrada: string s[] e o seu tamanho n
//   Saída:   devolve true se existem vogais
//            devolve falso caso contrario
//[]-------------------------------------------------------------[]
bool tem_vogais(char s[]){

	int n = strlen(s) - 1;
	while (n >= 0) if (s[n] == 'a' || s[n] == 'e' || s[n] == 'i' || s[n] == 'o' || s[n--] == 'u') return true;
	return false;

}


//[]-------------------------------------------------------------[]
//   Função: testar()
//   Entrada: valor obtido da funcao, valor esperado
//   Saída: ok se obtido igual a esperado e nao ok caso contrario
//[]-------------------------------------------------------------[]
void testar(bool obtido, bool esperado){
   if (obtido == esperado)
	   printf("Parabéns !!!");
   else
	   printf("Ainda não !!!");
   printf(" obtido: %s  esperado: %s\n", btoa(obtido), btoa(esperado));
}

//[]-------------------------------------------------------------[]
//    Casos de testes
//[]-------------------------------------------------------------[]
void caso_de_teste01(){
   char s[10] = "abcde";
   testar(tem_vogais(s), true);
}

void caso_de_teste02(){
   char s[10] = "bcdfgh";
   testar(tem_vogais(s), false);  
}

void caso_de_teste03(){
   char s[10] = "aeiou";
   testar(tem_vogais(s), true);
}

void caso_de_teste04(){
   char s[10] = "myxplkt";
   testar(tem_vogais(s), false);
}

void caso_de_teste05(){
   char s[10] = "xyzxxffa";
   testar(tem_vogais(s), true);
}

void caso_de_teste06(){
   char s[10] = "lmnpqt";
   testar(tem_vogais(s), false);
}

void caso_de_teste07(){
   char s[10] = "e";
   testar(tem_vogais(s), true);
}

void caso_de_teste08(){
   char s[10] = "f";
   testar(tem_vogais(s), false);
}

void caso_de_teste09(){
   char s[10] = "";
   testar(tem_vogais(s), false);
}

void caso_de_teste10(){
   char s[10] = "yioppoapl";
   testar(tem_vogais(s), true);
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
