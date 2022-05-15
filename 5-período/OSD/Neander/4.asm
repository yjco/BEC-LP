ORG 0		; vai para o endereço 00 da memória
A: DB 85	; cria o símbolo A, que carrega o valor 55 no endereço atual
ORG 136		; vai para o endereço 88 da memória
B: DB 51	; cria o símbolo B, que carrega o valor 33 no endereço atual
ORG 00		; vai para o endereço 00 da memória
LDA A		; carrega o valor do endereço do símbolo A no acumulador
STA 129		; coloca o valor do acumulador no endereço 81
LDA B		; carrega o valor do endereço do símbolo B no acumulador
STA A		; coloca o valor do acumulador no endereço do símbolo de A
LDA 129		; carrega o valor do endereço 81 no acumulador
STA B		; coloca o valor do acumulador no endereço do símbolo de B
HLT		; encerra o programa

; o programa troca os valores dos endereços de A e B
