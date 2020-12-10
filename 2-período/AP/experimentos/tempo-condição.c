#include <stdio.h>

/**** TEMPO CONDIÇÃO ****
 *
 *  Esse experimento tem como intenção avaliar se a quantidade de estruturas condicionais afeta no
 * tempo de execução de um programa.
 *
 *  Para essa avaliação, foi criado um loop que itera por um número muito grande, de forma que o
 * tempo de execução se mostre mais evidente.
 *
 *  Dentro do loop haverá duas condições que nunca serão cumpridas. 
 *
 *  Na primeira execução uma das condições foi comentada, resultando em um programa que testa apenas
 * uma condição. O código foi compilado com o compilador 'gcc'. Usando a ferramenta 'time', o tempo
 * de execução foi calculado como sendo:
 *
 * > \time -p ./a.out
 * 	real 7.89
 * 	user 7.87
 * 	sys 0.00
 *
 *  Seguindo, foi descomentada a segunda condicional e o mesmo processo foi realizado. Segue o 
 * retorno:
 *
 * > \time -p ./a.out
 * 	real 9.69
 * 	user 9.64
 * 	sys 0.00
 *
 *  Podemos concluir que a quantia de condicionais influencia no tempo de execução de um programa.
 *
 *
 * * INFORMAÇÕES *
 *
 * > gcc --version
 * gcc (GCC) 10.2.0
 * 	Copyright (C) 2020 Free Software Foundation, Inc.
 * 	This is free software; see the source for copying conditions.  There is NO
 * 	warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * > \time --version
 * 	time (GNU Time) UNKNOWN
 * 	Copyright (C) 2019 Free Software Foundation, Inc.
 * 	License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.
 * 	This is free software: you are free to change and redistribute it.
 * 	There is NO WARRANTY, to the extent permitted by law.
 *
 * 	Written by David Keppel, David MacKenzie, and Assaf Gordon.
 *
 * > uname -a
 * 	Linux host 5.9.11-arch1-1 #1 SMP PREEMPT Tue, 24 Nov 2020 15:08:54 +0000 x86_64 GNU/Linux
 *
 ****/

int main() {

	for (int i = 0; i < 100000000000000000; i++) {
		if (i == -1) return 0;
		//if (i == -2) return 0;
	}

}
