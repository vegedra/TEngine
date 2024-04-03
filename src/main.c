/* Coded by Ivo - 02/04/24 -- Programando um Text Game 

LEMBRETES: (Mais informações no .txt)
!= significa 'is not equal to' 
gcc -o JOGO main.c parsexec.c location.c   -- para compilar  */

#include <stdio.h>  // C standard library 
#include <stdbool.h>  // Adiciona booleans 
#include "parsexec.h"  // importa função criada 
#include <locale.h>  // Para mostrar caracteres especiais - não irei usar

// Declara variavel estatica (explico o que é em location.c)
static char input[100] = "look around";  // buffer de string que coleta input do teclado. 

/* Função declarada e definida com o tipo de retorno bool, que indica que a função retorna um valor 
de true ou false. O static antes da declaração indica que essa função só é visível dentro do arquivo 
onde está declarada */
static bool getInput(void) {
	printf("\n> ");  // Prompt com o texto para o jogador digitar. 
	return fgets(input, sizeof input, stdin) != NULL;  // Função fgets (standard) pega input do teclado. 
}

int main() {  // Função main() é o ponto inicial de um programa em C e que chama as outras funções.   
    
	//setlocale(LC_ALL, "Portuguese");  // Parte para deixar em portugues, nao funcionou
    printf("\t TEngine - Adventure Text Games Engine\n");
	printf("\t \t By Pedro Ivo - 2024 \n");	// \t = Tabulação  
    printf("\nWelcome to the default room.");
	
	while (parseAndExecute(input) && getInput());  // main loop, chamando as outras funções até elas darem 'false'. 
	printf("\nExiting...\n"); // Mensagem de quando o programa termina
	
    return 0;  // Função main() retorna um zero exit code para indicar que o programa terminou.  
}