/* Coded by Ivo - 02/04/24 -- Programando um Text Game 

LEMBRETES: != significa 'is not equal to' 
gcc -o JOGO main.c parsexec.c   -- para compilar 
Mais informações no .txt  */

#include <stdio.h>  // C standard library 
#include <stdbool.h>  // Adiciona booleans 
#include "parsexec.h"  // importa função criada 

static char input[100] = "olhar ao redor";  // buffer de string que coleta input do teclado. 

static bool getInput(void) {
	printf("\n> ");  // Prompt com o texto para o jogador digitar. 
	return fgets(input, sizeof input, stdin) != NULL;  // Função fgets (standard) pega input do teclado. 
}

int main() {  // Função main() é o ponto inicial de um programa em C e que chama as outras funções.   
    
    printf("EVERYTHING IS GONNA BE OK\n");  // \n = pular linha  
    printf("\nBem-vindo ao quarto do programador.");
	while (parseAndExecute(input) && getInput());  // main loop, chamando as outras funções até elas darem 'false'. 
	printf("\nSaindo...\n");
	
    return 0;  // Função main() retorna um zero exit code para indicar que o programa terminou.  
}